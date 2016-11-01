//学号：1352910 
//姓名：周同     
//文件名：Main.cpp 
//描述：定义控制台应用程序的入口点。

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ShoppingList *list = new ShoppingList();
	Cashier cashier(list);
    MYSQL *conn = Utils::GetConn();
	cout.setf(ios::fixed);
	cout.precision(2);
	DbUtil *dbUtil = NULL;

	cout<<"----欢迎进入小罗购物中心后台管理系统----"<<endl<<endl;
loop1:cout<<"亲爱的收营员，您好！"<<endl;
	cout<<"现在您可以进行以下操作：1：结算 2：基础数据导入 3:会员卡数据导出 4：购物卡数据导出"<<endl;
	cout<<"选择：";
	int select;
	cin>>select;
	if (select == 1)
	{
	loop2:cout<<"请输入商品代码和数量：";
		string itemCode;
		int itemCount;
		cin>>itemCode>>itemCount;
		Items *item = dbUtil->GetItems(itemCode);
		//需要加入购物车
		list->AddItems(item,itemCount);
		cout<<endl<<"您本次结算的商品信息如下:"<<endl;
		cout<<"商品名："<<item->GetItemName()<<"\t";
		cout<<"生产地："<<item->GetItemPlace()<<"\t";
		cout<<"基准价格："<<item->GetItemPrice()<<endl;
loop3:cout<<endl<<"请选择操作：1 支付订单 2 继续结算其他商品"<<endl;
		cout<<"选择：";
		int chooseIndex;
		cin>>chooseIndex;
		if(chooseIndex == 1)
		{
loop5:cout<<"请问是否使用会员卡：1 是 2 否"<<endl;
			cout<<"选择：";
			int memChoose;
			cin>>memChoose;
			string memberType = "0";//会员级别，0:默认非会员购物 其他：会员购物
			Member *member = NULL;
			if(memChoose == 1){
				cout<<"请输入会员卡号：";
				string memCode;
				cin>>memCode;
				member = dbUtil->GetMember(memCode);
		        cout<<endl<<"您的会员信息如下:"<<endl;
				cout<<"姓名："<<member->getMemName()<<"\t";
				cout<<"性别："<<member->getMemSex()<<"\t";
				cout<<"手机号："<<member->getMemPhone()<<"\t";
				cout<<"积分："<<member->getMemScore()<<"\t";
				cout<<"会员级别："<<Utils::getMemberTypeStr(member->getMemType())<<endl;
				memberType = member->getMemType();
				/*if(memberType == "1"){
				cout<<"会员级别："<<"金卡"<<endl;
				}else if(memberType == "2"){
				cout<<"会员级别："<<"银卡"<<endl;
				}else if(memberType == "3"){
				cout<<"会员级别："<<"普通会员"<<endl;
				}*/
				cout<<endl<<"您本次即将支付的购物清单为："<<endl;
			    list->Print();
				cout<<"本次共计消费"<<cashier.GetTotalMoney()<<"元"<<endl<<endl;
				cout<<"使用会员卡折后共计消费"<<cashier.GetTotalMemberMoney(member->getMemType())<<"元"<<endl<<endl;
			}else if(memChoose == 2){
				cout<<endl<<"您本次即将支付的购物清单为："<<endl;
			    list->Print();
			    cout<<"本次共计消费"<<cashier.GetTotalMoney()<<"元"<<endl<<endl;
			}else{
				cout<<"选择错误，请重新输入！"<<endl;
			    goto loop5;
			}
loop4:cout<<"请选择支付方式：1 现金 2 银行卡 3 超市购物卡"<<endl;
			cout<<"选择：";
			int payIndex;
			cin>>payIndex;
			if(payIndex == 1)//现金
			{
				cout<<"请支付现金：";
				double money = 0.0;
				cin>>money;
				double backMoney = cashier.Count(money,memberType);
				while (backMoney< 0)
				{
					cout<<"还差："<<-backMoney<<"元，";
					cout<<"请继续支付现金：";
					cin>>money;
					backMoney = cashier.Count(money,memberType);
				}
				cout<<endl;
				double totalMoney;
				if(memberType == "0"){
					totalMoney = cashier.GetTotalMoney();
				}else{
					totalMoney = cashier.GetTotalMemberMoney(memberType);
				}
				cout<<"支付成功!"<<endl;
				cout<<"共收取您现金："<<cashier.GetSmoney()<<"元\n";
				cout<<"应收金额："<<totalMoney<<"元\n";
				cout<<"找零："<<backMoney<<"元\n\n";
				string recordText = "支付方式：现金\n共收取现金："+Utils::doubleToString(cashier.GetSmoney())+"元"+"\n应收金额："+Utils::doubleToString(totalMoney)+"元"+"\n找零："+Utils::doubleToString(backMoney)+"元";
				cashier.setRecord(recordText);
			}else if(payIndex == 2)//银行卡
			{
				string cardNo;//卡号
				string name;//姓名
				double money = 0.0;//刷卡金额
				cout<<"请输入银行卡号：";
				cin>>cardNo;
				cout<<"请输入姓名：";
				cin>>name;
				cout<<"请输入刷卡金额：";
				cin>>money;
				double totalMoney;
				if(memberType == "0"){
					totalMoney = cashier.GetTotalMoney();
				}else
				{
					totalMoney = cashier.GetTotalMemberMoney(memberType);
				}
				while(money != totalMoney)
				{
					cout<<"刷卡金额和消费金额不一致，请重新输入刷卡金额：";
					cin>>money;
				}
				cout<<"支付成功!"<<endl;
				cout<<"银行卡共刷卡消费："<<money<<"元\n";
				string recordText = "支付方式：银行卡\n卡号："+cardNo+"\n姓名："+name+"\n消费金额："+Utils::doubleToString(money);
				cashier.setRecord(recordText);
			}else if(payIndex == 3)//超市购物卡
			{
				string cardNo;//卡号
				double money = 0.0;//刷卡金额
				cout<<"请输入超市购物卡号：";
				cin>>cardNo;
				cout<<"请输入刷卡金额：";
				cin>>money;
				double totalMoney;
				if(memberType == "0"){
					totalMoney = cashier.GetTotalMoney();
				}else
				{
					totalMoney = cashier.GetTotalMemberMoney(memberType);
				}
				while(money != totalMoney)
				{
					cout<<"刷卡金额和消费金额不一致，请重新输入刷卡金额：";
					cin>>money;
				}
				Cards *card = dbUtil->GetCards(cardNo);
				if(money > card->getCardMoney())
				{
					cout<<"对不起，购物卡余额不足，请选择其他支付方式！"<<endl;
					goto loop4;
				}
				double newCardMoney = card->getCardMoney() - money;
				if(dbUtil->UpdateCards(cardNo,newCardMoney))
				{
				    cout<<"支付成功!"<<endl;
				    cout<<"购物卡共刷卡消费："<<money<<"元\n";
					string recordText = "支付方式：购物卡\n卡号："+cardNo+"\n消费金额："+Utils::doubleToString(money);
				    cashier.setRecord(recordText);
				}
			}else
			{
				cout<<"选择错误，请重新输入！"<<endl;
			    goto loop4;
			}
			//此处录入会员积分即可，同时修改会员级别UpdateMember(string memCode,double newMemScore,string newMemType)
			if(memberType != "0"){//如果是会员需要更新积分以及会员级别
				double score = Utils::getMemberScore(memberType,cashier.GetTotalMemberMoney(memberType));
				double newMemScore = member->getMemScore() + score;
				string newMemType = Utils::getMemberType(newMemScore);
				dbUtil->UpdateMember(member->getMemCode(),newMemScore,newMemType);
				cout<<"本次获得积分:"<<score<<endl;
				if(member->getMemType() != newMemType){
					cout<<"会员卡升级为:"<<Utils::getMemberTypeStr(newMemType)<<endl;
				}
			}
		}else if (chooseIndex == 2)
		{
			goto loop2;
		}
		else
		{
			cout<<"选择错误，请重新输入！"<<endl;
			goto loop3;
		}
		cashier.outputToText();
		cashier.PrintList();
		cout<<endl<<"*************欢迎您再次使用本购物结算系统**************\n";
	    Utils::closeConnect(conn);
		system("pause");
		return 0;
	}else if(select == 2)//基础数据导入
	{
		dbUtil->importBaseData();
		goto loop1;
	}else if(select == 3){//会员数据导出
loop6:		cout<<"是否覆盖原始文件member.txt：0 否 1 是"<<endl;
		//dbUtil->createOriginalData();
		int index;
		cin>>index;
		if(index == 0){//新建文件导出
			cout<<"请输入新文件名,以.txt结尾：";
			string filename;
			cin>>filename;
		    dbUtil->exportMemberData(filename);
		}else if(index == 1){//覆盖原始文件导出
			dbUtil->exportMemberData("");
		}else{
			cout<<"选择错误，请重新输入！"<<endl;
			goto loop6;
		}
		goto loop1;
	}else if(select == 4){//购物卡数据导出
loop7:		cout<<"是否覆盖原始文件card.txt：0 否 1 是"<<endl;
		int index;
		cin>>index;
		if(index == 0){//新建文件导出
			cout<<"请输入新文件名,以.txt结尾：";
			string filename;
			cin>>filename;
		    dbUtil->exportCardData(filename);
		}else if(index == 1){//覆盖原始文件导出
			dbUtil->exportCardData("");
		}else{
			cout<<"选择错误，请重新输入！"<<endl;
			goto loop7;
		}
		goto loop1;
	}
	else
	{
		cout<<"选择错误，请重新输入！"<<endl;
		goto loop1;
	}
}

