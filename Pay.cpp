//Design Pattern Project
//成员：1352910 周同，1452734 储港
//文件名：Pay.cpp 
//描述：结算操作流程类处理 

#include "stdafx.h"
#include "Pay.h"

Pay::Pay(DbUtil *mdbUtil)
{
	list = new ShoppingList();
	cashier=new Cashier(list);
	cout.setf(ios::fixed);
	cout.precision(2);
	dbUtil = mdbUtil;
}

Pay::~Pay(){}

void Pay::pay_list()
{
	additem();
	while (!choose_if_pay())additem();
	if_member();
	pay_way();
	if (memberType != "0")write_score();
	cashier->outputToText();
	cashier->PrintList();
}

void Pay::additem()
{
	cout << "请输入商品代码和数量：";
	string itemCode;
	int itemCount;
	cin >> itemCode >> itemCount;
	Items *item = dbUtil->GetItems(itemCode);
	//需要加入购物车
	list->AddItems(item, itemCount);
	cout << endl << "您本次结算的商品信息如下:" << endl;
	cout << "商品名：" << item->GetItemName() << "\t";
	cout << "生产地：" << item->GetItemPlace() << "\t";
	cout << "基准价格：" << item->GetItemPrice() << endl;
}

bool Pay::choose_if_pay()
{
	cout << endl << "请选择操作：1 支付订单 2 继续结算其他商品" << endl;
	cout << "选择：";
	int chooseIndex;
	cin >> chooseIndex;
	switch (chooseIndex)
	{
	case 1:return true;
	case 2:return false;
	default:choose_if_pay(); return false;
	}
}

void Pay::if_member()
{
	cout << "请问是否使用会员卡：1 是 2 否" << endl;
	cout << "选择：";
	int memChoose;
	cin >> memChoose;
	switch (memChoose)
	{
	case 1:member_pay(); break;
	case 2:common_pay(); break;
	default:if_member();
	}
}

void Pay::member_pay()
{
	cout << "请输入会员卡号：";
	string memCode;
	cin >> memCode;
	member = dbUtil->GetMember(memCode);
	cout << endl << "您的会员信息如下:" << endl;
	cout << "姓名：" << member->getMemName() << "\t";
	cout << "性别：" << member->getMemSex() << "\t";
	cout << "手机号：" << member->getMemPhone() << "\t";
	cout << "积分：" << member->getMemScore() << "\t";
	cout << "会员级别：" << member->getMemberTypeStr() << endl;
	memberType = member->getMemType();
	/*if(memberType == "1"){
	cout<<"会员级别："<<"金卡"<<endl;
	}else if(memberType == "2"){
	cout<<"会员级别："<<"银卡"<<endl;
	}else if(memberType == "3"){
	cout<<"会员级别："<<"普通会员"<<endl;
	}*/
	cout << endl << "您本次即将支付的购物清单为：" << endl;
	list->Print();
	cout << "本次共计消费" << cashier->GetTotalMoney() << "元" << endl << endl;
	cout << "使用会员卡折后共计消费" << cashier->GetTotalMemberMoney(member->getMemType()) << "元" << endl << endl;
}

void Pay::common_pay()
{
	cout << endl << "您本次即将支付的购物清单为：" << endl;
	list->Print();
	cout << "本次共计消费" << cashier->GetTotalMoney() << "元" << endl << endl;
}

void Pay::pay_way()
{
	cout << "请选择支付方式：1 现金 2 银行卡 3 超市购物卡" << endl;
	cout << "选择：";
	int payIndex;
	cin >> payIndex;
	switch (payIndex)
	{
	   case 1:
		   pay_with_cash(); 
		   break;
	   case 2:
		   pay_with_card(); 
		   break;
	   case 3:
		   pay_with_shopcard(); 
		   break;
	   default:
		   pay_way();
	}
}

void Pay::pay_with_cash()
{
	cout << "请支付现金：";
	double money = 0.0;
	cin >> money;
	double backMoney = cashier->Count(money, memberType);
	while (backMoney< 0)
	{
		cout << "还差：" << -backMoney << "元，";
		cout << "请继续支付现金：";
		cin >> money;
		backMoney = cashier->Count(money, memberType);
	}
	cout << endl;
	double totalMoney;
	if (memberType == "0"){
		totalMoney = cashier->GetTotalMoney();
	}
	else{
		totalMoney = cashier->GetTotalMemberMoney(memberType);
	}
	cout << "支付成功!" << endl;
	cout << "共收取您现金：" << cashier->GetSmoney() << "元\n";
	cout << "应收金额：" << totalMoney << "元\n";
	cout << "找零：" << backMoney << "元\n\n";
	string recordText = "支付方式：现金\n共收取现金：" + Utils::doubleToString(cashier->GetSmoney()) + "元" + "\n应收金额：" + Utils::doubleToString(totalMoney) + "元" + "\n找零：" + Utils::doubleToString(backMoney) + "元";
	cashier->setRecord(recordText);
}

void Pay::pay_with_card()
{
	string cardNo;//卡号
	string name;//姓名
	double money = 0.0;//刷卡金额
	cout << "请输入银行卡号：";
	cin >> cardNo;
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入刷卡金额：";
	cin >> money;
	double totalMoney;
	if (memberType == "0"){
		totalMoney = cashier->GetTotalMoney();
	}
	else
	{
		totalMoney = cashier->GetTotalMemberMoney(memberType);
	}
	while (money != totalMoney)
	{
		cout << "刷卡金额和消费金额不一致，请重新输入刷卡金额：";
		cin >> money;
	}
	cout << "支付成功!" << endl;
	cout << "银行卡共刷卡消费：" << money << "元\n";
	string recordText = "支付方式：银行卡\n卡号：" + cardNo + "\n姓名：" + name + "\n消费金额：" + Utils::doubleToString(money);
	cashier->setRecord(recordText);
}

void Pay::pay_with_shopcard()
{
	string cardNo;//卡号
	double money = 0.0;//刷卡金额
	cout << "请输入超市购物卡号：";
	cin >> cardNo;
	cout << "请输入刷卡金额：";
	cin >> money;
	double totalMoney;
	if (memberType == "0"){
		totalMoney = cashier->GetTotalMoney();
	}
	else
	{
		totalMoney = cashier->GetTotalMemberMoney(memberType);
	}
	while (money != totalMoney)
	{
		cout << "刷卡金额和消费金额不一致，请重新输入刷卡金额：";
		cin >> money;
	}
	Cards *card = dbUtil->GetCards(cardNo);
	if (money > card->getCardMoney())
	{
		cout << "对不起，购物卡余额不足，请选择其他支付方式！" << endl;
	}
	double newCardMoney = card->getCardMoney() - money;
	if (dbUtil->UpdateCards(cardNo, newCardMoney))
	{
		cout << "支付成功!" << endl;
		cout << "购物卡共刷卡消费：" << money << "元\n";
		string recordText = "支付方式：购物卡\n卡号：" + cardNo + "\n消费金额：" + Utils::doubleToString(money);
		cashier->setRecord(recordText);
	}
}

void Pay::write_score()
{
	double score = member->getMemberScore(cashier->GetTotalMemberMoney(memberType));
	double newMemScore = member->getMemScore() + score;
	member->setMemScore(newMemScore);
	string newMemType = member->getMemberType();
	member->setMemType(newMemType);
	dbUtil->UpdateMember(member->getMemCode(), newMemScore, newMemType);
	cout << "本次获得积分:" << score << endl;
	if (member->getMemType() != newMemType){
		cout << "会员卡升级为:" << member->getMemberTypeStr() << endl;
	}
}