#include"Exam.hpp"
#include"MyownSQL.hpp"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void testArrange() //考试教室安排,管理员录入生成
{
	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());
}

void PrintInfo() //打印考试安排表，考试信息txt。
{
	string str = "call PrintInfo();";
	string filename;
	cout << "please import the address of file which you want to save as: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	Query(str.c_str(), &file);
}
