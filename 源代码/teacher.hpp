#ifndef TEACHER_H_
#define TEACHER_H_
#include<string>
using namespace std;
class Teacher {
private:
	string id;
	string password;
public:
	Teacher(string a, string b) :id(a), password(b) {};
	Teacher() {};
	~Teacher() {};

	int Load();//老师登录
	void TeaQueryStu(); //查询所有学生情况（选了这门课的学生们的一些信息，如学号，姓名，班级，成绩）
	void TeaCourseStat();//开课统计，(开了哪些课，每个选课人数)
	void worktime();//查询自己的教学班级，教学时间
	//void QueryTeacher();
};




#endif // !MANAGER_H_
