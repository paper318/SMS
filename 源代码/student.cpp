#include"student.hpp"
extern int open_time;//����ʱ��
extern int close_time;//ֹͣѡ��ʱ��

int  Student::Load() {//ѧ����¼
					  //����2����¼�ɹ�������-1���˺�������󣬷���0���������д���
	string str = "select PasswdStu( ";
	str += quote + id + quote + comma + quote + password + quote + rb + semi;
	int token = Query(str.c_str(), int(2));
	//int(2��Ψһ���������ṩһ��int�Ͳ����������ذ汾
	return token;
}

void Student::GetGrades() {//��ѯѧ���ɼ�
	string str = "call GetGrades(";
	str += quote + id + quote + rb + semi;
	Query(str.c_str());
}

