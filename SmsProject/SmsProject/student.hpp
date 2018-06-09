#ifndef class_h_
#define class_h_

#include<string>
#include"mysql.hpp"
using namespace std;

extern int open_time;//选课开放时间
extern int close_time;//结束时间

class Student {
private:
	string id;
	string password;
public:
	Student(string i, string p) :id(i), password(p){};
	~Student() {};
	int Load();//登陆
	//void SelectCourse();//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定 
	//void DeleteCourse();//删课
	//void CourseSelected();//已选课程
	void GetGrades();//查看成绩和所修学分



};


#endif // !class_h_
