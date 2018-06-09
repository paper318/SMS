//mysql函数定义

#include<iostream>
#include<winsock.h> 
#include<mysql.h>
#include <string>  
#include<cstdlib>
#include<iomanip>
using namespace std;

extern MYSQL myobj;
extern string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";";
void UseDB(const char * sqlstr);//使用表1
void InitDB();//初始化数据库1
void MenuF();//第一个菜单1
void SelectTeacher();//老师数据1
void SelectExpel();//开除数据1
void SelectInMenu();//选择菜单
void SelectGrades();//选择成绩

//查询方法的重载				
int Query(const char * sqlstr);//不带成功信息的Query
int Query(const char * sqlstr, char* success, char* failed);//给Query传递信息了										
int Query(const char * sqlstr, int token);//需要Query返回判断是否登陆成功
void GetStoreData(int status); //正常对返回信息处理
int GetStoreData(int status, int token); //返回查询 true or false的	
void process_result_set(MYSQL_RES * result); //一般的对查询结果的打印
int process_result_set(MYSQL_RES* result, int token); //返回的是对函数查询成功与否进行判断，不打印文字