#include"Exam.hpp"
#include"MyownSQL.hpp"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void testArrange() //管理员用sql命令插入考试安排表
{
	cout << "请使用sql语句插入考试安排表：" << endl;
	cout << "test(room_id,limit_num,course_name,class_id,time_start,time_stop,tea_id)" << endl;
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
	cout << "请输入你希望保存的文件名（如：C:\\Users\\wu\\Desktop\\test.txt）: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	Query(str.c_str(), &file);
}
