//ѡ�ι���
#ifndef SELECT_H_
#define SELECT_H_
 /*ѧ��*/
void DeleteCourse(string course_id, string stu_id);//ɾ�� 
void CourseSelected(string stu_id);//��ѡ�γ�
void SelectCourse(string course_id, string stu_id,string tea_id);//ѡ��  ps:ʱ��,ѡ������������ѡѡ�޿� �����Ƹ��ݹ���Ա�涨  ��һ����ѡ
void changePasswd(string stu_id, string new_password);//�޸����� ���ѧ��
void chagePasswd(string id, string new_password, string type);//�����ʦ�������κ��� typeΪ��������Ա������
void CourseStat(string course_id);//���ѡ����Ϣ���γ̺Ͷ�Ӧѡ�������͸�ѡ���ˣ�

 /*����Ա����ʦ*/
void PrintCourseStat();//ѡ����Ϣ��ӡ�������txt��


#endif