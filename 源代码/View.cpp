#include"view.hpp"
using namespace std;
enum token_type { TEA, STU, MAN, LED };
int token;
//û�취�����ȫ�֣�������Ҫ�����ˡ���
Teacher tea_obj =  Teacher(); //�޲ι��캯������ Teacher tea_obj();ʵ����
Student stu_obj = Student();
Manager man_obj  = Manager();
Leader led_obj = Leader();

//��½
void login() {
	cout << "                     ��¼                 " << endl;
	cout << "______________________________________" << endl;
	cout << "|" << "1.��ʦ 2.ѧ�� 3.����Ա 4.�쵼 \t|" << endl;
	cout << "����������������������������������������������������������������������������" << endl;
	string id, pwd;

	while (cin >> token) {
		if (token < 0 || token > 3)
			cout << "������������������:";
		else break;
	}
	while (1) {
		system("cls");
		cout << "���������˺ţ�";
		cin >> id;
		cout << "\n�����������룺 ";
		cin >> pwd;
		switch (token) {
		case TEA: {
			tea_obj = Teacher(id, pwd);
			if (tea_obj.Load() == 2)//�ɹ�
				Menu();
			else
				cout << "�˺Ż������������������";
			break;
		}
		case STU: {
			stu_obj = Student(id, pwd);
			if (stu_obj.Load() == 2)//�ɹ�
				Menu();
			else
				cout << "�˺Ż������������������";
			break;

		}
		case MAN: {
			man_obj = Manager(id, pwd);
			if (man_obj.Load() == 2)//�ɹ�
				Menu();
			else
				cout << "�˺Ż������������������";
			break;

		}
		case LED: {
			led_obj = Leader(id, pwd);
			if (led_obj.Load() == 2)//�ɹ�
				Menu();
			else
				cout << "�˺Ż������������������";
			break;
		}
		default:
			cout << "δ֪����";
			exit(0);
			//��һѭ������ʾ
			cout << "                     ��¼                 " << endl;
			cout << "______________________________________" << endl;
			cout << "|" << "1.��ʦ 2.ѧ�� 3.����Ա 4.�쵼 \t|" << endl;
			cout << "����������������������������������������������������������������������������" << endl;
		}
	}


}

void Menu() {
	system("cls");
	switch (token) {
	case TEA: {
		cout << "                             �˵�                                  " << endl;
		cout << "______________________________________________" << endl;
		cout << "|" << "1.���ι��� 2.ѡ�ι��� 3.���� 4.�˳���¼\t|" << endl;
		cout << "______________________________________________" << endl;
		int opt;
		cout << ":";
		while (cin >> opt) {
			switch (opt) {
			case 1:
				ViewEnroll(); break;
			case 2:
				ViewSe(); break;
			case 3:
				ViewOthers(); break;
			case 4:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 4)	break;//���ص�¼
			cout << "                             �˵�                                  " << endl;
			cout << "______________________________________________" << endl;
			cout << "|" << "1.���ι��� 2.ѡ�ι��� 3.���� 4.�˳���¼\t|" << endl;
			cout << "______________________________________________" << endl;
		}
	}
	case STU: {
		cout << "                             �˵�                                  " << endl;
		cout << "_______________________________________" << endl;
		cout << "|" << "1.ѡ�ι��� 2.�ɼ����� 3.�˳���¼\t|" << endl;
		cout << "________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:ViewSe(); break;
			case 2:ViewGra(); break;
			case 3:	break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 3)	break;//���ص�¼
			cout << "                             �˵�                                  " << endl;
			cout << "______________________________________________" << endl;
			cout << "|" << "1.���ι��� 2.ѡ�ι��� 3.���� 4.�˳���¼\t|" << endl;
			cout << "______________________________________________" << endl;
		}
	}
	case LED: {
		cout << "                             �˵�                                  " << endl;
		cout << "_________________________" << endl;
		cout << "|" << "1.���� 2.�˳���¼\t|" << endl;
		cout << "__________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:ViewOthers(); break;
			case 2:break;
			default:cout << "����ѡ����������������:";
			}
			if (opt == 2)	break;//���ص�¼
			cout << "                             �˵�                                  " << endl;
			cout << "_________________________" << endl;
			cout << "|" << "1.���� 2.�˳���¼\t|" << endl;
			cout << "__________________________" << endl;
		}
	}
	case MAN: {
		cout << "                             �˵�                                  " << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "|" << "1.ѧ������ 2.���ι��� 3.ѡ�ι��� 4.���Թ��� 5.�ɼ����� 6.���� 7.�˳���¼\t|" << endl;
		cout << "_____________________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:ViewEnroll(); break;
			case 2:ViewOpen(); break;
			case 3:ViewSe(); break;
			case 4:ViewExam(); break;
			case 5:ViewGra(); break;
			case 6:ViewOthers(); break;
			case 7:break;
			default:
			cout << "����ѡ����������������:";
			}
			if (opt == 7)	break;//���ص�¼
			cout << "                             �˵�                                  " << endl;
			cout << "_____________________________________________________________________________" << endl;
			cout << "|" << "1.ѧ������ 2.���ι��� 3.ѡ�ι��� 4.���Թ��� 5.�ɼ����� 6.���� 7.�˳���¼\t|" << endl;
			cout << "_____________________________________________________________________________" << endl;
		}
	}
	default:
		cout << "δ֪����";
		exit(0);
	}

}









/***********************************************************************************************/
/*���⿪ʼд*/








void ViewEnroll() {
	cout << "_______________________________________________________________________" << endl;
	cout << "|" << "1.���� 2.ѧ���䶯 3.���ķ��� 4.��ӡѧ���� 5.������һ��  \t|" << endl;
	cout << "_______________________________________________________________________" << endl;
	int opt;
	while (cin >> opt) {
		switch (opt) {
			// case 1:...AwardAndPunish();break;
			// case 2:...ChangeSchoolRoll(); break;
			// case 3:...ChangeOrient(); break;	
			// case 4:...PrintStuList();break;		
			// case 5:break;
		default:
			cout << "����ѡ����������������:";
		}
		if (opt == 5)	break;//���ص�¼
							  /*ѭ������*/
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.���� 2.ѧ���䶯 3.���ķ��� 4.��ӡѧ���� 5.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
	}



}
void ViewOpen() {
	system("cls");
	if (token == TEA) {

		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.���� 2.������ѧ�ƻ� 3.�鿴ѧ����� 4.�鿴����ѡ�� 5.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1: {
				string tea_id, course_id, course_name, start, stop, num, credit;
				cout << "��ʦ��ţ�"; cin >> tea_id;
				cout << "\n�γ̱��:"; cin >> course_id;
				cout << "\n�γ���:"; cin >> course_name;
				cout << "\nѡ�ο�ʼʱ�� [��ʽ��y-m-d h:m:s] :"; cin >> start;
				cout << "\nѡ�ν���ʱ�� [��ʽ��y-m-d h:m:s] :"; cin >> stop;
				cout << "\n��ѡ����: "; cin >> num;
				cout << "\n�γ�ѧ��: "; cin >> credit;
				OpenCourse( tea_id,  course_id,  course_name,  start,  stop,  num,  credit);
				break;
			}
			case 2: {
				string course_id, tea_id, text;
				cout << "�γ̱�ţ�"; cin >> course_id;
				cout << "\n��ʦ���:"; cin >> tea_id;
				cout << "\n��ѧ�ƻ���Ϣ:"; cin >> text;
				CreateProject(course_id, tea_id, text);
				break;
			}
			case 3: {
				string course_id, tea_id;
				cout << "�γ̱�ţ�"; cin >> course_id;
				cout << "\n��ʦ���:"; cin >> tea_id;
				SelectProject(course_id, tea_id);
				break;
			}
			case 4: {
				string tea_id;
				cout << "��ʦ��ţ�"; cin >> tea_id;
				QueryStudent(tea_id); break;
			}
			case 5: {
				string tea_id;
				cout << "��ʦ���:"; cin >> tea_id;
				QueryCourse(tea_id);
				break;
			}
			case 6:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 6)	break;//���ص�¼
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.���� 2.������ѧ�ƻ� 3.�鿴ѧ����� 4.�鿴����ѡ�� 5.������һ��  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == MAN) {
		cout << "_________________________________________________________________" << endl;
		cout << "|" << "1.��ѯ�鼮 2.�����鼮 3.����ľ����Ϣ��ѯ 4.����༶ 5.�½�ѧ��|" << endl;
		cout << "|" << "6.�ְ���� 7.�鿴�༶��Ϣ  8.�ſ�  9.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {


			switch (opt) {
			case 1: {
				string book_id;
				cout << "�鼮���: "; cin >> book_id;
				QueryBooks(book_id);
				break;
			}
			case 2: {
				string book_id, name, num;
				cout << "�鼮���: "; cin >> book_id;
				cout << "�鼮��Ŀ: "; cin >> num;

				UpdateBooks(book_id, name, num);
				break;
			}
			case 3: {
				CourseInfoQuery();
				break;
			}

			case 4: {//cpp�������⣡����
				int num;
				cout << "�뽫ѧ����Ϣ��д��student.txt�� ��д��ʽΪ ���� �꼶 ϵ��� ϵ�� ѧ�� רҵ״̬ ����";

				cout << "����༶����:"; cin >> num;
				SetClass(num);
				break;
			}
			case 5: {
				int id; string name; int cls; int grade; string dep_id; string dep_name; string school_roll; string major_status; string passwd;
				cout << "ѧ�����:"; cin >> id;
				cout << "\n ѧ������:"; cin >> name;
				cout << "\n �༶:"; cin >> cls;
				cout << "\n ϵ���:"; cin >> dep_id;
				cout << "\n ϵ��:"; cin >> dep_name;
				cout << "\n ѧ��:"; cin >> school_roll;
				cout << "\n רҵ״̬:"; cin >> major_status;
				cout << "\n ����:"; cin >> dep_id;
				CreateStu(id, name, cls, grade, dep_id, dep_name, school_roll, major_status, passwd);
				break;
			}
			case 6: {
				string stu_id, cls;
				cout << "ѧ�����:"; cin >> stu_id;
				cout << "\n cls:"; cin >> cls;
				ModifyClass(stu_id, cls);
				break;
			}
			case 7:GetClass(); break;
			case 8: {

				cout << "_______________________________________________________________________" << endl;
				cout << "|" << "1.���ض�ѧ���ſ� 2.ͬһ���ſ� 3.ͬһ�γ��ſ� 5.������һ��  \t|" << endl;
				cout << "_______________________________________________________________________" << endl;
				int opt1;
				while (cin >> opt1) {
					switch (opt1) {
						case 1: {
							string sid1; string cid1; string start1; string stop1; string day1;
							cout << "ѧ�����:"; cin >> sid1;
							cout << "\n �γ̱��:"; cin >> cid1;
							cout << "\n ��ʼʱ��:"; cin >> start1;//���ݸ�ʽ���������⣡����
							cout << "\n ����:"; cin >> stop1;
							cout << "\n ���ڼ�:"; cin >> day1;
							ScheduleSetByStu(sid1, cid1, start1, stop1, day1); break;
						}
						case 2: {
							string dep; string grd; string cls; string cid; string start; string stop; string day;
							cout << "ϵ:"; cin >> dep;
								cout << "\n �꼶:"; cin >> grd;
							cout << "\n �༶:"; cin >> cls;//���ݸ�ʽ���������⣡����
							cout << "\n �γ̱��:"; cin >> cid;
							cout << "\n ��ʼʱ��:"; cin >> start;
							cout << "\n ����:"; cin >> stop;
							cout << "\n ���ڼ�:"; cin >> day;
							ScheduleSetByCls(dep, grd, cls, cid, start, stop, day);
							break;
						}
						case 3: {
							string cid; string start; string stop; string day; 
							//vector< vector< string > > &data(40, vector<string>(20));

							cout << "\n �γ̱��:"; cin >> cid;
							cout << "\n ��ʼʱ��:"; cin >> start;
							cout << "\n ����:"; cin >> stop;
							cout << "\n ���ڼ�:"; cin >> day;
							ScheduleSetByCid(cid, start, stop, day);
							break; 

						}
						case 4:break;
						default:
							cout << "����ѡ����������������:";
					}
					if (opt == 5)	break;//���ص�¼
										  /*ѭ������*/
					cout << "_______________________________________________________________________" << endl;
					cout << "|" << "1.���ض�ѧ���ſ� 2.ͬһ���ſ� 3.ͬһ�γ��ſ� 5.������һ��  \t|" << endl;
					cout << "_______________________________________________________________________" << endl;
				}
			}
					// case 9:break;

			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 9)	break;//���ص�¼

			cout << "_________________________________________________________________" << endl;
			cout << "|" << "1.��ѯ�鼮 2.�����鼮 3.����ľ����Ϣ��ѯ 4.����༶ 5.�½�ѧ��|" << endl;
			cout << "|" << "6.�ְ���� 7.�鿴�༶��Ϣ  8.�ſ�  9.������һ��  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}

}
void ViewSe() {
	system("cls");
	if (token == TEA) {

		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.ѡ����Ϣ��ӡ  2.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:PrintCourseStat(); break;
			case 2:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 2)	break;//���ص�¼
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.ѡ����Ϣ��ӡ  2.������һ��  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == STU) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.ѡ�� 2.�鿴ѡ�� 3.ɾ��ѡ��  4.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1: {
				string cid, sid, tid;
				cout << "\n �γ̱��:"; cin >> cid;
				cout << "\n ѧ�����:"; cin >> sid;
				cout << "\n ��ʦ���:"; cin >> tid;
				SelectCourse(cid, sid, tid);
				break;
			}
			case 2: {
				string sid;
				cout << "\n ѧ�����:"; cin >> sid;
				CourseSelected(sid);
				break;
			}
			case 3: {
				string cid, sid;
				cout << "\n �γ̱��:"; cin >> cid;
				cout << "\n ѧ�����:"; cin >> sid;
				DeleteCourse(cid, sid);
				break;
			}
					// case 4:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 4)	break;//���ص�¼
		}
	}
	else if (token == MAN) {
		cout << "_____________________________________________________" << endl;
		cout << "|" << "1.���ѡ����Ϣ 2.ѡ����Ϣ��ӡ  3.������һ�� \t|" << endl;
		cout << "______________________________________________________" << endl;
		int opt;
		while (cin >> opt) {


			switch (opt) {
			case 1: {
				string course_id;
				cout << "\n �γ̱��:"; cin >> course_id;
				CourseStat(course_id);
				break;
			}
			case 2: {
				PrintCourseStat();
				break;
			}
			case 3:break;
			default:
				cout << "����ѡ����������������:";;
			}
			if (opt == 4)	break;//���ص�¼
		}
	}
}

void ViewExam() {
	system("cls");
	cout << "_______________________________________________________________________" << endl;
	cout << "|" << "1.��ʦ���� 2.������Ϣ 3.���԰��ű� 4.������һ��  \t|" << endl;
	cout << "_______________________________________________________________________" << endl;
	int opt;
	while (cin >> opt) {
		switch (opt) {
			// case 1:	...RoomArrange();break;
			// 	case 2:...TestInfo();
			//	case 3:...PrintInfo()��
			// case 4:...break;
		default:
			cout << "����ѡ����������������:";
		}
		if (opt == 4)	break;//���ص�¼
	}

}


void ViewGra() {
	system("cls");
	if (token == STU) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.��ѯ�ɼ�  2.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:stu_obj.GetGrades(); break;
			case 2:break; 
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 2)	break;//���ص�¼
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.��ѯ�ɼ�  2.������һ��  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == MAN) {



		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.����ɼ� 2.��ӡ�ɼ� 3.���� 4.�ɼ�������ͳ�� 5.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
				// case 1:InputGrades(); break;		
				// case 2:PrintGrades();break;
				// case 3:GradesSort();break;
				// case 4:GradesDistri();     
				// case 5:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 4)	break;//���ص�¼
		}
	}

}
void ViewOthers() {
	system("cls");
	if (token == TEA) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.ѧ����� 2.����ͳ��  3.�鿴��ѧʱ�� 4.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
				// case 1:   StudentCount();break;
				//case 2: TeaCourseStat();break;
				//case 3:void worktime();break;
				// case 4:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 4)	break;//���ص�¼
		}
	}
	else if (token == LED) {


		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1. 2. 3.  4.������һ��  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
				// case 1:getdep_id(); break;		
				// case 2:StudentCount();break;
				// case 3:LeaCourseStat();break;
				// case 4:LeaQueryTea();break;
				// case 5:LeaQueryStu(); break;
				// case 4:break;
			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 4)	break;//���ص�¼
		}
	}
	else if (token == MAN) {
		cout << "_____________________________________________________" << endl;
		cout << "|" << "1.�����û����� 2.������һ��\t|" << endl;
		cout << "______________________________________________________" << endl;
		int opt;
		while (cin >> opt) {


			switch (opt) {
				// case 1:changePasswd();break;

			default:
				cout << "����ѡ����������������:";
			}
			if (opt == 2)	break;//���ص�¼
		}
	}


}