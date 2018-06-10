#include"OpenClass.hpp"
#include"mysql.hpp"
#include<fstream>
#include<sstream>
using namespace std;
int stu_count;
/*��ʦ*/

//start stop��ʽӦ��Ϊ y-m-d h:m:s
void OpenCourse(string course_id, string course_name,string start,string stop ,string tea_id,string num,string credit) {//��ӿγ�����ѡ�Σ�������ѡ��ʱ�䣬ѡ��������Դ�һ����ѡѡ�޿�
	string str = "call OpenCourse(";
	str += quote+course_id+quote+comma+quote+course_name+quote+comma+quote + start + quote + comma + quote + stop + quote + comma + quote+tea_id+quote+comma+num + comma + credit + rb+semi;
	Query(str.c_str(), "���γɹ�", "����ʧ��");
}

void CreateProject(string course_id ,string tea_id,string text) {//��ѧ�ƻ���Ϣ��ѯ����ͷ���������
	string str = "call CreateProject(";
	str += quote + course_id + quote + comma + quote + tea_id + quote + comma + quote + text + quote  + rb + semi;
	Query(str.c_str(),"�����ƻ��ɹ�","�����ƻ�ʧ��");
}
void SelectProject(string course_id, string tea_id) {//�鿴��ѧ��Ϣ
	string str = "call SelectProject(";
	str += quote + course_id + quote + comma + quote + tea_id + quote  + rb + semi;
	Query(str.c_str(), "��ѯ�ƻ��ɹ�", "��ѯ�ƻ�ʧ��");
}
void QueryStudent(string tea_id) {//��ѯ����ѧ�������Բ�ѯ��ѧ�����ſγɼ�
	string str = "call QueryStudent(";
	str += quote + tea_id + quote + rb+semi;
	Query(str.c_str(), "��ѯѧ���ɹ�", "��ѯѧ��ʧ��");

}
void QueryCourse(string tea_id) { //��ѯ�Լ����Ŀγ̣����γ�ѡ�����
	string str = "call QueryCourse(";
	str += quote + tea_id + quote + rb + semi;
	Query(str.c_str(), "��ѯ�γ̳ɹ�", "��ѯ�γ�ʧ��");
}
					/*����Ա*/
void QueryBooks(string book_id) {//�̲Ŀ���Ϣ(���ƣ�����)
	string str = "call QueryBooks(";
	str += quote + book_id + quote + rb + semi;
	Query(str.c_str(), "��ѯ�̲ĳɹ�", "��ѯ�̲�ʧ��");
}
void UpdateBooks(string book_id ,string name,string num) {//���½̲���Ϣ
	string str = "call UpdateBooks(";
	str += quote + book_id + quote + comma+quote+name+quote+comma +num  + rb + semi;
	Query(str.c_str(), "���½̲ĳɹ�", "���½̲�ʧ��");
}
void CourseInfoQuery() {//����Ŀ¼��Ϣ��ѯ
	string str = "call CourseInfoQuery()";
	Query(str.c_str(), "��ѯ����Ŀ¼�ɹ�", "��ѯ����Ŀ¼ʧ��");
}
void SetClass(int num) {//����༶������ѧ�� Ӧ�����ʼ��ɣ�ͨ�����ļ��ж�ȡ���е���Ϣ��Ȼ��������ÿ������ˣ����з���
	fstream fs("student.txt");
	string name, department, passwd = "123456";
	int grade,id, cls =1,count=0;
	
	while (1) {
			
		if (fs >> name >> grade >> department) {
			CreateStu(id,name,cls, grade, department, passwd);
			count++;
			if (count > num) {
				cls += 1;
				count = 0;
			}

		}
		else break;
	}
		
}

void CreateStu(int id ,string name,int cls, int grade,string department,string passwd) {//�½�һ��ѧ��
	string res_id,res_cls,res_grade;//��������Ϊ���ַ���ƴ�ӣ���ת�����ַ���
	stringstream ss;
	ss <<  id;
	ss >> res_id;//���� res = ss.str();  
	ss << cls;
	ss >> res_cls;
	ss << grade;
	ss >> res_grade;
	string str = "call CreateStu(";
	str += quote + res_id + quote + comma + quote + name + quote + comma + res_cls + comma + res_grade + comma + quote + department + quote + comma + quote + passwd + quote + rb + semi;
	Query(str.c_str());
	
}

void ModifyClass(string stu_id, string cls) {//�ְ��������ѧ�����İࣩ
	string str = "call ModifyClass(";
	str += quote + stu_id + quote + comma + cls+  rb + semi;
	Query(str.c_str());
}
void GetClass() {//�ְ����� �������� ��������
	string str = "call GetClass()";
	Query(str.c_str());
}
void SetSchedule();//�ſβ��ƶ��γ̱� ���̫ɧ�ˡ��� fucku bitch
