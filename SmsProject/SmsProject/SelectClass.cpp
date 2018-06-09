#include"SelectClass.hpp"
#include<string>
#include"mysql.hpp"
using namespace std;
/*学生 角色区分建议保留 界面好写点*/

void SelectCourse();//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定 
void DeleteCourse();//删课
void CourseSelected();//已选课程

					  /*管理员*/
void changePasswd(string stu_id,string new_password) {//修改密码 针对学生
	string str = "call changePasswd(";
	string str1 = "student";
	str += quote + stu_id + quote + semi + quote + new_password + quote + semi + quote + str1 + quote + rb;
	Query(str.c_str(),"改密成功","改密失败");
}
void chagePasswd(string id, string new_password,string type) {//针对老师和其他任何人 type为其他的人员表名称
	string str = "call changePasswd(";
	str += quote + id + quote + semi + quote + new_password + quote + semi + quote  + quote + rb;
	Query(str.c_str(), "改密成功", "改密失败");

}
void OpenCourse();//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
void CourseStat();//获得选课信息（课程和对应选课人数和各选课人）

				  /*管理员，老师*/
void PrintCourseStat();//选课信息打印（输出到txt）