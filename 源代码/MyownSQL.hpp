//mysql��������

#include<iostream>
#include<winsock.h> 
#include<mysql.h>
#include <string>  
#include<cstdlib>
#include<iomanip>
#include "string.h"
#include<iostream>
#include<fstream>
using namespace std;

extern MYSQL myobj;
extern string comma, plus, quote, space, lb, rb, semi, colon, hyphen;
void UseDB(const char * sqlstr);//ʹ�ñ�1
void InitDB();//��ʼ�����ݿ�1

			  //��ѯ����������				
int Query(const char * sqlstr);//��������е����б��ӡ�������Ļ
int Query(const char * sqlstr, char* success, char* failed);//��Query������Ϣ��		
void process_result_set(MYSQL_RES * result); //�Բ�ѯ����Ĵ�ӡ
void GetStoreData(int status); //�����Է�����Ϣ����

int Query(const char * sqlstr, int token);//��ҪQuery�����ж��Ƿ��½�ɹ�
										  //int process_result_set(MYSQL_RES* result, int token); //���ص��ǶԺ�����ѯ�ɹ��������жϣ�����ӡ����
										  //�������3�����ã������������֮��Ĳ����������ã�������������խ�������Ұ�������һ���ĺ����ϲ���
int GetStoreData(int status, int token); //���ز�ѯ true or false��	


int Query(const char* sqlstr, fstream *fp); //�����Ĳ�ѯ
void process_result_set(MYSQL_RES * result, fstream*fp);//����ļ���
void GetStoreData(int status, fstream *fp);//����ļ�						 



int Query(const char * sqlstr, vector<vector<string>> &data);//����ѯ������������������
void GetStoreData(int status, vector<vector <string>> &data);
void process_result_set(MYSQL_RES * result, vector<vector<string>> &data);