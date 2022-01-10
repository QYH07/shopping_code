#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<vector>
using namespace std;

#define name_len 12
#define com_name_len 20
#define pasword_len 18
#define payPasword_len 6
#define balance_len 10
#define describe_len 200
#define zero 0
#define one 1
#define three 3
#define five 5
#define goodsMAX 5

#define Reg_true 11
#define Reg_fail 10
#define Log_noName 02
#define Log_true   01
#define Log_fail   00

#define Check_true 11
#define Check_fail 10

#define Recharge_true 21
#define Recharge_fail 20

#define Consume_true 311
#define Consume_NObalance 3100
#define Consume_NOgoods 3101
#define Consume_NOorder 3102

#define Change_PW_true 41
#define Change_PW_same 42
#define Change_PW_fail 43

#define View_true 51

#define Search_fail 620

#define ConPaywordTrue 71
#define ConPaywordFail 70

#define Add_good_true 31
#define Add_good_fail 30

#define Discount_true 41
#define Discount_fail 40

#define Modify_Price 51
#define Modify_Pfail 50

#define Modify_Remain 61
#define Modify_Rfail  60

#define LogoutSave 91
#define LogSaveFail 90

#define WithdrawTrue 71
#define WithdrawFail 70
#define WithdrawNoEgh 72

#define WrongOrder 99

//���ڵڶ��⣬�����ﳵ�Ͷ����Ĳ���������ָ������������ʾ�䷵��״̬
//���ﳵ�����Ӧ��������Ʒ�ɹ�
#define AddCartTrue 1111
//���ﳵ�����Ӧ��������Ʒ����ԭ��Ʒ��Ŀ���㣬���ʧ��
#define AddCartNoNum 1110
//���ﳵ�����Ʒ����û���ҵ���Ӧ��Ʒ�����ʧ��
#define AddCartNotFind 1112
//���ﳵ�����Ʒ�����ظ������ʧ��
#define AddCartRepeat 1113


//ɾ�����ﳵĳ��Ʒ�е���Ŀ�ɹ�
#define DeleteCartTrue 2111
//ɾ�����ﳵĳ��Ʒ����δ�ҵ�
#define DeleteCartNotFind 2112
//û���ҵ���Ӧ�Ĺ��ﳵ
#define DeleteCartNoName 2113

//�޸Ĺ��ﳵĳ��Ʒ��Ŀ�ɹ�
#define ModifyCartTrue 3111
//�޸Ĺ��ﳵĳ��Ʒ��Ŀ����δ�ҵ�����Ʒ
#define ModifyCartNotFind 3110
//�޸Ĺ��ﳵĳ��Ʒ��Ŀ��ԭ��Ʒ��Ŀ���㣬�޸�ʧ��
#define ModifyCartNoEgh 3112
//�޸Ĺ��ﳵĳ��Ʒ��Ŀ��û���ҵ���Ӧ���ﳵ
#define ModifyCartNoName 3113

//�鿴���ﳵ�ɹ�
#define ViewCartTrue 4111
//�鿴���ﳵ����ѡ����ĳ��Ʒ����
#define ViewCartBuy 4112
//�鿴���ﳵ����ѡ���Ʒɾ��
#define ViewCartDelete 4113
//�鿴���ﳵ����ѡ��ĳ��Ʒ�޸���Ϣ
#define ViewCartModify 4114

//���ɶ����ɹ�
#define GeneraOrderTrue 5111
//���ɶ���ʧ�ܣ�û���ҵ���Ӧ��Ʒ
#define GeneraOrderFail 5110
//���ɶ���ʧ�ܣ���Ӧ��Ʒ��Ŀ����
#define GeneraOrderNoEgh 5112

//��������
#define OrderTotal 20
//���ɶ�����������
#define GeneraOrder 22
#define PaywordCheck 23
#define PayTrue 33
#define PayFail 34
#define DeleteACart 12
#define ModifyACart 13
#define AddIntoCart 21
#define DeleteOrder 34