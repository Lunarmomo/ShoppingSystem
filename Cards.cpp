//Design Pattern Project
//成员：1352910 周同，1452734 储港  
//文件名：Cards.cpp 
//描述：超市购物卡信息类处理 

#include "stdafx.h"
#include "Cards.h"

string Cards::getCardCode()
{
	return card_code;
}
double Cards::getCardMoney()
{
	return card_money;
}
void Cards::setCardCode(string cardCode)
{
	card_code = cardCode;
}
void Cards::setCardMoney(double cardMoney)
{
	card_money = cardMoney;
}

Cards::Cards(void)
{
}
Cards::~Cards(void)
{
}
