#include"teacher.hpp"
#include"MyownSQL.hpp"


int Teacher::Load()//登录
{ //返回2：登录成功，-1：失败，0：程序其他错误
	string str = "select PasswdTea( ";
	str += quote + id + quote + comma + quote + password + quote + rb + semi;
	int token = Query(str.c_str(),int(2));
	//int(2）唯一的意义提供一个int参数就是对query重载识别
	return token;
}

void Teacher::TeaQueryStu()//老师查询学生情况（如选了该老师课程的学生的班级，学号，姓名）
{
	string str = "call TeaQueryStu(";
	str += quote + id + quote + semi;
	Query(str.c_str());
}


void Teacher::TeaCourseStat()//开课统计，(开了哪些课，每个选课人数)
{
	string str = "call TeaCourseStat(";
	str += quote + id + quote + semi;
	Query(str.c_str());
}

void Teacher::worktime()//查询自己的教学班级，教学时间
{
	string str = "call worktime(";
	str += quote + id + quote + semi;
	Query(str.c_str());
}

  
