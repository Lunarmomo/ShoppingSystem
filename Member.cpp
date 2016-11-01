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

Member::Member(){}
Member::~Member(){}
