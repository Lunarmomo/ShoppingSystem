//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ����   
//�ļ�����ShoppingList.h
//����:���ﳵԪ����,������Ʒ�Ͷ�Ӧ��Ʒ��������

#pragma once
#include "Items.h"
#include "Utils.h"
using namespace std;

//���ﳵԪ�ص���������
typedef struct shoppingInfo 
{
	Items *item;
	int num;
}ShoppingInfo,*pShoppingInfo;

//���ﳵ
class ShoppingList 
{
	vector<pShoppingInfo> m_list;
public:
	ShoppingList();
	~ShoppingList();
	bool AddItems(Items *item,int num);//������Ʒ
	vector<pShoppingInfo> *GetALLItems();//��ȡ���ﳵ��������Ʒ
	void Print();//��ӡ�����嵥
	void Print(ofstream &fout);
	void MemberPrint(string memType);//��ӡ��Ա�����嵥
};
