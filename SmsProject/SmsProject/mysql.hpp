//mysql��������

#include<iostream>
#include<winsock.h> 
#include<mysql.h>
#include <string>  
#include<cstdlib>
#include<iomanip>
using namespace std;

extern MYSQL myobj;
extern string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";";
void UseDB(const char * sqlstr);//ʹ�ñ�1
void InitDB();//��ʼ�����ݿ�1
void MenuF();//��һ���˵�1
void SelectTeacher();//��ʦ����1
void SelectExpel();//��������1
void SelectInMenu();//ѡ��˵�
void SelectGrades();//ѡ��ɼ�

//��ѯ����������				
int Query(const char * sqlstr);//�����ɹ���Ϣ��Query
int Query(const char * sqlstr, char* success, char* failed);//��Query������Ϣ��										
int Query(const char * sqlstr, int token);//��ҪQuery�����ж��Ƿ��½�ɹ�
void GetStoreData(int status); //�����Է�����Ϣ����
int GetStoreData(int status, int token); //���ز�ѯ true or false��	
void process_result_set(MYSQL_RES * result); //һ��ĶԲ�ѯ����Ĵ�ӡ
int process_result_set(MYSQL_RES* result, int token); //���ص��ǶԺ�����ѯ�ɹ��������жϣ�����ӡ����