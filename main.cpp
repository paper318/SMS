#define  _CRT_SECURE_NO_WARNINGS  

#include<iostream>  
using namespace std;
#include<string.h>  
#include<fstream>  

class student
{
private:
	student* next;
public:
	char stu_num[15];                  //学号  
	char stu_name[30];                //姓名  
	float stu_score;                      //成绩  

	void afterInsert(student *p);//在该节点后插入一个节点  
	void afterDelete();//在该节点后删除一个节点  

	student *getNext()//获得下一个节点的指针  
	{
		return next;
	}

	/***********查询学生信息************/
	void getMage();

	/******学生信息修改******/
	void changeMage(int n, char *ptr);
	void changegrade(float p);

	/******构造*****/
	student(char *num, char *name, float score);
	student();
};

void student::changegrade(float p)
{
	stu_score = p;
}

student::student()           //构造  
{
	strcpy(stu_num, "\0");
	strcpy(stu_name, "\0");
	stu_score = 0;
	next = '\0';
}

student::student(char *num, char *name, float score)
{
	strcpy(stu_num, num);
	strcpy(stu_name, name);
	stu_score = score;
	next = '\0';
}

void student::afterInsert(student *p)//插入节点  
{
	p->next = next;
	next = p;
}

void student::afterDelete()        //删除节点  
{
	student *p = next;
	next = p->next;
	delete p;
}

void student::getMage()             //获得信息  
{
	cout << "学号：" << stu_num << "      姓名：" << stu_name;
	cout << "      c++成绩：" << stu_score << endl;
}

void student::changeMage(int n, char *ptr)
{
	switch (n)
	{
	case 1: strcpy(stu_num, ptr);
		break;
	case 2: strcpy(stu_name, ptr);
	}
}

//建立链表函数  
void  construct_list(student *tail)
{
	student *p = new student;
	char very[20];
	float achieve;
	cout << "请输入学号:" << endl;
	cin >> very;
	p->changeMage(1, very);
	cout << "请输入姓名：" << endl;
	cin >> very;
	p->changeMage(2, very);
	cout << "请输入c++成绩：" << endl;
	cin >> achieve;
	p->changegrade(achieve);
	system("cls");
	cout << "信息输入完毕" << endl;

	for (; tail->getNext() != '\0';)
	{
		tail = tail->getNext();
	}

	tail->afterInsert(p);
}

/*********查询信息*********/
student *findmege(student *head)
{
loop:
	cout << "1--按姓名查询           2--按学号查询              q--返回上一级菜单" << endl;
	char p[5], ptr[20];
	student *mid = head;
	cin >> p;

	if (p[0] != '1'&&p[0] != '2'&&p[0] != 'q' || strlen(p)>1)
	{
		system("cls");
		cout << "对不起，你的输入有误，请重新输入！" << endl;
		goto loop;
	}

	switch (p[0])
	{
	case '1':
	{
		system("cls");
		cout << "请输入要查找的姓名：" << endl;
		cin >> ptr;

		for (; strcmp(ptr, mid->stu_name) != 0; mid = mid->getNext())
		{
			if (mid->getNext() == '\0')
			{
				cout << "对不起，你要查找的人不存在，请确认你的输入是否正确！" << endl;
				goto loop;
			}
		}
		return mid;
	}
	case '2':
	{
		system("cls");
		cout << "请输入您要查找的学号：" << endl;
		cin >> ptr;
		for (; strcmp(ptr, mid->stu_num) != 0; mid = mid->getNext())
		{
			if (mid->getNext() == '\0')
			{
				cout << "对不起，您要查找的内容不存在，请确认您的输入是否正确！" << endl;
				goto loop;
			}
		}
		return mid;
	}
	case 'q':
	{
		return '\0';
	}
	default:
	{
		system("cls");
		cout << "对不起，您的输入有误，请重新输入！" << endl;
		goto loop;
	}
	}
}

/******************删除链表 节点***********************/
void delete_list(student *head)
{
	student *p = '\0';
	char selet[4];
	system("cls");
	cout << "在删除前，系统会根据您的提示找到您要删除的学生信息！" << endl;
	p = findmege(head);
	if (p != '\0')
	{
		cout << "确认要删除吗（yes/任意键返回）" << endl;
		cin >> selet;

		if (strcmp(selet, "yes") == 0)
		{
			for (; head->getNext() != p; head = head->getNext());
			head->afterDelete();
			system("cls");
			cout << "该信息删除成功！" << endl;
		}
	}
}

/*******************修改节点信息********************/
void change_info(student *head)
{
	system("cls");
	cout << "在您修改前，系统会根据您提供的信息找的您要修改的信息：" << endl;
	student *p = '\0';

	float achieve;
	p = findmege(head);
	if (p != '\0')
	{
		cout << "请输入c++成绩:" << endl;
		cin >> achieve;
		p->changegrade(achieve);
		system("cls");
		cout << "修改成功!" << endl;
	}

}

/**************输出学生成绩信息**************/
void output(student *head)
{
	system("cls");
	cout << "1-查看指定学生信息；2-查看所有学生信息；3-分段输出学生信息" << endl;
	char ch;
	int n = 0;
	head = head->getNext();
	cin >> ch;
	switch (ch)
	{
	case '1':
		head = findmege(head);
		if (head == '\0')
		{
			break;
		}
		head->getMage();
		break;
	case '2':
		while (head)
		{
			head->getMage();
			head = head->getNext();
		}
		break;
	case '3':
		cout << "a-60分以下；b-60~70分之间；c-70~80分之间；d-80~90分之间；e-90~100分之间：" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'a':
			while (head)
			{
				if (head->stu_score <= 60)
				{
					head->getMage();
					n++;
				}
				head = head->getNext();
			}
			break;
		case 'b':
			while (head)
			{
				if (head->stu_score>60 && head->stu_score <= 70)
				{
					head->getMage();
					n++;
				}
				head = head->getNext();
			}
			break;
		case 'c':
			while (head)
			{
				if (head->stu_score>70 && head->stu_score <= 80)
				{
					head->getMage();
					n++;
				}
				head = head->getNext();
			}
			break;
		case 'd':
			while (head)
			{
				if (head->stu_score>80 && head->stu_score <= 90)
				{
					head->getMage();
					n++;
				}
				head = head->getNext();
			}
			break;
		case 'e':
			while (head)
			{
				if (head->stu_score>90 && head->stu_score <= 100)
				{
					head->getMage();
					n++;
				}
				head = head->getNext();
			}
		}
		if (n == 0)
		{
			cout << "该分段内没有您要找的学生信息" << endl;
		}
	}
}

/*****************主菜单************************/
void mainmenu(student *head)
{
	char selet[10];
	int n = 1;
	ofstream outfile;
	ifstream infile;
	student *p, *ptr;
	student *test = head, *mid;
	cout << "*************************欢迎进入学生信息管理系统*************************" << endl;
	do {
		cout << "**************************************************************************" << endl;
		cout << "1.插入信息；   2.删除信息；  3.修改信息； 4.查看信息； 5.保存  " << endl;
		cout << "按'q'键退出      " << endl;
		cout << "**************************************************************************" << endl;
		cin >> selet;
		if (((selet[0]<'1' || selet[0]>'6') && selet[0] != 'q') || strlen(selet)>1)
		{
			system("cls");
			cout << "您的输入有误，请重新输入！" << endl;
			break;
		}
		switch (selet[0])
		{

		case '1':
			construct_list(head);
			break;
		case '2':
			delete_list(head);
			break;
		case '3':
			change_info(head);
			break;
		case '4':
			output(head);
			break;
		case '5':
			outfile.open("students.txt", ios::out | ios::app);
			for (p = head->getNext(); p != '\0'; p = p->getNext())
			{
				outfile << p->stu_name << ' ';
				outfile << p->stu_num << ' ';
				outfile << p->stu_score << ' ';
				outfile << endl;
			}
			outfile.close();
			system("cls");
			cout << "保存成功！" << endl;
			break;
		case 'q':
			break;
		}
	} while (selet[0] != 'q');
}

void main()
{
	student head;
	mainmenu(&head);
}