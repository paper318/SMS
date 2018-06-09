#选出满足路线完整性的所有
create procedure route_complete()
	select a.custname 
	from reservations199 as a,reservations199 as b,reservations199 as c,reservations199 as d ,flights199
	where a.custname = b.custname and b.custname = c.custname and c.custname = d.custname and a.resvtype = 1 
	and flights199.flightnum = a.resvkey 
	and flights199.fromcity = b.resvkey and b.resvtype=3
	and flights199.arivcity = c.resvkey and c.resvtype=3
	and flights199.arivcity = d.resvkey and d.resvtype=2


-- #特定成员
delimiter //
create function route_complete1(name varchar(50))
	returns varchar(50)
	begin 
		if(name in
			(select a.custname 
			from reservations199 as a,reservations199 as b,reservations199 as c,reservations199 as d ,flights199
			where a.custname = b.custname and b.custname = c.custname and c.custname = d.custname and a.resvtype = 1 
			and flights199.flightnum = a.resvkey 
			and flights199.fromcity = b.resvkey and b.resvtype=3
			and flights199.arivcity = c.resvkey and c.resvtype=3
			and flights199.arivcity = d.resvkey and d.resvtype=2
			))
		then return "Match the rule";
		else
		return "Didn\'t match the rule";
		end if;
	end //
delimiter ;
select route_complete1();


-- 学生
		-- //学生登录
		delimiter //
		create function PasswdStu(identity varchar(20),password varchar(20))
			returns varchar(50)
			begin 
				if(id in
					(select id from student where passwd = password and identity= id
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



--开课管理

		-- //改密码
		delimiter //
		create procedure GetGrades( id varchar(20),np varchar(20) , role varchar(20))
				update role set passwd = np where  stu_id = id；

			end //
		delimiter ;



-- 学生
create table student(
stu_id varchar(20) not null primary key ,
name varchar(20),
passwd varchar(20),
class varchar(20),
Grade varchar(20),
Dorm varchar(20),
Counselor varchar(20),
Province varchar(20),
nation varchar(20)
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
stu_id varchar(20) ,
course_name varchar(30),
credit numeric(10.2),
tea_id varchar(20) references teacher(tea_id),
primary key (stu_id,course_name)
);
-- 成绩
create table grade(
stu_id varchar(20) not null,
course_name varchar(20) not null,
grade numeric(10.2),
primary key(stu_id,course_name)
);
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

