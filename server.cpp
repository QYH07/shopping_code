#include"server.h"

void Server::readAllItems()
{
	fstream f1, f2, f3;
	string _name, _describe;
	string useless;
	double _price;
	unsigned int _num;
	unsigned int _remaiNum;
	unsigned int _merchatNum;
	f1.open("./Commodity/Book_message.txt", ios::in);
	f1.seekg(0, ios::beg);
	if (!f1.is_open()) {
		system("pause"), exit(0);
	}
	else {
		getline(f1, _name);
		getline(f1, _describe);
		f1 >> setw(balance_len) >> _price;
		f1 >> setw(five) >> _remaiNum;
		f1 >> setw(three) >> _merchatNum;
		f1 >> setw(three) >> _num;
		getline(f1, useless);
		while (!f1.eof()) {
			Book temp(_num, _name, _describe, _price, _remaiNum, _merchatNum);
			all_Book.push_back(temp);
			getline(f1, _name);
			getline(f1, _describe);
			f1 >> setw(balance_len) >> _price;
			f1 >> setw(five) >> _remaiNum;
			f1 >> setw(three) >> _merchatNum;
			f1 >> setw(three) >> _num;
			getline(f1, useless);
		}
	}f1.close();
	f2.open("./Commodity/Cloth_message.txt", ios::in);
	f2.seekg(0, ios::beg);
	if (!f2.is_open()) {
		system("pause"), exit(0);
	}
	else {
		getline(f2, _name);
		getline(f2, _describe);
		f2 >> setw(balance_len) >> _price;
		f2 >> setw(five) >> _remaiNum;
		f2 >> setw(three) >> _merchatNum;
		f2 >> setw(three) >> _num;
		getline(f2, useless);
		while (!f2.eof()) {
			Cloth temp(_num, _name, _describe, _price, _remaiNum, _merchatNum);
			all_cloth.push_back(temp);
			getline(f2, _name);
			getline(f2, _describe);
			f2 >> setw(balance_len) >> _price;
			f2 >> setw(five) >> _remaiNum;
			f2 >> setw(three) >> _merchatNum;
			f2 >> setw(three) >> _num;
			getline(f2, useless);
		}
	}f2.close();
	f3.open("./Commodity/EleProduct_message.txt", ios::in);
	f3.seekg(0, ios::beg);
	if (!f3.is_open()) {
		system("pause"), exit(0);
	}
	else {
		getline(f3, _name);
		getline(f3, _describe);
		f3 >> setw(balance_len) >> _price;
		f3 >> setw(five) >> _remaiNum;
		f3 >> setw(three) >> _merchatNum;
		f3 >> setw(three) >> _num;
		getline(f3, useless);
		while (!f3.eof()) {
			ElectProduct temp(_num, _name, _describe, _price, _remaiNum, _merchatNum);
			all_eleProduct.push_back(temp);
			getline(f3, _name);
			getline(f3, _describe);
			f3 >> setw(balance_len) >> _price;
			f3 >> setw(five) >> _remaiNum;
			f3 >> setw(three) >> _merchatNum;
			f3 >> setw(three) >> _num;
			getline(f3, useless);
		}
	}f3.close();
}

void Server::readAllUsers()
{
	if (all_consumer.size() == 0) {
		ifstream f1;
		string _name, _password, _payPasword;
		double _balance = 0;
		int _type = -1;
		f1.open("./User/consumer_message.txt", ios::in);
		f1.seekg(0, ios::beg);
		if (!f1.is_open()) {
			system("pause"),exit(0);
		}
		else {
			f1 >> _name >> _password >> _payPasword >> _balance >> _type;
			while (!f1.eof()) {
				Consumer temp(_name, _password, _payPasword, _balance, _type);
				all_consumer.push_back(temp);
				f1 >> _name >> _password >> _payPasword >> _balance >> _type;
			}
		}
	}
	if (all_businessman.size() == 0) {
		ifstream f1;
		string _name, _password;
		double _balance = 0;
		int _type = -1;
		unsigned int _merchatNum = 0;
		f1.open("./User/businessman_message.txt", ios::in);
		f1.seekg(0, ios::beg);
		if (!f1.is_open()) {
			system("pause"), exit(0);
		}
		else {
			f1 >> _name >> _password >> _balance >> _type >> _merchatNum;
			while (!f1.eof()) {
				Businessman temp(_name, _password, _balance, _type, _merchatNum);
				all_businessman.push_back(temp);
				f1 >> _name >> _password >> _balance >> _type >> _merchatNum;
			}
		}
	}
}

void Server::readShopCart_Orders()
{
	fstream f1, f2, f3;
	f1.open("./ShopCart_Orders/shoppingcarts.txt", ios::in);
	f1.seekg(0, ios::beg);
	if (!f1.is_open()) {
		system("pause"), exit(0);
	}
	else {
		string userName;
		unsigned int total, temp1, temp2, temp3;
		vector<unsigned int> cType, cOrder, cNum;
		f1 >> userName >> total;
		for (unsigned int i = 0; i < total; i++) {
			f1 >> temp1 >> temp2 >> temp3;
			cType.push_back(temp1);
			cOrder.push_back(temp2);
			cNum.push_back(temp3);
		}
		while (!f1.eof()) {
			ShopCart A(userName, total, cType, cOrder, cNum);
			all_carts.push_back(A);
			cType.clear(), cOrder.clear(), cNum.clear();
			f1 >> userName >> total;
			for (unsigned int i = 0; i < total; i++) {
				f1 >> temp1 >> temp2 >> temp3;
				cType.push_back(temp1);
				cOrder.push_back(temp2);
				cNum.push_back(temp3);
			}
		}
	}
	f2.open("./ShopCart_Orders/unpay_orders.txt", ios::in);
	f2.seekg(0, ios::beg);
	if (!f2.is_open()) {
		system("pause"), exit(0);
	}
	else {
		string userName;
		bool state;
		unsigned int type, merchat_num, goods_order, number;
		double totalPrice;
		time_t p_time;
		f2 >> userName >> state >> type >> merchat_num >> goods_order >> number >> totalPrice >> p_time;
		while (!f2.eof()) {
			Order A(userName, state, type, merchat_num, goods_order, number, totalPrice, p_time);
			all_unpay_orders.push_back(A);
			f2 >> userName >> state >> type >> merchat_num >> goods_order >> number >> totalPrice >> p_time;
		}f2.close();
	}
	f3.open("./ShopCart_Orders/orders.txt", ios::in);
	f3.seekg(0, ios::beg);
	if (!f3.is_open()) {
		system("pause"), exit(0);
	}
	else {
		string userName;
		bool state;
		unsigned int type, merchat_num, goods_order, number;
		double totalPrice;
		time_t p_time;
		f3 >> userName >> state >> type >> merchat_num >> goods_order >> number >> totalPrice >> p_time;
		while (!f3.eof()) {
			Order A(userName, state, type, merchat_num, goods_order, number, totalPrice, p_time);
			all_orders.push_back(A);
			f3 >> userName >> state >> type >> merchat_num >> goods_order >> number >> totalPrice >> p_time;
		}
		f3.close();
	}
}

bool Server::saveConsumerFile()
{
	fstream f2;
	f2.open("./User/consumer_message.txt", ios::out);
	if (!f2.is_open()) {
		return false;
	}
	else {
		f2.seekg(0, ios::beg);
		for (unsigned int j = 0; j < all_consumer.size(); j++) {
			f2 << setw(name_len) << left << all_consumer[j].get_name() << " ";
			f2 << setw(pasword_len) << left << all_consumer[j].get_password() << " ";
			f2 << setw(payPasword_len) << left << all_consumer[j].get_payPasword() << " ";
			f2 << setw(balance_len) << left << all_consumer[j].get_balance() << " ";
			f2 << setw(one) << left << all_consumer[j].getUserType() << endl;
		}
		f2.close();
		return true;
	}
}

bool Server::saveCommodityFile()
{
	fstream f1, f2, f3;
	f1.open("./Commodity/Book_message.txt", ios::out);
	f1.seekg(0, ios::beg);
	if (!f1.is_open()) {
		return false;
	}
	else {
		f1.seekg(0, ios::beg);
		for (unsigned int j = 0; j < all_Book.size(); j++) {
			f1 << left << all_Book[j].getName() << endl;
			f1 << left << all_Book[j].getDescribe() << endl;
			f1 << setw(balance_len) << left << all_Book[j].get_price() << " ";
			f1 << setw(five) << left << all_Book[j].get_remainNum() << " ";
			f1 << setw(three) << left << all_Book[j].getMerchat_num() << " ";
			f1 << setw(three) << left << all_Book[j].get_order() << endl;
		}f1 << endl;
	}f1.close();
	f2.open("./Commodity/Cloth_message.txt", ios::out);
	f2.seekg(0, ios::beg);
	if (!f2.is_open()) {
		return false;
	}
	else {
		f2.seekg(0, ios::beg);
		for (unsigned int j = 0; j < all_cloth.size(); j++) {
			f2 << left << all_cloth[j].getName() << endl;
			f2 << left << all_cloth[j].getDescribe() << endl;
			f2 << setw(balance_len) << left << all_cloth[j].get_price() << " ";
			f2 << setw(five) << left << all_cloth[j].get_remainNum() << " ";
			f2 << setw(three) << left << all_cloth[j].getMerchat_num() << " ";
			f2 << setw(three) << left << all_cloth[j].get_order() << endl;
		}f2 << endl;
	}f2.close();
	f3.open("./Commodity/EleProduct_message.txt", ios::out);
	f3.seekg(0, ios::beg);
	if (!f3.is_open()) {
		return false;
	}
	else {
		f3.seekg(0, ios::beg);
		for (unsigned int j = 0; j < all_eleProduct.size(); j++) {
			f3 << left << all_eleProduct[j].getName() << endl;
			f3 << left << all_eleProduct[j].getDescribe() << endl;
			f3 << setw(balance_len) << left << all_eleProduct[j].get_price() << " ";
			f3 << setw(five) << left << all_eleProduct[j].get_remainNum() << " ";
			f3 << setw(three) << left << all_eleProduct[j].getMerchat_num() << " ";
			f3 << setw(three) << left << all_eleProduct[j].get_order() << endl;
		}f3 << endl;
	}f3.close();
	return true;
}

bool Server::saveBusinessFile()
{
	fstream f2;
	f2.open("./User/businessman_message.txt", ios::out);
	if (!f2.is_open()) {
		return false;
	}
	else {
		f2.seekg(0, ios::beg);
		for (unsigned int j = 0; j < all_businessman.size(); j++) {
			f2 << setw(name_len) << left << all_businessman[j].get_name() << " ";
			f2 << setw(pasword_len) << left << all_businessman[j].get_password() << " ";
			f2 << setw(balance_len) << left << all_businessman[j].get_balance() << " ";
			f2 << setw(one) << left << all_businessman[j].getUserType() << " ";
			f2 << setw(three) << left << all_businessman[j].get_merchatNum() << endl;
		}
		f2.close();
		return true;
	}
}

bool Server::saveCarts_Orders()
{
	fstream f1, f2, f3;
	f1.open("./ShopCart_Orders/shoppingcarts.txt", ios::out);
	if (!f1.is_open()) {
		return false;
	}
	else {
		f1.seekg(0, ios::beg);
		for (unsigned int i = 0; i < all_carts.size(); i++) {
			f1 << left << all_carts[i].get_userName() << " ";
			f1 << left << all_carts[i].get_total() << endl;
			for (unsigned int j = 0; j < all_carts[i].get_total(); j++) {
				f1 << all_carts[i].get_comType()[j] << " " << all_carts[i].get_comOrder()[j] << " " << all_carts[i].get_comNum()[j] << endl;
			}
		}
		f1.close();
	}
	f2.open("./ShopCart_Orders/orders.txt", ios::out);
	if (!f2.is_open()) {
		return false;
	}
	else {
		for (unsigned int i = 0; i < all_orders.size(); i++) {
			f2 << setw(five) << left << all_orders[i].get_name() << " ";
			f2 << setw(10) << left << all_orders[i].get_state() << " ";
			f2 << setw(13) << left << all_orders[i].get_type() << " ";
			f2 << setw(12) << left << all_orders[i].get_merchatNum() << " ";
			f2 << setw(13) << left << all_orders[i].get_order() << " ";
			f2 << setw(8)  << left << all_orders[i].get_number() << " ";
			f2 << setw(10) << left << all_orders[i].get_totalPrice() << " ";
			f2 << setw(64) << left << all_orders[i].get_time() << endl;
		}
		f2.close();
	}
	f3.open("./ShopCart_Orders/unpay_orders.txt", ios::out);
	if (!f3.is_open()) {
		return false;
	}
	else {
		for (unsigned int i = 0; i < all_unpay_orders.size(); i++) {
			f3 << all_unpay_orders[i].get_name() << " ";
			f3 << all_unpay_orders[i].get_state() << " ";
			f3 << all_unpay_orders[i].get_type() << " ";
			f3 << all_unpay_orders[i].get_merchatNum() << " ";
			f3 << all_unpay_orders[i].get_order() << " ";
			f3 << all_unpay_orders[i].get_number() << " ";
			f3 << all_unpay_orders[i].get_totalPrice() << " ";
			f3 << all_unpay_orders[i].get_time() <<  endl;
		}
		f3.close();
		return true;
	}
}

const unsigned int Server::consumerSystem(int log_reg, string _name, string _password, string _payPasword, Consumer& A)
{
	switch (log_reg) {
	case 1:
		return this->consumer_register(A, _name, _password, _payPasword);
	case 0:
		return this->consumer_login(A, _name, _password);
	default:
		return WrongOrder;
	}
}

unsigned int Server::consumer_register(Consumer& A, string _name, string _password, string _payPasword)
{
	judgeFullOrders();
	for (unsigned int i = 0; i < all_consumer.size(); i++) {
		if (_name == all_consumer[i].get_name()) {
			return Reg_fail;
		}
	}
	for (unsigned int i = 0; i < all_businessman.size(); i++) {
		if (_name == all_businessman[i].get_name()) {
			return Reg_fail;
		}
	}
	A.registerAccout(_name, _password, _payPasword);
	all_consumer.push_back(A);
	return Reg_true;
}

unsigned int Server::consumer_login(Consumer& A, string _name, string _password)
{
	judgeFullOrders();
	for (unsigned int i = 0; i < all_consumer.size(); i++) {
		if (all_consumer[i].get_name() == _name) {
			if (all_consumer[i].get_password() == _password) {
				A.loginAccout(_name, _password, all_consumer[i].get_payPasword(), all_consumer[i].get_balance(), all_consumer[i].getUserType());
				return Log_true;
			}
			else {
				return Log_fail;
			}
		}
	}return Log_noName;
}

const unsigned int Server::consumerSystemService(unsigned int service_type, Consumer& A, double& recharge_mon, string payPassword, 
	string origin_pasWord, string new_pasWord, unsigned int type, unsigned int quantity, unsigned int order)
{
	switch (service_type)
	{
	case 1:
		return this->consumer_checkBalance(A);
		break;
	case 2:
		return this->consumer_rechargeBalance(A, recharge_mon, payPassword);
		break;
	case 3:
		return this->consumer_consumeService(A, type, quantity, order, recharge_mon);
		break;
	case 4:
		return this->consumer_changePassword(A, origin_pasWord, new_pasWord);
		break;
	case 5:
		return View_true;
		break;
	case 6:
		return Search_fail;
		break;
	case 7:
		return this->consumer_withdrawal(A, recharge_mon, payPassword);
		break;
	case PaywordCheck:
		if (A.consumer_in_payword(payPassword))
			return ConPaywordTrue;
		else
			return ConPaywordFail;
		break;
	case 11: 
		return WrongOrder;
		break;
	case AddIntoCart: {
		unsigned int i = 0;
		for (i = 0; i < all_carts.size(); i++) {
			if (A.get_name() == all_carts[i].get_userName())
				return consumer_addIntoCart(quantity, type, order, i);
		}
		if (i == all_carts.size() || all_carts.size() == 0) {
			ShopCart B(A.get_name(), 0);
			all_carts.push_back(B);
			return consumer_addIntoCart(quantity, type, order, i);
		}break;
	}
	case DeleteACart:
		return this->consumer_deleteAcart(A, type, order);
		break;
	case ModifyACart:
		return this->consumer_modifyAcart(A, type, quantity, order);
		break;
	case GeneraOrder:
		return this->consumer_generateOrder(A, type, quantity, order, recharge_mon);
		break;
	case PayTrue:
		return this->consumer_payTrue(A, type, quantity, order);
		break;
	case PayFail:
		return this->consumer_payFail(A, type, quantity, order);
		break;
	case 0: {
		judgeFullOrders();
		if (saveConsumerFile() && saveCommodityFile() && saveBusinessFile() && saveCarts_Orders())
			return LogoutSave;
		else //saveTheFile 或者 saveC_File 失败
			return LogSaveFail;
		break;
	}
	default:
		return WrongOrder;
		break;
	}
	return WrongOrder;
}

unsigned int Server::consumer_checkBalance(Consumer& A)
{
	for (unsigned int i = 0; i < all_consumer.size(); i++) {
		if (A.get_name() == all_consumer[i].get_name()) {
			A.checkBalance(all_consumer[i].get_balance());
			return Check_true;
		}
	}return Check_fail;
}

unsigned int Server::consumer_rechargeBalance(Consumer& A, double recharge_mon, string payPasword)
{
	if (A.get_payPasword() == payPasword) {
		A.rechargeService(recharge_mon);
		for (unsigned int i = 0; i < all_consumer.size(); i++) {
			if (A.get_name() == all_consumer[i].get_name())
				all_consumer[i].rechargeService(recharge_mon);
		}
		return Recharge_true;
	}
	else
		return Recharge_fail;
}

unsigned int Server::consumer_consumeService(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order, double& totalPrice)
{
	unsigned int i = 0, j = 0;
	switch (type) {
	case 1:
		for (i = 0; i < all_Book.size(); i++) {
			if (all_Book[i].get_order() == order) {
				if ((totalPrice = all_Book[i].getPrice(quantity)) <= A.get_balance()) {
					A.consumeService(totalPrice);
					for (j = 0; j < all_consumer.size(); j++) {
						if (A.get_name() == all_consumer[j].get_name())
							all_consumer[j].consumeService(totalPrice);
					}
					for (unsigned int j = 0; j < all_businessman.size(); j++) {
						if (all_businessman[j].get_merchatNum() == all_Book[i].getMerchat_num()) {
							all_businessman[j].consumeAddBalance(totalPrice);
							break;
						}
					}
					return Consume_true;
					break;
				}
				else return Consume_NObalance;
			}
		}if (i == all_Book.size()) return Consume_NOorder;
		break;
	case 2:
		for (i = 0; i < all_cloth.size(); i++) {
			if (all_cloth[i].get_order() == order) {
				if ((totalPrice = all_cloth[i].getPrice(quantity)) <= A.get_balance()) {
					A.consumeService(totalPrice);
					for (j = 0; j < all_consumer.size(); j++) {
						if (A.get_name() == all_consumer[j].get_name())
							all_consumer[j].consumeService(totalPrice);
					}
					for (unsigned int j = 0; j < all_businessman.size(); j++) {
						if (all_businessman[j].get_merchatNum() == all_cloth[i].getMerchat_num()) {
							all_businessman[j].consumeAddBalance(totalPrice);
							break;
						}
					}
					return Consume_true;
					break;
				}
				else return Consume_NObalance;
			}
		}if (i == all_cloth.size()) return Consume_NOorder;
		break;
	case 3:
		for (i = 0; i < all_eleProduct.size(); i++) {
			if (all_eleProduct[i].get_order() == order) {
				if ((totalPrice = all_eleProduct[i].getPrice(quantity)) <= A.get_balance()) {
					A.consumeService(totalPrice);
					for (j = 0; j < all_consumer.size(); j++) {
						if (A.get_name() == all_consumer[j].get_name())
							all_consumer[j].consumeService(totalPrice);
					}
					for (unsigned int j = 0; j < all_businessman.size(); j++) {
						if (all_businessman[j].get_merchatNum() == all_eleProduct[i].getMerchat_num()) {
							all_businessman[j].consumeAddBalance(totalPrice);
							break;
						}
					}
					return Consume_true;
					break;
				}
				else return Consume_NObalance;
			}
		}if (i == all_eleProduct.size()) return Consume_NOorder;
		break;
	default:
		return WrongOrder;
		break;
	}
	return WrongOrder;
}

unsigned int Server::consumer_changePassword(Consumer& A, string origin_password, string new_password)
{
	for (unsigned int i = 0; i < all_consumer.size(); i++) {
		if (A.get_name() == all_consumer[i].get_name()) {
			if (origin_password == A.get_password()) {
				if (new_password == origin_password) {
					return Change_PW_same;
				}
				else {
					A.changePassword(new_password);//password = new_pasWord;
					all_consumer[i].changePassword(new_password);
					return Change_PW_true;
				}
			}
			else return Change_PW_fail;
		}
	}return WrongOrder;
}

unsigned int Server::consumer_withdrawal(Consumer& A, double withdraw_mon, string payPasword)
{
	if (A.get_balance() < withdraw_mon)
		return WithdrawNoEgh;
	else {
		if (payPasword == A.get_payPasword()) {
			A.withdrawalService(withdraw_mon);
			for (unsigned int i = 0; i < all_consumer.size(); i++) {
				if (A.get_name() == all_consumer[i].get_name())
					all_consumer[i].withdrawalService(withdraw_mon);
			}
			return WithdrawTrue;
		}
		else
			return WithdrawFail;
	}
}

unsigned int Server::consumer_generateOrder(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order, double& totalPrice)
{
	unsigned int i = 0, j = 0;
	switch (type) {
	case 1:
		for (i = 0; i < all_Book.size(); i++) {
			if (all_Book[i].get_order() == order) {
				if (all_Book[i].get_remainNum() >= quantity) {
					totalPrice = all_Book[i].getPrice(quantity);
					Order temp(A.get_name(), false, type, all_Book[i].getMerchat_num(), order, quantity, totalPrice, 0);
					temp.getTime();
					judgeFullOrders();//判断订单是否超限
					all_unpay_orders.push_back(temp);
					all_Book[i].SUB(quantity);//减去商品数量
					return GeneraOrderTrue;
				}
				else return GeneraOrderNoEgh;
			}
		}if (i == all_Book.size()) return GeneraOrderFail;
		break;
	case 2:
		for (i = 0; i < all_cloth.size(); i++) {
			if (all_cloth[i].get_order() == order) {
				if (all_cloth[i].get_remainNum() >= quantity) {
					totalPrice = all_cloth[i].getPrice(quantity);
					Order temp(A.get_name(), false, type, all_cloth[i].getMerchat_num(), order, quantity, totalPrice, 0);
					temp.getTime();
					judgeFullOrders();//判断订单是否超限
					all_unpay_orders.push_back(temp);
					all_cloth[i].SUB(quantity);
					return GeneraOrderTrue;
				}
				else return GeneraOrderNoEgh;
			}
		}if (i == all_cloth.size()) return GeneraOrderFail;
		break;
	case 3:
		for (i = 0; i < all_eleProduct.size(); i++) {
			if (all_eleProduct[i].get_order() == order) {
				if (all_eleProduct[i].get_remainNum() >= quantity) {
					totalPrice = all_eleProduct[i].getPrice(quantity);
					Order temp(A.get_name(), false, type, all_eleProduct[i].getMerchat_num(), order, quantity, totalPrice, 0);
					temp.getTime();
					judgeFullOrders();//判断订单是否超限
					all_unpay_orders.push_back(temp);
					all_eleProduct[i].SUB(quantity);
					return GeneraOrderTrue;
				}
				else return GeneraOrderNoEgh;
			}
		}if (i == all_eleProduct.size()) return GeneraOrderFail;
		break;
	default:
		return WrongOrder;
		break;
	}
	return WrongOrder;
}

void Server::judgeFullOrders()
{
	vector<Order>::iterator ilter;
	int i = 0, size = 0;
	while (true) {
		size = all_unpay_orders.size();
		for (ilter = all_unpay_orders.begin(), i = 0; ilter < all_unpay_orders.end() && i < size; i++,ilter++) {
			time_t now_time = time(0);
			if ((now_time - (*ilter).get_time()) >= 1800) { // 1800秒 为 30分钟
				findCommodity((*ilter).get_type(), (*ilter).get_number(), (*ilter).get_order());//将订单减去的商品数量加回去
				all_orders.push_back(*ilter);
				all_unpay_orders.erase(ilter);
				break;
			}
		}
		if (i == size) break;
	}
}

unsigned int Server::consumer_payTrue(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order)
{ // 订单支付成功，修改订单state，并且将其转为已处理行列
	vector<Order>::iterator ilter;
	for (ilter = all_unpay_orders.begin(); ilter < all_unpay_orders.end(); ilter++) {
		if ((*ilter).get_name() == A.get_name() && (*ilter).get_type() == type && (*ilter).get_order() == order && quantity == (*ilter).get_number()) {
			(*ilter).ModifyOrderStatus();//修改订单状态为已支付
			(*ilter).getTime();//修改为支付时间
			all_orders.push_back(*ilter);//加入到已完成订单行列
			all_unpay_orders.erase(ilter);//从未支付订单中删除该订单
			return true;
		}
	}
	return WrongOrder;
}

unsigned int Server::consumer_payFail(Consumer& A, unsigned int type, unsigned int quantity, unsigned int order)
{  //订单支付失败，将未支付订单中删除该订单，并添加到已完成订单中，修改商品信息
	vector<Order>::iterator ilter;
	for (ilter = all_unpay_orders.begin(); ilter < all_unpay_orders.end(); ilter++) {
		if ((*ilter).get_name() == A.get_name() && (*ilter).get_type() == type && (*ilter).get_order() == order && quantity == (*ilter).get_number()) {
			(*ilter).getTime();//获取支付失败时间
			all_orders.push_back(*ilter);
			all_unpay_orders.erase(ilter);
			break;
		}
	}
	return this->findCommodity(type, quantity, order);//修改商品信息，将减去的商品数量加回去
}

unsigned int Server::consumer_addIntoCart(unsigned int num, unsigned int type, unsigned int orderNum, unsigned int temp)
{
	switch (type) {
	case 1: {
		for (unsigned int i = 0; i < all_Book.size(); i++) {
			if (orderNum == all_Book[i].get_order()) {
				if (num > all_Book[i].get_remainNum())
					return AddCartNoNum;
				return all_carts[temp].addIntoCart(num, type, orderNum);
			}
		}
		return AddCartNotFind;
		break;
	}
	case 2: {
		for (unsigned int i = 0; i < all_cloth.size(); i++) {
			if (orderNum == all_cloth[i].get_order()) {
				if (num > all_cloth[i].get_remainNum())
					return AddCartNoNum;
				return all_carts[temp].addIntoCart(num, type, orderNum);
			}
		}
		return AddCartNotFind;
		break;
	}
	case 3: {
		for (unsigned int i = 0; i < all_eleProduct.size(); i++) {
			if (orderNum == all_eleProduct[i].get_order()) {
				if (num > all_eleProduct[i].get_remainNum())
					return AddCartNoNum;
				return all_carts[temp].addIntoCart(num, type, orderNum);
			}
		}
		return AddCartNotFind;
		break;
	}
	default:
		return WrongOrder;
		break;
	}
	return WrongOrder;
}

unsigned int Server::consumer_deleteAcart(Consumer& A, unsigned int type, unsigned int order)
{
	for (unsigned int i = 0; i < all_carts.size(); i++) {
		if (A.get_name() == all_carts[i].get_userName())
			return all_carts[i].deleteOfCart(0, type, order);
	}return DeleteCartNoName;
}

unsigned int Server::consumer_modifyAcart(Consumer& A, unsigned int type, unsigned int num, unsigned int order)
{
	unsigned int i = 0;
	switch (type) {
	case 1:
		for (i = 0; i < all_Book.size(); i++) {
			if (order == all_Book[i].get_order()) {
				if (num > all_Book[i].get_remainNum())
					return ModifyCartNoEgh;
				else break;
			}
		}
		if (i == all_Book.size()) return ModifyCartNotFind;
		break;
	case 2:
		for (i = 0; i < all_cloth.size(); i++) {
			if (order == all_cloth[i].get_order()) {
				if (num > all_cloth[i].get_remainNum())
					return ModifyCartNoEgh;
				else break;
			}
		}
		if (i == all_cloth.size()) return ModifyCartNotFind;
		break;
	case 3:
		for (i = 0; i < all_eleProduct.size(); i++) {
			if (order == all_eleProduct[i].get_order()) {
				if (num > all_eleProduct[i].get_remainNum())
					return ModifyCartNoEgh;
				else break;
			}
		}
		if (i == all_eleProduct.size()) return ModifyCartNotFind;
		break;
	default:
		return WrongOrder;
		break;
	}
	for (unsigned int i = 0; i < all_carts.size(); i++) {
		if (A.get_name() == all_carts[i].get_userName())
			return all_carts[i].modifyCart(num, type, order);
	}return ModifyCartNoName;
}


const unsigned int Server::businessmanSystem(int log_reg, string _name, string _password, Businessman& A)
{
	switch (log_reg) {
	case 1:
		return this->business_register(A, _name, _password);
	case 0:
		return this->business_login(A, _name, _password);
	default:
		return WrongOrder;
	}
}

unsigned int Server::business_register(Businessman& A, string _name, string _password)
{
	for (unsigned int i = 0; i < all_businessman.size(); i++) {
		if (_name == all_businessman[i].get_name()) {
			return Reg_fail;
		}
	}
	for (unsigned int i = 0; i < all_consumer.size(); i++) {
		if (_name == all_consumer[i].get_name()) {
			return Reg_fail;
		}
	}
	A.registerAccout(_name, _password, all_businessman.size());
	all_businessman.push_back(A);
	return Reg_true;
}

unsigned int Server::business_login(Businessman& A, string _name, string _password)
{
	for (unsigned int i = 0; i < all_businessman.size(); i++) {
		if (all_businessman[i].get_name() == _name) {
			if (all_businessman[i].get_password() == _password) {
				A.loginAccout(_name, _password, all_businessman[i].get_balance(), all_businessman[i].getUserType(), all_businessman[i].get_merchatNum());
				return Log_true;
			}
			else {
				return Log_fail;
			}
		}
	}return Log_noName;
}

const unsigned int Server::businessmanSystemService(unsigned int service_type, Businessman& A, string origin_pasWord, 
	string new_pasWord, int _type, double _price, unsigned int _remain_num, string _name, string _describe)
{
	switch (service_type)
	{
	case 1:
		return this->business_checkBalance(A);
		break;
	case 2:
		return this->business_changePssword(A, origin_pasWord, new_pasWord);
		break;
	case 3:
		return this->business_addNewGoods(A, _type, _remain_num, _name, _describe, _price);
		break;
	case 4:
		return this->business_discount(A, _type, _price);
		break;
	case 5:
		return this->business_modifyPrice(A, _type, _remain_num, _price);
		break;
	case 6:
		return this->business_modifyRemainNum(A, _type, _remain_num, (unsigned int)_price);
		break;
	case 7:
		return View_true;
		break;
	case 8:
		return this->business_withdraw(A, _price);
		break;
	case 0: {
		if (saveBusinessFile() && saveCommodityFile() && saveConsumerFile() && saveCarts_Orders())
			return LogoutSave;
		else //saveTheFile 或者 saveC_File 失败
			return LogSaveFail;
		break;
	}
	default:
		return WrongOrder;
		break;
	}
}

unsigned int Server::business_withdraw(Businessman& A, double withdraw_mon)
{
	if (A.get_balance() < withdraw_mon)
		return WithdrawNoEgh;
	else {
		A.withdrawalService(withdraw_mon);
		for (unsigned int i = 0; i < all_businessman.size(); i++) {
			if (A.get_name() == all_businessman[i].get_name())
				all_businessman[i].withdrawalService(withdraw_mon);
		}
		return WithdrawTrue;
	}
}

unsigned int Server::business_checkBalance(Businessman& A)
{
	for (unsigned int i = 0; i < all_businessman.size(); i++) {
		if (A.get_name() == all_businessman[i].get_name()) {
			A.checkBalance(all_businessman[i].get_balance());
			return Check_true;
		}
	}return Check_fail;
}

unsigned int Server::business_changePssword(Businessman& A, string origin_password, string new_password)
{
	for (unsigned int i = 0; i < all_businessman.size(); i++) {
		if (A.get_name() == all_businessman[i].get_name()) {
			if (origin_password == A.get_password()) {
				if (new_password == origin_password) {
					return Change_PW_same;
				}
				else {
					A.changePassword(new_password);
					all_businessman[i].changePassword(new_password);
					return Change_PW_true;
				}
			}
			else return Change_PW_fail;
		}
	}return WrongOrder;
}

unsigned int Server::business_addNewGoods(Businessman& A, unsigned int _type, unsigned int _remain_num, string _name, string _describe, double _price)
{
	if (_type == 1) {
		Book temp(all_Book.size(), _name, _describe, _price, _remain_num, A.get_merchatNum());
		all_Book.push_back(temp);
	}
	else if (_type == 2) {
		Cloth temp(all_cloth.size(), _name, _describe, _price, _remain_num, A.get_merchatNum());
		all_cloth.push_back(temp);
	}
	else if (_type == 3) {
		ElectProduct temp(all_eleProduct.size(), _name, _describe, _price, _remain_num, A.get_merchatNum());
		all_eleProduct.push_back(temp);
	}
	return Add_good_true;
}

unsigned int Server::business_discount(Businessman& A, unsigned int discount_type, double discount)
{
	if (discount_type == 1)
	{
		for (unsigned int i = 0; i < all_Book.size(); i++)
			if (all_Book[i].getMerchat_num() == A.get_merchatNum())
				all_Book[i].discount(discount);
	}
	else if (discount_type == 2)
	{
		for (unsigned int i = 0; i < all_cloth.size(); i++)
			if (all_cloth[i].getMerchat_num() == A.get_merchatNum())
				all_cloth[i].discount(discount);
	}
	else if (discount_type == 3)
	{
		for (unsigned int i = 0; i < all_eleProduct.size(); i++)
			if (all_eleProduct[i].getMerchat_num() == A.get_merchatNum())
				all_eleProduct[i].discount(discount);
	}
	return Discount_true;
}

unsigned int Server::business_modifyPrice(Businessman& A, unsigned int type, unsigned int num, double price)
{
	unsigned int i = 0;
	switch (type)
	{
	case 1:
		for (i = 0; i < all_Book.size(); i++) {
			if (all_Book[i].getMerchat_num() == A.get_merchatNum() && all_Book[i].get_order() == num) {
				all_Book[i].modifyPrice(price);
				return Modify_Price;
			}
		}if (i == all_Book.size())
			return Modify_Pfail;
		break;
	case 2:
		for (i = 0; i < all_cloth.size(); i++) {
			if (all_cloth[i].getMerchat_num() == A.get_merchatNum() && all_cloth[i].get_order() == num) {
				all_cloth[i].modifyPrice(price);
				return Modify_Price;
			}
		}if (i == all_cloth.size())
			return Modify_Pfail;
		break;
	case 3:
		for (i = 0; i < all_eleProduct.size(); i++) {
			if (all_eleProduct[i].getMerchat_num() == A.get_merchatNum() && all_eleProduct[i].get_order() == num) {
				all_eleProduct[i].modifyPrice(price);
				return Modify_Price;
			}
		}if (i == all_eleProduct.size())
			return Modify_Pfail;
		break;
	default:
		break;
	}
	return Modify_Pfail;
}

unsigned int Server::business_modifyRemainNum(Businessman& A, unsigned int type, unsigned int num, unsigned int _remainNum)
{
	unsigned int i = 0;
	switch (type)
	{
	case 1:
		for (i = 0; i < all_Book.size(); i++) {
			if (all_Book[i].getMerchat_num() == A.get_merchatNum() && all_Book[i].get_order() == num) {
				all_Book[i].mofifyRemain(_remainNum);
				return Modify_Remain;
			}
		}if (i == all_Book.size())
			return Modify_Rfail;
		break;
	case 2:
		for (i = 0; i < all_cloth.size(); i++) {
			if (all_cloth[i].getMerchat_num() == A.get_merchatNum() && all_cloth[i].get_order() == num) {
				all_cloth[i].mofifyRemain(_remainNum);
				return Modify_Remain;
			}
		}if (i == all_cloth.size())
			return Modify_Rfail;
		break;
	case 3:
		for (i = 0; i < all_eleProduct.size(); i++) {
			if (all_eleProduct[i].getMerchat_num() == A.get_merchatNum() && all_eleProduct[i].get_order() == num) {
				all_eleProduct[i].mofifyRemain(_remainNum);
				return Modify_Remain;
			}
		}if (i == all_eleProduct.size())
			return Modify_Rfail;
		break;
	default:
		break;
	}
	return Modify_Rfail;
}

inline unsigned int Server::findCommodity(unsigned int type, unsigned int quantity, unsigned int order)
{
	if (type == 1) {
		for (unsigned int i = 0; i < all_Book.size(); i++) {
			if (all_Book[i].get_order() == order)
				return all_Book[i].ADD_remainNum(quantity);
		}
	}
	if (type == 2) {
		for (unsigned int i = 0; i < all_cloth.size(); i++) {
			if (all_cloth[i].get_order() == order)
				return all_cloth[i].ADD_remainNum(quantity);
		}
	}
	if (type == 3) {
		for (unsigned int i = 0; i < all_eleProduct.size(); i++) {
			if (all_eleProduct[i].get_order() == order)
				return all_eleProduct[i].ADD_remainNum(quantity);
		}
	}
	return WrongOrder;
}
