//学号：1352910 
//姓名：周同     
//文件名：Cashier.cpp 
//描述：收银员类的处理 

#include "stdafx.h"
#include "Cashier.h"

Cashier::Cashier(ShoppingList *list)
{
	s_list = list;
	s_money = 0.0;
}
Cashier::~Cashier(){}


void Cashier::outputToText()
{
	//ofstream fout("C:/Users/hank/Desktop/国内pnr导入/作业/record.txt");
	ofstream fout("./database/record.txt");
	if(fout.is_open())
	{
		fout<<"***************本次消费清单及支付记录***************\n";
		s_list->Print(fout);
		fout<<record_text;
		fout.close();
	}
}
void Cashier::setRecord(string record)
{
	record_text = record;
}

string Cashier::GetRecord()
{
	return record_text;
}

void Cashier::PrintList()
{
	cout<<endl<<"***************本次消费清单及支付记录***************"<<endl;
	s_list->Print();
	cout<<record_text<<endl;
}
double Cashier::GetTotalMoney()
{
	double total = 0.0;
	vector<pShoppingInfo> *p = s_list->GetALLItems();
	int size = p->size();
	for(int i=0;i<size;i++)
	{
		pShoppingInfo pInfo = (*p)[i];
		total += pInfo->item->GetItemPrice() * pInfo->num;
	}
	return total;
}
double Cashier::GetTotalMemberMoney(string memType)
{
	double total = 0.0;
	vector<pShoppingInfo> *p = s_list->GetALLItems();
	int size = p->size();
	if(memType == "1"){//金卡，对商品单独打折
		for(int i=0;i<size;i++)
	    {
		   pShoppingInfo pInfo = (*p)[i];
		   double discountPrice = Utils::getDiscountPrice(memType,pInfo->item->GetItemPrice());//金卡打折单价
		   total += discountPrice * pInfo->num;
		}
	}else{//非金卡，只对总价进行打折
		for(int i=0;i<size;i++)
		{
			pShoppingInfo pInfo = (*p)[i];
		    total += pInfo->item->GetItemPrice() * pInfo->num;
			total = Utils::getDiscountPrice(memType,total);
		}
	}
	return total;
}

double Cashier::Count(double money,string memberType)
{
	s_money += money;
	double total;
	if(memberType == "0"){//非会员？
		total = GetTotalMoney();
	}else{//会员
	    total = GetTotalMemberMoney(memberType);
	}
	return s_money-total;
}

double Cashier::GetSmoney()
{
	return s_money;
}
