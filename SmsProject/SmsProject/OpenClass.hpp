#ifndef OPEN_H_
#define OPEN_H_

#include <string>

 /*��ʦ*/
void OpenCourse(string course_id, string course_name, string start, string stop, string tea_id, string num, string credit);
//��ӿγ�����ѡ�Σ�������ѡ��ʱ�䣬ѡ��������Դ�һ����ѡѡ�޿�
void CreateProject(string course_id, string tea_id, string text);// ��ѧ�ƻ���Ϣ��ѯ����ͷ���������
void SelectProject(string course_id, string tea_id)
//�鿴��ѧ��Ϣ
void QueryStudent(string tea_id);
//��ѯ����ѧ�������Բ�ѯ��ѧ�����ſγɼ�
void QueryCourse(string tea_id);
//��ѯ�Լ����Ŀγ̣����γ�ѡ�����

/*����Ա*/
void QueryBooks(string book_id);
//�̲Ŀ���Ϣ(���ƣ�����)
void UpdateBooks(string book_id, string name, string num);
//���½̲���Ϣ
void CourseInfoQuery();
//����Ŀ¼��Ϣ��ѯ
void SetClass(int num);
//����༶������ѧ�� Ӧ�����ʼ��ɣ�ͨ�����ļ��ж�ȡ���е���Ϣ��Ȼ��������ÿ������ˣ����з���
void CreateStu(int id, string name, int cls, int grade, string department, string passwd);
//�½�һ��ѧ��
void ModifyClass(string stu_id, string cls);
//�ְ��������ѧ�����İࣩ
void GetClass(); //�ְ����� �������� ��������




extern int stu_count;//ѧ����ͳ�ƣ�����ѧ�ŵı�д



#endif 