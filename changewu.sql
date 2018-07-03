use sms;
--   查询所有学生情况（选了这门课的学生们的一些信息，如学号，姓名，班级，成绩）
drop procedure TeaQueryStu;
delimiter //
create procedure TeaQueryStu(id nvarchar(20))
begin
select sec.course_id,student.stu_id,student.name,student.class_id
from  sec join student on (sec.stu_id=student.stu_id)
where (sec.tea_id=id)
group by student.class_id;
end //
delimiter ;

--   查询自己的教学班级，教学时间
drop procedure worktime;
delimiter //
create procedure worktime(id nvarchar(20))
begin
select schedule.name,schedule.class_id,time_start,time_stop
from schedule join student on(student.stu_id=schedule.stu_id)
where(schedule.tea_id=id);
end //
delimiter ;


--  领导
--   登录
drop function PasswdLea;
delimiter //
create function PasswdLea(id nvarchar(20), unknowkey nvarchar(20))
returns nvarchar(50)
begin 
if(id in
(select lea_id from leader where passwd =unknowkey and lea_id=id
))
then return "Success";
else
return "Failed";
end if;
end //
delimiter ;

--   获得登录领导的所在系dep_id
drop procedure getdep_id;
delimiter //
create procedure getdep_id(id nvarchar(20))
begin
select dep_id
from leader
where(lea_id=id);
end //
delimiter ;


--   查询本院学生人数
drop procedure StudentCount;
delimiter //
create procedure StudentCount(id nvarchar(20))
begin
select class_id,count(stu_id) as account
from student join leader on(student.dep_id=leader.dep_id)
where(leader.lea_id=id)
group by class_id;
end //
delimiter ;


--   查询本院的开课统计(开了哪些课，每个选课人数)
drop procedure LeaCourseStat;
delimiter //
create procedure LeaCourseStat(id nvarchar(20))
begin
select course.tea_id,teacher.name,course.course_id,course.course_name,count(sec.stu_id) as account
from sec join student on(sec.stu_id=student.stu_id)
right join course on(sec.course_id=course.course_id and sec.tea_id=course.tea_id)
join teacher on(teacher.tea_id=course.tea_id)
join leader on(teacher.dep_id=leader.dep_id)
where(leader.lea_id=id)
group by course.course_id,teacher.name;

end //
delimiter ;

--   按课程名查询老师相关信息
drop procedure LeaQueryTea;
delimiter //
create procedure LeaQueryTea(coursename nvarchar(20),depid nvarchar(20))
begin
select course.course_id,course.course_name,course.tea_id,teacher.name
from teacher join course on(teacher.tea_id=course.tea_id)
where(course.course_name=coursename and teacher.dep_id=depid);
end //
delimiter ;


--   按学生学号查询学生的相关信息(班级，选课等)
drop procedure LeaQueryStu;
delimiter //
create procedure LeaQueryStu(id nvarchar(20))
begin
select student.name,student.stu_id,student.class_id,sec.course_id
from student join sec on(student.stu_id=sec.stu_id)
where(student.stu_id=id);
end //
delimiter ;
--   管理员	
--   改密码
drop procedure ChangeOnePassword;

delimiter //
create procedure ChangeOnePassword(id nvarchar(20),newpasswd nvarchar(20))
begin
if (id in (select tea_id from teacher where tea_id=id))
then
update teacher set passwd=newpasswd where tea_id=id;
elseif (id in (select stu_id from student where stu_id=id))
then
update student set passwd=newpasswd where stu_id=id;
elseif (id in (select man_id from manager where man_id=id))
then
update manager set passwd=newpasswd where man_id=id;
elseif(id in (select lea_id from leader where lea_id=id))
then
update leader set passwd=newpasswd where leader.lea_id=id;
else  select "该用户不存在" as '结果';
end if;
end//
delimiter ;

--  成绩管理
drop procedure TeaPrintGrades;
--   打印老师各自所开课程的学生的成绩
delimiter //
create procedure TeaPrintGrades()
begin
select course.tea_id,teacher.name,course.course_id,course.course_name,stu_id,score
from grade join course on(grade.course_id=course.course_id and grade.tea_id=course.tea_id)
join teacher on(course.tea_id=teacher.tea_id)
order by course.tea_id;
end //
delimiter ;

--   按学号打印学生所有课程成绩
drop procedure StuPrintGrades;
delimiter //
create procedure StuPrintGrades()
begin
select stu_id,course.course_id,course.course_name,score
from grade join course on (course.tea_id=grade.tea_id and grade.course_id=course.course_id)
order by stu_id;
end //
delimiter ;


--   按学院，总分排名并且打印学生课程成绩
drop procedure DepGradesSort;
delimiter //
create procedure DepGradesSort()
begin
select student.dep_id,student.stu_id,student.name,sum(score) as total_score
from grade join course on(course.tea_id=grade.tea_id and grade.course_id=course.course_id)
join  student on (grade.stu_id=student.stu_id)
group by student.stu_id
order by total_score;
end //
delimiter ;

--   按学院，学位课计算分数段
drop procedure GradesDistri;
delimiter //
create procedure GradesDistri()
begin
select student.dep_id,grade.course_id,course.course_name,
sum(case when grade.score<60 then 1 else 0 end ) as '0~59',
sum(case when grade.score>=60 and grade.score <70 then 1 else 0 end) as '60~69',
sum(case when grade.score>=70 and grade.score <80 then 1 else 0 end) as '70~79',
sum(case when grade.score>=80 and grade.score <90 then 1 else 0 end) as '80~89',
sum(case when grade.score>=90 and grade.score <=100 then 1 else 0 end) as '90~100'
from grade join student on (grade.stu_id=student.stu_id)
join course on(grade.course_id=course.course_id and grade.tea_id=course.tea_id)
group by student.dep_id,grade.course_id;
end //
delimiter ;

--  考务管理
--   打印考试安排
drop procedure PrintInfo;
delimiter //
create procedure PrintInfo()
begin
select class_id,course_name,room_id,time_start,time_stop,tea_id
from test; 
end //
delimiter ;