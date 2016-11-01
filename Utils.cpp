//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Utils.cpp
//����:ͨ�÷�����Ĵ��� 

#include "stdafx.h"
#include "Utils.h"

MYSQL *Utils::conn;
//���ھ�̬���������ڲ����Ǹ���������C++Ҫ������ʵ�����κη��뵥Ԫ�ڱ�������ֻ��һ�����壬���Ե����ⲿ���塣һ������ͷ�ļ�������cpp�ж���

//����ǽ𿨣�����price�����ۣ������ʾ����Ʒ���ۺ󵥼�
//�������������ͨ��������price������Ʒ�ܼۣ����������ۺ��ܼ�
double Utils::getDiscountPrice(string memType,double price){
	double discountPrice;
	if(memType == "1"){//��
		if(price <= 10.00){
			discountPrice = price;
		}else if (price <= 20.00)
		{
			discountPrice = price*0.95;
		}else
		{
			discountPrice = price*0.9;
		}
	}else if (memType == "2")//����
	{
		if(price <= 1000.00){
			discountPrice = price*0.95;
		}else if (price <= 2000.00)
		{
			discountPrice = 1000*0.95 + (price-1000)*0.9;
		}else
		{
			discountPrice = 1000*0.95 + 1000*0.9 + (price-2000)*0.85;
		}
	}else if (memType == "3")//��ͨ��
	{
		if(price <= 2000.00){
			discountPrice = price;
		}else if (price <= 5000.00)
		{
			discountPrice = 2000 + (price-2000)*0.95;
		}else
		{
			discountPrice = 2000 + 3000*0.95 + (price-5000)*0.9;
		}
	}
	return discountPrice;
}
//ͨ����Ա��������뷵�ػ�Ա�����ļ������
string Utils::getMemberTypeStr(string memType){
	if(memType == "1"){
		return "��";
	}else if(memType == "2"){
		return "����";
	}else if(memType == "3"){
		return "��ͨ��Ա";
	}else{
		return "�ǻ�Ա";
	}

}
//ͨ�����ֻ�ȡ��Ӧ�Ļ�Ա����
string Utils::getMemberType(double score){
	if(score < 10000.00){
		return "3";
	}else if(score < 50000.00){
		return "2";
	}else{
		return "1";
	}
}
//�����Ա�������Լ�ʵ�����ѽ��,���ر�����������ȡ�Ļ���
double Utils::getMemberScore(string memType,double money){
	double memScore = 0.0;
	if(memType == "1"){
		if(money <= 1000.00){
			memScore = 1.5*money;
		}else if(money <= 5000.00){
			memScore = 1.5*1000 + (money-1000)*1.8;
		}else{
			memScore = 1.5*1000 + (5000-1000)*1.8 + (money-5000)*2;
		}
	}else if(memType == "2"){
		if(money <= 2000.00){
			memScore = 1.2*money;
		}else if(money <= 5000.00){
			memScore = 1.2*2000 + (money-2000)*1.5;
		}else{
			memScore = 1.8*2000 + (5000-2000)*1.5 + (money-5000)*1.8;
		}
	}else if(memType == "3"){
		memScore = 0.5*money;
	}
	return memScore;
}
MYSQL * Utils::GetConn()//��ȡ���ݿ�����
{
	if(NULL != conn)
	{
		return conn;
	}
	string host = "localhost";
	string user = "root";
	string password = "root";
	string dbname = "shoppingsystem";
	unsigned int port = 3306;
	string charset = "gbk";
	conn = new MYSQL();
	if(NULL == mysql_init(conn))
	{
		cout<<"mysql init failed!"<<endl;
		return NULL;
	}
	mysql_options(conn,MYSQL_SET_CHARSET_NAME,"gbk");
	if (NULL == mysql_real_connect(conn,host.c_str(),user.c_str(),password.c_str(),dbname.c_str(),port,NULL,0))
	{
		cout<<"connect failed!"<<endl;
		cout<<mysql_error(conn)<<endl;
		return NULL;
	}
	return conn;
}

void Utils::closeConnect(MYSQL *myConn)//�ͷ����ݿ����ӣ����ò�һ����null
{
	mysql_close(myConn);
	myConn = NULL;
}

string Utils::doubleToString(double num)
{
	ostringstream oss;
	oss<<num;
	return oss.str();
}
Utils::Utils(void)
{
}
Utils::~Utils(void)
{
}
