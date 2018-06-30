#ifndef class_h_
#define class_h_
#include"MyownSQL.hpp"
#include<string>
using namespace std;

extern int open_time;//开课时间
extern int close_time;//停止选课时间
class Student {
private:
	string id;
	string password;
public:
	Student(string i, string p) :id(i), password(p) {};
	~Student() {};
	Student() {};

	int Load();//学生登录
			   //void SelectCourse();//选课
			   //void DeleteCourse();//删除课
			   //void CourseSelected();
	void GetGrades();//查询成绩
};

 
#endif // !class_h_
