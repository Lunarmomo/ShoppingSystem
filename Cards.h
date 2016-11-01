//学号：1352910 
//姓名：周同     
//文件名：Cards.h 
//描述：超市购物卡信息类

#pragma once
#include "stdafx.h"
using namespace std;
class Cards
{
	string card_code;
	double card_money;
public:
	string getCardCode();
	double getCardMoney();
	void setCardCode(string cardCode);
	void setCardMoney(double cardMoney);
	Cards();
	~Cards();
};

