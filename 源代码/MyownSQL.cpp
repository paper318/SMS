#include"MyownSQL.hpp"
#include<vector>
#include<iostream>
MYSQL myobj;
string comma = ",", plus = "+", quote = "\"", space = " ", lb = "(", rb = ")", semi = ";", colon = ":", hyphen = "-";


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
		cout << mysql_error(&myobj) << endl; //�������ԭ��
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
	cout << "Datebase closed success..." << endl;
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
//ִ��mysql��䣬��������е����б��ӡ�������Ļ
int Query(const char * sqlstr) {
	int status = mysql_query(&myobj, sqlstr);
	if (status)//��0ʧ��
	{
		cout << "Query failed:" << endl;
		cout << mysql_error(&myobj) << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status);

	return 0;//�ɹ�

}
//ִ��mysql������ѯ��������������еı��ӡ������ļ�
int Query(const char* sqlstr, fstream* fp) {
	int status = mysql_query(&myobj, sqlstr);
	if (status)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status, fp);

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


//�������ֻ���ڵ����ĸ�mysql����,�ж������û��˺������Ƿ���ȷ
int Query(const char * sqlstr, int token) {  // ���token����Ψһ���þ�������
	int tag = 0;
	int status = mysql_query(&myobj, sqlstr);

	if (status)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	tag = GetStoreData(status, token); //������������������ڲ��������ã�Ψһ���þ���������ʶ��������

	return tag;//����2����¼�ɹ�������-1���˺�������󣬷���0���������д���

}


//ִ��mysql��䣬��������е����б�洢��vector<vector<string>> data �з���
int Query(const char * sqlstr, vector<vector<string>> &data) {
	int status = mysql_query(&myobj, sqlstr);
	if (status)//��0ʧ��
	{
		cout << "Query failed" << endl;
		mysql_close(&myobj);
		return 1;
	}
	cout << "Query success" << endl;
	GetStoreData(status, data);

	return 0;//�ɹ�
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
				cout << "error:" << mysql_error(&myobj) << endl;
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

//����2����¼�ɹ�������-1���˺�������󣬷���0���������д���
int GetStoreData(int status, int token) {
	int tag = 0;
	string a = "Success";
	string b;  //���𷵻����ݿ��ѯ�������Ϊ���ݿⷵ����һ��char*���飬������Ҫת��string
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {

			MYSQL_ROW row = mysql_fetch_row(result);
			//ע��MYSQL_ROW��һ���Կ��ַ���β���ַ�������
			b = row[0];
			if (b == a) tag = 2;//��2��ʾsuccess
			else tag = -1;//-1��ʾfail


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

//��Ҫ�������ݿ��ѯ�����������
void GetStoreData(int status, vector<vector <string>> &data) {
	MYSQL_RES *result = NULL;
	do {
		result = mysql_store_result(&myobj);
		if (result) {
			process_result_set(result, data);
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

//�������������ݴ���
void process_result_set(MYSQL_RES * result, vector<vector<string>> &data) {
	int rowcount = mysql_num_rows(result);
	vector<string> tem; // ÿһ��process  process_result_set ������ǽ�����е�һ����
						//����tem��������ȡ��ǰ���������ݣ�Ȼ���ٴ洢��data����������
						//	cout << "row count:" << rowcount << endl;
						//��ӡ�ֶ�����
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);

	//for (unsigned int i = 0; i < fieldcount; i++) {
	//	field = mysql_fetch_field_direct(result, i);
	//	//cout << setiosflags(ios::left) << setw(14) << field->name;
	//}
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//һ��һ�л�ȡֱ��û��
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			tem.push_back(row[i]);
		}
		cout << endl;
		row = mysql_fetch_row(result);
	}
	data.push_back(tem);
}

//������ļ���
void process_result_set(MYSQL_RES * result, fstream*fp) {
	int rowcount = mysql_num_rows(result);
	//	fp << "row count:" << rowcount << endl;
	//��ӡ�ֶ�����
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
	//��ӡ����
	for (int i = 0; i < fieldcount; i++) {
		*fp << "_______________";

	}
	*fp << endl;
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);//һ��һ�л�ȡֱ��û��
	while (NULL != row) {
		for (int i = 0; i < fieldcount; i++) {
			*fp << setiosflags(ios::left) << setw(14) << row[i];
		}
		*fp << endl;
		row = mysql_fetch_row(result);
	}
}