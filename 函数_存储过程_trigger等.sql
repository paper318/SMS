-- 学生
create table student(
stu_id nvarchar(20) not null primary key ,
name nvarchar(20),
passwd nvarchar(20),
class int,
Grade int,
department nvarchar(20),--系
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
passwd nvarchar(20)
);
-- 管理员
create table manager(
man_id nvarchar(20) not null primary key,
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
primary key (tea_id,course_id)
);
--选课
create table sec(
stu_id nvarchar(20) not null,
course_id nvarchar(20) not null,
primary key(stu_id,course_id)
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
create table schedule(  可以根据班级统一排课(根据stu_id找到班级，同一个的排一个课)，也可以根据学生排课(根据stu_id单独设置)，也可以根据课程排课(选择有这个课的所有学生，进行加课)
stu_id nvarchar(20),
course_name nvarchar(20),
time_start datetime,
time_stop datetime,
day int
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
-- 考试
create table test(
room_id nvarchar(20) not null primary key,
limit_num numeric(10.2),
supervisor nvarchar(20),
time_start datetime,
time_stop datetime
)
-- 考试房间
create table room(
stu_id nvarchar(20) not null primary key,
room_id nvarchar(20) references test(room_id)
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
		create function PasswdStu(identity nvarchar(20), nvarchar(20))
			returns nvarchar(50)
			begin 
				if(id in
					(select id from student where passwd =  and identity= id
					))
				then return "Success";
				else
				return "Failed";
				end if;能
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

