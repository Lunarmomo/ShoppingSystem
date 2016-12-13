//Design Pattern Project
//成员：1352910 周同，1452734 储港
//文件名：DbUtil.h 
//描述:数据库操作类，包含获取数据库商品、会员、购物卡信息，更新数据库信息，导入基础数据，导出数据库记录等功能。

#pragma once
#include "stdafx.h"
using namespace std;
class DbUtil
{
private:
	static MYSQL *myConn;
public:
    static Items *GetItems(string itemCode);//根据编号获取商品信息
	static Cards *GetCards(string cardCode);//根据编号获取购物卡信息
	static Member *GetMember(string memCode);//根据编号获取会员卡信息
	static bool UpdateMember(string memCode,double newMemScore,string newMemType);//更新会员卡信息，包括积分和会员类型
	static bool UpdateCards(string cardCode,double newCardMoney);//更新购物卡金额
	static bool importBaseData();//导入基础数据，包括商品、会员及购物卡数据
	static bool exportMemberData(string filename);//导出会员数据记录
	static bool exportCardData(string filename);//导出购物卡数据记录
	static void createOriginalData();//专门用来给自己创建原始数据，100行一个文件
	static void closeConn();
	DbUtil();
	~DbUtil();
};
