#ifndef class_h_
#define class_h_
#include<string>
using namespace std;

int open_time;//ѡ�ο���ʱ��
int close_time;//����ʱ��

class Student {
private:
	string id;
	string password;
	int grade;//�꼶
public:
	Student(string a, string b) :id(a), password(b) {};
	~Student() {};
	void Load(string id, string password);//��½
	void SelectCourse();//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨 
	void DeleteCourse();//ɾ��
	void CourseSelected();//��ѡ�γ�
	void GetGrades();//�鿴�ɼ�������ѧ��

};


class Teacher {
private:
	string id;
	string password;
public:
	Teacher(string a, string b) :id(a), password(b) {};
	~Teacher() {};

	void Load(string id, string password);//��½
	void QueryStudent();//��ѯ����ѧ�������Բ�ѯ��ѧ�����ſ������Ϣ
	void QueryCourse(); //��ѯ�Լ����Ŀγ̣����γ�ѡ�����
};

class Leader {
private:

	string id;
	string password;
public:
	Leader(string a, string b) :id(a), password(b) {};
	~Leader() {};

	void Load(string id, string password);//��¼
	void StudentCount();//ѧ������
	void CourseStat();//����ͳ�ƣ�(������Щ�Σ�ÿ��ѡ������)
	//�ον�ʦ���Բ�ѯ�Լ�����Ŀγ̣������к�׼ȷ�ϡ��ݲ�ʵ�֣����ò���  
	void QueryTeacher();//����γ̻�õ���ʦ����ʦ�����Ϣ
	void QueryStudent();//���ָ��ѧ���������Ϣ
};

class Manager {
private:
	string id;
	string password;
public:
	Manager(string a, string b) :id(a), password(b) {};
	~Manager() {};
	void Load(string id, string password);
	
	/*�����˻�*/
	void ChangePassword();//���κ��û����Ը�������
	
	/*ѡ��*/
	void OpenCourse();//��ӿγ�����ѡ�Σ�������ѡ��ʱ�䣬ѡ��������Դ�һ����ѡѡ�޿�
	void CourseStat();//���ѡ����Ϣ���γ̺Ͷ�Ӧѡ�������͸�ѡ���ˣ�
	void PrintCourseStat();//ѡ����Ϣ��ӡ�������txt��
	
	/*���ι���*/
	void QueryBooks();//�̲Ŀ���Ϣ(���ƣ�����)
	void UpdateBooks();//���½̲���Ϣ
	void SetClass();//����༶������ѧ��
	void ModifyClass();//�ְ��������ѧ�����İࣩ
	void GetClass();//�ְ����� ���������� ��������
	void SetSchedule();//�ſβ��ƶ��γ̱�
	
	/*�ɼ�����*/
	void InputGrades();//ѧ���ɼ�¼��
	//�ɼ�ת��ʲô��˼
	void PrintGrades();//��ӡ�ɼ�   b	�γ̳ɼ�������ʦ����ѧ���ɼ�֪ͨ����ѧ����ҵ�ɼ��������txt
	void GradesSort();// �ɼ�����
	void GradesDistri();// ��������ͳ�ƣ����ܷ� / ѧλ�γɼ�������
	
	/*ѧ��ά��*/
	void AwardAndPunish();//������Ϣ
	void ChangeSchoolRoll();//�ı�ѧ����ѧ�����ڵصȵ�
	void ChangeOrient(); //רҵ�������
	void PrintStuList();//�����ӡ �����������꼶ѧ������������ѧ��������ѧ�Ŷ���ѧ����������ʡ��/����/����ͳ��ѧ������������ʦѧ��������
	void GraduaStuList();//��ҵ�������Լ���Ӧ�ı�ҵ֤���

	/*�������*/
	void RoomArrange();//���Խ��Ұ���,���ؿ��԰��ű�
	void TestInfo();//ѧ�����ο���ʦ���࿼��ʦ�ȿ�����Ϣ
	void PrintInfo();//��ӡ���԰��ű�������Ϣtxt��
};

#endif // !class_h_
