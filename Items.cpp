//学号：1352910 
//姓名：周同     
//文件名：Items.cpp
//描述:商品信息类的处理 

#include "stdafx.h"
#include "Items.h"
Items::Items(string item_code,string item_name,string item_place,double item_price)
{
	this->item_code = item_code;
	this->item_name = item_name;
	this->item_place = item_place;
	this->item_price = item_price;
}
Items::Items(){}
Items::~Items(){}
string Items::GetItemCode()
{
	return item_code;
}
string Items::GetItemName()
{
	return item_name;
}
string Items::GetItemPlace()
{
	return item_place;
}
double Items::GetItemPrice()
{
	return item_price;
}
void Items::SetItemCode(string itemCode)
{
	item_code = itemCode;
}
void Items::SetItemName(string itemName)
{
	item_name = itemName;
}
void Items::SetItemPlace(string itemPlace)
{
	item_place = itemPlace;
}
void Items::SetItemPrice(double price)
{
	item_price = price;
}
Items *Items::Clone()
{
	return new Items(item_code,item_name,item_place,item_price);
}
