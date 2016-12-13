//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ����
//�ļ�����DbUtil.h 
//����:���ݿ�����࣬������ȡ���ݿ���Ʒ����Ա�����￨��Ϣ���������ݿ���Ϣ������������ݣ��������ݿ��¼�ȹ��ܡ�

#pragma once
#include "stdafx.h"
using namespace std;
class DbUtil
{
private:
	static MYSQL *myConn;
public:
    static Items *GetItems(string itemCode);//���ݱ�Ż�ȡ��Ʒ��Ϣ
	static Cards *GetCards(string cardCode);//���ݱ�Ż�ȡ���￨��Ϣ
	static Member *GetMember(string memCode);//���ݱ�Ż�ȡ��Ա����Ϣ
	static bool UpdateMember(string memCode,double newMemScore,string newMemType);//���»�Ա����Ϣ���������ֺͻ�Ա����
	static bool UpdateCards(string cardCode,double newCardMoney);//���¹��￨���
	static bool importBaseData();//����������ݣ�������Ʒ����Ա�����￨����
	static bool exportMemberData(string filename);//������Ա���ݼ�¼
	static bool exportCardData(string filename);//�������￨���ݼ�¼
	static void createOriginalData();//ר���������Լ�����ԭʼ���ݣ�100��һ���ļ�
	static void closeConn();
	DbUtil();
	~DbUtil();
};
