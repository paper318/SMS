#include"Enrollment.hpp"
#include<iostream>
#include<string>
#include"MyownSQL.hpp"
using namespace std;


void WriteAward(string sid,string time,string event) {//����Ϣ
	string str = "call WriteAward(";
	str += quote + sid + quote + comma + quote + time + quote +comma+quote+event+quote+ rb + semi;
	Query(str.c_str(), "������¼�ɹ�", "��ѯ��¼ʧ��");
}
void WritePunish(string sid, string time, string event) {//�ͷ�
	string str = "call WritePunish(";
	str += quote + sid + quote + comma + quote + time + quote + comma + quote + event + quote + rb + semi;
	Query(str.c_str(), "�ͷ���¼�ɹ�", "�ͷ���¼ʧ��");
}
void PrintAward() {//����Ϣ
	string str = "call PrintAward()";
	Query(str.c_str(), "������ѯ�ɹ�", "��ѯ��ѯʧ��");
}
void PrintPunish() {//�ͷ�
	string str = "call PrintPunish()";
	Query(str.c_str(), "�ͷ���ѯ�ɹ�", "�ͷ���ѯʧ��");
}
void Expel(string sid) {//�ı�ѧ�����Ƿ��ڼ�
	string str = "call Expel(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "����ѧ���ɹ�","����ѧ��ʧ��");
}
void StayinSchool(string sid) {
	string str = "call StayinSchool(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "����ѧ���ɹ�", "����ѧ��ʧ��");
}
void RestatHome(string sid) {
	string str = "call RestatHome(";
	str += quote + sid + quote + rb + semi;
	Query(str.c_str(), "��ѧ�ɹ�", "��ѧʧ��");
}

void ChangeOrient(string sid,string dep_id,string dep_name  ) { //רҵ������� ת���ĸ�ϵ
	string str = "call ChangeOrient(";
	str += quote + sid + quote +comma+quote+dep_id+quote+comma+quote+dep_name+quote+ rb + semi;
	Query(str.c_str(), "תרҵ�ɹ�", "תרҵʧ��");

}
void PrintStuList() {//�����ӡ �����������꼶ѧ������������ѧ��������ѧ�Ŷ���ѧ����������ʡ��/����/����ͳ��ѧ������������ʦѧ��������
	string str = "call List()";
	Query(str.c_str(), "������ѯ�ɹ�", "������ѯʧ��");
}

void GraduaStuList(string id ,string name) {//��ҵ�������Լ���Ӧ�ı�ҵ֤���
	string str = "call GraduateInsert(";
	str += quote + id + quote + comma+quote+name+quote+rb + semi;
//	cout << str;

	Query(str.c_str(), "��ѯ�ɹ�", "��ѯʧ��");
}
void GraduaStuListQ() {//��ҵ�������Լ���Ӧ�ı�ҵ֤���
	string str = "call GraduateQuery()";
	//cout << str;
	Query(str.c_str(), "��ѯ�ɹ�", "��ѯʧ��");
}