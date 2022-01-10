#pragma once
#include"global.h"
#include"user.h"
#include"commodity.h"
#include"ShopCart.h"
#include"order.h"

class Server {
private:
	vector<Consumer> all_consumer;
	vector<Businessman> all_businessman;
	vector<Book> all_Book;
	vector<Cloth> all_cloth;
	vector<ElectProduct> all_eleProduct;

	vector<ShopCart> all_carts;
	vector<Order> all_orders;
	vector<Order> all_unpay_orders;
public:
	void readAllItems();
	void readAllUsers();
	void readShopCart_Orders();

	const vector<Book> get_all_books() { return all_Book; }
	const vector<Cloth> get_all_clothes() { return all_cloth; }
	const vector<ElectProduct> get_all_eleProduct() { return all_eleProduct; }
	const vector<ShopCart> get_all_carts() { return all_carts; }
	const vector<Order> get_unpay_orders() { 
		judgeFullOrders();
		return all_unpay_orders; 
	}
	const vector<Order> get_orders() { return all_orders; }

	inline unsigned int findCommodity(unsigned int type, unsigned int quantity, unsigned int order);

	const unsigned int consumerSystem(int log_reg, string _name, string _password, string _payPasword, Consumer& A);
	const unsigned int consumerSystemService(unsigned int service_type, Consumer& A, double& recharge_mon, string payPasword, 
		string origin_pasWord, string new_pasWord, unsigned int type, unsigned int quantity, unsigned int order);
	const unsigned int businessmanSystem(int log_reg, string _name, string _password, Businessman& A);
	const unsigned int businessmanSystemService(unsigned int service_type, Businessman& A, string origin_pasWord, 
		string new_pasWord, int _type, double _price, unsigned int _remain_num, string _name, string _describe);

	//服务器函数：消费者
	unsigned int consumer_register(Consumer& A, string _name, string _password, string _payPasword);
	unsigned int consumer_login(Consumer& A, string _name, string _password);

	unsigned int consumer_checkBalance(Consumer& A);
	unsigned int consumer_rechargeBalance(Consumer& A, double recharge_mon, string payPasword);
	unsigned int consumer_consumeService(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order, double& totalPrice);
	unsigned int consumer_changePassword(Consumer& A, string origin_password, string new_password);
	unsigned int consumer_withdrawal(Consumer& A, double withdraw_mon, string payPasword);
	bool saveConsumerFile();
	bool saveCommodityFile();
	bool saveCarts_Orders();

	unsigned int consumer_generateOrder(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order, double& totalPrice);
	void judgeFullOrders();//判断订单是否超时，并进行相应处理
	unsigned int consumer_payTrue(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order);
	unsigned int consumer_payFail(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order);
	unsigned int consumer_addIntoCart(unsigned int num, unsigned int type, unsigned int orderNum, unsigned int temp);
	unsigned int consumer_deleteAcart(Consumer& A, unsigned int type, unsigned int order);
	unsigned int consumer_modifyAcart(Consumer& A, unsigned int type, unsigned int num, unsigned int order);

	//服务器函数：商家
	unsigned int business_register(Businessman& A, string _name, string _password);
	unsigned int business_login(Businessman& A, string _name, string _password);

	unsigned int business_checkBalance(Businessman& A);
	unsigned int business_changePssword(Businessman& A, string origin_password, string new_password);
	unsigned int business_addNewGoods(Businessman& A, unsigned int _type, unsigned int _remain_num, string _name, string _describe, double _price);
	unsigned int business_discount(Businessman& A, unsigned int discount_type, double discount);
	unsigned int business_modifyRemainNum(Businessman& A, unsigned int type, unsigned int num, unsigned int _remainNum);
	unsigned int business_modifyPrice(Businessman& A, unsigned int type, unsigned int num, double price);
	unsigned int business_withdraw(Businessman& A, double withdraw_mon);

	bool saveBusinessFile();
};