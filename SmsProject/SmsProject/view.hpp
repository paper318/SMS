//界面显示

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
//	cout << "|" << "1.查询成绩 2.查询学生老师 3.查询开除 4.清屏   |" << endl;
//	cout << "_______________________________________________" << endl;
//	cout << "输入您要进行的操作：" << endl;
//	while (cin >> type1_3) {
//		switch (type1_3) {
//			//航班
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
//		default: cout << "输入有误，重新输入";
//		}
//
//		cout << "_______________________________________________" << endl;
//		cout << "|" << "1.查询成绩 2.查询学生老师 3.查询开除 4.清屏     |" << endl;
//		cout << "_______________________________________________" << endl;
//		cout << "输入您要进行的操作：" << endl;
//	}
//}
//
//void SelectGrades() {
//	string sql_str, student;
//	char* success = "search student success";
//	char* failed = "search student failed";
//	cout << "输入学生姓名:";
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
//	cout << "输入学生姓名:";
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



