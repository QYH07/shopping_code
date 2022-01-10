#pragma once
#include"global.h"

class User {
private:
	//暂为空
protected:
	string name;
	string password;
	double balance;
	int user_type;
public:
	User() {
		name = "张三";
		password = "123456";
		balance = 0;
		user_type = -1;
	}
	User(string _name, string _password, double _balance, int userType) {
		name = _name;
		password = _password;
		balance = _balance;
		user_type = userType;
	}
	User(const User& pre) {
		name = pre.name;
		password = pre.password;
		balance = pre.balance;
		user_type = pre.user_type;
	}
	~User() { }

	virtual const int getUserType() = 0;
	const double get_balance() { return balance; }
	const string get_name() { return name; }
	const string get_password() { return password; }

	void changePassword(string new_pasWord) { password = new_pasWord; }
	void checkBalance(double _balance) { balance = _balance; }
	void withdrawalService(double withdraw_mon) { balance -= withdraw_mon; }
};

class Consumer : public User {
private:
	string pay_pasword;
public:
	Consumer() { pay_pasword = "000000"; }
	Consumer(string _name, string _password, string _payPasword, double _balance, int type) :User(_name, _password, _balance, type) {
		pay_pasword = _payPasword;
	}
	Consumer(const Consumer& pre) :User(pre) {
		pay_pasword = pre.pay_pasword;
	}
	~Consumer();

	const string get_payPasword() { return pay_pasword; }
	const int getUserType() override;

	void registerAccout(string _name, string _password, string _payPasword);
	void loginAccout(string _name, string _password, string _payPasword, double _balance, int userType);
	void rechargeService(double _recharge_mon);
	void consumeService(double totalPrice);
	bool consumer_in_payword(string pay_password);//内联于consumeService()函数
};

class Businessman : public User {
private:
	unsigned int merchatNum;
public:
	Businessman() { merchatNum = -1; }
	Businessman(string _name, string _password, double _balance, int _type, unsigned int _merchatNum) :User(_name, _password, _balance, _type) {
		merchatNum = _merchatNum;
	}
	Businessman(const Businessman& pre) :User(pre) {
		merchatNum = pre.merchatNum;
	}
	~Businessman();

	const unsigned int get_merchatNum() { return merchatNum; }
	const int getUserType() override;

	void registerAccout(string _name, string _password, unsigned int merchatNum);
	void loginAccout(string _name, string _password, double _balance, int userType, unsigned int _merchatNum);
	void consumeAddBalance(double totalPrice);
};
