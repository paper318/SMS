#ifndef class_h_
#define class_h_

#include<string>
#include"mysql.hpp"
using namespace std;

extern int open_time;//ѡ�ο���ʱ��
extern int close_time;//����ʱ��

class Student {
private:
	string id;
	string password;
public:
	Student(string i, string p) :id(i), password(p){};
	~Student() {};
	int Load();//��½
	//void SelectCourse();//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨 
	//void DeleteCourse();//ɾ��
	//void CourseSelected();//��ѡ�γ�
	void GetGrades();//�鿴�ɼ�������ѧ��



};


#endif // !class_h_
