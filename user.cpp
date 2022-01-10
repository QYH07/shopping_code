#include"global.h"
#include"user.h"

Consumer::~Consumer()
{

}

const int Consumer::getUserType()
{
	if (user_type == 1)
		return user_type;
	else if (user_type == 0)
		return user_type;;
	return -1;
}

void Consumer::registerAccout(string _name, string _password, string _payPasword)
{ 
	this->name = _name;
	this->password = _password;
	this->pay_pasword = _payPasword;
	this->balance = 0;
	this->user_type = 1;
}

void Consumer::loginAccout(string _name, string _password, string _payPasword, double _balance, int userType)
{
	this->name = _name;
	this->password = _password;
	this->pay_pasword = _payPasword;
	this->balance = _balance;
	this->user_type = userType;
}

void Consumer::rechargeService(double _recharge_mon)
{
	this->balance += _recharge_mon;
}

void Consumer::consumeService(double totalPrice)
{
	balance = balance - totalPrice;
}

bool Consumer::consumer_in_payword(string pay_password)
{
	if (pay_password == this->pay_pasword)
		return true;
	else
		return false;
}

Businessman::~Businessman()
{

}

const int Businessman::getUserType()
{
	if (user_type == 1)
		return user_type;
	else if (user_type == 0)
		return user_type;;
	return -1;
}

void Businessman::consumeAddBalance(double totalPrice)
{
	balance += totalPrice;
}

void Businessman::loginAccout(string _name, string _password, double _balance, int userType, unsigned int _merchatNum)
{
	this->name = _name;
	this->password = _password;
	this->balance = _balance;
	this->user_type = userType;
	this->merchatNum = _merchatNum;
}

void Businessman::registerAccout(string _name, string _password, unsigned int merchatNum)
{
	this->name = _name;
	this->password = _password;
	this->balance = 0;
	this->user_type = 0;
	this->merchatNum = merchatNum;
}