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
	char stu_num[15];                  //ѧ��  
	char stu_name[30];                //����  
	float stu_score;                      //�ɼ�  

	void afterInsert(student *p);//�ڸýڵ�����һ���ڵ�  
	void afterDelete();//�ڸýڵ��ɾ��һ���ڵ�  

	student *getNext()//�����һ���ڵ��ָ��  
	{
		return next;
	}

	/***********��ѯѧ����Ϣ************/
	void getMage();

	/******ѧ����Ϣ�޸�******/
	void changeMage(int n, char *ptr);
	void changegrade(float p);

	/******����*****/
	student(char *num, char *name, float score);
	student();
};

void student::changegrade(float p)
{
	stu_score = p;
}

student::student()           //����  
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

void student::afterInsert(student *p)//����ڵ�  
{
	p->next = next;
	next = p;
}

void student::afterDelete()        //ɾ���ڵ�  
{
	student *p = next;
	next = p->next;
	delete p;
}

void student::getMage()             //�����Ϣ  
{
	cout << "ѧ�ţ�" << stu_num << "      ������" << stu_name;
	cout << "      c++�ɼ���" << stu_score << endl;
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

//����������  
void  construct_list(student *tail)
{
	student *p = new student;
	char very[20];
	float achieve;
	cout << "������ѧ��:" << endl;
	cin >> very;
	p->changeMage(1, very);
	cout << "������������" << endl;
	cin >> very;
	p->changeMage(2, very);
	cout << "������c++�ɼ���" << endl;
	cin >> achieve;
	p->changegrade(achieve);
	system("cls");
	cout << "��Ϣ�������" << endl;

	for (; tail->getNext() != '\0';)
	{
		tail = tail->getNext();
	}

	tail->afterInsert(p);
}

/*********��ѯ��Ϣ*********/
student *findmege(student *head)
{
loop:
	cout << "1--��������ѯ           2--��ѧ�Ų�ѯ              q--������һ���˵�" << endl;
	char p[5], ptr[20];
	student *mid = head;
	cin >> p;

	if (p[0] != '1'&&p[0] != '2'&&p[0] != 'q' || strlen(p)>1)
	{
		system("cls");
		cout << "�Բ�����������������������룡" << endl;
		goto loop;
	}

	switch (p[0])
	{
	case '1':
	{
		system("cls");
		cout << "������Ҫ���ҵ�������" << endl;
		cin >> ptr;

		for (; strcmp(ptr, mid->stu_name) != 0; mid = mid->getNext())
		{
			if (mid->getNext() == '\0')
			{
				cout << "�Բ�����Ҫ���ҵ��˲����ڣ���ȷ����������Ƿ���ȷ��" << endl;
				goto loop;
			}
		}
		return mid;
	}
	case '2':
	{
		system("cls");
		cout << "��������Ҫ���ҵ�ѧ�ţ�" << endl;
		cin >> ptr;
		for (; strcmp(ptr, mid->stu_num) != 0; mid = mid->getNext())
		{
			if (mid->getNext() == '\0')
			{
				cout << "�Բ�����Ҫ���ҵ����ݲ����ڣ���ȷ�����������Ƿ���ȷ��" << endl;
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
		cout << "�Բ������������������������룡" << endl;
		goto loop;
	}
	}
}

/******************ɾ������ �ڵ�***********************/
void delete_list(student *head)
{
	student *p = '\0';
	char selet[4];
	system("cls");
	cout << "��ɾ��ǰ��ϵͳ�����������ʾ�ҵ���Ҫɾ����ѧ����Ϣ��" << endl;
	p = findmege(head);
	if (p != '\0')
	{
		cout << "ȷ��Ҫɾ����yes/��������أ�" << endl;
		cin >> selet;

		if (strcmp(selet, "yes") == 0)
		{
			for (; head->getNext() != p; head = head->getNext());
			head->afterDelete();
			system("cls");
			cout << "����Ϣɾ���ɹ���" << endl;
		}
	}
}

/*******************�޸Ľڵ���Ϣ********************/
void change_info(student *head)
{
	system("cls");
	cout << "�����޸�ǰ��ϵͳ��������ṩ����Ϣ�ҵ���Ҫ�޸ĵ���Ϣ��" << endl;
	student *p = '\0';

	float achieve;
	p = findmege(head);
	if (p != '\0')
	{
		cout << "������c++�ɼ�:" << endl;
		cin >> achieve;
		p->changegrade(achieve);
		system("cls");
		cout << "�޸ĳɹ�!" << endl;
	}

}

/**************���ѧ���ɼ���Ϣ**************/
void output(student *head)
{
	system("cls");
	cout << "1-�鿴ָ��ѧ����Ϣ��2-�鿴����ѧ����Ϣ��3-�ֶ����ѧ����Ϣ" << endl;
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
		cout << "a-60�����£�b-60~70��֮�䣻c-70~80��֮�䣻d-80~90��֮�䣻e-90~100��֮�䣺" << endl;
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
			cout << "�÷ֶ���û����Ҫ�ҵ�ѧ����Ϣ" << endl;
		}
	}
}

/*****************���˵�************************/
void mainmenu(student *head)
{
	char selet[10];
	int n = 1;
	ofstream outfile;
	ifstream infile;
	student *p, *ptr;
	student *test = head, *mid;
	cout << "*************************��ӭ����ѧ����Ϣ����ϵͳ*************************" << endl;
	do {
		cout << "**************************************************************************" << endl;
		cout << "1.������Ϣ��   2.ɾ����Ϣ��  3.�޸���Ϣ�� 4.�鿴��Ϣ�� 5.����  " << endl;
		cout << "��'q'���˳�      " << endl;
		cout << "**************************************************************************" << endl;
		cin >> selet;
		if (((selet[0]<'1' || selet[0]>'6') && selet[0] != 'q') || strlen(selet)>1)
		{
			system("cls");
			cout << "���������������������룡" << endl;
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
			cout << "����ɹ���" << endl;
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