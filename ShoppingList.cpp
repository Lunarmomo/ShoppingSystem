//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ���� 
//�ļ�����ShoppingList.cpp
//����:���ﳵԪ����Ĵ��� 

#include "stdafx.h"
#include "ShoppingList.h"


ShoppingList::ShoppingList(){}
ShoppingList::~ShoppingList(){}
bool ShoppingList::AddItems(Items *item,int num)
{
	pShoppingInfo p = new ShoppingInfo;
	p->item = item;
	p->num = num;
	m_list.push_back(p);
	return true;
}
vector<pShoppingInfo> *ShoppingList::GetALLItems()
{
	return &m_list;
}
void ShoppingList::Print(ofstream &fout)
{
	fout.setf(ios::fixed);
	fout.precision(2);
	string title[4];
	title[0] = "��Ʒ����";
	title[1] = "��Ʒ��";
	title[2] = "����";
	title[3] = "����";
	for(int i=0;i<4;i++)
	{
		fout.width(16);
		fout<<left<<title[i];
	}
	fout<<endl;
	int size = m_list.size();
	for(int i=0;i<size;i++)
	{
		fout.width(16);
		fout<<left<<m_list[i]->item->GetItemCode();
		fout.width(16);
		fout<<left<<m_list[i]->item->GetItemName();
		fout.width(16);
		fout<<left<<m_list[i]->num;
		fout.width(16);
		fout<<left<<m_list[i]->item->GetItemPrice()<<"\n";
	}
}
void ShoppingList::MemberPrint(string memType){
	string title[5];
	title[0] = "��Ʒ����";
	title[1] = "��Ʒ��";
	title[2] = "����";
	title[3] = "����";
	title[4] = "��Ա��";
	for(int i=0;i<5;i++)
	{
		cout.width(16);
		cout<<left<<title[i];
	}	
	cout<<endl;
	int size = m_list.size();
	for(int i=0;i<size;i++)
	{
		cout.width(16);
		cout<<left<<m_list[i]->item->GetItemCode();
		cout.width(16);
		cout<<left<<m_list[i]->item->GetItemName();
		cout.width(16);
		cout<<left<<m_list[i]->num;
		cout.width(16);
		double price = m_list[i]->item->GetItemPrice();
		cout<<left<<price;
		cout.width(16);
		double discountPrice;
		discountPrice = Utils::getDiscountPrice(memType,price);
		cout<<left<<discountPrice<<"\n";
	}

}
void ShoppingList::Print()
{
	string title[4];
	title[0] = "��Ʒ����";
	title[1] = "��Ʒ��";
	title[2] = "����";
	title[3] = "����";
	for(int i=0;i<4;i++)
	{
		cout.width(16);
		cout<<left<<title[i];
	}
	cout<<endl;
	int size = m_list.size();
	for(int i=0;i<size;i++)
	{
		cout.width(16);
		cout<<left<<m_list[i]->item->GetItemCode();
		cout.width(16);
		cout<<left<<m_list[i]->item->GetItemName();
		cout.width(16);
		cout<<left<<m_list[i]->num;
		cout.width(16);
		cout<<left<<m_list[i]->item->GetItemPrice()<<"\n";
	}
}
