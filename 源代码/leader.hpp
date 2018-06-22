



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

	void Load(string id, string password);//登录
	void StudentCount();//学生人数
	void CourseStat();//开课统计，(开了哪些课，每个选课人数)
					  //任课教师可以查询自己开设的课程，并进行核准确认。暂不实现，不好测试  
	void QueryTeacher();//输入课程或得到老师和老师相关信息
	void QueryStudent();//获得指定学生的相关信息
};










#endif // !MANAGER_H_
