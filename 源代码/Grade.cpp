#include"Grade.hpp"
#include"MyownSQL.hpp"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void InputGrades() //管理员sql语句录入成绩
{	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());

}
				  
void TeaPrintGrades() //打印老师各自所开课程的学生的成绩
{	string filename;
	cout << "please import the address of file which you want to save as: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	string str = "call TeaPrintGrades();";
	Query(str.c_str(), &file);
}

void StuPrintGrades() //按学号打印学生所有课程成绩
{
	string filename;
	cout << "please import the address of file which you want to save as: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	string str = "call StuPrintGrades();";
	Query(str.c_str(), &file);
}

void DepGradesSort()//按学院，总分排名并且打印学生课程成绩
{	string filename;
	cout << "please import the address of file which you want to save as: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	string str = "call DepGradesSort();";
	Query(str.c_str(), &file);
}





void GradesDistri()   //按学院，学位课计算分数段
{
	string filename;
	cout << "please import the address of file which you want to save as: " << endl;
	cin >> filename;
	fstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}
	string str = "call GradesDistri();";
	Query(str.c_str(), &file);
}

