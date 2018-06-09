//选课管理
#ifndef SELECT_H_
#define SELECT_H_

/*学生*/
void changePasswd();//修改密码
void SelectCourse();//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定 
void DeleteCourse();//删课
void CourseSelected();//已选课程

/*管理员*/
void OpenCourse();//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
void CourseStat();//获得选课信息（课程和对应选课人数和各选课人）

  /*管理员，老师*/
void PrintCourseStat();//选课信息打印（输出到txt）


#endif