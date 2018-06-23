

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
	~Teacher() {};

	int Load();//登陆
	void TeaQueryStu(); //老师查询所有学生情况（如选了该老师课程的学生的班级，学号，姓名）
	void TeaCourseStat();//开课统计，(开了哪些课，每个选课人数)
	void worktime();//查询自己的教学班级，教学时间



	//任课教师可以查询自己开设的课程，并进行核准确认。暂不实现，不好测试  
	//void QueryTeacher();//输入课程或得到老师和老师相关信息
	//这个功能不要求
};




#endif // !MANAGER_H_
