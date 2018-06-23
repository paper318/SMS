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

	int Load();//登录
	string getdep_id(); //获得该院领导dep_id;
	void StudentCount();//查询整个院的学生人数
	void LeaCourseStat();//查询整个院的开课统计，(开了哪些课，每个选课人数) 
	int LeaQueryTea(string coursename);//输入课程或得到老师和老师相关信息
	void LeaQueryStu(string stu_id);//获得指定学生的相关信息
};










#endif // !MANAGER_H_
