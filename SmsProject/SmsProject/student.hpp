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
	//void SelectCourse();//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨 
	//void DeleteCourse();//ɾ��
	//void CourseSelected();//��ѡ�γ�
	void GetGrades();//�鿴�ɼ�������ѧ��
	void Getid

};


#endif // !class_h_
