//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ����  
//�ļ�����Items.h
//����:��Ʒ��Ϣ��

#pragma once
using namespace std;
class Items
{
	string item_code;//��Ʒ����
	string item_name;//����
	string item_place;//����
	double item_price;//��׼�۸�
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

