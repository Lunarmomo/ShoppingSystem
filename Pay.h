//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Pay.h 
//�������������������

#pragma once
#include "stdafx.h"
using namespace std;

class Pay
{
	ShoppingList *list;
	Cashier *cashier;
	Member *member;
	DbUtil *dbUtil;
	string memberType;
public:
	Pay(DbUtil *mdbUtil);
	~Pay();
	void pay_list();
	void additem();
	bool choose_if_pay();
	void if_member();
	void member_pay();
	void common_pay();
	void pay_way();
	void pay_with_cash();
	void pay_with_card();
	void pay_with_shopcard();
	void write_score();	
};