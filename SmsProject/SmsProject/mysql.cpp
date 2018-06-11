#include"mysql.hpp"

MYSQL myobj;
string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";",colon= ":",hyphen="-";


//��ʼ�����ݿ�
void InitDB() {
	string sqlstr;
	//��ʼ��lib
	mysql_library_init(0, NULL, NULL);
	//��ʼ��mysql
	mysql_init(&myobj);
	//mysql_query(&myobj,"SET NAMES GBK");����

	//����option
	mysql_options(&myobj, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	//if(NULL!= mysql_databse)
	if (NULL != mysql_real_connect(&myobj, "localhost", "root", "zhanxinrui", "test", 3306, NULL, CLIENT_MULTI_STATEMENTS))
		//����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������  
	{
		cout << "mysql_real_connect() succeed" << endl;
	}
	else {
		cout << "mysql_real_connect() failed" << endl;
		exit(1);
	}
	//mysql_query(&myobj, "set names utf8");
	//ʹ�û򴴽����ݿ�
	UseDB("studb");

	//mysql_free_result(result);

}

//�ر�
void closeDB() {
	mysql_close(&myobj);
	mysql_server_end();
}
//ʹ�����ݿ�
void UseDB(const char * sqlstr) {

	if (mysql_select_db(&myobj, sqlstr) == 0)
	{
		cout << "use database" << sqlstr << endl;
	}
	else {
		cout << "������������ݿ�" << endl;
	}

}
//�����ɹ���Ϣ��Query
int Query(const char * sqlstr) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status);

	return 0;//�ɹ�

}
//�����Ĳ�ѯ
int Query(const char* sqlstr,fstream* fp) {
	int status = mysql_query(&myobj, sqlstr);
	if (status>0)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status,fp);

	return 0;//�ɹ�
}

//��Query������Ϣ��
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

//��ҪQuery�����ж��Ƿ��½�ɹ���
int Query(const char * sqlstr,int token) {
	int tag = 0;
	int status = mysql_query(&myobj, sqlstr);

	if (status>0)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status,token);

	return tag;//0��ʾquery�ɹ� 2��ʾ��ѯfunc���return success -1 ��ʾfunc������Ч

}

//�����Է�����Ϣ����
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
			/*		����ֵ	����
			0	�ɹ������и���Ľ��
			- 1	�ɹ���û�и���Ľ��
			> 0	��������*/
			cout << "could not execute statement\n";

	} while (status == 0);
}

//���ز�ѯ true or false��
int GetStoreData(int status,int token) {
	int tag = 0;//��ǰ��ı�־
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
			/*		����ֵ	����
			0	�ɹ������и���Ľ��
			- 1	�ɹ���û�и���Ľ��
			> 0	��������*/
			cout << "could not execute statement\n";

	} while (status == 0);
	return tag;

}

//���е����ļ���
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
			/*		����ֵ	����
			0	�ɹ������и���Ľ��
			- 1	�ɹ���û�и���Ľ��
			> 0	��������*/
			cout << "could not execute statement\n";

	} while (status == 0);

}



//���ص��ǶԺ�����ѯ�ɹ��������жϣ�����ӡ����
int process_result_set(MYSQL_RES* result,int token) {
	string a = "success";
	if (token = 1) {
		MYSQL_ROW row = mysql_fetch_row(result);
		if (row[0] == a) {
			return 2;//��2��ʾsuccess
		}
		else
			return -1;//-1��ʾfail
	}
}


//һ��ĶԲ�ѯ����Ĵ�ӡ
void process_result_set(MYSQL_RES * result) {
	int rowcount = mysql_num_rows(result);
	cout << "row count:" << rowcount << endl;
	//��ӡ�ֶ�����
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
	//��ӡ����
	for (int i = 0; i < fieldcount; i++) {
		cout << "_______________";

	}
	cout << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//һ��һ�л�ȡֱ��û��
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			cout << setiosflags(ios::left) << setw(14) << row[i];
		}
		cout << endl;
		row = mysql_fetch_row(result);
	}
}


//������ļ���
void process_result_set(MYSQL_RES * result, fstream fp) {
	int rowcount = mysql_num_rows(result);
	//	fp << "row count:" << rowcount << endl;
	//��ӡ�ֶ�����
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
	//��ӡ����
	for (int i = 0; i < fieldcount; i++) {
		fp << "_______________";

	}
	fp << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//һ��һ�л�ȡֱ��û��
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			fp << setiosflags(ios::left) << setw(14) << row[i];
		}
		fp << endl;
		row = mysql_fetch_row(result);
	}
}