//学号：1352910 
//姓名：周同     
//文件名：Member.h
//描述:会员卡信息类 

#pragma once
using namespace std;
class Member
{
	string mem_code;
	string mem_name;
	string mem_sex;
	string mem_phone;
	double mem_score;
	string mem_type;
public:
	string getMemCode();
	string getMemName();
	string getMemSex();
	string getMemPhone();
	double getMemScore();
	string getMemType();
	void setMemCode(string memCode);
	void setMemName(string memName);
	void setMemSex(string memSex);
	void setMemPhone(string memPhone);
	void setMemScore(double memScore);
	void setMemType(string memType);
	Member();
	~Member();
};

