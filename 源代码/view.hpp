//界面显示

#ifndef VIEW_H_
#define VIEW_H_
#include"leader.hpp"
#include"manager.hpp"
#include"student.hpp"
#include"teacher.hpp"
#include"Enrollment.hpp"
#include"OpenClass.hpp"
#include"SelectClass.hpp"
#include"Exam.hpp"
#include"Grade.hpp"
#include<iostream>
#include<string>
#include<sstream>
void login();
void Menu();//主菜单
void ViewEnroll();//学籍管理界面
void ViewOpen();//开课界面
void ViewSe();//选课界面
void ViewExam();// 考试界面
void ViewGra();//成绩管理界面
void ViewOthers();//其它成员函数方法界面
#endif