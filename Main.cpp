//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Main.cpp 
//�������������̨Ӧ�ó������ڵ㡣

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

	cout<<"----��ӭ����С�޹������ĺ�̨����ϵͳ----"<<endl<<endl;
loop1:cout<<"�װ�����ӪԱ�����ã�"<<endl;
	cout<<"���������Խ������²�����1������ 2���������ݵ��� 3:��Ա�����ݵ��� 4�����￨���ݵ���"<<endl;
	cout<<"ѡ��";
	int select;
	cin>>select;
	if (select == 1)
	{
	loop2:cout<<"��������Ʒ�����������";
		string itemCode;
		int itemCount;
		cin>>itemCode>>itemCount;
		Items *item = dbUtil->GetItems(itemCode);
		//��Ҫ���빺�ﳵ
		list->AddItems(item,itemCount);
		cout<<endl<<"�����ν������Ʒ��Ϣ����:"<<endl;
		cout<<"��Ʒ����"<<item->GetItemName()<<"\t";
		cout<<"�����أ�"<<item->GetItemPlace()<<"\t";
		cout<<"��׼�۸�"<<item->GetItemPrice()<<endl;
loop3:cout<<endl<<"��ѡ�������1 ֧������ 2 ��������������Ʒ"<<endl;
		cout<<"ѡ��";
		int chooseIndex;
		cin>>chooseIndex;
		if(chooseIndex == 1)
		{
loop5:cout<<"�����Ƿ�ʹ�û�Ա����1 �� 2 ��"<<endl;
			cout<<"ѡ��";
			int memChoose;
			cin>>memChoose;
			string memberType = "0";//��Ա����0:Ĭ�Ϸǻ�Ա���� ��������Ա����
			Member *member = NULL;
			if(memChoose == 1){
				cout<<"�������Ա���ţ�";
				string memCode;
				cin>>memCode;
				member = dbUtil->GetMember(memCode);
		        cout<<endl<<"���Ļ�Ա��Ϣ����:"<<endl;
				cout<<"������"<<member->getMemName()<<"\t";
				cout<<"�Ա�"<<member->getMemSex()<<"\t";
				cout<<"�ֻ��ţ�"<<member->getMemPhone()<<"\t";
				cout<<"���֣�"<<member->getMemScore()<<"\t";
				cout<<"��Ա����"<<Utils::getMemberTypeStr(member->getMemType())<<endl;
				memberType = member->getMemType();
				/*if(memberType == "1"){
				cout<<"��Ա����"<<"��"<<endl;
				}else if(memberType == "2"){
				cout<<"��Ա����"<<"����"<<endl;
				}else if(memberType == "3"){
				cout<<"��Ա����"<<"��ͨ��Ա"<<endl;
				}*/
				cout<<endl<<"�����μ���֧���Ĺ����嵥Ϊ��"<<endl;
			    list->Print();
				cout<<"���ι�������"<<cashier.GetTotalMoney()<<"Ԫ"<<endl<<endl;
				cout<<"ʹ�û�Ա���ۺ󹲼�����"<<cashier.GetTotalMemberMoney(member->getMemType())<<"Ԫ"<<endl<<endl;
			}else if(memChoose == 2){
				cout<<endl<<"�����μ���֧���Ĺ����嵥Ϊ��"<<endl;
			    list->Print();
			    cout<<"���ι�������"<<cashier.GetTotalMoney()<<"Ԫ"<<endl<<endl;
			}else{
				cout<<"ѡ��������������룡"<<endl;
			    goto loop5;
			}
loop4:cout<<"��ѡ��֧����ʽ��1 �ֽ� 2 ���п� 3 ���й��￨"<<endl;
			cout<<"ѡ��";
			int payIndex;
			cin>>payIndex;
			if(payIndex == 1)//�ֽ�
			{
				cout<<"��֧���ֽ�";
				double money = 0.0;
				cin>>money;
				double backMoney = cashier.Count(money,memberType);
				while (backMoney< 0)
				{
					cout<<"���"<<-backMoney<<"Ԫ��";
					cout<<"�����֧���ֽ�";
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
				cout<<"֧���ɹ�!"<<endl;
				cout<<"����ȡ���ֽ�"<<cashier.GetSmoney()<<"Ԫ\n";
				cout<<"Ӧ�ս�"<<totalMoney<<"Ԫ\n";
				cout<<"���㣺"<<backMoney<<"Ԫ\n\n";
				string recordText = "֧����ʽ���ֽ�\n����ȡ�ֽ�"+Utils::doubleToString(cashier.GetSmoney())+"Ԫ"+"\nӦ�ս�"+Utils::doubleToString(totalMoney)+"Ԫ"+"\n���㣺"+Utils::doubleToString(backMoney)+"Ԫ";
				cashier.setRecord(recordText);
			}else if(payIndex == 2)//���п�
			{
				string cardNo;//����
				string name;//����
				double money = 0.0;//ˢ�����
				cout<<"���������п��ţ�";
				cin>>cardNo;
				cout<<"������������";
				cin>>name;
				cout<<"������ˢ����";
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
					cout<<"ˢ���������ѽ�һ�£�����������ˢ����";
					cin>>money;
				}
				cout<<"֧���ɹ�!"<<endl;
				cout<<"���п���ˢ�����ѣ�"<<money<<"Ԫ\n";
				string recordText = "֧����ʽ�����п�\n���ţ�"+cardNo+"\n������"+name+"\n���ѽ�"+Utils::doubleToString(money);
				cashier.setRecord(recordText);
			}else if(payIndex == 3)//���й��￨
			{
				string cardNo;//����
				double money = 0.0;//ˢ�����
				cout<<"�����볬�й��￨�ţ�";
				cin>>cardNo;
				cout<<"������ˢ����";
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
					cout<<"ˢ���������ѽ�һ�£�����������ˢ����";
					cin>>money;
				}
				Cards *card = dbUtil->GetCards(cardNo);
				if(money > card->getCardMoney())
				{
					cout<<"�Բ��𣬹��￨���㣬��ѡ������֧����ʽ��"<<endl;
					goto loop4;
				}
				double newCardMoney = card->getCardMoney() - money;
				if(dbUtil->UpdateCards(cardNo,newCardMoney))
				{
				    cout<<"֧���ɹ�!"<<endl;
				    cout<<"���￨��ˢ�����ѣ�"<<money<<"Ԫ\n";
					string recordText = "֧����ʽ�����￨\n���ţ�"+cardNo+"\n���ѽ�"+Utils::doubleToString(money);
				    cashier.setRecord(recordText);
				}
			}else
			{
				cout<<"ѡ��������������룡"<<endl;
			    goto loop4;
			}
			//�˴�¼���Ա���ּ��ɣ�ͬʱ�޸Ļ�Ա����UpdateMember(string memCode,double newMemScore,string newMemType)
			if(memberType != "0"){//����ǻ�Ա��Ҫ���»����Լ���Ա����
				double score = Utils::getMemberScore(memberType,cashier.GetTotalMemberMoney(memberType));
				double newMemScore = member->getMemScore() + score;
				string newMemType = Utils::getMemberType(newMemScore);
				dbUtil->UpdateMember(member->getMemCode(),newMemScore,newMemType);
				cout<<"���λ�û���:"<<score<<endl;
				if(member->getMemType() != newMemType){
					cout<<"��Ա������Ϊ:"<<Utils::getMemberTypeStr(newMemType)<<endl;
				}
			}
		}else if (chooseIndex == 2)
		{
			goto loop2;
		}
		else
		{
			cout<<"ѡ��������������룡"<<endl;
			goto loop3;
		}
		cashier.outputToText();
		cashier.PrintList();
		cout<<endl<<"*************��ӭ���ٴ�ʹ�ñ��������ϵͳ**************\n";
	    Utils::closeConnect(conn);
		system("pause");
		return 0;
	}else if(select == 2)//�������ݵ���
	{
		dbUtil->importBaseData();
		goto loop1;
	}else if(select == 3){//��Ա���ݵ���
loop6:		cout<<"�Ƿ񸲸�ԭʼ�ļ�member.txt��0 �� 1 ��"<<endl;
		//dbUtil->createOriginalData();
		int index;
		cin>>index;
		if(index == 0){//�½��ļ�����
			cout<<"���������ļ���,��.txt��β��";
			string filename;
			cin>>filename;
		    dbUtil->exportMemberData(filename);
		}else if(index == 1){//����ԭʼ�ļ�����
			dbUtil->exportMemberData("");
		}else{
			cout<<"ѡ��������������룡"<<endl;
			goto loop6;
		}
		goto loop1;
	}else if(select == 4){//���￨���ݵ���
loop7:		cout<<"�Ƿ񸲸�ԭʼ�ļ�card.txt��0 �� 1 ��"<<endl;
		int index;
		cin>>index;
		if(index == 0){//�½��ļ�����
			cout<<"���������ļ���,��.txt��β��";
			string filename;
			cin>>filename;
		    dbUtil->exportCardData(filename);
		}else if(index == 1){//����ԭʼ�ļ�����
			dbUtil->exportCardData("");
		}else{
			cout<<"ѡ��������������룡"<<endl;
			goto loop7;
		}
		goto loop1;
	}
	else
	{
		cout<<"ѡ��������������룡"<<endl;
		goto loop1;
	}
}

