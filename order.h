#pragma once
#include"global.h"

class Order {
private:
	string userName;//�����������û���
	bool state;//����״̬��1Ϊ֧����0Ϊδ֧��
	unsigned int type;//��Ʒ����
	unsigned int merchat_num;//�̼ұ��
	unsigned int goods_order;//��Ʒ���
	unsigned int number;//��Ʒ��������
	double totalPrice;//�ܼ�
	time_t time_now;//��������ʱ��
public:
	Order();
	Order(string _name, bool State, unsigned int _type, unsigned int merchatNum, unsigned int goodsOrd, unsigned int Number, double TotalPrice, time_t p_time);
	Order(const Order& pre);
	~Order() {}

	const string get_name() { return userName; }
	const bool get_state() { return state; }
	const unsigned int get_type() { return type; }
	const unsigned int get_merchatNum() { return merchat_num; }
	const unsigned int get_order() { return goods_order; }
	const unsigned int get_number() { return number; }
	const double get_totalPrice() { return totalPrice; }
	const time_t get_time() { return time_now; }

	bool getTime();//��ȡ��ǰʱ��
	bool ModifyOrderStatus();
};
