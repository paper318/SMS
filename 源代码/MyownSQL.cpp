#include"MyownSQL.hpp"
#include<vector>
#include<iostream>
MYSQL myobj;
extern string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";", colon = ":", hyphen = "-";


//初始化数据库
void InitDB() {
	string sqlstr;
	//初始化lib
	mysql_library_init(0, NULL, NULL);
	//初始化mysql
	mysql_init(&myobj);
	//mysql_query(&myobj,"SET NAMES GBK");报错

	//设置option
	mysql_options(&myobj, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	//if(NULL!= mysql_databse)
	//本地//if (NULL != mysql_real_connect(&myobj, "localhost", "root", "123456", "sms", 3306, NULL, CLIENT_MULTI_STATEMENTS))
	if (NULL != mysql_real_connect(&myobj, "60.205.223.213", "DB199", "DB199", "sms", 3306, NULL, CLIENT_MULTI_STATEMENTS))//第一个是用户名第二个是密码
	{
		cout << "mysql_real_connect() succeed" << endl;
	}
	else {
		cout << "mysql_real_connect() failed" << endl;
		cout << mysql_error(&myobj) << endl; //报告错误原因
		exit(1);
	}
	//mysql_query(&myobj, "set names utf8");
	//使用或创建数据库
	//UseDB("studb");

	//mysql_free_result(result);

}
 
//关闭
void closeDB() {
	mysql_close(&myobj);
	mysql_server_end();
	cout << "Datebase closed success..." << endl;
}


//使用数据库
void UseDB(const char * sqlstr) {

	if (mysql_select_db(&myobj, sqlstr) == 0)
	{
		cout << "use database" << sqlstr << endl;
	}
	else {

		cout << "不存在相关数据库" << endl;
	}
 
}
//执行mysql语句，将结果集中的所有表打印输出到屏幕
int Query(const char * sqlstr) {
	int status = mysql_query(&myobj, sqlstr);
	if (status)//非0失败
	{
		cout << "Query failed:" << endl;
		cout << mysql_error(&myobj) << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status);

	return 0;//成功

}
//执行mysql的语句查询，将结果集中所有的表打印输出到文件
int Query(const char* sqlstr, fstream* fp) {
	int status = mysql_query(&myobj, sqlstr);
	if (status)//非0失败
	{
		cout << "Query failed" << endl;
		cout << mysql_error(&myobj) << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status, fp);

	return 0;//成功
}

//给Query传递信息了
int Query(const char * sqlstr, char* success, char* failed) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)
	{
		cout << failed << endl;
		cout << mysql_error(&myobj) << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << success << endl;
	GetStoreData(status);
	return 0;
}



//这个函数只用于调用四个mysql函数,判断四种用户账号密码是否正确
int Query(const char * sqlstr, int token) {  // 这个token参数唯一作用就是重载
	int tag = 0;
	int status = mysql_query(&myobj, sqlstr);
	if (status)//非0失败
	{
		cout << "Query failed" << endl;
		cout << mysql_error(&myobj) << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	tag = GetStoreData(status, token); //这两个参数这个函数内部毫无作用，唯一作用就是起到重载识别作用了

	return tag;//返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误

}


//执行mysql语句，将结果集中的所有表存储到vector<vector<string>> data 中返回  由于仅返回类型和别的重载不一样，所以需要换个名字  不能直接用vector的引用，不然得初始化，还得是左值，没找到合适的方法，只能使用返回值
vector<vector<string>>  Query1(const char * sqlstr) {
	int status = mysql_query(&myobj, sqlstr);
	//由于失败时无返回信息，所以也不能写成功的提示了，
	return GetStoreData1(status);
}

//正常对返回信息处理
void GetStoreData(int status) {
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			process_result_set(result);
			mysql_free_result(result);
		}
		else {
			if (mysql_field_count(&myobj) == 0) {
				cout << mysql_affected_rows(&myobj) << " rows affected\n";
			}
			else {
				cout << "error:" << mysql_error(&myobj) << endl;
				break;
			}
		}
		if ((status = mysql_next_result(&myobj)) > 0)
			/*		返回值	描述
			0	成功，并有更多的结果
			- 1	成功，没有更多的结果
			> 0	发生错误*/
			cout << "could not execute statement\n";

	} while (status == 0);
}

//返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误
int GetStoreData(int status, int token) {
	int tag = 0;
	string a = "Success";
	string b;  //负责返回数据库查询结果，因为数据库返回是一个char*数组，所以需要转成string
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			MYSQL_ROW row = mysql_fetch_row(result);
			//注意MYSQL_ROW是一个以空字符结尾的字符串数组
			b = row[0];
			if (b == a) tag = 2;//用2表示success
			else tag = -1;//-1表示fail
			mysql_free_result(result);
		}
		else {
			if (mysql_field_count(&myobj) == 0) {
				cout << mysql_affected_rows(&myobj) << " rows affected\n";
			}
			else {
				cout << "error \n";
				break;
			}
		}
		if ((status = mysql_next_result(&myobj)) > 0)
			/*		返回值	描述
			0	成功，并有更多的结果
			- 1	成功，没有更多的结果
			> 0	发生错误*/
			cout << "could not execute statement\n";

	} while (status == 0);
	return tag;
}

//需要返回数据库查询后的向量数据
vector<vector<string>> GetStoreData1(int status) {
	MYSQL_RES *result = NULL;
	vector<vector<string>> data;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			data.push_back((process_result_set1(result)));
			mysql_free_result(result);
		}
		else {
			if (mysql_field_count(&myobj) == 0) {
				cout << mysql_affected_rows(&myobj) << " rows affected\n";
			}
			else {
				cout << "error \n";
				break;
			}
		}
		if ((status = mysql_next_result(&myobj)) > 0)
			/*		返回值	描述
			0	成功，并有更多的结果
			- 1	成功，没有更多的结果
			> 0	发生错误*/
			cout << "could not execute statement\n";

	} while (status == 0);
	return  data;
}

//进行导出文件的
void GetStoreData(int status, fstream* fp) {
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			process_result_set(result, fp);
			mysql_free_result(result);
		}
		else {
			if (mysql_field_count(&myobj) == 0) {
				cout << mysql_affected_rows(&myobj) << " rows affected\n";
			}
			else {
				cout << "error \n";
				break;
			}
		}
		if ((status = mysql_next_result(&myobj)) > 0)
			/*		返回值	描述
			0	成功，并有更多的结果
			- 1	成功，没有更多的结果
			> 0	发生错误*/
			cout << "could not execute statement\n";

	} while (status == 0);

}

//一般的对查询结果的打印
void process_result_set(MYSQL_RES * result) {
	int rowcount = mysql_num_rows(result);
	cout << "row count:" << rowcount << endl;
	//打印字段名称
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);
	for (int i = 0; i < fieldcount; i++) {
		cout << "_______________";
	}
	cout << endl;
	for (unsigned int i = 0; i < fieldcount; i++) {
		field = mysql_fetch_field_direct(result, i);
		cout << setiosflags(ios::left) << setw(14) << field->name;
	}
	cout << endl;
	//打印各行
	for (int i = 0; i < fieldcount; i++) {
		cout << "_______________";

	}
	cout << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//一行一行获取直到没有
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			if (!row[i])cout << setiosflags(ios::left) << setw(14) << "NULL";
			else cout << setiosflags(ios::left) << setw(14) << row[i];
		}
		cout << endl;
		row = mysql_fetch_row(result);
	}
	for (int i = 0; i < fieldcount; i++)
		cout << "_______________";cout << endl;
}

//返回向量的数据处理
vector<string> process_result_set1(MYSQL_RES * result) {
	int rowcount = mysql_num_rows(result);
	vector<string> tem; // 每一个process  process_result_set 处理的是结果集中的一个表
						//所以tem是用来获取当前这个表的数据，然后再存储到data这个结果集中
						//	cout << "row count:" << rowcount << endl;
						//打印字段名称
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);

	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//一行一行获取直到没有
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			if (!row[i])tem.push_back("NULL");
			else tem.push_back(row[i]);
		}
		cout << endl;
		row = mysql_fetch_row(result);
	}
	//push_back(tem);
	return tem;
}

//输出到文件中
void process_result_set(MYSQL_RES * result, fstream*fp) {
	int rowcount = mysql_num_rows(result);
	//	fp << "row count:" << rowcount << endl;
	//打印字段名称
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);
	for (int i = 0; i < fieldcount; i++) {
		*fp << "_______________";
	}
	*fp << endl;
	for (unsigned int i = 0; i < fieldcount; i++) {
		field = mysql_fetch_field_direct(result, i);
		*fp << setiosflags(ios::left) << setw(14) << field->name;
	}
	*fp << endl;
	//打印各行
	for (int i = 0; i < fieldcount; i++) {
		*fp << "_______________";

	}
	*fp << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//一行一行获取直到没有
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			if(!row[i])*fp << setiosflags(ios::left) << setw(14) << "NULL";
			else *fp << setiosflags(ios::left) << setw(14) << row[i];
		}
		*fp << endl;
		row = mysql_fetch_row(result);
	}
}