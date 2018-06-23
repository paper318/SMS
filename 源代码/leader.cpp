#include"leader.hpp"
#include"MyownSQL.hpp"
#include<vector>

int Leader::Load()//登录
{//返回2：登录成功，-1：失败，0：程序其他错误
		string str = "select PasswdLea( ";
		str += quote + id + quote + comma + quote + password + quote + rb + semi;
		int token = Query(str.c_str(),int(2));
		//int(2）唯一的意义提供一个int参数就是对query重载识别
		return token;
}

string Leader::getdep_id()
{
	string str = "call getdep_id(";
	str += quote + id + quote + rb + semi;
	vector<vector<string>> data; //data是一个结果集，存储多个表
	if (!Query(str.c_str(), data))
		return data[0][0]; 
	else return "faild";
}

void Leader::StudentCount() //查询整个院的学生人数
{
	string str = "call  StudentCount(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());
}

void Leader::LeaCourseStat() //查询本院的开课统计，(开了哪些课，每个选课人数)
{
	string str = "call LeaCourseStat(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());

}


					 //任课教师可以查询自己开设的课程，并进行核准确认。暂不实现，不好测试  
int Leader::LeaQueryTea(string coursename)  //输入课程或得到老师和老师相关信息
{	
	string dep_id = this->getdep_id(); //成功返回该用户的dep_id,失败返回string "faild"
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
void Leader::LeaQueryStu(string stu_id) //按学生学号查询学生的相关信息(班级，选课，，成绩等)
{
	string str = "call LeaQueryStu(";
	str += quote + stu_id + quote + rb + semi;
	Query(str.c_str());
}

