#include"student.hpp"
//zhanxinrui
extern int open_time;//选课开放时间
extern int close_time;//结束时间v

int  Student::Load() {//登陆
	string str = "select PasswodStu( ";
	str += quote+id+quote+comma+quote+password+quote+rb+semi;
	
	int token = Query(str.c_str());
	return token;



	
}
	
void Student::GetGrades() {//查看成绩和所修学分
	string str = "select GetGrades(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());

}