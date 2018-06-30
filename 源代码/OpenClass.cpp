#include"MyownSQL.hpp"
#include"OpenClass.hpp"


using namespace std;
int stu_count;
/*教师*/

//start stop格式应该为 y-m-d h:m:s
void OpenCourse(string tea_id,string course_id, string course_name,string start,string stop ,string num,string credit) {//添加课程用于选课，并设置选课时间，选课数，针对大一不能选选修课
	string str = "call OpenCourse(";
	str += quote+tea_id+quote+comma+quote+course_id+quote+comma+quote+course_name+quote+comma+quote + start + quote + comma + quote + stop + quote + comma + quote+tea_id+quote+comma+num + comma + credit + rb+semi;
	Query(str.c_str(), "开课成功", "开课失败");
}

void CreateProject(string course_id ,string tea_id,string text) {//教学计划信息查询处理和发布？？？
	string str = "call CreateProject(";
	str += quote + course_id + quote + comma + quote + tea_id + quote + comma + quote + text + quote  + rb + semi;
	Query(str.c_str(),"创建计划成功","创建计划失败");
}
void SelectProject(string course_id, string tea_id) {//查看教学信息
	string str = "call SelectProject(";
	str += quote + course_id + quote + comma + quote + tea_id + quote  + rb + semi;
	Query(str.c_str(), "查询计划成功", "查询计划失败");
}
void QueryStudent(string tea_id) {//查询所带学生，可以查询各学生这门课成绩
	string str = "call QueryStudent(";
	str += quote + tea_id + quote + rb+semi;
	Query(str.c_str(), "查询学生成功", "查询学生失败");

}
void QueryCourse(string tea_id) { //查询自己开的课程，各课程选课情况
	string str = "call QueryCourse(";
	str += quote + tea_id + quote + rb + semi;
	Query(str.c_str(), "查询课程成功", "查询课程失败");
}
					/*管理员*/
void QueryBooks(string book_id) {//教材库信息(名称：数量)
	string str = "call QueryBooks(";
	str += quote + book_id + quote + rb + semi;
	Query(str.c_str(), "查询教材成功", "查询教材失败");
}
void UpdateBooks(string book_id ,string name,string num) {//更新教材信息
	string str = "call UpdateBooks(";
	str += quote + book_id + quote + comma+quote+name+quote+comma +num  + rb + semi;
	Query(str.c_str(), "更新教材成功", "更新教材失败");
}
void CourseInfoQuery() {//开课目录信息查询
	string str = "call CourseInfoQuery()";
	Query(str.c_str(), "查询开课目录成功", "查询开课目录失败");
}
void SetClass(int num) {//分配班级，分配学号 应该是最开始完成，通过从文件中读取所有的信息，然后按照需求每班多少人，进行分配
	fstream fs("student.txt");
	string name, dep_id,dep_name, school_roll , major_status,passwd = "123456";
	int grade, cls =1,count=0;
	
	while (1) {
			
		if (fs >> name >> grade >> dep_id>>dep_name >> school_roll >> major_status ) {
			CreateStu(count,name,cls, grade, dep_id,dep_name,school_roll, major_status, passwd);
			count++;
			if (count > num) {
				cls += 1;
				count = 0;
			}

		}
		else break;
	}
		
}

void CreateStu(int id ,string name,int cls, int grade,string dep_id,string dep_name,string school_roll,string major_status,string passwd) {//新建一个学生 ,也可用于单独新建一个学生
	string res_id,res_cls,res_grade;//整数类型为了字符串拼接，得转换成字符串
	stringstream ss;
	ss <<  id;
	ss >> res_id;//或者 res = ss.str();  
	res_id = dep_id + res_id; //比如000应该加上系在前面，各院就不管了，因为是院管理系统
	ss << cls;
	ss >> res_cls;
	ss << grade;
	ss >> res_grade;
	string str = "call CreateStu(";
	str += quote + res_id + quote + comma + quote + name + quote + comma + res_cls + comma + res_grade + comma + quote + dep_id+quote+comma+quote+dep_name + quote + comma + quote + passwd + quote + rb + semi;
	Query(str.c_str());
	
}

void ModifyClass(string stu_id, string cls) //分班调整，（学生更改班）
{	string str = "call ModifyClass(";
	str += quote + stu_id + quote + comma + cls+  rb + semi;
	Query(str.c_str());
}

void GetClass() //分班的情况 （各班人 ，姓名）
{
	string str = "call GetClass()";
	Query(str.c_str());
}



void ScheduleSetByStu(string sid,string cid,string start,string stop,string day) {//对特定学号排课
	string str = "call ScheduleSetByStu(";
	str += quote + sid + quote + comma + quote + cid + quote + comma + quote + start + quote + comma + quote + stop + quote + comma + day + rb + semi;
	Query(str.c_str());
}

void ScheduleSetByCls(string dep, string grd, string cls, string cid, string start, string stop, string day) {//对一个班排课
	vector<vector<string>> data = SelectStuSameCls(dep,grd,cls);
	for (auto sid : data[0]) {//对应得到的每一个sid都插入相应的时间表
		string str = "call ScheduleSetByStu(";
		str += quote + sid + quote + comma + quote + cid + quote + comma + quote + start + quote + comma + quote + stop + quote + comma + day + rb + semi;
	Query1(str.c_str());
	}
}

void ScheduleSetByCid(string cid, string start, string stop, string day) {//对一个班排课 cid为courseid
	vector<vector<string>> data = SelectStuSameCid(cid);
	for (auto sid : data[0]) {//对应得到的每一个sid都插入相应的时间表
		string str = "call ScheduleSetByStu(";
		str += quote + sid + quote + comma + quote + cid + quote + comma + quote + start + quote + comma + quote + stop + quote + comma + day + rb + semi;
		Query(str.c_str());
	}
}


vector<vector<string>> SelectStuSameCls(string dep,string grd ,string cls ) {//选出同一个班的所有学生
	string str = "call SelectStuSameCls(";
	str  += quote + dep + quote + comma + quote + grd + quote + comma + quote + cls + quote + rb + semi;
	return  Query1(str.c_str());
}

vector<vector<string>> SelectStuSameCid(string cid) {//选出同一个course的所有人

	string str = "call SelectStuSameCid(";
	str += quote + cid + quote + rb + semi;
	return Query1(str.c_str());
}