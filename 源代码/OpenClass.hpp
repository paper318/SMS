#ifndef OPEN_H_
#define OPEN_H_
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

 
 /*教师*/
void OpenCourse(string tea_id,string course_id, string course_name, string start, string stop, string num, string credit);
//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
void CreateProject(string course_id, string tea_id, string text);// 教学计划信息查询处理和发布？？？
void SelectProject(string course_id, string tea_id);
//查看教学信息
void QueryStudent(string tea_id);
//查询所带学生，可以查询各学生这门课成绩
void QueryCourse(string tea_id);
//查询自己开的课程，各课程选课情况

/*管理员*/ 
void QueryBooks(string book_id);
//教材库信息(名称：数量)
void UpdateBooks(string book_id, string name, string num);
//更新教材信息
void CourseInfoQuery();
//开课目录信息查询
void SetClass(int num);
//分配班级，分配学号 应该是最开始完成，通过从文件中读取所有的信息，然后按照需求每班多少人，进行分配

void CreateStu(int id, string name, int cls, int grade, string dep_id, string dep_name, string school_roll, string major_status, string passwd);//新建一个学生 ,也可用于单独新建一个学生

//新建一个学生
void ModifyClass(string stu_id, string cls);
//分班调整，（学生更改班）
void GetClass(); //分班的情况 （各班人 ，姓名）

//排课程表
void ScheduleSetByStu(string sid, string cid, string start, string stop, string day);//对特定学号排课

void ScheduleSetByCls(string dep, string grd, string cls, string cid, string start, string stop, string day);//对一个班排课
void ScheduleSetByCid(string cid, string start, string stop, string day);//对一个班排课 cid为courseid
vector<vector<string>> SelectStuSameCls(string dep, string grd, string cls); //选出同一个班的所有学生
vector<vector<string>> SelectStuSameCid(string cid);//选出同一个course的所有人


extern int stu_count;//学生数统计，便于学号的编写



#endif 