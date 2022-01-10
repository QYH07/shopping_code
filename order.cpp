#include"order.h"

Order::Order()
{
	userName = "ÕÅÈý";
	state = false;
	type = 0;
	merchat_num = 0;
	goods_order = 0;
	number = 0;
	totalPrice = 0;
	time_now = 0;
}

Order::Order(string _name, bool State, unsigned int _type, unsigned int merchatNum, unsigned int goodsOrd, unsigned int Number, double TotalPrice, time_t p_time)
{
	this->userName = _name;
	this->state = State;
	this->type = _type;
	this->merchat_num = merchatNum;
	this->goods_order = goodsOrd;
	this->number = Number;
	this->totalPrice = TotalPrice;
	this->time_now = p_time;
}

Order::Order(const Order& pre)
{
	this->userName = pre.userName;
	this->state = pre.state;
	this->type = pre.type;
	this->merchat_num = pre.merchat_num;
	this->goods_order = pre.goods_order;
	this->number = pre.number;
	this->totalPrice = pre.totalPrice;
	this->time_now = pre.time_now;
}

bool Order::ModifyOrderStatus()
{
	state = true;
	return true;
}

bool Order::getTime()
{
	time_now = time(0);
	return true;
}