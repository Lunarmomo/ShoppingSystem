//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Cards.cpp 
//���������й��￨��Ϣ�ദ�� 

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
