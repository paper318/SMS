/*成绩管理*/
#ifndef EXAM_H_
#define EXAM_H_
/*管理员*/
void InputGrades();//学生成绩录入

				   //成绩转存什么意思
void TeaPrintGrades();//按老师id，打印课程成绩 
void StuPrintGrades(); //按学生id，打印课程成绩
void DepGradesSort();// 按学院，总分排名并且打印学生课程成绩
void GradesDistri();// 按学院，学位课计算分数段
#endif 