#include"Exam.hpp"
#include"MyownSQL.hpp"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void testArrange() //管理员用sql命令插入考试安排表
{
	string room_id, limit_num, course_name, class_id, time_start, time_stop, tea_id;
	cout << "请输入room_id:";cin >> room_id;
	cout << "请输入limit_num:";cin >> limit_num;
	cout << "请输入course_name:";cin >> course_name;
	cout << "请输入class_id:";cin >> class_id;
	cout << "请输入time_start(xxxx-xx-xx-xx:xx:xx):";cin >> time_start;
	cout << "请输入time_stop (xxxx-xx-xx-xx:xx:xx):";cin >> time_stop;
	cout << "请输入tea_id:";cin >> tea_id;
	std::string str;
	str = "insert into test values (";
	str += quote + room_id + quote + comma + quote + limit_num + quote + comma + quote + course_name + quote + comma + quote + class_id + quote + comma +
		quote + tea_id + quote+comma+quote + time_start + quote + comma + quote + time_stop + quote + rb + semi;
	Query(str.c_str());
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
