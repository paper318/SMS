



#ifndef LEADER_H_
#define LEADER_H_

#include<string>
using namespace std;

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










#endif // !MANAGER_H_
