#pragma once
#include"global.h"
#include"commodity.h"
#include"server.h"

class Client {
private:
	vector<Book> books;
	vector<Cloth> clothes;
	vector<ElectProduct> eleProducts;
	vector<ShopCart> carts;
	vector<Order> all_orders;
	vector<Order> unpay_orders;
public:
	Client() {}
	~Client() {}

	void exitOutput();
	bool Update_member(Server& serve);//更新数据，用以本地输出

	void get_input(string& s, unsigned int max, bool sign);//检测输入是否合法，包括用户名和密码
	void getDouble(double& temp);//检测double类型输入是否合法
	void getUnsignedInt(unsigned int& temp);//检测unsigned int类型输入是否合法
	void getInt(int& temp);//检测int类型输入是否合法

	void viewAllProducts(Server& serve);//查看所有商品(内部先更新数据)
	unsigned int viewShopCarts(Server& serve, string userName, unsigned int& cType, unsigned int& cOrder, unsigned int& cNum);//查看购物车(需先更新)
	unsigned int viewGoods(Server& serve);//顾客购买选项中，先查看所有商品，返回商品类型
	
	void applySystem(Server& serve);//申请消费者系统还是商家系统
	void applyC_log_reg(Server& serve);//消费者系统，你想要登录还是注册
	bool applyC_log(Server& serve, int log_reg, Consumer& A);//消费者系统，登录页面
	bool applyC_reg(Server& serve, int log_reg, Consumer& A);//消费者系统，注册页面
	void applyC_service(Server& serve, Consumer& A);//消费者系统，选择服务

	//下面是客户端中消费者的所有服务类型，通过调用不同的函数，将需求发送给服务器
	void applyC_checkbalance(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_rechargeMoney(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_consumeGoods(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_changePassword(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_withdrawal(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_search(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_logout(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_shopCartService(Server& serve, Consumer& A, unsigned int service_type);
	void applyC_generaOrder(Server& serve, Consumer& A, unsigned int cType, unsigned int cNum, unsigned int cOrder);
	bool applyC_payForOrder(Server& serve, Consumer& A, unsigned int type, unsigned int num, unsigned int order);
	void applyC_viewOrder(Server& serve, Consumer& A);
	void applyC_view_historyOrder(unsigned int temp);
	void applyC_findOrderGood(unsigned int temp);//内联于applyC_viewOrder,用以寻找输出订单信息

	void applyB_log_reg(Server& serve);//商家系统，你想要登录还是注册
	bool applyB_log(Server& serve, int log_reg, Businessman& A);//商家系统，登录页面
	bool applyB_reg(Server& serve, int log_reg, Businessman& A);//商家系统，注册页面
	void applyB_service(Server& serve, Businessman& A);//商家系统，选择服务

	//下面是客户端中商家的所有服务类型，通过调用不同的函数，将需求发送给服务器
	void applyB_checkBalance(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_changePassword(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_addNewGoods(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_discount(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_modifyPrice(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_modifyRemainNum(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_logout(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_withdrawal(Server& serve, Businessman& A, unsigned int service_type);
};

