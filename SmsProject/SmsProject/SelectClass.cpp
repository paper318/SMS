#include"SelectClass.hpp"
#include<string>
#include"mysql.hpp"
using namespace std;
/*ѧ�� ��ɫ���ֽ��鱣�� �����д��*/

void SelectCourse();//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨 
void DeleteCourse();//ɾ��
void CourseSelected();//��ѡ�γ�

					  /*����Ա*/
void changePasswd(string stu_id,string new_password) {//�޸����� ���ѧ��
	string str = "call changePasswd(";
	string str1 = "student";
	str += quote + stu_id + quote + semi + quote + new_password + quote + semi + quote + str1 + quote + rb;
	Query(str.c_str(),"���ܳɹ�","����ʧ��");
}
void chagePasswd(string id, string new_password,string type) {//�����ʦ�������κ��� typeΪ��������Ա������
	string str = "call changePasswd(";
	str += quote + id + quote + semi + quote + new_password + quote + semi + quote  + quote + rb;
	Query(str.c_str(), "���ܳɹ�", "����ʧ��");

}
void OpenCourse();//��ӿγ�����ѡ�Σ�������ѡ��ʱ�䣬ѡ��������Դ�һ����ѡѡ�޿�
void CourseStat();//���ѡ����Ϣ���γ̺Ͷ�Ӧѡ�������͸�ѡ���ˣ�

				  /*����Ա����ʦ*/
void PrintCourseStat();//ѡ����Ϣ��ӡ�������txt��