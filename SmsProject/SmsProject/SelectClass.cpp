#include"SelectClass.hpp"
#include<string>
#include"mysql.hpp"
#include<fstream>
using namespace std;
/*ѧ�� ��ɫ���ֽ��鱣�� �����д��*/


void DeleteCourse(string course_id,string stu_id){//ɾ�� 
	string str = "call DeleteCourse(";
	str += quote + course_id + quote +comma+quote+course_id+quote+comma+ rb + semi;
	Query(str.c_str(), "ɾ���ɹ�", "ɾ��ʧ��");
}
void CourseSelected(string stu_id) {//��ѡ�γ�
	string str = "call CourseSelected(";
	str += quote + stu_id + quote + rb + semi;
	Query(str.c_str(), "��ѯ�ɹ�ѡ�γɹ�", "��ѯѡ��ʧ��");
}
void SelectCourse(string course_id, string stu_id) {//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨  ��һ����ѡ
	string str = "select SelectCourse(";
	str += quote + course_id + quote + comma + quote + stu_id + quote + rb + semi;
	Query(str.c_str());
}

					  /*����Ա*/
void changePasswd(string stu_id,string new_password) {//�޸����� ���ѧ��
	string str = "call changePasswd(";
	string str1 = "student";
	str += quote + stu_id + quote + comma + quote + new_password + quote + comma + quote + str1 + quote + rb+semi;
	Query(str.c_str(),"���ܳɹ�","����ʧ��");
}
void chagePasswd(string id, string new_password,string type) {//�����ʦ�������κ��� typeΪ��������Ա������
	string str = "call changePasswd(";
	str += quote + id + quote + comma + quote + new_password + quote + comma + quote  + quote + rb+semi;
	Query(str.c_str(), "���ܳɹ�", "����ʧ��");

}

void CourseStat(string course_id) {//���ѡ����Ϣ���γ̺Ͷ�Ӧѡ�������͸�ѡ���ˣ�
	string str = "call CourseStat(";
	str += quote + course_id + quote + rb + semi;
	Query(str.c_str(), "��ѯ�ɹ�ѡ�γɹ�", "��ѯѡ��ʧ��");
	
}
				  /*����Ա����ʦ*/

void PrintCourseStat() {//ѡ����Ϣ��ӡ�������txt��
	string str = "call PrintCourse()";
	fstream course_select("course_select.txt");
	Query(str.c_str(), &course_select);
}


