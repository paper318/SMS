#include"Enrollment.hpp"
#include<iostream>
#include<string>
#include"MyownSQL.hpp"
using namespace std;


void WriteAward(string sid,string time,string event) {//奖信息
	string str = "call WriteAward(";
	str += quote + sid + quote + comma + quote + time + quote +comma+quote+event+quote+ rb + semi;
	Query(str.c_str(), "奖励记录成功", "查询记录失败");
}
void WritePunish(string sid, string time, string event) {//惩罚
	string str = "call WritePunish(";
	str += quote + sid + quote + comma + quote + time + quote + comma + quote + event + quote + rb + semi;
	Query(str.c_str(), "惩罚记录成功", "惩罚记录失败");
}
void PrintAward() {//奖信息
	string str = "call PrintAward()";
	Query(str.c_str(), "奖励查询成功", "查询查询失败");
}
void PrintPunish() {//惩罚
	string str = "call PrintPunish()";
	Query(str.c_str(), "惩罚查询成功", "惩罚查询失败");
}
void Expel(string sid) {//改变学籍，是否在籍
	string str = "call Expel(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "开除学籍成功","开除学籍失败");
}
void StayinSchool(string sid) {
	string str = "call StayinSchool(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "保留学籍成功", "保留学籍失败");
}
void RestatHome(string sid) {
	string str = "call RestatHome(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "休学成功", "休学失败");
}

void ChangeOrient(string sid,string dep_id,string dep_name  ) { //专业方向调整 转到哪个系
	string str = "call ChangeOrient(";
	str += quote + sid + quote +comma+quote+dep_id+quote+comma+quote+dep_name+quote+ rb + semi;
	Query(str.c_str(), "转专业成功", "转专业失败");

}
void PrintStuList() {//分类打印 ：总名单、年级学生名单、各班学生名单、学号段内学生名单、按省份/民族/宿舍统计学生名单、各导师学生名单等
	string str = "call List()";
	Query(str.c_str(), "名单查询成功", "名单查询失败");
}

void GraduaStuList(string id ,string name) {//毕业生名单以及对应的毕业证编号
	string str = "call GraduateInsert(";
	str += quote + id + quote + comma+quote+name+quote+rb + semi;
//	cout << str;

	Query(str.c_str(), "查询成功", "查询失败");
}
void GraduaStuListQ() {//毕业生名单以及对应的毕业证编号
	string str = "call GraduateQuery()";
	//cout << str;
	Query(str.c_str(), "查询成功", "查询失败");
}