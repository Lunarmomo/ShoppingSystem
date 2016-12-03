//学号：1352910 
//姓名：周同     
//文件名：Utils.h
//描述:通用方法类,主要用来获取数据库连接和其他一些常用转换方法。

#pragma once
using namespace std;
class Utils
{
    static MYSQL *conn;
public:
	static double getDiscountPrice(string memType,double price);
	static MYSQL *GetConn();
	static void closeConnect(MYSQL *myConn);
	static string doubleToString(double num);

	Utils(void);
	~Utils(void);
};

