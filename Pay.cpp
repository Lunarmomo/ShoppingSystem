//Design Pattern Project
//��Ա��1352910 ��ͬ��1452734 ����
//�ļ�����Pay.cpp 
//������������������ദ�� 

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
	cout << "��������Ʒ�����������";
	string itemCode;
	int itemCount;
	cin >> itemCode >> itemCount;
	Items *item = dbUtil->GetItems(itemCode);
	//��Ҫ���빺�ﳵ
	list->AddItems(item, itemCount);
	cout << endl << "�����ν������Ʒ��Ϣ����:" << endl;
	cout << "��Ʒ����" << item->GetItemName() << "\t";
	cout << "�����أ�" << item->GetItemPlace() << "\t";
	cout << "��׼�۸�" << item->GetItemPrice() << endl;
}

bool Pay::choose_if_pay()
{
	cout << endl << "��ѡ�������1 ֧������ 2 ��������������Ʒ" << endl;
	cout << "ѡ��";
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
	cout << "�����Ƿ�ʹ�û�Ա����1 �� 2 ��" << endl;
	cout << "ѡ��";
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
	cout << "�������Ա���ţ�";
	string memCode;
	cin >> memCode;
	member = dbUtil->GetMember(memCode);
	cout << endl << "���Ļ�Ա��Ϣ����:" << endl;
	cout << "������" << member->getMemName() << "\t";
	cout << "�Ա�" << member->getMemSex() << "\t";
	cout << "�ֻ��ţ�" << member->getMemPhone() << "\t";
	cout << "���֣�" << member->getMemScore() << "\t";
	cout << "��Ա����" << member->getMemberTypeStr() << endl;
	memberType = member->getMemType();
	/*if(memberType == "1"){
	cout<<"��Ա����"<<"��"<<endl;
	}else if(memberType == "2"){
	cout<<"��Ա����"<<"����"<<endl;
	}else if(memberType == "3"){
	cout<<"��Ա����"<<"��ͨ��Ա"<<endl;
	}*/
	cout << endl << "�����μ���֧���Ĺ����嵥Ϊ��" << endl;
	list->Print();
	cout << "���ι�������" << cashier->GetTotalMoney() << "Ԫ" << endl << endl;
	cout << "ʹ�û�Ա���ۺ󹲼�����" << cashier->GetTotalMemberMoney(member->getMemType()) << "Ԫ" << endl << endl;
}

void Pay::common_pay()
{
	cout << endl << "�����μ���֧���Ĺ����嵥Ϊ��" << endl;
	list->Print();
	cout << "���ι�������" << cashier->GetTotalMoney() << "Ԫ" << endl << endl;
}

void Pay::pay_way()
{
	cout << "��ѡ��֧����ʽ��1 �ֽ� 2 ���п� 3 ���й��￨" << endl;
	cout << "ѡ��";
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
	cout << "��֧���ֽ�";
	double money = 0.0;
	cin >> money;
	double backMoney = cashier->Count(money, memberType);
	while (backMoney< 0)
	{
		cout << "���" << -backMoney << "Ԫ��";
		cout << "�����֧���ֽ�";
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
	cout << "֧���ɹ�!" << endl;
	cout << "����ȡ���ֽ�" << cashier->GetSmoney() << "Ԫ\n";
	cout << "Ӧ�ս�" << totalMoney << "Ԫ\n";
	cout << "���㣺" << backMoney << "Ԫ\n\n";
	string recordText = "֧����ʽ���ֽ�\n����ȡ�ֽ�" + Utils::doubleToString(cashier->GetSmoney()) + "Ԫ" + "\nӦ�ս�" + Utils::doubleToString(totalMoney) + "Ԫ" + "\n���㣺" + Utils::doubleToString(backMoney) + "Ԫ";
	cashier->setRecord(recordText);
}

void Pay::pay_with_card()
{
	string cardNo;//����
	string name;//����
	double money = 0.0;//ˢ�����
	cout << "���������п��ţ�";
	cin >> cardNo;
	cout << "������������";
	cin >> name;
	cout << "������ˢ����";
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
		cout << "ˢ���������ѽ�һ�£�����������ˢ����";
		cin >> money;
	}
	cout << "֧���ɹ�!" << endl;
	cout << "���п���ˢ�����ѣ�" << money << "Ԫ\n";
	string recordText = "֧����ʽ�����п�\n���ţ�" + cardNo + "\n������" + name + "\n���ѽ�" + Utils::doubleToString(money);
	cashier->setRecord(recordText);
}

void Pay::pay_with_shopcard()
{
	string cardNo;//����
	double money = 0.0;//ˢ�����
	cout << "�����볬�й��￨�ţ�";
	cin >> cardNo;
	cout << "������ˢ����";
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
		cout << "ˢ���������ѽ�һ�£�����������ˢ����";
		cin >> money;
	}
	Cards *card = dbUtil->GetCards(cardNo);
	if (money > card->getCardMoney())
	{
		cout << "�Բ��𣬹��￨���㣬��ѡ������֧����ʽ��" << endl;
	}
	double newCardMoney = card->getCardMoney() - money;
	if (dbUtil->UpdateCards(cardNo, newCardMoney))
	{
		cout << "֧���ɹ�!" << endl;
		cout << "���￨��ˢ�����ѣ�" << money << "Ԫ\n";
		string recordText = "֧����ʽ�����￨\n���ţ�" + cardNo + "\n���ѽ�" + Utils::doubleToString(money);
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
	cout << "���λ�û���:" << score << endl;
	if (member->getMemType() != newMemType){
		cout << "��Ա������Ϊ:" << member->getMemberTypeStr() << endl;
	}
}