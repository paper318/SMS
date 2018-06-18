//mysql函数定义

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
extern string comma , plus, quote, space , lb, rb, semi ,colon,hyphen;
void UseDB(const char * sqlstr);//使用表1
void InitDB();//初始化数据库1

//查询方法的重载				
int Query(const char * sqlstr);//不带成功信息的Query
int Query(const char * sqlstr, char* success, char* failed);//给Query传递信息了		
void process_result_set(MYSQL_RES * result); //一般的对查询结果的打印
void GetStoreData(int status); //正常对返回信息处理

int Query(const char * sqlstr, int token);//需要Query返回判断是否登陆成功
int process_result_set(MYSQL_RES* result, int token); //返回的是对函数查询成功与否进行判断，不打印文字
int GetStoreData(int status, int token); //返回查询 true or false的	


int Query(const char* sqlstr, fstream *fp); //导出的查询
void process_result_set(MYSQL_RES * result, fstream*fp);//输出文件中
void GetStoreData(int status, fstream *fp);//输出文件						 



int Query(const char * sqlstr, vector<string> &data);//将查询结果打包成向量。返回
void GetStoreData(int status, vector <string>&data);
void process_result_set(MYSQL_RES * result, vector<string>&data);