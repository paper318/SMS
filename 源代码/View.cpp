#include"view.hpp"
using namespace std;
enum token_type { TEA=1, STU, MAN, LED };
int token;
//没办法如果不全局，函数就要重载了。。
Teacher tea_obj =  Teacher(); //无参构造函数不能 Teacher tea_obj();实例化
Student stu_obj = Student();
Manager man_obj  = Manager();
Leader led_obj = Leader();

//登陆
void login() {
	cout << "                     登录                 " << endl;
	cout << "_______________________________________" << endl;
	cout << "|" << "1.教师 2.学生 3.管理员 4.领导 \t|" << endl;
	cout << "_______________________________________" << endl;
	string id, pwd;

	while (cin >> token) {
		if (token < 0 || token > 4)
			cout << "输入有误，请重新输入:";
		else break;
	}
	while (1) {  
		//system("cls");
		cout << "输入您的账号：";
		cin >> id;
		cout << "\n输入您的密码： ";
		cin >> pwd;
		switch (token) {
		case TEA: {
			tea_obj = Teacher(id, pwd);
			if (tea_obj.Load() == 2)//成功
				Menu();
			else
				cout << "账号或密码错误，请重新输入";
			break;
		}
		case STU: {
			stu_obj = Student(id, pwd);
			if (stu_obj.Load() == 2)//成功
				Menu();
			else
				cout << "账号或密码错误，请重新输入";
			break;

		}
		case MAN: {
			man_obj = Manager(id, pwd);
			if (man_obj.Load() == 2)//成功
				Menu();
			else
				cout << "账号或密码错误，请重新输入";
			break;

		}
		case LED: {
			led_obj = Leader(id, pwd);
			if (led_obj.Load() == 2)//成功
				Menu();
			else
				cout << "账号或密码错误，请重新输入";
			break;
		}
		default:
			cout << "未知错误";
			exit(0);
			//下一循环的显示
			cout << "                     登录                 " << endl;
			cout << "_______________________________________" << endl;
			cout << "|" << "1.教师 2.学生 3.管理员 4.领导 \t|" << endl;
			cout << "_______________________________________" << endl;
		}
	}


}

void Menu() {
	system("cls");
	switch (token) {
	case TEA: {
		cout << "                             菜单                                  " << endl;
		cout << "______________________________________________" << endl;
		cout << "|" << "1.开课管理 2.选课管理 3.其他 4.退出登录\t|" << endl;
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
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 4)	break;//返回登录
			system("cls");
			cout << "                             菜单                                  " << endl;
			cout << "______________________________________________" << endl;
			cout << "|" << "1.开课管理 2.选课管理 3.其他 4.退出登录\t|" << endl;
			cout << "______________________________________________" << endl;
		}
		exit(0);
	}
	case STU: {
		cout << "                             菜单                                  " << endl;
		cout << "_______________________________________" << endl;
		cout << "|" << "1.选课管理 2.成绩管理 3.退出登录\t|" << endl;
		cout << "________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:ViewSe(); break;
			case 2:ViewGra(); break;
			case 3:	break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 3)	break;//返回登录
			cout << "                             菜单                                  " << endl;
			cout << "______________________________________________" << endl;
			cout << "|" << "1.开课管理 2.选课管理 3.其他 4.退出登录\t|" << endl;
			cout << "______________________________________________" << endl;
		}
	}
	case LED: {
		cout << "                             菜单                                  " << endl;
		cout << "_________________________" << endl;
		cout << "|" << "1.其他 2.退出登录\t|" << endl;
		cout << "__________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:ViewOthers(); break;
			case 2:break;
			default:cout << "输入选项有误，请重新输入:";
			}
			if (opt == 2)	break;//返回登录
			cout << "                             菜单                                  " << endl;
			cout << "_________________________" << endl;
			cout << "|" << "1.其他 2.退出登录\t|" << endl;
			cout << "__________________________" << endl;

		}
		exit(0);
	}
	case MAN: {
		cout << "                             菜单                                  " << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "|" << "1.学籍管理 2.开课管理 3.选课管理 4.考试管理 5.成绩管理 6.其他 7.退出登录\t|" << endl;
		cout << "_____________________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			system("cls");
			switch (opt) {
			case 1:ViewEnroll(); break;
			case 2:ViewOpen(); break;
			case 3:ViewSe(); break;
			case 4:ViewExam(); break;
			case 5:ViewGra(); break;
			case 6:ViewOthers(); break;
			case 7:break;
			default:
			cout << "输入选项有误，请重新输入:";
			}
			if (opt == 7)	break;//返回登录
			cout << "                             菜单                                  " << endl;
			cout << "_____________________________________________________________________________" << endl;
			cout << "|" << "1.学籍管理 2.开课管理 3.选课管理 4.考试管理 5.成绩管理 6.其他 7.退出登录\t|" << endl;
			cout << "_____________________________________________________________________________" << endl;
		}
		exit(0);
	}
	default:
		cout << "未知错误";
		exit(0);
	}

}









/***********************************************************************************************/
/*从这开始写*/








void ViewEnroll() {
	cout << "__________________________________________________________________" << endl;
	cout << "|" << "1.奖励登记 2.惩罚登记 3.学籍变动 4.更改院系  5.打印学生表    \t|" << endl;
	cout << "|" << " 6.毕业生登记 7.毕业生打印 8.返回上一级		\t|" << endl;
	cout << "___________________________________________________________________" << endl;
	int opt;
	while (cin >> opt) {
		switch (opt) {
		case 1: {
			string sid, time, event;
			cout << "学生学号："; cin >> sid;
			cout << "\n奖励时间:"; cin >> time;
			cout << "\n事件信息和奖品:"; cin >> event;
			Award(sid ,time ,event);
			break;
		}
		case 2: {
			string sid, time, event;
			cout << "学生学号："; cin >> sid;
			cout << "\n惩罚时间:"; cin >> time;
			cout << "\n事件信息和惩罚:"; cin >> event;
			Punish(sid, time, event);
			break;
		}
		case 3: {
			cout << "_________________________________________________________________" << endl;
			cout << "|" << "1.保留学籍 2.开除学籍 3.休学	4.返回上一级					\t|" << endl;
			cout << "__________________________________________________________________" << endl;
			int opt1;
			while (cin >> opt1) {
				switch (opt1) {
				case 1: {
					string sid;
					cout << "学生学号："; cin >> sid;
					StayinSchool(sid);
					break;
				}
				case 2: {
					string sid;
					cout << "学生学号："; cin >> sid;
					Expel(sid);
					break;
				}
				case 3: {
					string sid;
					cout << "学生学号："; cin >> sid;
					RestatHome(sid);
					break;
				}
				case 4:break;
				default:
					cout << "输入选项有误，请重新输入:";
				}
				if (opt == 4)	break;//返回登录
									  /*循环输入*/
				cout << "_________________________________________________________________" << endl;
				cout << "|" << "1.保留学籍 2.开除学籍 3.休学	4.返回上一级					\t|" << endl;
				cout << "__________________________________________________________________" << endl;
			}
		}
		case 4: {
			string sid, dep_id, dep_name;
			cout << "学生学号："; cin >> sid;
			cout << "\n新的系编号:"; cin >> dep_id;
			cout << "\n新的系名称:"; cin >> dep_name;
			ChangeOrient(sid, dep_id, dep_name);
			break;
		}
		case 5: {
			PrintStuList();
			break;
		}
		case 6: {
			string id, name;
			cout << "毕业证编号："; cin >> id;
			cout << "\n毕业证姓名:"; cin >> name;
			GraduaStuList(id,name);
			break;
		}
		case 7:{
			GraduaStuListQ();
			break;
		}
		case 8: break;
		default:
			cout << "输入选项有误，请重新输入:";
		}
		if (opt == 8)	break;//返回登录
							  /*循环输入*/
		cout << "__________________________________________________________________" << endl;
		cout << "|" << "1.奖励登记 2.惩罚登记 3.学籍变动 4.更改院系  5.打印学生表    \t|" << endl;
		cout << "|" << " 6.毕业生登记 7.毕业生打印 8.返回上一级		\t|" << endl;
		cout << "___________________________________________________________________" << endl;
	}



}
void ViewOpen() {
	system("cls");
	if (token == TEA) {

		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.开课 2.创建教学计划 3.查看学生情况 4.查看带课选课 5.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1: {
				string tea_id, course_id, course_name, start, stop, num, credit;
				cout << "教师编号："; cin >> tea_id;
				cout << "\n课程编号:"; cin >> course_id;
				cout << "\n课程名:"; cin >> course_name;
				cout << "\n选课开始时间 [格式：y-m-d h:m:s] :"; cin >> start;
				cout << "\n选课结束时间 [格式：y-m-d h:m:s] :"; cin >> stop;
				cout << "\n限选人数: "; cin >> num;
				cout << "\n课程学分: "; cin >> credit;
				OpenCourse( tea_id,  course_id,  course_name,  start,  stop,  num,  credit);
				break;
			}
			case 2: {
				string course_id, tea_id, text;
				cout << "课程编号："; cin >> course_id;
				cout << "\n教师编号:"; cin >> tea_id;
				cout << "\n教学计划信息:"; cin >> text;
				CreateProject(course_id, tea_id, text);
				break;
			}
			case 3: {
				string course_id, tea_id;
				cout << "课程编号："; cin >> course_id;
				cout << "\n教师编号:"; cin >> tea_id;
				SelectProject(course_id, tea_id);
				break;
			}
			case 4: {
				string tea_id;
				cout << "教师编号："; cin >> tea_id;
				QueryStudent(tea_id); break;
			}
			case 5: {
				string tea_id;
				cout << "教师编号:"; cin >> tea_id;
				QueryCourse(tea_id);
				break;
			}
			case 6:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 6)	break;//返回登录
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.开课 2.创建教学计划 3.查看学生情况 4.查看带课选课 5.返回上一级  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == MAN) {
		cout << "_________________________________________________________________" << endl;
		cout << "|" << "1.查询书籍 2.更新书籍 3.开课木库信息查询 4.分配班级 5.新建学生|" << endl;
		cout << "|" << "6.分班调整 7.查看班级信息  8.排课  9.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {


			switch (opt) {
			case 1: {
				string book_id;
				cout << "书籍编号: "; cin >> book_id;
				QueryBooks(book_id);
				break;
			}
			case 2: {
				string book_id, name, num;
				cout << "书籍编号: "; cin >> book_id;
				cout << "书籍数目: "; cin >> num;

				UpdateBooks(book_id, name, num);
				break;
			}
			case 3: {
				CourseInfoQuery();
				break;
			}

			case 4: {//cpp这有问题！！！
				int num;
				cout << "请将学生信息填写在student.txt中 填写格式为 姓名 年级 系编号 系名 学籍 专业状态 密码";

				cout << "分配班级个数:"; cin >> num;
				SetClass(num);
				break;
			}
			case 5: {
				int id; string name; int cls; int grade; string dep_id; string dep_name; string school_roll; string major_status; string passwd;
				cout << "学生编号:"; cin >> id;
				cout << "\n 学生姓名:"; cin >> name;
				cout << "\n 班级:"; cin >> cls;
				cout << "\n年级";cin >> grade;
				cout << "\n 系编号:"; cin >> dep_id;
				cout << "\n 系名:"; cin >> dep_name;
				cout << "\n 学籍:"; cin >> school_roll;
				cout << "\n 专业状态:"; cin >> major_status;
				cout << "\n 密码:"; cin >> dep_id;
				CreateStu(id, name, cls, grade, dep_id, dep_name, school_roll, major_status, passwd);
				break;
			}
			case 6: {
				string stu_id, cls;
				cout << "学生编号:"; cin >> stu_id;
				cout << "\n cls:"; cin >> cls;
				ModifyClass(stu_id, cls);
				break;
			}
			case 7:GetClass(); break;
			case 8: {

				cout << "_______________________________________________________________________" << endl;
				cout << "|" << "1.对特定学生排课 2.同一班排课 3.同一课程排课 5.返回上一级  \t|" << endl;
				cout << "_______________________________________________________________________" << endl;
				int opt1;
				while (cin >> opt1) {
					switch (opt1) {
						case 1: {
							string sid1; string cid1; string start1; string stop1; string day1;
							cout << "学生编号:"; cin >> sid1;
							cout << "\n 课程编号:"; cin >> cid1;
							cout << "\n 开始时间:"; cin >> start1;//数据格式可能有问题！！！
							cout << "\n 结束:"; cin >> stop1;
							cout << "\n 星期几:"; cin >> day1;
							ScheduleSetByStu(sid1, cid1, start1, stop1, day1); break;
						}
						case 2: {
							string dep; string grd; string cls; string cid; string start; string stop; string day;
							cout << "系:"; cin >> dep;
								cout << "\n 年级:"; cin >> grd;
							cout << "\n 班级:"; cin >> cls;//数据格式可能有问题！！！
							cout << "\n 课程编号:"; cin >> cid;
							cout << "\n 开始时间:"; cin >> start;
							cout << "\n 结束:"; cin >> stop;
							cout << "\n 星期几:"; cin >> day;
							ScheduleSetByCls(dep, grd, cls, cid, start, stop, day);
							break;
						}
						case 3: {
							string cid; string start; string stop; string day; 
							//vector< vector< string > > &data(40, vector<string>(20));

							cout << "\n 课程编号:"; cin >> cid;
							cout << "\n 开始时间:"; cin >> start;
							cout << "\n 结束:"; cin >> stop;
							cout << "\n 星期几:"; cin >> day;
							ScheduleSetByCid(cid, start, stop, day);
							break; 

						}
						case 4:break;
						default:
							cout << "输入选项有误，请重新输入:";
					}
					if (opt == 5)	break;//返回登录
										  /*循环输入*/
					cout << "_______________________________________________________________________" << endl;
					cout << "|" << "1.对特定学生排课 2.同一班排课 3.同一课程排课 5.返回上一级  \t|" << endl;
					cout << "_______________________________________________________________________" << endl;
				}
			}
					// case 9:break;

			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 9)	break;//返回登录

			cout << "_________________________________________________________________" << endl;
			cout << "|" << "1.查询书籍 2.更新书籍 3.开课木库信息查询 4.分配班级 5.新建学生|" << endl;
			cout << "|" << "6.分班调整 7.查看班级信息  8.排课  9.返回上一级  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}

}
void ViewSe() {
	system("cls");
	if (token == TEA) {

		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.选课信息打印  2.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:PrintCourseStat(); break;
			case 2:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 2)	break;//返回登录
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.选课信息打印  2.返回上一级  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == STU) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.选课 2.查看选课 3.删除选课  4.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1: {
				string cid, sid, tid;
				cout << "\n 课程编号:"; cin >> cid;
				cout << "\n 学生编号:"; cin >> sid;
				cout << "\n 教师编号:"; cin >> tid;
				SelectCourse(cid, sid, tid);
				break;
			}
			case 2: {
				string sid;
				cout << "\n 学生编号:"; cin >> sid;
				CourseSelected(sid);
				break;
			}
			case 3: {
				string cid, sid;
				cout << "\n 课程编号:"; cin >> cid;
				cout << "\n 学生编号:"; cin >> sid;
				DeleteCourse(cid, sid);
				break;
			}
					// case 4:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 4)	break;//返回登录
		}
	}
	else if (token == MAN) {
		cout << "_____________________________________________________" << endl;
		cout << "|" << "1.获得选课信息 2.选课信息打印  3.返回上一级 \t|" << endl;
		cout << "______________________________________________________" << endl;
		int opt;
		while (cin >> opt) {


			switch (opt) {
			case 1: {
				string course_id;
				cout << "\n 课程编号:"; cin >> course_id;
				CourseStat(course_id);
				break;
			}
			case 2: {
				PrintCourseStat();
				break;
			}
			case 3:break;
			default:
				cout << "输入选项有误，请重新输入:";;
			}
			if (opt == 4)	break;//返回登录
		}
	}
}

void ViewExam() {
	system("cls");
	cout << "_______________________________________________________________________" << endl;
	cout << "|" << "1.sql插入考场安排表 2.打印考试信息 3.返回上一级  \t|" << endl;
	cout << "_______________________________________________________________________" << endl;
	int opt;
	while (cin >> opt) {
		switch (opt) {
		case 1: 
			testArrange();//管理员用sql命令插入考试安排表
			break;
		case 2:
			PrintInfo();//打印考试安排
			break;
		case 3:break;
		default:
			cout << "输入选项有误，请重新输入:";
		}
		if (opt == 3)	break;//返回登录
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.sql插入考场安排表 2.打印考试信息 3.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
	}

}


void ViewGra() {
	system("cls");
	if (token == STU) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.查询成绩  2.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
			case 1:stu_obj.GetGrades(); break;
			case 2:break; 
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 2)	break;//返回登录
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.查询成绩  2.返回上一级  \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == MAN) {


		cout << "_______________________________________________________________________" << endl;
		cout << "|   1.录入成绩    2.打印老师课程成绩    3.给打印学生课程成绩          |" << endl;
		cout << "|   4.打印总分排名成绩       5.打印课程成绩分数段人数			       |" << endl;
		cout << "|   6.返回上一级											           |" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			system("cls");
			switch (opt) {
				 case 1:InputGrades(); break;		
				 case 2:TeaPrintGrades();break;
				 case 3:StuPrintGrades();break;
				 case 4:DepGradesSort();break;
				 case 5:GradesDistri();break;
				 case 6:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 6)	break;//返回登录

			cout << "_______________________________________________________________________" << endl;
			cout << "|   1.录入成绩    2.打印老师课程成绩    3.给打印学生课程成绩          |" << endl;
			cout << "|   4.打印总分排名成绩       5.打印课程成绩分数段人数			       |" << endl;
			cout << "|   6.返回上一级											           |" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}

}
void ViewOthers() {
	system("cls");
	if (token == TEA) {
		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.学生情况 2.开课统计  3.查看教学时间 4.返回上一级  \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			switch (opt) {
				case 1:   tea_obj.TeaQueryStu();break;
				case 2: tea_obj.TeaCourseStat();break;
				case 3:tea_obj.worktime();break;
				case 4:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 4)	break;//返回登录
		}
	}
	else if (token == LED) {


		cout << "_______________________________________________________________________" << endl;
		cout << "|" << "1.查询本院学生总数   2.查询本院开课统计 3.按课程名查询老师   \t|" << endl;
		cout << "|" << "4.查询某个学生的信息   5.返回上一级                          \t|" << endl;
		cout << "_______________________________________________________________________" << endl;
		int opt;
		while (cin >> opt) {
			system("cls");
			switch (opt) {
				case 1:led_obj.StudentCount(); break;		
				case 2:led_obj.LeaCourseStat();break;
				case 3:led_obj.LeaQueryTea();break;
				case 4:led_obj.LeaQueryStu(); break;
				case 5:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 5)	break;//返回登录
			cout << "_______________________________________________________________________" << endl;
			cout << "|" << "1.查询本院学生总数   2.查询本院开课统计 3.按课程名查询老师   \t|" << endl;
			cout << "|" << "4.查询某个学生的信息   5.返回上一级                          \t|" << endl;
			cout << "_______________________________________________________________________" << endl;
		}
	}
	else if (token == MAN) {
		cout << "_____________________________________________________" << endl;
		cout << "|" << "1.更改用户密码 2.返回上一级\t|" << endl;
		cout << "______________________________________________________" << endl;
		int opt;
		while (cin >> opt) {

			system("cls");
			switch (opt) {
				case 1:man_obj.ChangeOnePassword();break;
				case 2:break;
			default:
				cout << "输入选项有误，请重新输入:";
			}
			if (opt == 2)	break;//返回登录
			cout << "_____________________________________________________" << endl;
			cout << "|" << "1.更改用户密码 2.返回上一级\t|" << endl;
			cout << "______________________________________________________" << endl;
		}
	}


}
