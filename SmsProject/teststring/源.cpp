#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
	//std::string a = "zhanxinrui";

	//std::cout << (a=="zhanxinrui");
	double a = 123.32;
	string res;
	stringstream ss;
	ss << a;
	ss >> res;//Лђеп res = ss.str();
	cout << res;
	return 0;
}