#include"client.h"

bool Client::Update_member(Server& serve)
{
	books.clear();
	clothes.clear();
	eleProducts.clear();
	carts.clear();
	unpay_orders.clear();
	all_orders.clear();

	books = serve.get_all_books();
	clothes = serve.get_all_clothes();
	eleProducts = serve.get_all_eleProduct();
	carts = serve.get_all_carts();
	unpay_orders = serve.get_unpay_orders();
	all_orders = serve.get_orders();
	return true;
}

void Client::exitOutput()
{
	cout << "--------------------------------------" << endl;
	cout << "------     THANKS FOR USING     ------" << endl;
	cout << "------      Copyright: QYH      ------" << endl;
	cout << "------      See You Around!     ------" << endl;
	cout << "--------------------------------------" << endl;
}

void Client::get_input(string& s, unsigned int max, bool sign)
{
	int flag = 0;
	while (!flag) {
		flag = 1;
		getline(cin, s);
		if (sign == true) {
			if (s.size() > max || s.size() == 0) {
				flag = 0;
				cout << "Exceed the word limit or have a word count of 0, please reenter:" << endl;
			}
		}
		else {
			if (s.size() != max) {
				flag = 0;
				cout << "Payment password entry is not legal. Please reenter:" << endl;
			}
		}
		for (unsigned int i = 0; flag && i < s.size(); i++) {
			char t = s.c_str()[i];
			if ((t >= '0' && t <= '9') || (t >= 'a' && t <= 'z')
				|| (t >= 'A' && t <= 'Z'))
				;
			else {
				cout << "The input doesn't conform to the format, please reenter:" << endl;
				flag = 0;
			}
		}
	}
}

void Client::getDouble(double& temp)
{
	char ch;
	cin >> temp;
	ch = getchar();
	while (ch != '\n' || cin.fail() || cin.bad()) {
		cout << "Wrong, you have inputed a wrong type data." << endl;
		cout << "Please input again!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> temp;
		ch = getchar();
	}
}

void Client::getUnsignedInt(unsigned int& temp)
{
	char ch;
	cin >> temp;
	ch = getchar();
	while (ch != '\n' || cin.fail() || cin.bad()) {
		cout << "Wrong, you have inputed a wrong type data." << endl;
		cout << "Please input again!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> temp;
		ch = getchar();
	}
}

void Client::getInt(int& temp)
{
	char ch;
	cin >> temp;
	ch = getchar();
	while (ch != '\n' || cin.fail() || cin.bad()) {
		cout << "Wrong, you have inputed a wrong type data." << endl;
		cout << "Please input again!" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cin >> temp;
		ch = getchar();
	}
}

void Client::viewAllProducts(Server& serve)
{
	if (this->Update_member(serve) == true)
		cout << "The data update is successful." << endl;
	else {
		cout << "The data update is failed.    " << endl;
		return;
	}
	cout << "The Book part:" << endl;
	for (unsigned int i = 0; i < books.size(); i++)
		books[i].outputGood();
	cout << endl;
	cout << endl << "The Cloth part:" << endl;
	for (unsigned int i = 0; i < clothes.size(); i++)
		clothes[i].outputGood();
	cout << endl;
	cout << endl << "The Electronic products part:" << endl;
	for (unsigned int i = 0; i < eleProducts.size(); i++)
		eleProducts[i].outputGood();
	cout << endl;
	system("pause");
	system("cls");
}

unsigned int Client::viewShopCarts(Server& serve, string userName, unsigned int& cType, unsigned int& cOrder, unsigned int& cNum)
{
	if (this->Update_member(serve) == true)
		cout << "The data update is successful." << endl;
	else {
		cout << "The data update is failed.    " << endl;
		return WrongOrder;
	}
	cout << userName << "'s shopping cart: " << endl;
	for (unsigned int i = 0; i < carts.size(); i++) {
		if (userName == carts[i].get_userName()) {
			vector<unsigned int> type = carts[i].get_comType();
			vector<unsigned int> order = carts[i].get_comOrder();
			vector<unsigned int> num = carts[i].get_comNum();
			for (unsigned int j = 0; j < carts[i].get_total(); j++) {
				for (unsigned int k = 0; k < books.size(); k++) {
					if (type[j] == 1 && order[j] == books[k].get_order()) {
						cout << "-------------------------------------------" << endl;
						cout << "--type:   " << setw(33) << left << "Book" << endl;
						cout << "--name:   " << setw(33) << left << books[k].getName() << endl;
						cout << "--order:  " << setw(33) << left << order[j] << endl;
						cout << "--number: " << setw(33) << left << num[j] << endl;
						cout << "-------------------------------------------" << endl;
					}
				}
				for (unsigned int k = 0; k < clothes.size(); k++) {
					if (type[j] == 2 && order[j] == clothes[k].get_order()) {
						cout << "-------------------------------------------" << endl;
						cout << "--type:   " << setw(33) << left << "Cloth" << endl;
						cout << "--name:   " << setw(33) << left << clothes[k].getName() << endl;
						cout << "--order:  " << setw(33) << left << order[j] << endl;
						cout << "--number: " << setw(33) << left << num[j] << endl;
						cout << "-------------------------------------------" << endl;
					}
				}
				for (unsigned int k = 0; k < eleProducts.size(); k++) {
					if (type[j] == 3 && order[j] == eleProducts[k].get_order()) {
						cout << "-------------------------------------------" << endl;
						cout << "--type:   " << setw(33) << left << "Electronic product" << endl;
						cout << "--name:   " << setw(33) << left << eleProducts[k].getName() << endl;
						cout << "--order:  " << setw(33) << left << order[j] << endl;
						cout << "--number: " << setw(33) << left << num[j] << endl;
						cout << "-------------------------------------------" << endl;
					}
				}
				unsigned int choose = 0;
				cout << "Please enter: " << endl;
				cout << "The next one: 1 || End the view: 2 || Generate an order: 3" << endl;
				cout << "Delete item : 4 || Modify item : 5 || The previous one : 6" << endl;
				this->getUnsignedInt(choose);
				while (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 && choose != 6) {
					cout << "Wrong input! Please reenter: " << endl;
					this->getUnsignedInt(choose);
				}
				system("cls");
				switch (choose) {
				case 1:
					cout << userName << "'s shopping cart: " << endl;
					break;
				case 2:
					return ViewCartTrue;
				case 3:
					cType = type[j];
					cOrder = order[j];
					cNum = num[j];
					return ViewCartBuy;
				case 4:
					cType = type[j];
					cOrder = order[j];
					cNum = num[j];
					return ViewCartDelete;
				case 5:
					cType = type[j];
					cOrder = order[j];
					cNum = num[j];
					return ViewCartModify;
				case 6:
					cout << userName << "'s shopping cart: " << endl;
					if (j >= 2)
						j -= 2;
					else j = -1;
					break;
				default:
					break;
				}
			}
		}
	}
	system("cls");
	return ViewCartTrue;
}

unsigned int Client::viewGoods(Server& serve)
{
	if (this->Update_member(serve) == true)
		cout << "The data update is successful." << endl;
	else {
		cout << "The data update is failed.    " << endl;
		return WrongOrder;
	}
	unsigned int type = 0;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "Please input the type of product: 1 for book, 2 for cloth, 3 for electronic product." << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	this->getUnsignedInt(type);
	while (type != 1 && type != 2 && type != 3) {
		cout << "Your input is wrong, please reenter:" << endl;
		this->getUnsignedInt(type);
	}
	switch (type) {
	case 1:
		if (books.size() == 0) return WrongOrder;
		cout << "The Book part:" << endl;
		for (unsigned int i = 0; i < books.size(); i++) {
			books[i].outputGood();
		}
		break;
	case 2:
		if (clothes.size() == 0) return WrongOrder;
		cout << endl << "The Cloth part:" << endl;
		for (unsigned int i = 0; i < clothes.size(); i++) {
			clothes[i].outputGood();
		}
		break;
	case 3:
		if (eleProducts.size() == 0) return WrongOrder;
		cout << endl << "The Electronic products part:" << endl;
		for (unsigned int i = 0; i < eleProducts.size(); i++) {
			eleProducts[i].outputGood();
		}
		break;
	default:
		break;
	}
	return type;
}

void Client::applySystem(Server& serve)
{
	int user_type;
L3:
	cout << "******************************************************" << endl;
	cout << "*If you're a consumer, please input 1;               *" << endl;
	cout << "*if you're a businessman, please input 2;            *" << endl;
	cout << "*if you want to view all commodities, please input 3;*" << endl;
	cout << "*if you want to exit, please input 0.                *" << endl;
	cout << "******************************************************" << endl;
	this->getInt(user_type);
	while (true) {
		if (user_type == 1 || user_type == 2 || user_type == 3) {
			system("cls");
			while (true) {
				switch (user_type) {
				case 1:
					this->applyC_log_reg(serve);
					goto L3;
					break;
				case 2:
					this->applyB_log_reg(serve);
					goto L3;
					break;
				case 3:
					this->viewAllProducts(serve);
					goto L3;
					break;
				}
			}
		}
		else if (user_type == 0) {
			system("cls");
			system("pause");
			return;
		}
		else {
			cout << "Your input is not right. Please reenter:" << endl;
			this->getInt(user_type);
		}
	}
}

void Client::applyC_log_reg(Server& serve)
{
	int log_reg;
	Consumer A;
	system("cls");
	cout << "-------------------------------------------------------" << endl;
	cout << " If you want to login your account, please input 0, " << endl
		<< " if you want to register a new account, please input 1:" << endl;
	cout << "-------------------------------------------------------" << endl;
	this->getInt(log_reg);
	while (log_reg != 0 && log_reg != 1) {
		cout << "Your input is wrong. Please reenter:" << endl;
		this->getInt(log_reg);
	}
	switch (log_reg) {
	case 0:
		if (this->applyC_log(serve, log_reg, A))
			this->applyC_service(serve, A);
		break;
	case 1:
		if (this->applyC_reg(serve, log_reg, A))
			this->applyC_service(serve, A);
		break;
	default:
		break;
	}
}

bool Client::applyC_reg(Server& serve, int log_reg, Consumer& A)
{
	system("cls");
	string _name, _password, _payPasword;
	unsigned int return_num;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "--   Please input your account name(within 12 characters, only letters and numbers can be included),--" << endl;
	cout << "--   password(within 18 characters, only letters and numbers can be included)                       --" << endl;
	cout << "--   and pay_password(6 characters, only letters and numbers can be included)!                      --" << endl;
	cout << "--   ATTENTION: Modification of payment password is not supported,                                  --" << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
L1:
	cout << "Now you need to enter the name first." << endl;
	this->get_input(_name, name_len, true);
	cout << "The account was entered successfully, so please enter your password next." << endl;
	this->get_input(_password, pasword_len, true);
	cout << "The password was entered successfully, so please enter the payment password." << endl;
	this->get_input(_payPasword, payPasword_len, false);
	cout << "The payment password was entered successfully." << endl;
	if ((return_num = serve.consumerSystem(log_reg, _name, _password, _payPasword, A)) == Reg_fail) {
		system("cls");
		cout << "The user name already exists. Please reenter them all:" << endl;
		goto L1;
	}
	else {	/*if(return_num == Reg_true)*/
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "--The account is registered successfully.-" << endl;
		cout << "--Account name: ";
		cout << setw(20) << left << _name << "    --" << endl;
		cout << "--Account password: ******************  --" << endl;
		cout << "--Account payment password: ******      --" << endl;
		cout << "--Account type:   Consumer              --" << endl;
		cout << "------------------------------------------" << endl;
		return true;
	}
}

bool Client::applyC_log(Server& serve, int log_reg, Consumer& A)
{
	system("cls");
	unsigned int i = 0, return_num;
	string _name, _password, useless;
	cout << "**********************************************" << endl;
	cout << "*Please input your account name and password!*" << endl;
	cout << "**********************************************" << endl;
	cout << "Now you need to enter the name first." << endl;
	this->get_input(_name, name_len, true);
	cout << "The account was entered successfully, so please enter your password next." << endl;
	this->get_input(_password, pasword_len, true);
	system("cls");
L5:
	return_num = serve.consumerSystem(log_reg, _name, _password, useless, A);
	if (return_num == Log_true) {
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "--          Login successfully.         --" << endl;
		cout << "--Account name: ";
		cout << setw(20) << left << _name << "    --" << endl;
		cout << "--Account password: ******************  --" << endl;
		cout << "--Account payment password: ******      --" << endl;
		cout << "--Account type:   Consumer              --" << endl;
		cout << "------------------------------------------" << endl;
		return true;
	}
	else if (i == 5 && return_num == Log_fail) {
		system("cls");
		cout << "Reach the maximum number of attempts." << endl;
		system("pause");
		return false;
	}
	else if (i < 5 && return_num == Log_fail) {
		cout << "Your password is wrong. Please reenter:" << endl;
		this->get_input(_password, pasword_len, true);
		i++;
		goto L5;
	}
	else {  //if (return_num == Log_noName)
		system("cls");
		cout << "Your name is not found." << endl;
		system("pause");
		return false;
	}
}

void Client::applyC_service(Server& serve, Consumer& A)
{
	unsigned int service_type;
L6:
	cout << "****************************************" << endl;
	cout << "* The following choices for you:       *" << endl;
	cout << "*  input 1 : check the balance;        *" << endl;
	cout << "*  input 2 : recharge money;           *" << endl;
	cout << "*  input 3 : consume goods;            *" << endl;
	cout << "*  input 4 : change the password;      *" << endl;
	cout << "*  input 5 : show you all products;    *" << endl;
	cout << "*  input 6 : search for your favorites;*" << endl;
	cout << "*  input 7 : withdrawal;               *" << endl;
	cout << "*  input 8 : shopping cart service;    *" << endl;
	cout << "*  input 9 : View all orders;          *" << endl;
	cout << "*  input 0 : logout.                   *" << endl;
	cout << "****************************************" << endl;
	this->getUnsignedInt(service_type);
	while (service_type < 0 || service_type > 10) {
		cout << "Your input is wrong. Please reenter:" << endl;
		this->getUnsignedInt(service_type);
	}system("cls");
	switch (service_type) {
	case 0: {
		this->applyC_logout(serve, A, service_type);
		return;
		break;
	}
	case 1: {
		this->applyC_checkbalance(serve, A, service_type);
		break;
	}
	case 2: {
		this->applyC_rechargeMoney(serve, A, service_type);
		break;
	}
	case 3: {
		this->applyC_consumeGoods(serve, A, service_type);
		break;
	}
	case 4: {
		this->applyC_changePassword(serve, A, service_type);
		break;
	}
	case 5: {
		this->viewAllProducts(serve);
		break;
	}
	case 6: {
		this->applyC_search(serve, A, service_type);
		break;
	}
	case 7: {
		this->applyC_withdrawal(serve, A, service_type);
		break;
	}
	case 8: {
		this->applyC_shopCartService(serve, A, service_type);
		break;
	}
	case 9: {
		this->applyC_viewOrder(serve, A);
		break;
	}
	default: {
		cout << "WRONG SERVICE TYPE." << endl;
		system("pause");
		system("cls");
		break;
	}
	}
	goto L6;
}

void Client::applyC_checkbalance(Server& serve, Consumer& A, unsigned int service_type)
{
	double useless = 0;
	if (serve.consumerSystemService(service_type, A, useless, "", "", "", 0, 0, 0) == Check_true)
		cout << "Your balance is " << A.get_balance() << " yuan left." << endl;
	else
		cout << "Check balance service failed." << endl;
	system("pause");
}

void Client::applyC_rechargeMoney(Server& serve, Consumer& A, unsigned int service_type)
{
	double recharge_mon;
	string payPasword;
	unsigned int i = 0, service_return = 0;
	cout << "Please input your recharge amount :" << endl;
	this->getDouble(recharge_mon);
	while (recharge_mon <= 0) {
		cout << "Your input is wrong, please reenter: " << endl;
		this->getDouble(recharge_mon);
	}
	cout << "Please input your pay_password :" << endl;
	this->get_input(payPasword, payPasword_len, false);
	service_return = serve.consumerSystemService(service_type, A, recharge_mon, payPasword, "", "", 0, 0, 0);
	while (true) {
		if (service_return == Recharge_true) {
			system("cls");
			cout << "Recharge service succeeded." << endl;
			break;
		}
		else if (service_return == Recharge_fail && i < 5) {
			cout << "Your pay_password is wrong." << endl;
			cout << "Do you want to continue?(yes or Yes to continue, else to exit)" << endl;
			string in;
			this->get_input(in, 100, true);
			if (in == "yes" || in == "Yes") {
				cout << "Please reenter the payment password:" << endl;
				this->get_input(payPasword, payPasword_len, false);
				service_return = serve.consumerSystemService(service_type, A, recharge_mon, payPasword, "", "", 0, 0, 0);
			}
			else {
				system("cls");
				cout << "Recharge service failed." << endl;
				break;
			}
			i++;
		}
		else if (service_return == Recharge_fail && i == 5) {
			system("cls");
			cout << "Input limit reached. Recharge service failed." << endl;
			break;
		}
	}
}

void Client::applyC_withdrawal(Server& serve, Consumer& A, unsigned int service_type)
{
	double withdraw_mon;
	string payPasword;
	unsigned int i = 0, service_return = 0;
	cout << "Please input your amount of withdrawal:" << endl;
	this->getDouble(withdraw_mon);
	while (withdraw_mon <= 0) {
		cout << "Your input is wrong, please reenter: " << endl;
		this->getDouble(withdraw_mon);
	}
	cout << "Please input your pay_password :" << endl;
	this->get_input(payPasword, payPasword_len, false);
	service_return = serve.consumerSystemService(service_type, A, withdraw_mon, payPasword, "", "", 0, 0, 0);
	while (true) {
		if (service_return == WithdrawTrue) {
			system("cls");
			cout << "Withdrawal service succeeded." << endl;
			break;
		}
		else if (service_return == WithdrawNoEgh) {
			system("cls");
			cout << "Your balance is not enough. Withdrawal service is failed." << endl;
			break;
		}
		else if (service_return == WithdrawFail && i < 5) {
			cout << "Your pay_password is wrong." << endl;
			cout << "Do you want to continue?(yes or Yes to continue, else to exit)" << endl;
			string in;
			this->get_input(in, 100, true);
			if (in == "yes" || in == "Yes") {
				cout << "Please reenter the payment password:" << endl;
				this->get_input(payPasword, payPasword_len, false);
				service_return = serve.consumerSystemService(service_type, A, withdraw_mon, payPasword, "", "", 0, 0, 0);
			}
			else {
				system("cls");
				cout << "Withdrawal service failed." << endl;
				break;
			}
			i++;
		}
		else if (service_return == WithdrawFail && i == 5) {
			system("cls");
			cout << "Input limit reached. Recharge service failed." << endl;
			break;
		}
	}
}

void Client::applyC_consumeGoods(Server& serve, Consumer& A, unsigned int service_type)
{
	unsigned int type = 0, order = -1, quantity = -1, k = 0, service_return;
	double totalPrice = 0, useless;
	type = (this->viewGoods(serve));
	if (type == WrongOrder) {
		cout << "Consume failed." << endl;
		return;
	}
	cout << "Now please input the order number of the product :" << endl;
	this->getUnsignedInt(order);
	while (order >= INT_MAX) {
		cout << "Wrong order! Please reenter :" << endl;
		this->getUnsignedInt(order);
	}
	cout << "Now please input the purchase quantity :          " << endl;
	cout << "ATTENTION: quantity need to fewer than 1000.      " << endl;
	this->getUnsignedInt(quantity);
	while (quantity <= 0 || quantity >= 1000) {
		cout << "Your quantity input is wrong. Please renter the quantity: " << endl;
		this->getUnsignedInt(quantity);
	}
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*  input 1: add into the shopping cart;     *" << endl;
	cout << "*  input 2: generate an order;              *" << endl;
	cout << "*********************************************" << endl;
	unsigned int conChoice = 0;
	this->getUnsignedInt(conChoice);
	while (conChoice != 1 && conChoice != 2) {
		cout << "Wrong input. please reenter: " << endl;
		this->getUnsignedInt(conChoice);
	}
	conChoice += 20;
	if (conChoice == 21) {
		service_return = serve.consumerSystemService(AddIntoCart, A, useless, "", "", "", type, quantity, order);
		system("cls");
		if (service_return == AddCartTrue)
			cout << "-----Add an item into cart successfully-----" << endl;
		else if (service_return == AddCartNoNum)
			cout << "----Add failed, because no enough number----" << endl;
		else if (service_return == AddCartNotFind)
			cout << "--Add failed, because can't find the goods--" << endl;
		else // service_return == AddCartRepeat
			cout << "-Add failed, because the goods already exist-" << endl;
	}
	else if (conChoice == 22) {
		applyC_generaOrder(serve, A, type, quantity, order);
	}
}

void Client::applyC_changePassword(Server& serve, Consumer& A, unsigned int service_type)
{
	double useless1 = 0;
	unsigned int service_return = 0;
	string origin_pasWord, new_pasWord;
	cout << "Please input the original password:" << endl;
	this->get_input(origin_pasWord, pasword_len, true);
	cout << "Please input the new password:" << endl;
	this->get_input(new_pasWord, pasword_len, true);
	service_return = serve.consumerSystemService(service_type, A, useless1, "", origin_pasWord, new_pasWord, 0, 0, 0);
	while (true) {
		if (service_return == Change_PW_true) {
			system("cls");
			cout << "Change password successfully." << endl;
			break;
		}
		else if (service_return == Change_PW_same) {
			cout << "The new password is the same as the original one, please reenter the new one:" << endl;
			this->get_input(new_pasWord, pasword_len, true);
			service_return = serve.consumerSystemService(service_type, A, useless1, "", origin_pasWord, new_pasWord, 0, 0, 0);
		}
		else if (service_return == Change_PW_fail) {
			cout << "Your original password is wrong. Please reenter them:" << endl;
			cout << "Do you want to continue ? yes or Yes to continue, else to exit." << endl;
			string in;
			this->get_input(in, 100, true);
			while (true) {
				system("cls");
				if (in == "yes" || in == "Yes") {
					cout << "Then, please reenter them:" << endl;
					cout << "Please input the original password:" << endl;
					this->get_input(origin_pasWord, pasword_len, true);
					cout << "Please input the new password:" << endl;
					this->get_input(new_pasWord, pasword_len, true);
					service_return = serve.consumerSystemService(service_type, A, useless1, "", origin_pasWord, new_pasWord, 0, 0, 0);
					break;
				}
				else {
					system("cls");
					cout << "Abandon modification." << endl;
					return;
				}
			}
		}
	}
}

void Client::applyC_search(Server& serve, Consumer& A, unsigned int service_type)
{
	unsigned int searchType = 0;
	cout << "-------------------------------------------------" << endl;
	cout << "If you want to search by category please enter 1," << endl;
	cout << "or if you want to search by price please enter 2," << endl;
	cout << "or if you want to search by name  please enter 3." << endl;
	cout << "-------------------------------------------------" << endl;
	this->getUnsignedInt(searchType);
	while (searchType != 1 && searchType != 2 && searchType != 3) {
		cout << "Your input is wrong, please reenter:" << endl;
		this->getUnsignedInt(searchType);
	}
	system("cls");
	switch (searchType) {
	case 1: {
		if (this->viewGoods(serve))
			cout << "The search service is successful." << endl;
		else
			cout << "The search service is failed." << endl;
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		if (this->Update_member(serve)) {
			double min = 0, max = 0;
			cout << "-------------------------------------------------------------" << endl;
			cout << "---            Please input your ideal price :            ---" << endl;
			cout << "-(the lowest price is before and the highest price is after)-" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "Please input the lowest price :" << endl;
			this->getDouble(min);
			cout << "Please input the highest price :" << endl;
			this->getDouble(max);
			while (min < 0 || min > max) {
				cout << "Your input is wrong, please reenter them:" << endl;
				cout << "Please input the lowest price :" << endl;
				this->getDouble(min);
				cout << "Please input the highest price :" << endl;
				this->getDouble(max);
			}system("cls");
			for (unsigned int i = 0; i < books.size(); i++) {
				if (books[i].getPrice(zero) >= min && books[i].getPrice(zero) <= max)
					books[i].outputGood();
			}
			for (unsigned int i = 0; i < clothes.size(); i++) {
				if (clothes[i].getPrice(zero) >= min && clothes[i].getPrice(zero) <= max)
					clothes[i].outputGood();
			}
			for (unsigned int i = 0; i < eleProducts.size(); i++) {
				if (eleProducts[i].getPrice(zero) >= min && eleProducts[i].getPrice(zero) <= max)
					eleProducts[i].outputGood();
			}
			cout << "The search service is successful." << endl;
		}
		else
			cout << "The search service is failed." << endl;
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		if (this->Update_member(serve)) {
			cout << "The data is updated successfully." << endl;
			string in_name;
			cout << "Please input the name you want to search: " << endl;
			getline(cin, in_name);
			for (unsigned int i = 0; i < books.size(); i++) {
				if (books[i].getName().find(in_name) != books[i].getName().npos || books[i].getDescribe().find(in_name) != books[i].getName().npos)
					books[i].outputGood();
			}
			for (unsigned int i = 0; i < clothes.size(); i++) {
				if (clothes[i].getName().find(in_name) != clothes[i].getName().npos || clothes[i].getDescribe().find(in_name) != clothes[i].getName().npos)
					clothes[i].outputGood();
			}
			for (unsigned int i = 0; i < eleProducts.size(); i++) {
				if (eleProducts[i].getName().find(in_name) != eleProducts[i].getName().npos || eleProducts[i].getDescribe().find(in_name) != eleProducts[i].getName().npos)
					eleProducts[i].outputGood();
			}
			cout << "The search service is successful." << endl;
		}
		else
			cout << "The search service is failed." << endl;
		system("pause");
		system("cls");
		break;
	}
	default:
		break;
	}
}

void Client::applyC_logout(Server& serve, Consumer& A, unsigned int service_type)
{
	double useless = 0;
	if (serve.consumerSystemService(service_type, A, useless, "", "", "", 0, 0, 0) == LogoutSave)
		cout << "Logout successfully." << endl;
	else // service_return == LogoutFail
		cout << "Can't open the files." << endl;
	system("pause");
}

void Client::applyC_shopCartService(Server& serve, Consumer& A, unsigned int service_type)
{
	system("cls");
	unsigned int cType = 0, cOrder = 0, cNum = 0, service_return;
	service_return = this->viewShopCarts(serve, A.get_name(), cType, cOrder, cNum);
	if (service_return == ViewCartTrue)
		cout << "View all items in the cart successfully." << endl;
	else if (service_return == ViewCartBuy) {
		applyC_generaOrder(serve, A, cType, cNum, cOrder);
	}
	else if (service_return == ViewCartDelete) {
		double useless = 0;
		service_return = serve.consumerSystemService(DeleteACart, A, useless, "", "", "", cType, 0, cOrder);
		if (service_return == DeleteCartTrue)
			cout << "Delete an item successfully.    " << endl;
		else if (service_return == DeleteCartNotFind)
			cout << "Can't find the commodity.       " << endl;
		else // service_return == DeleteCartNoName
			cout << "You didn't have a shopping cart." << endl;
	}
	else if (service_return == ViewCartModify) {
		double useless = 0;
		unsigned int num;
		cout << "Please input the goods number:" << endl;
		this->getUnsignedInt(num);
		service_return = serve.consumerSystemService(ModifyACart, A, useless, "", "", "", cType, num, cOrder);
		if (service_return == ModifyCartTrue)
			cout << "Modify an item in the cart successfully." << endl;
		else if (service_return == ModifyCartNoEgh)
			cout << "Modify failed, because no enough number." << endl;
		else if (service_return == ModifyCartNotFind)
			cout << "Modify failed, because can't find the goods." << endl;
		else // service_return == ModifyCartNoName
			cout << "Modify failed. Can't find your shopping cart." << endl;
	}
	else // service_return == WrongOrder;
		cout << "View all items in the cart failed.      " << endl;
}

void Client::applyC_generaOrder(Server& serve, Consumer& A, unsigned int cType, unsigned int cNum, unsigned int cOrder)
{
	double totalPrice = 0;
	unsigned int service_return;
	service_return = serve.consumerSystemService(GeneraOrder, A, totalPrice, "", "", "", cType, cNum, cOrder);
	if (service_return == GeneraOrderTrue) {
		system("cls");
		cout << "---------------------------------" << endl;
		cout << "-Generate an order successfully.-" << endl;
		cout << "-Pay now: 1   ||   Pay later: 2 -" << endl;
		cout << "---------------------------------" << endl;
		unsigned int pay_choose;
		this->getUnsignedInt(pay_choose);
		while (pay_choose != 1 && pay_choose != 2) {
			cout << "Your input is wrong. Please reenter: " << endl;
			this->getUnsignedInt(pay_choose);
		}
		system("cls");
		if (pay_choose == 1) {
			applyC_payForOrder(serve, A, cType, cNum, cOrder);
		}
		else if (pay_choose == 2) {
			cout << "Your need to pay for the order later." << endl;
		}
		else;
	}
	else {// service_return == WrongOrder | GeneraOrderFail | GeneraOrderNoEgh
		cout << "                Generate an order failed.                " << endl;
		cout << "Because can't find the goods or the number is not enough." << endl;
	}
}

bool Client::applyC_payForOrder(Server& serve, Consumer& A, unsigned int type, unsigned int num, unsigned int order)
{
	string pay_password;
	unsigned int service_return;
	double useless, totalPrice = 0, k = 0;
	cout << "Please input your pay_password." << endl;
	this->get_input(pay_password, payPasword_len, false);
	while ((service_return = serve.consumerSystemService(PaywordCheck, A, useless, pay_password, "", "", 0, 0, 0))
		== ConPaywordFail && k < 5) {
		system("cls");
		cout << "Your pay password is wrong, please reenter: (" << 4 - k << " chances left)" << endl;
		++k;
		this->get_input(pay_password, payPasword_len, false);
		service_return = serve.consumerSystemService(PaywordCheck, A, useless, pay_password, "", "", 0, 0, 0);
		if (k == 5 && service_return == ConPaywordFail) {
			system("cls");
			cout << "The maximum number of attempts reached." << endl;
			return false;
		}
	}system("cls");
	service_return = serve.consumerSystemService(3, A, totalPrice, "", "", "", type, num, order);//相当于只是付款
	cout << "The total price of the commodity is " << totalPrice << " yuan." << endl;
	if (service_return == Consume_true) { //付款成功
		service_return = serve.consumerSystemService(PayTrue, A, useless, "", "", "", type, num, order);
		cout << "Consume successfully." << endl;
		return true;
	}
	else { // 订单支付失败
		if (service_return == Consume_NObalance)
			cout << "Your balance is insufficient." << endl;
		else if (service_return == Consume_NOorder) {
			system("cls");
			cout << "Consume failed. Can't find the order number." << endl;
		}
		service_return = serve.consumerSystemService(PayFail, A, useless, "", "", "", type, num, order);
		return false;
	}
}

void Client::applyC_viewOrder(Server& serve, Consumer& A)
{
	int count = 0;
	unsigned choose;
	if (this->Update_member(serve) == true)
		cout << "The data update is successful." << endl;
	else {
		cout << "The data update is failed.    " << endl;
		return;
	}
	cout << "-----------------------------------------" << endl;
	cout << "--View history: 1    ||   View unpay: 2--" << endl;
	cout << "-----------------------------------------" << endl;
	getUnsignedInt(choose);
	while (choose != 1 && choose != 2) {
		cout << "Wrong input! Please reenter:" << endl;
		getUnsignedInt(choose);
	}
	if (choose == 2)
	{
		for (unsigned int i = 0; i < unpay_orders.size(); i++) {
			if (unpay_orders[i].get_name() == A.get_name()) {
				count++;
				applyC_findOrderGood(i);
				unsigned int choice;
				this->getUnsignedInt(choice);
				while (choice <= 0 || choice >= 5) {
					cout << "Wrong input! Please reenter: " << endl;
					this->getUnsignedInt(choice);
				}
				system("cls");
				if (choice == 1)
					continue;
				if (choice == 2)
					break;
				if (choice == 3) {
					applyC_payForOrder(serve, A, unpay_orders[i].get_type(), unpay_orders[i].get_number(), unpay_orders[i].get_order());
					break;
				}
				if (choice == 4) {
					double useless;
					unsigned int service_return = serve.consumerSystemService(DeleteOrder, A, useless, "", "", "", unpay_orders[i].get_type(), unpay_orders[i].get_number(), unpay_orders[i].get_order());
					if (service_return == 1)
						cout << "Delete order successfully." << endl;
					else
						cout << "Delete order is failed." << endl;
				}
			}
		}
	}
	else {//查看历史订单
		for (unsigned i = 0; i < all_orders.size(); i++) {
			if (all_orders[i].get_name() == A.get_name()) {
				count++;
				applyC_view_historyOrder(i);
				unsigned int choice;
				this->getUnsignedInt(choice);
				while (choice <= 0 || choice >= 3) {
					cout << "Wrong input! Please reenter: " << endl;
					this->getUnsignedInt(choice);
				}
				system("cls");
				if (choice == 1)
					continue;
				if (choice == 2)
					break;
			}
		}
	}
	system("cls");
	if (count == 0)cout << "You have no orders." << endl;
	else cout << "View orders successfully." << endl;
}

void Client::applyC_view_historyOrder(unsigned int temp)
{
	cout << all_orders[temp].get_name() << "'s order:" << endl;
	char tmp[64];
	time_t time_now = all_orders[temp].get_time();
	struct tm t;
	localtime_s(&t, &time_now);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d-%H:%M:%S", &t);
	if (all_orders[temp].get_type() == 1) {
		for (unsigned int i = 0; i < books.size(); i++) {
			if (all_orders[temp].get_order() == books[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Book" << endl;
				cout << "--name:   " << setw(33) << left << books[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << all_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << all_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << all_orders[temp].get_totalPrice() << endl;
				if (all_orders[temp].get_state() == 1)
					cout << "--status: True                             " << endl;
				else
					cout << "--status: False                            " << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				break;
			}
		}
	}
	if (all_orders[temp].get_type() == 2) {
		for (unsigned int i = 0; i < clothes.size(); i++) {
			if (all_orders[temp].get_order() == clothes[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Cloth" << endl;
				cout << "--name:   " << setw(33) << left << clothes[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << all_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << all_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << all_orders[temp].get_totalPrice() << endl;
				if (all_orders[temp].get_state() == 1)
					cout << "--status: True                             " << endl;
				else
					cout << "--status: False                            " << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				break;
			}
		}
	}
	if (all_orders[temp].get_type() == 3) {
		for (unsigned int i = 0; i < eleProducts.size(); i++) {
			if (all_orders[temp].get_order() == eleProducts[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Electronic product" << endl;
				cout << "--name:   " << setw(33) << left << eleProducts[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << all_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << all_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << all_orders[temp].get_totalPrice() << endl;
				if (all_orders[temp].get_state() == 1)
					cout << "--status: True                             " << endl;
				else
					cout << "--status: False                            " << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				break;
			}
		}
	}
}

void Client::applyC_findOrderGood(unsigned int temp)
{
	char tmp[64];
	time_t time_now = unpay_orders[temp].get_time();
	struct tm t;
	localtime_s(&t, &time_now);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d-%H:%M:%S", &t);
	cout << unpay_orders[temp].get_name() << "'s order:" << endl;
	if (unpay_orders[temp].get_type() == 1) {
		for (unsigned int i = 0; i < books.size(); i++) {
			if (unpay_orders[temp].get_order() == books[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Book" << endl;
				cout << "--name:   " << setw(33) << left << books[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << unpay_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << unpay_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << unpay_orders[temp].get_totalPrice() << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				cout << "Pay for order: 3   ||   Delete the order: 4" << endl;
				break;
			}
		}
	}
	if (unpay_orders[temp].get_type() == 2) {
		for (unsigned int i = 0; i < clothes.size(); i++) {
			if (unpay_orders[temp].get_order() == clothes[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Cloth" << endl;
				cout << "--name:   " << setw(33) << left << clothes[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << unpay_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << unpay_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << unpay_orders[temp].get_totalPrice() << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				cout << "Pay for order: 3   ||   Delete the order: 4" << endl;
				break;
			}
		}
	}
	if (unpay_orders[temp].get_type() == 3) {
		for (unsigned int i = 0; i < eleProducts.size(); i++) {
			if (unpay_orders[temp].get_order() == eleProducts[i].get_order()) {
				cout << "-------------------------------------------" << endl;
				cout << "--type:   " << setw(33) << left << "Electronic product" << endl;
				cout << "--name:   " << setw(33) << left << eleProducts[i].getName() << endl;
				cout << "--order:  " << setw(33) << left << unpay_orders[temp].get_order() << endl;
				cout << "--number: " << setw(33) << left << unpay_orders[temp].get_number() << endl;
				cout << "--total price: " << setw(28) << left << unpay_orders[temp].get_totalPrice() << endl;
				cout << "--time:   " << setw(33) << left << tmp << endl;
				cout << "-------------------------------------------" << endl;
				cout << "Next one: 1        ||       End the view: 2" << endl;
				cout << "Pay for order: 3   ||   Delete the order: 4" << endl;
				break;
			}
		}
	}
}

void Client::applyB_log_reg(Server& serve)
{
	Businessman A;
	int log_reg;
	system("cls");
	cout << "-------------------------------------------------------" << endl;
	cout << " If you want to login your account, please input 0, " << endl
		<< " if you want to register a new account, please input 1:" << endl;
	cout << "-------------------------------------------------------" << endl;
	this->getInt(log_reg);
	while (log_reg != 0 && log_reg != 1) {
		cout << "Your input is wrong. Please reenter:" << endl;
		this->getInt(log_reg);
	}
	switch (log_reg) {
	case 0:
		if (this->applyB_log(serve, log_reg, A))
			this->applyB_service(serve, A);
		break;
	case 1:
		if (this->applyB_reg(serve, log_reg, A))
			this->applyB_service(serve, A);
		break;
	default:
		break;
	}
}

bool Client::applyB_reg(Server& serve, int log_reg, Businessman& A)
{
	system("cls");
	string _name, _password;
	unsigned int return_num;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "-- Please input your account name(with in 12 characters),                                  --" << endl;
	cout << "-- password(within 18 characters)!                                                         --" << endl;
	cout << "-- ATTENTION: Boht of them can't include space, only letters and numbers can be included. --" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
L2:
	cout << "Now you need to enter the name first." << endl;
	this->get_input(_name, name_len, true);
	cout << "The account was entered successfully, so please enter your password next." << endl;
	this->get_input(_password, pasword_len, true);
	system("cls");
	if ((return_num = serve.businessmanSystem(log_reg, _name, _password, A)) == Reg_fail) {
		system("cls");
		cout << "The user name already exists. Please reenter both them:" << endl;
		goto L2;
	}
	else {//if(return_num == Reg_true)
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "--The account is registered successfully.-" << endl;
		cout << "--Account name: ";
		cout << setw(20) << left << _name << "    --" << endl;
		cout << "--Account password: ******************  --" << endl;
		cout << "--Account type:   Businessman           --" << endl;
		cout << "------------------------------------------" << endl;
		return true;
	}
}

bool Client::applyB_log(Server& serve, int log_reg, Businessman& A)
{
	system("cls");
	unsigned int i = 0, return_num;
	string _name, _password;
	cout << "**********************************************" << endl;
	cout << "*Please input your account name and password!*" << endl;
	cout << "**********************************************" << endl;
	cout << "Now you need to enter the name first." << endl;
	this->get_input(_name, name_len, true);
	cout << "The account was entered successfully, so please enter your password next." << endl;
	this->get_input(_password, pasword_len, true);
	system("cls");
L5:
	return_num = serve.businessmanSystem(log_reg, _name, _password, A);
	if (return_num == Log_true) {
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "--          Login successfully.         --" << endl;
		cout << "--Account name: ";
		cout << setw(20) << left << _name << "    --" << endl;
		cout << "--Account password: ******************  --" << endl;
		cout << "--Account type:   Businessman           --" << endl;
		cout << "------------------------------------------" << endl;
		return true;
	}
	else if (i == 5 && return_num == Log_fail) {
		system("cls");
		cout << "Reach the maximum number of attempts." << endl;
		system("pause");
		return false;
	}
	else if (i < 5 && return_num == Log_fail) {
		cout << "Your password is wrong. Please reenter:" << endl;
		this->get_input(_password, pasword_len, true);
		i++;
		goto L5;
	}
	else {  //if (return_num == Log_noName)
		system("cls");
		cout << "Your name is not found." << endl;
		system("pause");
		return false;
	}
}

void Client::applyB_service(Server& serve, Businessman& A)
{
	unsigned int service_type, service_return = 0;
L6:
	cout << "***********************************************" << endl;
	cout << "*The following choices for you:               *" << endl;
	cout << "* input 1 : check the balance;                *" << endl;
	cout << "* input 2 : change the password;              *" << endl;
	cout << "* input 3 : add new commodity;                *" << endl;
	cout << "* input 4 : discount activities;              *" << endl;
	cout << "* input 5 : modify the price;                 *" << endl;
	cout << "* input 6 : modify the remain number;         *" << endl;
	cout << "* input 7 : show you all products;            *" << endl;
	cout << "* input 8 : withdrawal;                       *" << endl;
	cout << "* input 0 : logout.                           *" << endl;
	cout << "***********************************************" << endl;
	this->getUnsignedInt(service_type);
	while (service_type < 0 || service_type > 8) {
		cout << "Your input is wrong. Please reenter:" << endl;
		this->getUnsignedInt(service_type);
	}system("cls");
	switch (service_type) {
	case 0: {
		this->applyB_logout(serve, A, service_type);
		return;
		break;
	}
	case 1: {
		this->applyB_checkBalance(serve, A, service_type);
		break;
	}
	case 2: {
		this->applyB_changePassword(serve, A, service_type);
		break;
	}
	case 3: {
		this->applyB_addNewGoods(serve, A, service_type);
		break;
	}
	case 4: {
		this->applyB_discount(serve, A, service_type);
		break;
	}
	case 5: {
		this->applyB_modifyPrice(serve, A, service_type);
		break;
	}
	case 6: {
		this->applyB_modifyRemainNum(serve, A, service_type);
		break;
	}
	case 7: {
		this->viewAllProducts(serve);
		break;
	}
	case 8: {
		this->applyB_withdrawal(serve, A, service_type);
		break;
	}
	}goto L6;
}

void Client::applyB_logout(Server& serve, Businessman& A, unsigned int service_type)
{
	if (serve.businessmanSystemService(service_type, A, "", "", 0, 0, 0, "", ""))
		cout << "Logout successfully." << endl;
	else // service_return == LogoutFail
		cout << "Can't open the files." << endl;
	system("pause");
}

void Client::applyB_checkBalance(Server& serve, Businessman& A, unsigned int service_type)
{
	if (serve.businessmanSystemService(service_type, A, "", "", 0, 0, 0, "", "") == Check_true)
		cout << "Your balance is " << A.get_balance() << " yuan left." << endl;
	else
		cout << "Check balance service failed." << endl;
}

void Client::applyB_changePassword(Server& serve, Businessman& A, unsigned int service_type)
{
	unsigned int service_return = 0;
	string origin_pasWord, new_pasWord;
	cout << "Please input the original password:" << endl;
	this->get_input(origin_pasWord, pasword_len, true);
	cout << "Please input the new password:" << endl;
	this->get_input(new_pasWord, pasword_len, true);
	service_return = serve.businessmanSystemService(service_type, A, origin_pasWord, new_pasWord, 0, 0, 0, "", "");
	while (true) {
		if (service_return == Change_PW_true) {
			system("cls");
			cout << "Change password successfully." << endl;
			break;
		}
		else if (service_return == Change_PW_same) {
			cout << "The new password is the same as the original one, please reenter the new one:" << endl;
			this->get_input(new_pasWord, pasword_len, true);
			service_return = serve.businessmanSystemService(service_type, A, origin_pasWord, new_pasWord, 0, 0, 0, "", "");
		}
		else if (service_return == Change_PW_fail) {
			cout << "Your original password is wrong. Please reenter them:" << endl;
			cout << "Do you want to continue ? yes or Yes to continue, else to exit." << endl;
			string in;
			this->get_input(in, 100, true);
			while (true) {
				system("cls");
				if (in == "yes" || in == "Yes") {
					cout << "Then, please reenter them:" << endl;
					cout << "Please input the original password:" << endl;
					this->get_input(origin_pasWord, pasword_len, true);
					cout << "Please input the new password:" << endl;
					this->get_input(new_pasWord, pasword_len, true);
					service_return = serve.businessmanSystemService(service_type, A, origin_pasWord, new_pasWord, 0, 0, 0, "", "");
					break;
				}
				else {
					system("cls");
					cout << "Abandon modification." << endl;
					return;
				}
			}
		}
	}
}

void Client::applyB_addNewGoods(Server& serve, Businessman& A, unsigned int service_type)
{
	string _name, _describe;
	double _price;
	unsigned int _remain_num, service_return;
	int _type;
	cout << "Please input the name of your commodity (within 20 characters):" << endl;
	getline(cin, _name);
	while (_name.size() == 0 || _name.size() > com_name_len) {
		cout << "The name length doesn't meet the request. Please reenter:" << endl;
		getline(cin, _name);
	}
	cout << "Please input the description of your commodity (with in 200 characters)" << endl;
	getline(cin, _describe);
	while (_describe.size() == 0 || _describe.size() > describe_len) {
		cout << "The description length doesn't meet the request. Please reenter:" << endl;
		getline(cin, _describe);
	}
	cout << "Please input the price :" << endl;
	this->getDouble(_price);
	while (_price <= 0 || _price >= INT_MAX) {
		cout << "Wrong input price. Please reenter: " << endl;
		this->getDouble(_price);
	}
	cout << "Please input the remain number :" << endl;
	this->getUnsignedInt(_remain_num);
	while (_remain_num == 0 || _remain_num > INT_MAX) {
		cout << "Wrong input remain number. Please reenter:" << endl;
		this->getUnsignedInt(_remain_num);
	}
	cout << "Please input the type of your product: " << endl;
	cout << "1 for Book; 2 for cloth; 3 for electronic product." << endl;
	this->getInt(_type);
	while (_type != 1 && _type != 2 && _type != 3) {
		cout << "Your input is wrong. Please reenter: " << endl;
		this->getInt(_type);
	}system("cls");
	if ((service_return = serve.businessmanSystemService(service_type, A, "", "",
		_type, _price, _remain_num, _name, _describe)) == Add_good_true)
		cout << "Add new product service successfully." << endl;
	else  //if(service_return == Add_good_fail)
		cout << "Add product failed." << endl;
}

void Client::applyB_discount(Server& serve, Businessman& A, unsigned int service_type)
{
	unsigned int service_return;
	int discount_type = 0;
	double discount = 1;
	cout << "Please input which product type you want to discount:" << endl;
	cout << "1 for book; 2 for cloth; 3 for electronic product." << endl;
	this->getInt(discount_type);
	while (discount_type != 1 && discount_type != 2 && discount_type != 3) {
		cout << "Your discount_type input wrong, please reenter:" << endl;
		this->getInt(discount_type);
	}
	cout << "Please input the discount: (less than 1)" << endl;
	this->getDouble(discount);
	while (discount <= 0 || discount >= 1) {
		cout << "Your discount input wrong, please reenter:" << endl;
		this->getDouble(discount);
	}system("cls");
	if ((service_return = serve.businessmanSystemService(service_type, A, "", "",
		discount_type, discount, 0, "", "")) == Discount_true)
		cout << "The discount service succeeded." << endl;
	else //if(service_return == Discount_fail)
		cout << "The discount service failed." << endl;
}

void Client::applyB_modifyPrice(Server& serve, Businessman& A, unsigned int service_type)
{
	if (this->Update_member(serve))
	{
		int type = 0;
		unsigned num = -1, service_return;
		double price = 0;
		cout << "What kind of product do you want to modify?" << endl;
		cout << "Please input your choice: 1 for book, 2 for cloth, 3 for electronic product." << endl;
		this->getInt(type);
		while (type != 1 && type != 2 && type != 3) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getInt(type);
		}
		switch (type) {
		case 1:
			cout << "The Book part:" << endl;
			for (unsigned int i = 0; i < books.size(); i++) {
				if (books[i].getMerchat_num() == A.get_merchatNum())
					books[i].outputGood();
			}
			break;
		case 2:
			cout << endl << "The Cloth part:" << endl;
			for (unsigned int i = 0; i < clothes.size(); i++) {
				if (clothes[i].getMerchat_num() == A.get_merchatNum())
					clothes[i].outputGood();
			}
			break;
		case 3:
			cout << endl << "The Electronic products part:" << endl;
			for (unsigned int i = 0; i < eleProducts.size(); i++) {
				if (eleProducts[i].getMerchat_num() == A.get_merchatNum())
					eleProducts[i].outputGood();
			}
			break;
		default:
			break;
		}
		cout << "and please input the order number of the product." << endl;
		this->getUnsignedInt(num);
		while (num == -1 || num >= INT_MAX) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getUnsignedInt(num);
		}
		cout << "Please reenter the price:" << endl;
		this->getDouble(price);
		while (price <= 0) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getDouble(price);
		}
		system("cls");
		if ((service_return = serve.businessmanSystemService(service_type, A, "", "",
			type, price, num, "", "") == Modify_Price)) {
			cout << "Modify successfully." << endl;
		}
		else //service_return == Modify_Pfail
			cout << "Modify failed. Can't find the order number." << endl;
	}
	else
		cout << "The data update is failed." << endl;
}

void Client::applyB_modifyRemainNum(Server& serve, Businessman& A, unsigned int service_type)
{
	if (this->Update_member(serve))
	{
		int type = 0;
		unsigned int remain_num = 0, num = -1, service_return;
		cout << "What kind of product do you want to modify?" << endl;
		cout << "Please input your choice: 1 for book, 2 for cloth, 3 for electronic product." << endl;
		this->getInt(type);
		while (type != 1 && type != 2 && type != 3) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getInt(type);
		}
		switch (type) {
		case 1:
			cout << "The Book part:" << endl;
			for (unsigned int i = 0; i < books.size(); i++) {
				if (books[i].getMerchat_num() == A.get_merchatNum())
					books[i].outputGood();
			}
			break;
		case 2:
			cout << endl << "The Cloth part:" << endl;
			for (unsigned int i = 0; i < clothes.size(); i++) {
				if (clothes[i].getMerchat_num() == A.get_merchatNum())
					clothes[i].outputGood();
			}
			break;
		case 3:
			cout << endl << "The Electronic products part:" << endl;
			for (unsigned int i = 0; i < eleProducts.size(); i++) {
				if (eleProducts[i].getMerchat_num() == A.get_merchatNum())
					eleProducts[i].outputGood();
			}
			break;
		default:
			break;
		}
		cout << "and please input the order number of the product." << endl;
		this->getUnsignedInt(num);
		while ((int)num < 0 || num >= INT_MAX) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getUnsignedInt(num);
		}
		cout << "Please reenter the new remain_number:" << endl;
		this->getUnsignedInt(remain_num);
		while ((int)remain_num < 0) {
			cout << "Your input is wrong, please reenter:" << endl;
			this->getUnsignedInt(remain_num);
		}
		system("cls");
		if ((service_return = serve.businessmanSystemService(service_type, A, "", "",
			type, (double)remain_num, num, "", "") == Modify_Remain)) {
			cout << "Modify successfully." << endl;
		}
		else //service_return == Modify_Rfail
			cout << "Modify failed. Can't find the order number." << endl;
	}
	else
		cout << "The data update is failed." << endl;
}

void Client::applyB_withdrawal(Server& serve, Businessman& A, unsigned int service_type)
{
	double withdraw_mon;
	unsigned int i = 0, service_return = 0;
	cout << "Please input your amount of withdrawal:" << endl;
	this->getDouble(withdraw_mon);
	while (withdraw_mon <= 0) {
		cout << "Your input is wrong, please reenter: " << endl;
		this->getDouble(withdraw_mon);
	}
	service_return = serve.businessmanSystemService(service_type, A, "", "", 0, withdraw_mon, 0, "", "");
	if (service_return == WithdrawTrue) {
		system("cls");
		cout << "Withdrawal service succeeded." << endl;
	}
	else {//if (service_return == WithdrawNoEgh)
		system("cls");
		cout << "Your balance is not enough. Withdrawal service is failed." << endl;
	}
}