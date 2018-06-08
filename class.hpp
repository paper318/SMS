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
	void SelectCourse();//选课  ps:时间,选课数量，不能选选修课 有限制根据管理员规定 
	void DeleteCourse();//删课
	void CourseSelected();//已选课程
	void GetGrades();//查看成绩和所修学分

};


class Teacher {
private:
	string id;
	string password;
public:
	Teacher(string a, string b) :id(a), password(b) {};
	~Teacher() {};

	void Load(string id, string password);//登陆
	void QueryStudent();//查询所带学生，可以查询各学生这门课相关信息
	void QueryCourse(); //查询自己开的课程，各课程选课情况
};

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
	
	/*选课*/
	void OpenCourse();//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
	void CourseStat();//获得选课信息（课程和对应选课人数和各选课人）
	void PrintCourseStat();//选课信息打印（输出到txt）
	
	/*开课管理*/
	void QueryBooks();//教材库信息(名称：数量)
	void UpdateBooks();//更新教材信息
	void SetClass();//分配班级，分配学号
	void ModifyClass();//分班调整，（学生更改班）
	void GetClass();//分班的情况 （各班人数 ，姓名）
	void SetSchedule();//排课并制定课程表
	
	/*成绩管理*/
	void InputGrades();//学生成绩录入
	//成绩转存什么意思
	void PrintGrades();//打印成绩   b	课程成绩单（教师）、学生成绩通知单、学生毕业成绩表输出到txt
	void GradesSort();// 成绩排名
	void GradesDistri();// 及分数段统计（按总分 / 学位课成绩排名）
	
	/*学籍维护*/
	void AwardAndPunish();//奖惩信息
	void ChangeSchoolRoll();//改变学籍，学生所在地等等
	void ChangeOrient(); //专业方向调整
	void PrintStuList();//分类打印 ：总名单、年级学生名单、各班学生名单、学号段内学生名单、按省份/民族/宿舍统计学生名单、各导师学生名单等
	void GraduaStuList();//毕业生名单以及对应的毕业证编号

	/*考务管理*/
	void RoomArrange();//考试教室安排,返回考试安排表
	void TestInfo();//学生，任课老师，监考老师等考试信息
	void PrintInfo();//打印考试安排表，考试信息txt。
};

#endif // !class_h_
