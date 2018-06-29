#ifndef LEADER_H_
#define LEADER_H_

#include<string>
using namespace std;

class Leader {
private:
	 
	string id;
	string password;
public:
	Leader(string a, string b) :id(a), password(b) {};
	~Leader() {};
	string getdep_id();//返回该领导所在院的dep_ip，这是个为了简化LeaQueryTea()查询的辅助函数
	int Load();//老师登录
	void StudentCount();//查询本院学生人数
	void LeaCourseStat();//查询本院的开课统计(开了哪些课，每个选课人数)
	int LeaQueryTea(string coursename);//按课程名查询老师相关信息
	void LeaQueryStu(string stu_id);//按学生学号查询学生的相关信息(班级，选课等)
};





#endif // !MANAGER_H_
