--  奖励
drop procedure WriteAward;
delimiter // ;
create procedure WriteAward(sid nvarchar(20),t date,eve nvarchar(50))
begin 
insert into award(stu_id,time,event)
values(sid,t,eve);
end //
delimiter ; //

drop procedure PrintAward;
delimiter // ;
create procedure PrintAward()
begin 
select * from award; 
end //
delimiter ; //

--  惩罚
drop procedure WritePunish;
delimiter // ;
create procedure WritePunish(sid nvarchar(20),t date,eve nvarchar(50))
begin 
insert into punish(stu_id,time,event)
values(sid,t,eve);
end //
delimiter ; //

drop procedure PrintPunish ;
delimiter // ;
create procedure PrintPunish()
select * from punish //
delimiter ; //

--  开除
drop procedure Expel;
delimiter // 
create procedure Expel(sid nvarchar(20))
update student  set  school_roll = "expel" where  stu_id = sid;//
delimiter ; //
--  在籍	
drop procedure StayinSchool;		
delimiter //
create procedure StayinSchool(sid nvarchar(20))
update student  set  school_roll = "stay" where  stu_id = sid; //
delimiter ; //
--  休学			
drop procedure RestatHome;
delimiter //
create procedure RestatHome(sid nvarchar(20))
update student  set  school_roll = "Rest" where  stu_id = sid; //
delimiter ; //

--  方向改变
drop procedure ChangeOrient;
delimiter //
create procedure ChangeOrient(sid nvarchar(20),did nvarchar(20),dname nvarchar(20))
begin	
update student set  dep_id =did  where  stu_id = sid;
update student set major_status = "changed"; 
end //
delimiter ; //

--  毕业生打印
drop procedure GraduateQuery;
delimiter //
create procedure GraduateQuery()
select * from graduate;	 //
delimiter ; //
--  毕业生登记
drop procedure GraduateInsert;
delimiter //
create procedure GraduateInsert(i_d nvarchar(20),n_ame nvarchar(20))
insert into graduate(id,name) values(i_d,n_ame)	; //
delimiter ; //


-- 选课
-- 所有信息打印
drop procedure PrintCourse;
delimiter //
create procedure PrintCourse()
select* from sec	; //
delimiter ; //
-- insert into course(tea_id,course_id,course_name,opent,closet,num,credit,course_type) values("890101","21","test","2018-7-1 12:00:00","2018-7-4 12:00:00",122,2,"选修");
--  开课管理
--  开课
drop procedure OpenCourse;
delimiter //
create procedure OpenCourse( tid nvarchar(20),theid nvarchar(20),name nvarchar(20),start_time nvarchar(50),stop_time nvarchar(50), n int,cre numeric(10.2),thetype nvarchar(20))
insert into course(tea_id,course_id,course_name,opent,closet,num,credit,course_type) values(tid,theid,name,start_time,stop_time,n,cre,thetype);
//
delimiter ; //

--  创建教学计划
drop procedure CreateProject;
delimiter //
create procedure CreateProject( id nvarchar(20),tid nvarchar(20),txt text)
insert into project(course_id,tea_id,msg) values(id,tid,txt);
-- insert into project(course_id,tea_id,msg) values("21","980101","这是一个测试");
//
delimiter ; //		

--  查看教学计划
drop procedure SelectProject;
delimiter //
create procedure SelectProject( id nvarchar(20),tid nvarchar(20))
select msg from project where course_id=id and tea_id = tid;
-- select msg from project where course_id = "21" and tea_id = "980101";
//
delimiter ; //		

--  查看所带学生的成绩
drop procedure QueryStudent;
delimiter //
create procedure QueryStudent(tid nvarchar(20))
select sec.stu_id,student.name,grade.score from student,grade,sec,course
where sec.tea_id = course.tea_id and sec.stu_id = grade.stu_id and grade.tea_id = course.tea_id and sec.course_id = course.course_id and tid= course.tea_id 
and sec.stu_id= student.stu_id and grade.course_id = course.course_id
//
delimiter ; //		

--  查询开课信息
drop procedure QueryCourse;
delimiter //
create procedure QueryCourse(tid nvarchar(20))
select course.course_name, sec.stu_id,student.name from student,sec,course
where sec.stu_id = student.stu_id and sec.tea_id = tid and course.course_id = sec.course_id;
//
--  查询所有学生情况（选了这门课的学生们的一些信息，如学号，姓名，班级，成绩）
drop procedure TeaQueryStu;
delimiter //
create procedure TeaQueryStu(tid nvarchar(20))
begin	
select sec.course_id,student.stu_id,student.name,student.class_id
from  sec join student on (sec.stu_id=student.stu_id)
where (sec.tea_id=tid)
group by student.class_id;
end //
delimiter ; //

--  选课
drop function SelectCourse;
delimiter //
create function SelectCourse( cid nvarchar(20),sid nvarchar(20),tid nvarchar(20))
returns nvarchar(40)
begin
if ( select distinct(student.stuGrade)-year(NOW()) from student where student.stu_id=sid) !=0  and (select opent from course where cid=course.course_id and  course.tea_id=tid)<NOW()and(select closet from course where cid=course.course_id and course.tea_id=tid)>NOW()
then
insert into sec(stu_id,course_id,tea_id) values(sid,cid,tid);
return "选课成功";
else
return	"不满足选课条件";	
end if;
end //
delimiter ; //


--  学生查成绩
drop procedure  GetGrades;

delimiter //
create procedure GetGrades(id nvarchar(20))
begin 
select student.name ,course.course_name,grade.score,course.credit
from student,grade,course
where student.stu_id=grade.stu_id and student.stu_id=grade.stu_id and course.course_id = grade.course_id and student.stu_id=id;

select student.name as "姓名",sum(course.credit) as "学分"
from student,course,grade
where student.stu_id=grade.stu_id and student.stu_id=grade.stu_id and course.course_id = grade.course_id 
and student.stu_id=id and grade.score>60 
group by student.name ;
end //
delimiter ; //

--  导入学生信息
--  开始学生应该统一导入，班级也是统一分配的，
drop procedure CreateStu;
delimiter //
create procedure CreateStu(id nvarchar(20),na nvarchar(20), cls nvarchar(20),  gr int, did nvarchar(20), dname  nvarchar(20), pw nvarchar(20),sr nvarchar(20) ,ms nvarchar(20))
begin 
if (not  exists(select * from student where stu_id = id))
then
insert into student(stu_id,name,stuGrade,class_id,dep_id,passwd,school_roll,major_status) values(id,na,gr,cls,did,pw,sr,ms);
end if ;
if (not exists(select * from class where  cls= class_id))
then
insert into class (dep_id,class_id) values(did,cls);
end if;
if ( not exists(select * from department where dep_id = did ))
then
insert into department(dep_id,name) values(did,dname)  ;
end if;
end //
delimiter ; //

--  修改班级
drop procedure ModifyClass;
create procedure ModifyClass( id nvarchar(20),cls nvarchar(20))
update student set  class_id = cls where id = stu_id;

--  查看各班学生
drop procedure GetClass;
delimiter //
create procedure GetClass()
begin
select class_id as"班级",count(stu_id) as "人数" from student group by class_id;
select class_id,stu_id ,name from student group by class_id;
end //
delimiter ; //

--  同一个班的所有学生id
drop procedure SelectStuSameCls;

create procedure SelectStuSameCls(dep nvarchar(20),grd int,cls nvarchar(20))
select student.stu_id 
from student,class,department 
where student.dep_id = dep and department.dep_id = student.dep_id and student.stuGrade = grd and class.class_id = cls; 		


--  制定课程表
--  通过特定学生设置
drop procedure ScheduleSetByStu;
delimiter //
create procedure ScheduleSetByStu(sid nvarchar(20),cname nvarchar(20),cid nvarchar(20),starttime datetime,stoptime datetime,tid nvarchar(20))
begin 
insert into schedule(stu_id,name,class_id,time_start,time_stop,tea_id)
values(sid,cname,cid,starttime,stoptime,tid);
end //
delimiter ; //

--  同一个班的所有学生id
drop procedure SelectClassSameCls;
delimiter //
create procedure SelectClassSameCls(dep nvarchar(20),grd int,cls int)
select stu_id from student,class where dep_id = dep_id and stuGrade = grd and class.class_id = cls;
//
delimiter ; //

--  同一个课程所有学生的id
drop procedure SelectStuSameCid;
delimiter //
create procedure SelectStuSameCid(cid nvarchar(20))
select stu_id from sec where sec.course_id = cid;
//
delimiter ; //


--  同一个班的所有学生id
drop procedure SelectClassSameCls;
delimiter //
create procedure SelectClassSameCls(dep nvarchar(20),grd int,cls int)
select stu_id from student,class where dep_id = dep and stuGrade = grd and class.class_id = cls;
//
delimiter ; //


--  获得选课信息
drop procedure CourseStat;
delimiter //
create procedure CourseStat( id nvarchar(20))
begin
--  课程人数

select course.course_id,course.course_name,count(sec.stu_id) as sum
from course,student,sec 
where course.course_id = sec.course_id and sec.stu_id = student.stu_id and course.course_id = id;

--  课程选课人 
select course.course_id,course.course_name,student.name,teacher.name
from course,student,sec,teacher
where course.course_id = sec.course_id and sec.stu_id = student.stu_id and course.course_id = id and sec.tea_id = teacher.tea_id;
end	 //
delimiter ; //