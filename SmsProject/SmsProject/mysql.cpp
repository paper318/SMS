#include"mysql.hpp"

MYSQL myobj;
string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";",colon= ":",hyphen="-";


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
	if (NULL != mysql_real_connect(&myobj, "localhost", "root", "zhanxinrui", "test", 3306, NULL, CLIENT_MULTI_STATEMENTS))
		//这里的地址，用户名，密码，端口可以根据自己本地的情况更改  
	{
		cout << "mysql_real_connect() succeed" << endl;
	}
	else {
		cout << "mysql_real_connect() failed" << endl;
		exit(1);
	}
	//mysql_query(&myobj, "set names utf8");
	//使用或创建数据库
	UseDB("studb");

	//mysql_free_result(result);

}

//关闭
void closeDB() {
	mysql_close(&myobj);
	mysql_server_end();
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
//不带成功信息的Query
int Query(const char * sqlstr) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)//非0失败
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status);

	return 0;//成功

}
//导出的查询
int Query(const char* sqlstr,fstream* fp) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)//非0失败
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status,fp);

	return 0;//成功
}

//给Query传递信息了
int Query(const char * sqlstr, char* success, char* failed) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)
	{
		cout << failed << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << success << endl;
	GetStoreData(status);
	return 0;
}

//需要Query返回判断是否登陆成功，
int Query(const char * sqlstr,int token) {
	int tag = 0;
	int status = mysql_query(&myobj, sqlstr);

	if (status>0)//非0失败
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status,token);

	return tag;//0表示query成功 2表示查询func结果return success -1 表示func返回无效

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

//返回查询 true or false的
int GetStoreData(int status,int token) {
	int tag = 0;//当前层的标志
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			tag = process_result_set(result,token);
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



//返回的是对函数查询成功与否进行判断，不打印文字
int process_result_set(MYSQL_RES* result,int token) {
	string a = "success";
	if (token = 1) {
		MYSQL_ROW row = mysql_fetch_row(result);
		if (row[0] == a) {
			return 2;//用2表示success
		}
		else
			return -1;//-1表示fail
	}
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
			cout << setiosflags(ios::left) << setw(14) << row[i];
		}
		cout << endl;
		row = mysql_fetch_row(result);
	}
}


//输出到文件中
void process_result_set(MYSQL_RES * result, fstream fp) {
	int rowcount = mysql_num_rows(result);
	//	fp << "row count:" << rowcount << endl;
	//打印字段名称
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);
	for (int i = 0; i < fieldcount; i++) {
		fp << "_______________";
	}
	fp << endl;
	for (unsigned int i = 0; i < fieldcount; i++) {
		field = mysql_fetch_field_direct(result, i);
		fp << setiosflags(ios::left) << setw(14) << field->name;
	}
	fp << endl;
	//打印各行
	for (int i = 0; i < fieldcount; i++) {
		fp << "_______________";

	}
	fp << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//一行一行获取直到没有
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			fp << setiosflags(ios::left) << setw(14) << row[i];
		}
		fp << endl;
		row = mysql_fetch_row(result);
	}
}