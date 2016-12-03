//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����Member.cpp
//����:��Ա����Ϣ��Ĵ��� 

#include "stdafx.h"
#include "Member.h"


string Member::getMemCode(){
	return mem_code;
}
string Member::getMemName(){
	return mem_name;
}
string Member::getMemSex(){
	return mem_sex;
}
string Member::getMemPhone(){
	return mem_phone;
}
double Member::getMemScore(){
	return mem_score;
}
string Member::getMemType(){
	return mem_type;
}
void Member::setMemCode(string memCode){
	mem_code = memCode;
}
void Member::setMemName(string memName){
	mem_name = memName;
}
void Member::setMemSex(string memSex){
	mem_sex = memSex;
}
void Member::setMemPhone(string memPhone){
	mem_phone = memPhone;
}
void Member::setMemScore(double memScore){
	mem_score = memScore;
}
void Member::setMemType(string memType){
	mem_type = memType;
}
//ͨ����Ա��������뷵�ػ�Ա�����ļ������
string Member::getMemberTypeStr(){
	if (mem_type == "1"){
		return "��";
	}
	else if (mem_type == "2"){
		return "����";
	}
	else if (mem_type == "3"){
		return "��ͨ��Ա";
	}
	else{
		return "�ǻ�Ա";
	}

}
//ͨ�����ֻ�ȡ��Ӧ�Ļ�Ա����
string Member::getMemberType(){
	if (mem_score < 10000.00){
		return "3";
	}
	else if (mem_score < 50000.00){
		return "2";
	}
	else{
		return "1";
	}
}
//�����Ա�������Լ�ʵ�����ѽ��,���ر�����������ȡ�Ļ���
double Member::getMemberScore( double money){
	double memScore = 0.0;
	if (mem_type == "1"){
		if (money <= 1000.00){
			memScore = 1.5*money;
		}
		else if (money <= 5000.00){
			memScore = 1.5 * 1000 + (money - 1000)*1.8;
		}
		else{
			memScore = 1.5 * 1000 + (5000 - 1000)*1.8 + (money - 5000) * 2;
		}
	}
	else if (mem_type == "2"){
		if (money <= 2000.00){
			memScore = 1.2*money;
		}
		else if (money <= 5000.00){
			memScore = 1.2 * 2000 + (money - 2000)*1.5;
		}
		else{
			memScore = 1.8 * 2000 + (5000 - 2000)*1.5 + (money - 5000)*1.8;
		}
	}
	else if (mem_type == "3"){
		memScore = 0.5*money;
	}
	return memScore;
}
Member::Member(){}
Member::~Member(){}
