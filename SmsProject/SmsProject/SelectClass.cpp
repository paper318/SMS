#include"SelectClass.hpp"
#include<string>
#include"mysql.hpp"
#include<fstream>
using namespace std;
/*学生 角色区分建议保留 界面好写点*/


void DeleteCourse(string course_id,string stu_id){//删课 
	string str = "call DeleteCourse(";
	str += quote + course_id + quote +comma+quote+course_id+quote+comma+ rb + semi;
	Query(str.c_str(), "删除成功", "删除失败");
}
void CourseSelected(string stu_id) {//已选课程
	string str = "call CourseSelected(";
	str += quote + stu_id + quote + rb + semi;
	Query(str.c_str(), "查询成功选课成功", "查询选课失败");
}
void SelectCourse(string course_id, string stu_id) {//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定  大一不能选
	string str = "select SelectCourse(";
	str += quote + course_id + quote + comma + quote + stu_id + quote + rb + semi;
	Query(str.c_str());
}

					  /*管理员*/
void changePasswd(string stu_id,string new_password) {//修改密码 针对学生
	string str = "call changePasswd(";
	string str1 = "student";
	str += quote + stu_id + quote + comma + quote + new_password + quote + comma + quote + str1 + quote + rb+semi;
	Query(str.c_str(),"改密成功","改密失败");
}
void chagePasswd(string id, string new_password,string type) {//针对老师和其他任何人 type为其他的人员表名称
	string str = "call changePasswd(";
	str += quote + id + quote + comma + quote + new_password + quote + comma + quote  + quote + rb+semi;
	Query(str.c_str(), "改密成功", "改密失败");

}

void CourseStat(string course_id) {//获得选课信息（课程和对应选课人数和各选课人）
	string str = "call CourseStat(";
	str += quote + course_id + quote + rb + semi;
	Query(str.c_str(), "查询成功选课成功", "查询选课失败");
	
}
				  /*管理员，老师*/

void PrintCourseStat() {//选课信息打印（输出到txt）
	string str = "call PrintCourse()";
	fstream course_select("course_select.txt");
	Query(str.c_str(), &course_select);
}


