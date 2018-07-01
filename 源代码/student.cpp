#include"student.hpp"
extern int open_time;//开课时间
extern int close_time;//停止选课时间

int  Student::Load() {//学生登录
//返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误
	string str = "select PasswdStu( ";
	str += quote+id+quote+comma+quote+password+quote+rb+semi;
	int token = Query(str.c_str(),int(2));
	//int(2）唯一的作用是提供一个int型参数区别重载版本
	return token;
}
	 
void Student::GetGrades() {//查询学生成绩
	string str = "select GetGrades(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());


}

 