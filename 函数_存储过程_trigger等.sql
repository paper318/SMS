--系
create table department
( name nvarchar(20), 
  dep_id nvarchar(20) not null primary key,
 );
 
 
 --班
 create table class
(	dep_id nvarchar(200,
	class_id nvarchar(20) not null primary key,
)


-- 学生
create table student(
dep_id nvarchar(20),--系
class_id int,
Grade int,
name nvarchar(20),
stu_id nvarchar(20) not null primary key ,
passwd nvarchar(20),
school_roll nvarchar(20)  --学籍状态（开除，休学，留级等）
major_status nvarchar(20) --专业变动

);
-- 老师
create table teacher(
tea_id nvarchar(20) not null primary key,
name nvarchar(20),
passwd nvarchar(20),
);
-- 领导
create table leader(
lea_id nvarchar(20) not null primary key,
name nvarchar(20),
dep_id nvarchar(20),
passwd nvarchar(20)
);
-- 管理员
create table manager(
man_i
d nvarchar(20) not null primary key,
name nvarchar(20),
passwd nvarchar(20),
);
-- 课程
create table course(
course_id nvarchar(20),   
course_name nvarchar(30),  --可能是同一个名字不同的课程内容
opent datetime,
closet datetime,
credit numeric(10.2),
tea_id nvarchar(20) ,
num int,
course_type nvarchar(20),
primary key (tea_id,course_id) 
);                              

--选课     
create table sec(
stu_id nvarchar(20) not null,
course_id nvarchar(20) not null,
tea_id nvarchar(20)
primary key(stu_id,course_id,tea_id)
)

-- 成绩
create table grade(
stu_id nvarchar(20) not null,
course_name nvarchar(20) not null,
grade numeric(10.2),
primary key(stu_id,course_name)
);
--教材
create table book(
book_id nvarchar(20) not null primary key,
name nvarchar(50) ,
num int
);
-- 课程表
create table schedule  --可以根据班级统一排课(根据stu_id找到班级，同一个的排一个课)，也可以根据学生排课(根据stu_id单独设置)，也可以根据课程排课(选择有这个课的所有学生，进行加课)
stu_id nvarchar(20),
name nvarchar(20),
time_start datetime,
time_stop datetime,
tea_id nvarchar(20)
class_time int,

);
-- 奖励
create table award(
time date,
event nvarchar(50),
award nvarchar(30)
);
-- 惩罚
create table punish(
time date,
event nvarchar(50),
award nvarchar(30)
);
-- 毕业
create table graduate(
id nvarchar(30),
name nvarchar(20)
);




--生成考试安排表的思路如下：
教室一个时间段内能使用的时间一定（需要一个表classroom 记录教室数量如（room_id,limit_num）），全校所有科目需要考试的时间一定，
所有排法应该是用一个表记录每个需要考试的科目（course表大致能实现这个功能，需要的信息（课程id,class）注意一个班按人数可以能需要填入多个相同的信息，比如150人的一个班考大物，则需要填入3个相同的信息段，分成3个部分，因此可以再补充1,2，3数字，与前面两个字段合并成主码）
以时间顺序开始分配，可以采用下列规则:
给所有课程编号，像填空格一样，把课程填入空教室，依次填，一直到所有课程全部填入教室，安排结束
填的过程中要考虑几个条件
1.一个课程必须在同一个时间段内考完，如大物都得在同一天的同上午或者下午考完，不允许跨时间段，处理时就是要求插入时检查表里已经存在的相同的课程的时间段，后面插入的就得填入和前面插入的同一个时间段，如果是第一个插入的就选一个最近的时间就好
2.同一个院一个专业同一个年级在一个时间段内只能进行一门考试，也就是说上午考数据库的同时，不能再安排c++，但可以安排其他院的考试科目，
	这就要求我们在插入时，检查是否这个一个时间段内是否存在着院、专业、年级一样的考试：如果不存在，那就直接插入，如果存在，就检查将要插入的与表里存在的是否是同一个科目，如果是，插入，如果不是，拒绝插入
3.每次插入一个考试安排后，在那个记录着等待安排的考试科目的表中删除对应的行，因为它已经被安排了	
总结起来：
结束循环的判断条件是：需要安排的考试科目的那个表是否为空
循环以时间的推进进行，从规定的考试周开始那个日期开始：伪代码如下：
do{
for(开始的日期start;这个时间段还有能安排的教室&&还有需要安排的教室 ;)
{
	插入；
}
start++;  //进入下一个时间段

}while(还有需要安排的考试)

有一点需要注意，当教室很少的情况下，这样写程序肯定会出问题，因为结合上面的条件可以知道，一个学校的教室最多能容纳100个人，却招了101人，这个时候有两种错误的情况：一.101人同时考一门科目，比如全校同时考毛概，这个分配系统会怎么样呢。前面100人都没问题，最后一个人插入的时候，问题来了，
插入会被拒绝，因为当前时间段，人已经满了，插入其他时间段同样会被拒绝，因为同一个科目，不允许两个时间段考试，所以是死循环且没办法解决。二，101人同时考两门或者以上的不同科目，前面100人没问题，但最后1人插入，问题又来了，插入当前时间段会被拒绝，因为没位置，满了，
插入其他时间段同样被拒绝，因为同一个科目不允许两个时间段考试。这个问题能够解决，就是移除与发生错误的这个人考试科目相同的那些安排，重新在下一个时间段统一插入。

错误总结就是：
如果某一门科目需要安排的考试人数大于一个时间段内能提供的最大座位数量，那就死循环了，所以得增加一个条件先判断，避免死循环
在排除了第一种错误后，如果多门科目需要安排的考试人数大于一个时间段内能提供的最大座位数量，需要解决上面守的问题，很简单，就把已经插入的那些人取出来，放到下个时间段就好。


最后生成的表应该为

-- 考试
create table test(
room_id nvarchar(20) not null primary key, 
limit_num numeric(10.2),
course_name 
class_id    
time_start datetime,  
time_stop datetime
);


--监考教师表 根据test 表用存储过程生成
--表结构如下：
create table invigilator
( tea_id nvarchar(20),
  room_id nvarchar(20),
  time_start datetime,
  time_stop datetime,
 );

还是一个填空格的游戏，对应考试表里的每一行数据，都得安排一个老师监考，同一个时间段内，一名老师只能监考一个考试
过程是这样的：
从头将考试安排表按行扫描，每读一行，就读取他的时间段，教室，然后从监考老师表（就是那些任课老师teacher表）中依次读取
老师，然后插入一个新表，每次插入都检查：这个时间段内，这名老师有没有监考，没有的话，插入；有的话换老师。当然也会出现老师总数少于每天的考场安排的，这个时候，肯定又会出bug，
具体分析和上面一样，但如果在进行这个考试安排表之前，就根据每个时间段能监考的老师最大数量设置为每个时间段能安排的考试最大数量，就可以消除bug

总得来说，就是在一个时间段内：同一个科目的考生、考场能容纳的最大数量、能提供的监考老师、每个时间段安排的考场，都得符合逻辑规则才行。
同一个科目的考生是确定、考场能容纳的最大数量、能提供的监考老师都是安排前都已经知道的，这种失衡无法改变，但每个时间段安排的考场数却能根据前面3个设定一个合理
的上限。提前设置上限，非常有必要。

--学生考试表 根据test生成
--表的结构如下
create table stu_test
( name nvarchar(200),
  room_id nvarchar(20),
  time_start datetime,
  time_stop datetime,
 )

--教学计划  
create table poject(
course_id nvarchar(20), 
tea_id nvarchar(20),
msg TEXT
);


-- 学生
		-- //学生登录
		delimiter //
		create function PasswdStu(id nvarchar(20), key nvarchar(20))
			returns nvarchar(50)
			begin 
				if(id in
					(select stu_id from student where passwd =unknowkey and stu_id=id
					))
				then return "Success";
				else
				return "Failed";
				end if;
			end //
		delimiter ;

		select PasswodStu();

		-- //学生查成绩
		delimiter //
		create procedure GetGrades(identity nvarchar(20))
			begin 
				select student.name ,course.course_name,grade.grade,course.credit
				from student,grade,course
				where student.stu_id=grade.stu_id and student.stu_id=grade.stu_id and course.course_name = grade.course_name;
				
				select student.name,sum(course.credit)
				from student,course,grade
				where student.stu_id=grade.stu_id and student.stu_id=grade.stu_id and course.course_name = grade.course_name
					and grade.grade>60 
				group by student.name ;

			end //
		delimiter ;

--老师

		--//老师登录
		delimiter //
		create function PasswdTea(id nvarchar(20), key nvarchar(20))
			returns nvarchar(50)
			begin 
				if(id in
					(select tea_id from teacher where passwd =key and tea_id=id
					))
				then return "Success";
				else
				return "Failed";
				end if;能
			end //
		delimiter 
		
		--//查询所有学生情况（选了这门课的学生们的一些信息，如学号，姓名，班级，成绩）
		delimiter //
		create procedure TeaQueryStu(id nvarchar(20))
		begin
			select sec.course_id,student.stu_id,student.name,stuedent.class_id,
			from  sec join student on (sec.stu_id=student.stu_id)
			where (sec.tea_id=identity)
			group by student.class_id;
		end //
		delimiter ;
		
		
		--//开课统计，(开了哪些课，每个选课人数)
		delimiter //
		create procedure TeaCourseStat(id nvarchar(20))
		begin
			select course.course_id, course.course_name, sum(stu_id),course.
			from sec join course on(course.tea_id=sec.tea_id and course.course_id=sec.course_id)
			where (course.tea_id=id)
			group by course.course_id;
		end //
		delimiter ;
		
		--//查询自己的教学班级，教学时间
		delimiter //
		create procedure worktime(id nvarchar(20))
		begin
			select course_id,class_id,class_time,time_start,time_stop
			from schedule join student on(student.stu_id=schedule.stu_id)
			where(schedule.tea_id=id)
		end //
		delimiter ;
		

--领导
		--//登录
		delimiter //
		create function PasswdTea(id nvarchar(20), key nvarchar(20))
			returns nvarchar(50)
			begin 
				if(id in
					(select lea_id from leader where passwd =key and tea_id=id
					))
				then return "Success";
				else
				return "Failed";
				end if;能
			end //
		delimiter

		--//获得登录领导的所在系dep_id
		delimiter //
		create procedure getdep_id(id nvarchar(20)
		begin
			select lep__id
			from leader
			where(lea_id=id);
		end //
		delimiter ;
		
		
		
		--//查询本院学生人数
		delimiter //
		create procedure StudentCount(id nvarchar(20))
		begin
			select class_id,sum(stu_id)
			from student join leader on(student.dep_id=leader.dep_id)
			where(student.dep_id=id)
			group by class_id;
		end //
		delimiter ;
		
		--//查询本院的开课统计(开了哪些课，每个选课人数)
		delimiter //
		create procedure LeaCourseStat(id nvarchar(20))
		begin
			select course.tea_id,teacher.name,course.course_id,course.name,sum(sec.stu_id)
			from sec join student on(sec.stu_id=student.stu_id)
			   right join course on(sec.course_id=course.course_id and sec.tea_id=course.tea_id)
					 join teacher on(teacher.tea_id=course.tea_id)
					 join leader on(teacher.dep_id=leader.dep_id)
			where(leader.dep_id=id)
			group by course.course_id;
			
		end //
		delimiter ;
		
		--//按课程名查询老师相关信息
		delimiter //
		create procedure LeaQueryTea(coursename nvarchar(20),depid nvarchar(20))
		begin
			select course.course_id,course.name,course.tea_id,teacher.name
			from teacher join course on(teacher.tea_id=course.tea_id)
			where(course.name=coursename and teacher.dep_id=depid)
		end //
		delimiter ;
		
		--//按学生学号查询学生的相关信息(班级，选课等)
		delimiter //
		create procedure LeaQueryStu(id nvarchar(20))
		begin
			select student.name,student.stu_id,student.classs_id,sec.course_id
			from student join sec on(student.stu_id=sec.stu_id)
			where(student.stu_id=id)
		end //
		delimiter ;
		
		
			
		
		
		
		
	

--选课管理

		-- //改密码
		delimiter //
		create procedure GetGrades( id nvarchar(20),np nvarchar(20) , role nvarchar(20))
				update role set passwd = np where  stu_id = id；
		delimiter ;
		-- 查一个学生选课
		delimiter //
		create procedure CourseSlected( id nvarchar(20))
				select * from sec where sec.stu_id = id;
		delimiter ;
		-- 选课
		delimiter //
		create function SelectCourse( cid nvarchar(20)，sid nvarchar(20))
			returns nvarchar(40)
			
			begin
				if (select Grade from student where student.id= sid) != 1 and (select opent from course where cid=course.course_id)>NOW()and(select closet from course where cid=course.course_id)<NOW()
				then
					insert into sec(stu_id,course_id) values(sid,cid);
				else
					return	"不满足选课条件";	
				end if
			end //
		delimiter ;

		-- 删课		
		create procedure DeleteCourse( cid nvarchar(20),sid nvarchar(20))
				delete from sec where sec.stu_id = sid, and sec.course_id = cid;

		---获得选课信息
		delimiter //
		create procedure CourseStat( id nvarchar(20))
			begin
				--课程人数
				select course.course_id,course.course_name,count(sec.stu_id) as sum
				from course,student,sec 
				where course.course_id = sec.course_id and sec.stu_id = student.stu_id and course.course_id = id;
				--课程选课人
				select course.course_id,course.course_name,student.name 
				from course,studen,sec
				where course.course_id = sec.course_id and sec.stu_id = student.stu_id and course.course_id = id;
			end	
		delimiter ;
		

-- 开课管理
		-- 开课
		delimiter //
		create procedure OpenCourse( id nvarchar(20),name nvarchar(20),start nvarchar(50),stop nvarchar(50),id nvarchar(20) , n int,cre numeric(10.2))
				insert into Course(course_id,course_name,opent,closet,tea_id,course_name,num,credit) values(id,name,start,stop,id,n,cre);
		delimiter ;

		--创建教学计划
		delimiter //
		create procedure CreateProject( id nvarchar(20),tid nvarchar(20),txt text)
				insert into project(course_id,tea_id,message) values(id,tid,txt);
		delimiter ;
		--查看教学计划
		delimiter //
		create procedure SelectProject( id nvarchar(20),tid nvarchar(20))
				select text from project where course_id=id and tea_id = tid;
		delimiter ;
		--查看所带学生的成绩
		delimiter //
		create procedure QueryStudent(id nvarchar(20))
			select sec.stu_id,student.stu_name,grade.grade from student,grade,sec,course
			where sec.stu_id = grade.stu_id and sec.course_id = course.course_id and course.course_name = grade.course_name and id = course.tea_id and sec.stu_id= student.stu_id
		delimiter ;
		-- 查询开课信息
		delimiter //
		create procedure QueryCourse(id nvarchar(20))
			select sec.stu_id,student.stu_name from student,sec,course
			where sec.stu_id = grade.stu_id and sec.course_id = course.course_id and id = course.tea_id and sec.stu_id= student.stu_id
		delimiter ;
		-- 查询教材库
		delimiter //
		create procedure QueryBooks(id nvarchar(20))
			select name from  book
			where id = book_id;
		delimiter ;
		-- 更新教材库
		delimiter //
		create procedure UpdateBooks(id nvarchar(20),na nvarchar(50),nu int)
			begin
				if(id in select book_id from book)
				then update book set book_num = num;
				else (insert into book(book_id,name,num) values(id,na,nu));
				end if;
			end;
		delimiter ;
		-- 开课目录信息查询
		create procedure CourseInfoQuery()
			select * from course;
		--导入学生信息
		create procedure CreateStu(id nvarchar(20),na nvarchar(20), cls int,  gr int, dep nvarchar(20), pw nvarchar(20))
			insert into student(stu_id,name,grade,department,passwd) values(id,na,cls,gr,dep,pw);
		--修改班级
		create procedure ModifyClass( id nvarchar(20),cls int)
			update student set class = cls where id = stu_id;
		--查看各班学生
		delimiter //
		create procedure GetClass()
			begin
				select count(stu_id) from student group by class;
				select class,stu_id ,stu_name from student group by class;
			end;
		delimiter ;


		--制定课程表
			--通过特定学生设置
			delimiter//
			create procedure ScheduleSetByStu(sid nvarchar(20),cid nvarchar(20),start datetime,stop datetime,wday int)
				begin 
					insert into schedule(stu_id,course_id,time_start,time_stop,day)
						values(sid,cid,start,stop,wday);

			delimiter ;

			--同一个班的所有学生id
			delimiter//
			create procedure SelectStuSameCls(dep nvarchar(20),grd int,cls int)
				select stu_id from student where department = dep and grade = grd,class = cls;
			delimiter ;

			--同一个课程所有学生的id
			delimiter//
			create procedure SelectStuSameCls(cid nvarchar(20))
				select stu_id from sec where sec.course_id = cid;
			delimiter ;

