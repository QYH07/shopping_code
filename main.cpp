#include"global.h"
#include"client.h"
#include"server.h"
using namespace std;

int main(void)
{
	SetConsoleTitle("���̽���ƽ̨");

	Server ser;
	ser.readAllItems();
	ser.readAllUsers();
	ser.readShopCart_Orders();
	ser.judgeFullOrders();

	Client A;
	A.applySystem(ser);
	A.exitOutput();

	system("pause");
	return 0;
}