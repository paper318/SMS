#include"manager.hpp"
#include"MyownSQL.hpp"
int Manager::Load(string id, string password)
{ //返回2：登录成功，返回-1：账号密码错误，返回0：程序运行错误
	string str = "select PasswdMan( ";
	str += quote + id + quote + comma + quote + password + quote + rb + semi;
	int token = Query(str.c_str(), int(2));
	//int(2）唯一的作用是提供一个int型参数区别重载版本
	return token;

} 


/*更改账户*/
void ChangePassword() //管理员用sql语句update用户账户密码
{
	std::string str, sqlstr;
	while (getline(cin, str))
	{
		sqlstr += str;
		str.clear();
	}
	Query(sqlstr.c_str());

}
