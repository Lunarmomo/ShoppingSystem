//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Cards.h 
//���������й��￨��Ϣ��

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
