#include"teacher.hpp"
#include"MyownSQL.hpp"


int Teacher::Load()//老师登录
{ //返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误
	string str = "select PasswdTea( ";
	str += quote + id + quote + comma + quote + password + quote + rb + semi;
	int token = Query(str.c_str(),int(2));
	return token;
}

void Teacher::TeaQueryStu()//查询所有学生情况（选了这门课的学生们的一些信息，如学号，姓名，班级，成绩）
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

  
 