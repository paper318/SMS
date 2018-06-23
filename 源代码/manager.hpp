




#ifndef MANAGER_H_
#define MANAGER_H_
#include<string>
using namespace std;
class Manager {
private:
	string id;
	string password;
public:
	Manager(string a, string b) :id(a), password(b) {};
	~Manager() {};
	void Load(string id, string password);

	/*更改账户*/
	void ChangePassword();//对任何用户可以更改密码

	//					  /*选课*/
	//void OpenCourse();//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
	//void CourseStat();//获得选课信息（课程和对应选课人数和各选课人）
	//void PrintCourseStat();//选课信息打印（输出到txt）

						   /*开课管理*/
	//void QueryBooks();//教材库信息(名称：数量)
	//void UpdateBooks();//更新教材信息
	//void SetClass();//分配班级，分配学号
	//void ModifyClass();//分班调整，（学生更改班）
	//void GetClass();//分班的情况 （各班人数 ，姓名）
	//void SetSchedule();//排课并制定课程表

					   /*成绩管理*/
	//void InputGrades();//学生成绩录入
	//				   //成绩转存什么意思
	//void PrintGrades();//打印成绩   b	课程成绩单（教师）、学生成绩通知单、学生毕业成绩表输出到txt
	//void GradesSort();// 成绩排名
	//void GradesDistri();// 及分数段统计（按总分 / 学位课成绩排名）

	//					/*学籍维护*/
	//void AwardAndPunish();//奖惩信息
	//void ChangeSchoolRoll();//改变学籍，学生所在地等等
	//void ChangeOrient(); //专业方向调整
	//void PrintStuList();//分类打印 ：总名单、年级学生名单、各班学生名单、学号段内学生名单、按省份/民族/宿舍统计学生名单、各导师学生名单等
	//void GraduaStuList();//毕业生名单以及对应的毕业证编号

	//					 /*考务管理*/
	//void RoomArrange();//考试教室安排,返回考试安排表
	//void TestInfo();//学生，任课老师，监考老师等考试信息
	//void PrintInfo();//打印考试安排表，考试信息txt。
};





#endif // !MANAGER_H_
