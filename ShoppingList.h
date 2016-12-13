//Design Pattern Project
//成员：1352910 周同，1452734 储港   
//文件名：ShoppingList.h
//描述:购物车元素类,包含商品和对应商品的数量。

#pragma once
#include "Items.h"
#include "Utils.h"
using namespace std;

//购物车元素的数据类型
typedef struct shoppingInfo 
{
	Items *item;
	int num;
}ShoppingInfo,*pShoppingInfo;

//购物车
class ShoppingList 
{
	vector<pShoppingInfo> m_list;
public:
	ShoppingList();
	~ShoppingList();
	bool AddItems(Items *item,int num);//增加商品
	vector<pShoppingInfo> *GetALLItems();//获取购物车中所有商品
	void Print();//打印购物清单
	void Print(ofstream &fout);
	void MemberPrint(string memType);//打印会员购物清单
};
