//Design Pattern Project
//成员：1352910 周同，1452734 储港    
//文件名：Main.cpp 
//描述：定义控制台应用程序的入口点。

#include "stdafx.h"
using namespace std;

void export_member_data(DbUtil *dbUtil);
void export_shopcard_data(DbUtil *dbUtil);

int _tmain(int argc, _TCHAR* argv[])
{
	cout.setf(ios::fixed);
	cout.precision(2);
	DbUtil *dbUtil = new DbUtil();

	cout << "----欢迎进入购物中心后台管理系统----"<<endl<<endl;
	cout << "亲爱的收营员，您好！" << endl;
	cout << "现在您可以进行以下操作：1：结算 2：基础数据导入 3:会员卡数据导出 4：购物卡数据导出 5：退出系统" << endl;
	cout << "选择：";
	int select;
	cin >> select;
	while (select != 5) 
	{
		if (select == 1) {
			Pay *pay = new Pay(dbUtil);
			pay->pay_list();//结算
		}
		else if (select == 2) {
			dbUtil->importBaseData();//基础数据导入

		}
		else if (select == 3) {
			export_member_data(dbUtil);	//会员数据导出
		}
		else if (select == 4) {
			export_shopcard_data(dbUtil);	//购物卡数据导出
		}
		else {
			cout << "选择错误，请重新输入！" << endl;
		}
		cout << endl <<"现在您可以继续进行以下操作：1：结算 2：基础数据导入 3:会员卡数据导出 4：购物卡数据导出 5：退出系统" << endl;
		cout << "选择：";
		cin >> select;
	}
	cout << endl << "*************欢迎您再次使用本购物结算系统**************\n";
	dbUtil->closeConn();
	system("pause");
	return 0;
}


void export_member_data(DbUtil *dbUtil)
{
    cout << "是否覆盖原始文件member.txt：0 否 1 是" << endl;
	//dbUtil->createOriginalData();
	int index;
	cin >> index;
	if (index == 0){//新建文件导出
		cout << "请输入新文件名,以.txt结尾：";
		string filename;
		cin >> filename;
		dbUtil->exportMemberData(filename);
	}
	else if (index == 1){//覆盖原始文件导出
		dbUtil->exportMemberData("");
	}
	else{
		cout << "选择错误，请重新输入！" << endl;
		export_member_data(dbUtil);
	}
}
void export_shopcard_data(DbUtil *dbUtil)
{
    cout << "是否覆盖原始文件card.txt：0 否 1 是" << endl;
	int index;
	cin >> index;
	if (index == 0){//新建文件导出
		cout << "请输入新文件名,以.txt结尾：";
		string filename;
		cin >> filename;
		dbUtil->exportCardData(filename);
	}
	else if (index == 1){//覆盖原始文件导出
		dbUtil->exportCardData("");
	}
	else{
		cout << "选择错误，请重新输入！" << endl;
		export_shopcard_data(dbUtil);
	}
}
