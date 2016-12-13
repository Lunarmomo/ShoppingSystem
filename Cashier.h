//Design Pattern Project
//成员：1352910 周同，1452734 储港  
//文件名：Cashier.h
//描述：收银员类，包含购物车、收取现金数、支付记录等信息，可以计算本次购物总价、本次会员购物总价、打印购物清单等。

#pragma once
#include "ShoppingList.h"
using namespace std;
class Cashier
{
	ShoppingList *s_list; //购物车
	double s_money; //共收取现金数
	string record_text;//支付记录
	
public:
	Cashier(ShoppingList *slist);
	~Cashier();
	double GetTotalMoney();//计算本次购物总价
	double GetTotalMemberMoney(string memType);//计算本次会员购物总价
	double GetSmoney();// 共收取现金
	double Count(double money,string memberType);//收钱找零，money：顾客给的现金，返回给客户零钱
	void PrintList();//打印结算清单，包括购物清单和支付记录
	string GetRecord();
	void setRecord(string record);
	void outputToText();

};
