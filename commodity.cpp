#include"commodity.h"

Commodity::Commodity()
{
	this->name = "¿Õ";
	this->description = "ÔÝÎÞ";
	this->price = 0;
	this->remain_num = 0;
	this->merchat_num = 0;
}

Commodity::Commodity(string _name, string _describe, double _price, unsigned int _remaiNum, unsigned int _merchatNum)
{
	this->name = _name;
	this->description = _describe;
	this->price = _price;
	this->remain_num = _remaiNum;
	this->merchat_num = _merchatNum;
}

Commodity::Commodity(const Commodity& pre)
{
	this->name = pre.name;
	this->description = pre.description;
	this->price = pre.price;
	this->remain_num = pre.remain_num;
	this->merchat_num = pre.merchat_num;
}

Commodity::~Commodity()
{
}

bool Commodity::ADD_remainNum(unsigned int quantity)
{
	remain_num += quantity;
	return true;
}

void Commodity::discount(double discount)
{
	price = price * discount;
}

void Commodity::modifyPrice(double _price)
{
	price = _price;
}

void Commodity::mofifyRemain(unsigned int quantity)
{
	remain_num = quantity;
}

Book::~Book()
{

}

double Book::getPrice(int num)
{
	if (num != 0) {
		return num * price;
	}
	else
		return price;
}

void Book::outputGood()
{
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "type:             " << left << "BOOK" << endl;
	cout << "commodity number: " << left << number << endl;
	cout << "name:             " << left << name << endl;
	cout << "description:      " << left << description << endl;
	cout << "price:            " << left << price << endl;
	cout << "remain number:    " << left << remain_num << endl;
	cout << "merchant number:  " << left << merchat_num << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}

Cloth::~Cloth()
{

}

double Cloth::getPrice(int num)
{
	if (num != 0) {
		return num * price;
	}
	else
		return price;
}

void Cloth::outputGood()
{
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "type:             " << left << "CLOTH" << endl;
	cout << "commodity number: " << left << number << endl;
	cout << "name:             " << left << name << endl;
	cout << "description:      " << left << description << endl;
	cout << "price:            " << left << price << endl;
	cout << "remain number:    " << left << remain_num << endl;
	cout << "merchant number:  " << left << merchat_num << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}

ElectProduct::~ElectProduct()
{

}

double ElectProduct::getPrice(int num)
{
	if (num != 0) {
		return num * price;
	}
	else
		return price;
}

void ElectProduct::outputGood()
{
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "type:             " << left << "ELECTRONIC PRODUCT" << endl;
	cout << "commodity number: " << left << number << endl;
	cout << "name:             " << left << name << endl;
	cout << "description:      " << left << description << endl;
	cout << "price:            " << left << price << endl;
	cout << "remain number:    " << left << remain_num << endl;
	cout << "merchant number:  " << left << merchat_num << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}