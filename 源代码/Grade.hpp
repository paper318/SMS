/*成绩管理*/
#ifndef EXAM_H_
#define EXAM_H_ 
/*管理员*/
void InputGrades();//管理员sql语句录入成绩
void TeaPrintGrades();//打印老师各自所开课程的学生的成绩
void StuPrintGrades(); //按学号打印学生所有课程成绩
void DepGradesSort();// 按学院，总分排名并且打印学生课程成绩
void GradesDistri();// 按学院，学位课计算分数段

#endif 