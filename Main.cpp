//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Main.cpp 
//�������������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
using namespace std;

void start(DbUtil *dbUtil);
void export_member_data(DbUtil *dbUtil);
void export_shopcard_data(DbUtil *dbUtil);

int _tmain(int argc, _TCHAR* argv[])
{
	cout.setf(ios::fixed);
	cout.precision(2);
	DbUtil *dbUtil = NULL;

	cout<<"----��ӭ����С�޹������ĺ�̨����ϵͳ----"<<endl<<endl;
	start(dbUtil);
	cout << endl << "*************��ӭ���ٴ�ʹ�ñ��������ϵͳ**************\n";
	system("pause");
	return 0;
}

void start(DbUtil *dbUtil)
{
	cout << "�װ�����ӪԱ�����ã�" << endl;
	cout << "���������Խ������²�����1������ 2���������ݵ��� 3:��Ա�����ݵ��� 4�����￨���ݵ��� 5����������" << endl;
	cout << "ѡ��";
	int select;
	cin >> select;
	if (select == 1){
		Pay *pay = new Pay(dbUtil);
		pay->pay_list();//����
	}
	else if (select == 2){
		dbUtil->importBaseData();//�������ݵ���

	}
	else if (select == 3){
		export_member_data(dbUtil);	//��Ա���ݵ���
	}
	else if (select == 4){
		export_shopcard_data(dbUtil);	//���￨���ݵ���
	}
	else if (select == 5){
		return;//�����������˳�ϵͳ
	}
	else{
		cout << "ѡ��������������룡" << endl;
	}
	start(dbUtil);
}

void export_member_data(DbUtil *dbUtil)
{
    cout << "�Ƿ񸲸�ԭʼ�ļ�member.txt��0 �� 1 ��" << endl;
	//dbUtil->createOriginalData();
	int index;
	cin >> index;
	if (index == 0){//�½��ļ�����
		cout << "���������ļ���,��.txt��β��";
		string filename;
		cin >> filename;
		dbUtil->exportMemberData(filename);
	}
	else if (index == 1){//����ԭʼ�ļ�����
		dbUtil->exportMemberData("");
	}
	else{
		cout << "ѡ��������������룡" << endl;
		export_member_data(dbUtil);
	}
}
void export_shopcard_data(DbUtil *dbUtil)
{
    cout << "�Ƿ񸲸�ԭʼ�ļ�card.txt��0 �� 1 ��" << endl;
	int index;
	cin >> index;
	if (index == 0){//�½��ļ�����
		cout << "���������ļ���,��.txt��β��";
		string filename;
		cin >> filename;
		dbUtil->exportCardData(filename);
	}
	else if (index == 1){//����ԭʼ�ļ�����
		dbUtil->exportCardData("");
	}
	else{
		cout << "ѡ��������������룡" << endl;
		export_shopcard_data(dbUtil);
	}
}