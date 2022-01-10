#pragma once
#include"global.h"

class ShopCart {
private:
	string userName;//购物车所有者用户名
	unsigned int total;//购物车中元素个数
	vector<unsigned int> comType;//商品种类
	vector<unsigned int> comOrder;//商品编号
	vector<unsigned int> comNum;//商品数量
public:
	ShopCart();
	ShopCart(string _name, unsigned int _total, vector<unsigned int> type,
		vector<unsigned int> order, vector<unsigned int> num);
	ShopCart(string _name, unsigned int _total);
	~ShopCart() {}

	const string get_userName() { return userName; }
	const unsigned int get_total() { return total; }
	const vector<unsigned int> get_comType() { return comType; }
	const vector<unsigned int> get_comOrder() { return comOrder; }
	const vector<unsigned int> get_comNum() { return comNum; }

	unsigned int addIntoCart(unsigned int num, unsigned int type, unsigned int orderNum);
	unsigned int deleteOfCart(unsigned int num, unsigned int type, unsigned int orderNum);
	unsigned int modifyCart(unsigned int num, unsigned int type, unsigned int orderNum);
};
