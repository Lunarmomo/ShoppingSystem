//Design Pattern Project
//成员：1352910 周同，1452734 储港  
//文件名：Items.h
//描述:商品信息类

#pragma once
using namespace std;
class Items
{
	string item_code;//商品代码
	string item_name;//名称
	string item_place;//产地
	double item_price;//基准价格
public:
	Items(string item_code,string item_name,string item_place,double item_price);
	string GetItemCode();
	string GetItemName();
	string GetItemPlace();
	double GetItemPrice();
	void SetItemCode(string itemCode);
	void SetItemName(string itemName);
	void SetItemPlace(string itemPlace);
	void SetItemPrice(double price);
	Items *Clone();
	Items();
	~Items();
};

