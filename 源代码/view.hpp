//������ʾ

#ifndef VIEW_H_
#define VIEW_H_


#endif // !VIEW_H_

//void MenuF() {
//	SelectInMenu();
//}
//
//void SelectInMenu() {
//	int type1_3;
//	system("cls");
//	cout << "_______________________________________________" << endl;
//	cout << "|" << "1.��ѯ�ɼ� 2.��ѯѧ����ʦ 3.��ѯ���� 4.����   |" << endl;
//	cout << "_______________________________________________" << endl;
//	cout << "������Ҫ���еĲ�����" << endl;
//	while (cin >> type1_3) {
//		switch (type1_3) {
//			//����
//		case 1:
//			SelectGrades();
//			break;
//		case 2:
//			SelectTeacher();
//			break;
//		case 3:
//			SelectExpel();
//			break;
//		case 4:
//			system("cls");
//			break;
//		default: cout << "����������������";
//		}
//
//		cout << "_______________________________________________" << endl;
//		cout << "|" << "1.��ѯ�ɼ� 2.��ѯѧ����ʦ 3.��ѯ���� 4.����     |" << endl;
//		cout << "_______________________________________________" << endl;
//		cout << "������Ҫ���еĲ�����" << endl;
//	}
//}
//
//void SelectGrades() {
//	string sql_str, student;
//	char* success = "search student success";
//	char* failed = "search student failed";
//	cout << "����ѧ������:";
//	cin >> student;
//	sql_str = "call getgrades(" + quote;
//	sql_str += student + quote;
//	sql_str += ");";
//	cout << sql_str;
//	Query(sql_str.c_str(), success, failed);
//	sql_str = "call getavg(" + quote;
//	sql_str += student + quote;
//	sql_str += ");";
//	cout << sql_str;
//	Query(sql_str.c_str(), success, failed);
//}
//void SelectTeacher() {
//	string sql_str, student;
//	char* success = "search Teacher success";
//	char* failed = "search Teacher failed";
//	cout << "����ѧ������:";
//	cin >> student;
//	sql_str = "call getteacher(" + quote;
//	sql_str += student + quote;
//	sql_str += ");";
//	cout << sql_str;
//	Query(sql_str.c_str(), success, failed);
//
//}
//void SelectExpel() {
//	string sql_str;
//	char* success = "search expel stu success";
//	char* failed = "search expel stu failed";
//	sql_str = "call getout();";
//	cout << sql_str;
//	Query(sql_str.c_str(), success, failed);
//}



