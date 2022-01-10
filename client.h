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
	bool Update_member(Server& serve);//�������ݣ����Ա������

	void get_input(string& s, unsigned int max, bool sign);//��������Ƿ�Ϸ��������û���������
	void getDouble(double& temp);//���double���������Ƿ�Ϸ�
	void getUnsignedInt(unsigned int& temp);//���unsigned int���������Ƿ�Ϸ�
	void getInt(int& temp);//���int���������Ƿ�Ϸ�

	void viewAllProducts(Server& serve);//�鿴������Ʒ(�ڲ��ȸ�������)
	unsigned int viewShopCarts(Server& serve, string userName, unsigned int& cType, unsigned int& cOrder, unsigned int& cNum);//�鿴���ﳵ(���ȸ���)
	unsigned int viewGoods(Server& serve);//�˿͹���ѡ���У��Ȳ鿴������Ʒ��������Ʒ����
	
	void applySystem(Server& serve);//����������ϵͳ�����̼�ϵͳ
	void applyC_log_reg(Server& serve);//������ϵͳ������Ҫ��¼����ע��
	bool applyC_log(Server& serve, int log_reg, Consumer& A);//������ϵͳ����¼ҳ��
	bool applyC_reg(Server& serve, int log_reg, Consumer& A);//������ϵͳ��ע��ҳ��
	void applyC_service(Server& serve, Consumer& A);//������ϵͳ��ѡ�����

	//�����ǿͻ����������ߵ����з������ͣ�ͨ�����ò�ͬ�ĺ������������͸�������
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
	void applyC_findOrderGood(unsigned int temp);//������applyC_viewOrder,����Ѱ�����������Ϣ

	void applyB_log_reg(Server& serve);//�̼�ϵͳ������Ҫ��¼����ע��
	bool applyB_log(Server& serve, int log_reg, Businessman& A);//�̼�ϵͳ����¼ҳ��
	bool applyB_reg(Server& serve, int log_reg, Businessman& A);//�̼�ϵͳ��ע��ҳ��
	void applyB_service(Server& serve, Businessman& A);//�̼�ϵͳ��ѡ�����

	//�����ǿͻ������̼ҵ����з������ͣ�ͨ�����ò�ͬ�ĺ������������͸�������
	void applyB_checkBalance(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_changePassword(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_addNewGoods(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_discount(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_modifyPrice(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_modifyRemainNum(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_logout(Server& serve, Businessman& A, unsigned int service_type);
	void applyB_withdrawal(Server& serve, Businessman& A, unsigned int service_type);
};

