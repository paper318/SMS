#ifndef MANAGER_H_
#define MANAGER_H_
#include<string>
using namespace std;
class Manager {
private:
	string id;
	string password;
public:
	Manager(string a, string b) :id(a), password(b) {};
	Manager() {};
	~Manager() {};
	int Load();

	/*更改账户*/
	void ChangePassword(); //管理员用sql语句update用户账户密码


};
 




#endif // !MANAGER_H_
