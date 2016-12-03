//学号：1352910 
//姓名：周同     
//文件名：Member.cpp
//描述:会员卡信息类的处理 

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
//通过会员卡级别代码返回会员卡中文级别解释
string Member::getMemberTypeStr(){
	if (mem_type == "1"){
		return "金卡";
	}
	else if (mem_type == "2"){
		return "银卡";
	}
	else if (mem_type == "3"){
		return "普通会员";
	}
	else{
		return "非会员";
	}

}
//通过积分获取对应的会员级别
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
//输入会员卡级别以及实际消费金额,返回本次消费所获取的积分
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
