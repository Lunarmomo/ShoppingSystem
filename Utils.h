//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ���� 
//�ļ�����Utils.h
//����:ͨ�÷�����,��Ҫ������ȡ���ݿ����Ӻ�����һЩ����ת��������

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

