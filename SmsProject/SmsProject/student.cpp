#include"student.hpp"
//zhanxinrui
extern int open_time;//ѡ�ο���ʱ��
extern int close_time;//����ʱ��v

int  Student::Load() {//��½
	string str = "select PasswodStu( ";
	str += quote+id+quote+comma+quote+password+quote+rb+semi;
	
	int token = Query(str.c_str());
	return token;



	
}
	
void Student::GetGrades() {//�鿴�ɼ�������ѧ��
	string str = "select GetGrades(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());

}