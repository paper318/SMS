




#ifndef MANAGER_H_
#define MANAGER_H_
#include<string>
using namespace std;
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

	//					  /*ѡ��*/
	//void OpenCourse();//��ӿγ�����ѡ�Σ�������ѡ��ʱ�䣬ѡ��������Դ�һ����ѡѡ�޿�
	//void CourseStat();//���ѡ����Ϣ���γ̺Ͷ�Ӧѡ�������͸�ѡ���ˣ�
	//void PrintCourseStat();//ѡ����Ϣ��ӡ�������txt��

						   /*���ι���*/
	//void QueryBooks();//�̲Ŀ���Ϣ(���ƣ�����)
	//void UpdateBooks();//���½̲���Ϣ
	//void SetClass();//����༶������ѧ��
	//void ModifyClass();//�ְ��������ѧ�����İࣩ
	//void GetClass();//�ְ����� ���������� ��������
	//void SetSchedule();//�ſβ��ƶ��γ̱�

					   /*�ɼ�����*/
	//void InputGrades();//ѧ���ɼ�¼��
	//				   //�ɼ�ת��ʲô��˼
	//void PrintGrades();//��ӡ�ɼ�   b	�γ̳ɼ�������ʦ����ѧ���ɼ�֪ͨ����ѧ����ҵ�ɼ��������txt
	//void GradesSort();// �ɼ�����
	//void GradesDistri();// ��������ͳ�ƣ����ܷ� / ѧλ�γɼ�������

	//					/*ѧ��ά��*/
	//void AwardAndPunish();//������Ϣ
	//void ChangeSchoolRoll();//�ı�ѧ����ѧ�����ڵصȵ�
	//void ChangeOrient(); //רҵ�������
	//void PrintStuList();//�����ӡ �����������꼶ѧ������������ѧ��������ѧ�Ŷ���ѧ����������ʡ��/����/����ͳ��ѧ������������ʦѧ��������
	//void GraduaStuList();//��ҵ�������Լ���Ӧ�ı�ҵ֤���

	//					 /*�������*/
	//void RoomArrange();//���Խ��Ұ���,���ؿ��԰��ű�
	//void TestInfo();//ѧ�����ο���ʦ���࿼��ʦ�ȿ�����Ϣ
	//void PrintInfo();//��ӡ���԰��ű�������Ϣtxt��
};





#endif // !MANAGER_H_
