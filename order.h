#pragma once
#include"global.h"

class Order {
private:
	string userName;//订单所有者用户名
	bool state;//订单状态，1为支付，0为未支付
	unsigned int type;//商品类型
	unsigned int merchat_num;//商家编号
	unsigned int goods_order;//商品编号
	unsigned int number;//商品购买数量
	double totalPrice;//总价
	time_t time_now;//订单最终时间
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

	bool getTime();//获取当前时间
	bool ModifyOrderStatus();
};
