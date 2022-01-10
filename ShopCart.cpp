#include"ShopCart.h"

ShopCart::ShopCart()
{
	userName = "ÕÅÈý";
	total = 0;
}

ShopCart::ShopCart(string _name, unsigned int _total, vector<unsigned int> type,
	vector<unsigned int> order, vector<unsigned int> num)
{
	userName = _name;
	total = _total;
	comType = type;
	comOrder = order;
	comNum = num;
}

ShopCart::ShopCart(string _name, unsigned int _total)
{
	userName = _name;
	total = _total;
}

unsigned int ShopCart::addIntoCart(unsigned int num, unsigned int type, unsigned int orderNum)
{
	for (unsigned int i = 0; i < total; i++) {
		if (comType[i] == type && comOrder[i] == orderNum)
			return AddCartRepeat;
	}
	this->comType.push_back(type);
	this->comOrder.push_back(orderNum);
	this->comNum.push_back(num);
	total++;
	return AddCartTrue;
}

unsigned int ShopCart::deleteOfCart(unsigned int num, unsigned int type, unsigned int orderNum)
{
	vector<unsigned int>::iterator ilter;
	vector<unsigned int>::iterator ilter1;
	vector<unsigned int>::iterator ilter2;
	for (ilter = comOrder.begin(), ilter1 = comType.begin(), ilter2 = comNum.begin(); ilter < comOrder.end() &&
		ilter1 < comType.end() && ilter2 < comNum.end(); ilter++, ilter1++, ilter2++) {
		if (type == (*ilter1) && orderNum == (*ilter)) {
			comOrder.erase(ilter);
			comType.erase(ilter1);
			comNum.erase(ilter2);
			total -= 1;
			return DeleteCartTrue;
		}
	}
	return DeleteCartNotFind;
}

unsigned int ShopCart::modifyCart(unsigned int num, unsigned int type, unsigned int orderNum)
{
	for (unsigned int i = 0; i < total; i++) {
		if (type == comType[i] && orderNum == comOrder[i]) {
			comNum[i] = num;
			return ModifyCartTrue;
		}
	}return WrongOrder;
}