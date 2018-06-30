//mysql函数定义
#include<iostream>
#include<winsock.h> 
#include<mysql.h>
#include <string>  
#include<cstdlib>
#include<Windows.h>
#include<iomanip>
#include "string.h"
#include<mysql.h>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std; 
extern MYSQL myobj;
extern string comma, plus, quote, space, lb, rb, semi, colon, hyphen;
void UseDB(const char * sqlstr);//使用表1
void InitDB();//初始化数据库1

			  //查询方法的重载				
int Query(const char * sqlstr);//将结果集中的所有表打印输出到屏幕
int Query(const char * sqlstr, char* success, char* failed);//给Query传递信息了		
void process_result_set(MYSQL_RES * result); //对查询结果的打印
void GetStoreData(int status); //正常对返回信息处理

int Query(const char * sqlstr, int token);//需要Query返回判断是否登陆成功
										  //int process_result_set(MYSQL_RES* result, int token); //返回的是对函数查询成功与否进行判断，不打印文字
										  //这个函数3级调用，结果两级调用之间的参数毫无作用，而且适用性狭窄，所以我把它和上一级的函数合并了
int GetStoreData(int status, int token); //返回查询 true or false的	


int Query(const char* sqlstr, fstream *fp); //导出的查询
void process_result_set(MYSQL_RES * result, fstream*fp);//输出文件中
void GetStoreData(int status, fstream *fp);//输出文件						 

vector<vector<string>>  Query1(const char * sqlstr);

//需要返回数据库查询后的向量数据
vector<vector<string>> GetStoreData1(int status);
vector<string> process_result_set1(MYSQL_RES * result);
