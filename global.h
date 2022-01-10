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

//对于第二题，即购物车和订单的操作，设置指定的数字来表示其返回状态
//购物车添加相应数量的商品成功
#define AddCartTrue 1111
//购物车添加相应数量的商品，但原商品数目不足，添加失败
#define AddCartNoNum 1110
//购物车添加商品，但没有找到相应商品，添加失败
#define AddCartNotFind 1112
//购物车添加商品，但重复，添加失败
#define AddCartRepeat 1113


//删除购物车某商品中的数目成功
#define DeleteCartTrue 2111
//删除购物车某商品，但未找到
#define DeleteCartNotFind 2112
//没有找到相应的购物车
#define DeleteCartNoName 2113

//修改购物车某商品数目成功
#define ModifyCartTrue 3111
//修改购物车某商品数目，但未找到该商品
#define ModifyCartNotFind 3110
//修改购物车某商品数目，原商品数目不足，修改失败
#define ModifyCartNoEgh 3112
//修改购物车某商品数目，没有找到对应购物车
#define ModifyCartNoName 3113

//查看购物车成功
#define ViewCartTrue 4111
//查看购物车并且选择了某产品购买
#define ViewCartBuy 4112
//查看购物车并且选择产品删除
#define ViewCartDelete 4113
//查看购物车并且选择某产品修改信息
#define ViewCartModify 4114

//生成订单成功
#define GeneraOrderTrue 5111
//生成订单失败，没有找到相应商品
#define GeneraOrderFail 5110
//生成订单失败，相应商品数目不足
#define GeneraOrderNoEgh 5112

//订单总数
#define OrderTotal 20
//生成订单服务类型
#define GeneraOrder 22
#define PaywordCheck 23
#define PayTrue 33
#define PayFail 34
#define DeleteACart 12
#define ModifyACart 13
#define AddIntoCart 21
#define DeleteOrder 34