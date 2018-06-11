-- 学生
create table student(
stu_id varchar(20) not null primary key ,
name varchar(20),
passwd varchar(20),
class int,
Grade int,
department varchar(20),--系
);
-- 老师
create table teacher(
tea_id varchar(20) not null primary key,
name varchar(20),
passwd varchar(20),
);
-- 领导
create table leader(
lea_id varchar(20) not null primary key,
name varchar(20),
passwd varchar(20)
);
-- 管理员
create table manager(
man_id varchar(20) not null primary key,
name varchar(20),
passwd varchar(20),
);
-- 课程
create table course(
course_id varchar(20),   
course_name varchar(30),  --可能是同一个名字不同的课程内容
opent datetime,
closet datetime,
credit numeric(10.2),
tea_id varchar(20) ,
num int,
primary key (tea_id,course_id)
);
--选课
create table sec(
stu_id varchar(20) not null,
course_id varchar(20) not null,
primary key(stu_id,course_id)
)
-- 成绩
create table grade(
stu_id varchar(20) not null,
course_name varchar(20) not null,
grade numeric(10.2),
primary key(stu_id,course_name)
);
--教材
create table book(
book_id varchar(20) not null primary key;
name varchar(50) ;
num int;
)
-- 课程表
create table schedule(
course_name varchar(20),
time_start datetime,
time_stop datetime
);
-- 奖励
create table award(
time date,
event varchar(50),
award varchar(30)
);
-- 惩罚
create table punish(
time date,
event varchar(50),
award varchar(30)
);
-- 毕业
create table graduate(
id varchar(30),
name varchar(20)
);
-- 考试
create table test(
room_id varchar(20) not null primary key,
limit_num numeric(10.2),
supervisor varchar(20),
time_start datetime,
time_stop datetime
)
-- 考试房间
create table room(
stu_id varchar(20) not null primary key,
room_id varchar(20) references test(room_id)
)

--教学计划
create table poject(
course_id varchar(20), 
tea_id varchar(20),
msg TEXT
)


-- 学生
		-- //学生登录
		delimiter //
		create function PasswdStu(identity varchar(20), varchar(20))
			returns varchar(50)
			begin 
				if(id in
					(select id from student where passwd =  and identity= id
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
		create procedure GetGrades(identity varchar(20))
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
		create procedure GetGrades( id varchar(20),np varchar(20) , role varchar(20))
				update role set passwd = np where  stu_id = id；
		delimiter ;
		-- 查一个学生选课
		delimiter //
		create procedure CourseSlected( id varchar(20))
				select * from sec where sec.stu_id = id;
		delimiter ;
		-- 选课
		delimiter //
		create function SelectCourse( cid varchar(20)，sid varchar(20))
			returns varchar(40)
			
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
		create procedure DeleteCourse( cid varchar(20),sid varchar(20))
				delete from sec where sec.stu_id = sid, and sec.course_id = cid;

		---获得选课信息
		delimiter //
		create procedure CourseStat( id varchar(20))
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
		create procedure OpenCourse( id varchar(20),name varchar(20),start varchar(50),stop varchar(50),id varchar(20) , n int,cre numeric(10.2))
				insert into Course(course_id,course_name,opent,closet,tea_id,course_name,num,credit) values(id,name,start,stop,id,n,cre);
		delimiter ;

		--创建教学计划
		delimiter //
		create procedure CreateProject( id varchar(20),tid varchar(20),txt text)
				insert into project(course_id,tea_id,message) values(id,tid,txt);
		delimiter ;
		--查看教学计划
		delimiter //
		create procedure SelectProject( id varchar(20),tid varchar(20))
				select text from project where course_id=id and tea_id = tid;
		delimiter ;
		--查看所带学生的成绩
		delimiter //
		create procedure QueryStudent(id varchar(20))
			select sec.stu_id,student.stu_name,grade.grade from student,grade,sec,course
			where sec.stu_id = grade.stu_id and sec.course_id = course.course_id and course.course_name = grade.course_name and id = course.tea_id and sec.stu_id= student.stu_id
		delimiter ;
		-- 查询开课信息
		delimiter //
		create procedure QueryCourse(id varchar(20))
			select sec.stu_id,student.stu_name from student,sec,course
			where sec.stu_id = grade.stu_id and sec.course_id = course.course_id and id = course.tea_id and sec.stu_id= student.stu_id
		delimiter ;
		-- 查询教材库
		delimiter //
		create procedure QueryBooks(id varchar(20))
			select name from  book
			where id = book_id;
		delimiter ;
		-- 更新教材库
		delimiter //
		create procedure UpdateBooks(id varchar(20),na varchar(50),nu int)
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
		create procedure CreateStu(id varchar(20),na varchar(20), cls int,  gr int, dep varchar(20), pw varchar(20))
			insert into student(stu_id,name,grade,department,passwd) values(id,na,cls,gr,dep,pw);
		--修改班级
		create procedure ModifyClass( id varchar(20),cls int)
			update student set class = cls where id = stu_id;
		--查看各班学生
		delimiter //
		create procedure GetClass()
			begin
				select count(stu_id) from student group by class;
				select class,stu_id ,stu_name from student group by class;
			end;
		delimiter ;


