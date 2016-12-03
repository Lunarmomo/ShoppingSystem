//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Cashier.cpp 
//����������Ա��Ĵ��� 

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
	//ofstream fout("C:/Users/hank/Desktop/����pnr����/��ҵ/record.txt");
	ofstream fout("./database/record.txt");
	if(fout.is_open())
	{
		fout<<"***************���������嵥��֧����¼***************\n";
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
	cout<<endl<<"***************���������嵥��֧����¼***************"<<endl;
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
	if(memType == "1"){//�𿨣�����Ʒ��������
		for(int i=0;i<size;i++)
	    {
		   pShoppingInfo pInfo = (*p)[i];
		   double discountPrice = Utils::getDiscountPrice(memType,pInfo->item->GetItemPrice());//�𿨴��۵���
		   total += discountPrice * pInfo->num;
		}
	}else{//�ǽ𿨣�ֻ���ܼ۽��д���
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
	if(memberType == "0"){//�ǻ�Ա��
		total = GetTotalMoney();
	}else{//��Ա
	    total = GetTotalMemberMoney(memberType);
	}
	return s_money-total;
}

double Cashier::GetSmoney()
{
	return s_money;
}
