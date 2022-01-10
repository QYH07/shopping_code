#pragma once
#include"global.h"
using namespace std;

class Commodity {
private:
	//ÔÝÎª¿Õ
protected:
	string name;
	string description;
	double price;
	unsigned int remain_num;
	unsigned int merchat_num;
public:
	Commodity();
	Commodity(string _name, string _describe, double _price, unsigned int _remaiNum, unsigned int _merchatNum);
	Commodity(const Commodity& pre);
	~Commodity();

	const string getName() { return name; }
	const string getDescribe() { return description; }
	const double get_price() { return price; }
	const unsigned int get_remainNum() { return remain_num; }
	const unsigned int getMerchat_num() { return merchat_num; }

	virtual double getPrice(int num) = 0;

	bool ADD_remainNum(unsigned int quantity); 
	void SUB(unsigned int quantity) { remain_num -= quantity; }
	void discount(double discount);
	void modifyPrice(double _price);
	void mofifyRemain(unsigned int quantity);
};

class Book :public Commodity {
private:
	unsigned int number;
public:
	Book() { number = 0; }
	Book(unsigned int num, string _name, string _describe, double _price, unsigned int _remaiNum, unsigned int _merchatNum) :
		Commodity(_name, _describe, _price, _remaiNum, _merchatNum) {
		this->number = num;
	}
	Book(const Book& pre) :
		Commodity(pre) {
		this->number = pre.number;
	}
	~Book();

	const unsigned int get_order() { return number; }

	virtual double getPrice(int num) override;
	void outputGood();
};

class Cloth :public Commodity {
private:
	unsigned int number;
public:
	Cloth() { number = 0; }
	Cloth(unsigned int num, string _name, string _describe, double _price, unsigned int _remaiNum, unsigned int _merchatNum) :
		Commodity(_name, _describe, _price, _remaiNum, _merchatNum) {
		this->number = num;
	}
	Cloth(const Cloth& pre) :
		Commodity(pre) {
		this->number = pre.number;
	}
	~Cloth();

	const unsigned int get_order() { return number; }

	virtual double getPrice(int num) override;
	void outputGood();
};

class ElectProduct :public Commodity {
private:
	unsigned int number;
public:
	ElectProduct() { number = 0; }
	ElectProduct(unsigned int num, string _name, string _describe, double _price, unsigned int _remaiNum, unsigned int _merchatNum) :
		Commodity(_name, _describe, _price, _remaiNum, _merchatNum) {
		this->number = num;
	}
	ElectProduct(const ElectProduct& pre) :
		Commodity(pre) {
		this->number = pre.number;
	}
	~ElectProduct();

	const unsigned int get_order() { return number; }

	virtual double getPrice(int num) override;
	void outputGood();
};