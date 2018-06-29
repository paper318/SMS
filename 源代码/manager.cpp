#include"manager.hpp"
#include"MyownSQL.hpp"
int Manager::Load(string id, string password)
{
	string str = "select PasswdMan( ";
	str += quote + id + quote + comma + quote + password + quote + rb + semi;

	int token = Query(str.c_str(), int(2));
	//int(2）唯一的意义提供一个int参数就是对query重载识别
	return token;

}



/*更改账户*/
void ChangePassword() //对任何用户可以更改密码
{
	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());

}