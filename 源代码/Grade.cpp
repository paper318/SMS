#include"Grade.hpp"
#include"MyownSQL.hpp"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void InputGrades() //学生成绩录入,手动
{
	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());

}
				  
void TeaPrintGrades() //按教师id，打印课程成绩d
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

void StuPrintGrades() //按学生id，打印课程成绩d
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

void DepGradesSort()// 按学院，总分打印排名 
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





void GradesDistri()     //按学院，学位课统计分数段
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



             
