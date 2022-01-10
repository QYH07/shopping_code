#pragma once
#include"global.h"

class ShopCart {
private:
	string userName;//���ﳵ�������û���
	unsigned int total;//���ﳵ��Ԫ�ظ���
	vector<unsigned int> comType;//��Ʒ����
	vector<unsigned int> comOrder;//��Ʒ���
	vector<unsigned int> comNum;//��Ʒ����
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
