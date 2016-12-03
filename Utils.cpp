//学号：1352910 
//姓名：周同     
//文件名：Utils.cpp
//描述:通用方法类的处理 

#include "stdafx.h"
#include "Utils.h"

MYSQL *Utils::conn;
//对于静态变量，类内部的那个叫声明，C++要求所有实体在任何翻译单元内必须有且只有一个定义，所以得在外部定义。一般是在头文件声明，cpp中定义

//如果是金卡，输入price代表单价，输出表示该商品打折后单价
//如果是银卡及普通卡，输入price代表商品总价，输出代表打折后总价
double Utils::getDiscountPrice(string memType, double price){
	double discountPrice;
	if (memType == "1"){//金卡
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
	else if (memType == "2")//银卡
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
	else if (memType == "3")//普通卡
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

MYSQL * Utils::GetConn()//获取数据库连接
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

void Utils::closeConnect(MYSQL *myConn)//释放数据库连接，引用不一定是null
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
