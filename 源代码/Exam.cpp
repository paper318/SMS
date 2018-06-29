#include"Exam.hpp"
#include"MyownSQL.hpp"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void testArrange() //管理员用sql命令插入考试安排表
{
	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());
}

void PrintInfo() //打印考试安排表
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
