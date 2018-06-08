#ifndef class_h_
#define class_h_

#include<string>
using namespace std;

int open_time;//选课开放时间
int close_time;//结束时间

class Student {
private:
	string id;
	string password;
	int grade;//年级
public:
	Student(string a, string b) :id(a), password(b) {};
	~Student() {};
	void Load(string id, string password);//登陆
	//void SelectCourse();//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定 
	//void DeleteCourse();//删课
	//void CourseSelected();//已选课程
	void GetGrades();//查看成绩和所修学分
	void Getid

};


#endif // !class_h_
