

#ifndef TEACHER_H_
#define TEACHER_H_
#include<string>
using namespace std;

class Teacher {
private:
	string id;
	string password;
public:
	Teacher(string a, string b) :id(a), password(b) {};
	~Teacher() {};

	void Load(string id, string password);//µÇÂ½

};




#endif // !MANAGER_H_
