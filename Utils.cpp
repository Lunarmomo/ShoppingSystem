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
double Utils::getDiscountPrice(string memType, double price){
	double discountPrice;
	if (memType == "1"){//��
		if (price <= 10.00){
			discountPrice = price;
		}
		else if (price <= 20.00)
		{
			discountPrice = price*0.95;
		}
		else
		{
			discountPrice = price*0.9;
		}
	}
	else if (memType == "2")//����
	{
		if (price <= 1000.00){
			discountPrice = price*0.95;
		}
		else if (price <= 2000.00)
		{
			discountPrice = 1000 * 0.95 + (price - 1000)*0.9;
		}
		else
		{
			discountPrice = 1000 * 0.95 + 1000 * 0.9 + (price - 2000)*0.85;
		}
	}
	else if (memType == "3")//��ͨ��
	{
		if (price <= 2000.00){
			discountPrice = price;
		}
		else if (price <= 5000.00)
		{
			discountPrice = 2000 + (price - 2000)*0.95;
		}
		else
		{
			discountPrice = 2000 + 3000 * 0.95 + (price - 5000)*0.9;
		}
	}
	return discountPrice;
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
