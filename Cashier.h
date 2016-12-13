//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ����  
//�ļ�����Cashier.h
//����������Ա�࣬�������ﳵ����ȡ�ֽ�����֧����¼����Ϣ�����Լ��㱾�ι����ܼۡ����λ�Ա�����ܼۡ���ӡ�����嵥�ȡ�

#pragma once
#include "ShoppingList.h"
using namespace std;
class Cashier
{
	ShoppingList *s_list; //���ﳵ
	double s_money; //����ȡ�ֽ���
	string record_text;//֧����¼
	
public:
	Cashier(ShoppingList *slist);
	~Cashier();
	double GetTotalMoney();//���㱾�ι����ܼ�
	double GetTotalMemberMoney(string memType);//���㱾�λ�Ա�����ܼ�
	double GetSmoney();// ����ȡ�ֽ�
	double Count(double money,string memberType);//��Ǯ���㣬money���˿͸����ֽ𣬷��ظ��ͻ���Ǯ
	void PrintList();//��ӡ�����嵥�����������嵥��֧����¼
	string GetRecord();
	void setRecord(string record);
	void outputToText();

};
