#include"leader.hpp"
#include"MyownSQL.hpp"
#include<vector>

int Leader::Load()//登录
{//返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误
		string str = "select PasswdLea( ";
		str += quote + id + quote + comma + quote + password + quote + rb + semi;
		int token = Query(str.c_str(),int(2));
		//int(2）唯一的作用是提供一个int型参数区别重载版本
		return token;
}

string Leader::getdep_id()
{  //用来返回学院领导所在院的dep_id
	string str = "call getdep_id(";
	str += quote + id + quote + rb + semi;
	vector<vector<string>> data; 
	if (!Query(str.c_str(), data))
		return data[0][0]; 
	else return "faild";
}

void Leader::StudentCount() //查询本院学生人数
{
	string str = "call  StudentCount(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());
}

void Leader::LeaCourseStat() //查询本院的开课统计(开了哪些课，每个选课人数)
{
	string str = "call LeaCourseStat(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());

}
 

int Leader::LeaQueryTea()  //按课程名查询老师相关信息
{
	string coursename;
	cout << "请输入课程名：";
	cin >> coursename;
	string dep_id = this->getdep_id(); //成功则返回dep_id,否则返回string "faild"
	string s = "faild";
	if (dep_id == s) {
		cout << "query faild,can't get user's dep_id" << endl;
		return 0;
	}
	string str = "call LeaQueryTea(";
	str += quote + coursename + quote + comma + quote + dep_id + quote + rb + semi;
	Query(str.c_str());
	return 1;
}
void Leader::LeaQueryStu () //按学生学号查询学生的相关信息(班级，选课等)
{
	string stu_id;
	cout << "请输入要查询的学生学号：";
	cin >> stu_id;
	string str = "call LeaQueryStu(";
	str += quote + stu_id + quote + rb + semi;
	Query(str.c_str());
}

