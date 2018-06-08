#ifndef OPEN_H_
#define OPEN_H_

/*教师*/
void TeachProject();//教学计划信息查询处理和发布？？
void QueryStudent();//查询所带学生，可以查询各学生这门课相关信息
void QueryCourse(); //查询自己开的课程，各课程选课情况
/*管理员*/
void QueryBooks();//教材库信息(名称：数量)
void UpdateBooks();//更新教材信息
void SetClass();//分配班级，分配学号
void ModifyClass();//分班调整，（学生更改班）
void GetClass();//分班的情况 （各班人数 ，姓名）
void SetSchedule();//排课并制定课程表
#endif 