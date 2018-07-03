//选课管理
#ifndef SELECT_H_
#define SELECT_H_
#include<string>
#include"MyownSQL.hpp"
#include<fstream>
 /*学生*/ 
void DeleteCourse(string course_id, string stu_id);//删课 
void CourseSelected(string stu_id);//已选课程
void SelectCourse(string course_id, string stu_id,string tea_id);//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定  大一不能选
void changePasswd(string stu_id, string new_password);//修改密码 针对学生
void chagePasswd(string id, string new_password, string type);//针对老师和其他任何人 type为其他的人员表名称
void CourseStat(string course_id);//获得选课信息（课程和对应选课人数和各选课人）
 /*管理员，老师*/
int PrintCourseStat();//选课信息打印（输出到txt）


#endif 