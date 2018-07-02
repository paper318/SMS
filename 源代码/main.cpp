#include"View.hpp"
int main() {
	/*cout << "学院管理系统" << endl;

	cout << "\n\n\n\n\n\t\t\t\tpowered by 。。。 " << endl;
	cout << "\t\t\t\t回车进入" << endl;*/
	cout << "学院管理系统\n" << endl;
	InitDB();
	login();
	closeDB();
	return 0;
}