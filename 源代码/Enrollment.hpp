/*学籍管理*/
#ifndef ENROLL_H_ 
#define ENROLL_H_
#include<string>
using namespace std;
/*学籍维护*/
void WriteAward(string sid, string time, string event);//奖信息
void WritePunish(string sid, string time, string event);//惩罚
void PrintAward();//奖信息
void PrintPunish();//惩罚

void Expel(string sid);//改变学籍，是否在籍
void StayinSchool(string sid);
void RestatHome(string sid);
void ChangeOrient(string sid, string dep_id, string dep_name); //专业方向调整 转到哪个系
void PrintStuList();//分类打印 ：总名单、年级学生名单、各班学生名单、学号段内学生名单、按省份/民族/宿舍统计学生名单、各导师学生名单等
void GraduaStuList(string id, string name);//毕业生名单以及对应的毕业证编号
void GraduaStuListQ();//毕业生名单以及对应的毕业证编号


#endif // !ENROLL_H_
 