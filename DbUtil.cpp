//ѧ�ţ�1352910 
//��������ͬ     
//�ļ�����DbUtil.cpp 
//����:���ݿ������Ĵ���

#include "stdafx.h"
#include "DbUtil.h"
//#include "atlstr.h"
//#include<string>
//#include<tchar.h>

MYSQL *DbUtil::myConn;


char* TCHAR2char(TCHAR* tchStr) 
{ 
	size_t i;
int iLen = 2*wcslen(tchStr);//CString,TCHAR������һ���ַ�����˲�����ͨ���㳤�� 
char* chRtn = new char[iLen+1] ;
wcstombs_s(&i,chRtn,(size_t)(iLen+1),tchStr,(size_t)(iLen+1));//ת���ɹ�����Ϊ�Ǹ�ֵ 
return chRtn; 
} 

string& replace_all(string& str,const   string&   old_value,const   string&   new_value)     
{     
    while(true)   {     
        string::size_type   pos(0);     
        if(   (pos=str.find(old_value))!=string::npos   )     
            str.replace(pos,old_value.length(),new_value);     
        else   break;     
    }     
    return   str;     
}  

void DbUtil::createOriginalData()
{
	//ofstream fout("C:/Users/hank/Desktop/��ҵ/record.txt");
	ofstream fout1("./database/card.txt");
	if(fout1.is_open())
	{
		for(int i=1;i<=100;i++){
			fout1<<i<<"\t";
			fout1<<i*100<<endl;
		}
		fout1.close();
	}
	ofstream fout2("./database/member.txt");
	if(fout2.is_open())
	{
		for(int i=1;i<=100;i++){
			fout2<<i<<"\t";
			fout2<<"���»�"<<i<<"\t";
			if(i%2 == 0){
				fout2<<"��"<<"\t";
			}else{
				fout2<<"Ů"<<"\t";
			}
			fout2<<1509999000+i<<"\t";
			fout2<<1000<<"\t";
			fout2<<"3"<<endl;
		}
		fout2.close();
	}
	ofstream fout3("./database/items.txt");
	if(fout3.is_open())
	{
		for(int i=1;i<=100;i++){
			fout3<<i<<"\t";
			fout3<<"ƻ��"<<i<<"\t";
			fout3<<"����"<<i<<"\t";
			fout3<<i*10<<endl;
		}
		fout3.close();
	}
}

bool DbUtil::exportCardData(string filename){

	TCHAR buf[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,buf);
	char *dic = TCHAR2char(buf);
	string path = dic;
	fstream out_file;
	string filepath;
	if(filename == ""){//����ǿվ͸���ԭʼ�ļ�
		filepath = path + "\\database\\card.txt";
	}else{
		filepath = path + "\\database\\" + filename;
	}
	out_file.open(filepath,ios::in);
    if(out_file){//������ڸ��ļ�������ɾ��
		out_file.close();
		remove(filepath.c_str());
	}
	out_file.close();
	filepath = replace_all(filepath,"\\","/");//��ȡ��ǰ����Ŀ¼
	//filepath = "C:/Users/hank/Desktop/����pnr����/��ҵ/member3.txt";
	string sql = "select card_code,card_money into outfile '" + filepath +  "' lines terminated by '\r\n' from card";
	mysql_query(myConn,sql.c_str());//�������￨����
	long row = mysql_affected_rows(myConn);//������¼��
	cout<<mysql_error(myConn)<<endl;
	if(row > 0)
	{
		cout<<"�ɹ��������￨��¼��"<<row<<"��"<<endl;
		cout<<"�ļ�·��Ϊ��"<<filepath<<endl;
	}else
	{
		cout<<"���￨��¼��������"<<endl;
	}
	cout<<endl;
	return true;
}

bool DbUtil::exportMemberData(string filename){

	TCHAR buf[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,buf);
	char *dic = TCHAR2char(buf);
	string path = dic;
	fstream out_file;
	string filepath;
	if(filename == ""){
		filepath = path + "\\database\\member.txt";
	}else{
		filepath = path + "\\database\\" + filename;
	}
	out_file.open(filepath,ios::in);
    if(out_file){//������ڸ��ļ�������ɾ��
		out_file.close();
		remove(filepath.c_str());
	}
	out_file.close();
	filepath = replace_all(filepath,"\\","/");//��ȡ��ǰ����Ŀ¼
	//filepath = "C:/Users/hank/Desktop/��ҵ/member3.txt";
	string sql = "select mem_code,mem_name,mem_sex,mem_phone,mem_score,mem_type into outfile '" + filepath +  "' lines terminated by '\r\n' from member";
	mysql_query(myConn,sql.c_str());//������Ա����
	long row = mysql_affected_rows(myConn);//������¼��
	cout<<mysql_error(myConn)<<endl;
	if(row > 0)
	{
		cout<<"�ɹ�������Ա��¼��"<<row<<"��"<<endl;
		cout<<"�ļ�·��Ϊ��"<<filepath<<endl;
	}else
	{
		cout<<"��Ա��¼��������"<<endl;
	}
	cout<<endl;
	return true;
}

Member *DbUtil::GetMember(string memCode){
	string sql = "select * from member where mem_code = " + memCode;
	mysql_query(myConn,sql.c_str());//��ѯ
	MYSQL_RES *result = mysql_store_result(myConn);//�ý��
	unsigned int fieldCount = result->field_count;
	MYSQL_ROW row;
	Member *member = new Member();
	while(row = mysql_fetch_row(result))
	{
		member->setMemCode(row[1]);
		member->setMemName(row[2]);
		member->setMemSex(row[3]); 
		member->setMemPhone(row[4]); 
		member->setMemScore(atof(row[5]));
		member->setMemType(row[6]);
	}
	return member;
}
bool DbUtil::UpdateMember(string memCode,double newMemScore,string newMemType){
	ostringstream oss;
	oss<<newMemScore;
	string typeAppend = "";
	if(!newMemType.empty()){
		typeAppend += ",mem_type=" + newMemType;
	}
	string sql = "update member set mem_score = " + oss.str() + typeAppend + " where mem_code = " + memCode;
	mysql_query(myConn,sql.c_str());//���� 
	long affectRow = mysql_affected_rows(myConn);//��ȡ���θ��µ�������0��ʾδ�ҵ�where����Ӧ���У�-1��ʾ����
	if(affectRow > 0)
	{
		return true;
	}else
	{
		return false;
	}
}
bool DbUtil::importBaseData()
{
	//lines terminated by '\r\n' ��ֹ���һ���ַ�������/r
	//string itemsSql = "load data local infile './database/items.txt' into table items character set gbk lines terminated by '\r\n' (item_code,item_name,item_place,item_price)";
	//string cardSql = "load data local infile './database/card.txt' into table card character set gbk lines terminated by '\r\n' (card_code,card_money)";
	//string memberSql = "load data local infile './database/member.txt' into table member character set gbk lines terminated by '\r\n' (mem_code,mem_name,mem_sex,mem_phone,mem_score,mem_type)";
	string itemsSql = "load data local infile 'D:/github/ShoppingSystem/database/items.txt' into table items character set gbk (item_code,item_name,item_place,item_price)";
	string cardSql = "load data local infile 'D:/github/ShoppingSystem/database/card.txt' into table card character set gbk (card_code,card_money)";
	string memberSql = "load data local infile 'D:/github/ShoppingSystem/database/member.txt' into table member character set gbk (mem_code,mem_name,mem_sex,mem_phone,mem_score,mem_type)";
	mysql_query(myConn,itemsSql.c_str());//������Ʒ����
	long itemsRow = mysql_affected_rows(myConn);//�����¼��
	mysql_query(myConn,cardSql.c_str());//���빺�￨����
	long cardRow = mysql_affected_rows(myConn);//�����¼��
	mysql_query(myConn,memberSql.c_str());//�����Ա����
	long memberRow = mysql_affected_rows(myConn);//�����¼��
	//��ȡ���θ��µ�������0��ʾδ�ҵ�where����Ӧ���У�-1��ʾ����
	if(itemsRow > 0)
	{
		cout<<"�ɹ�������Ʒ��¼��"<<itemsRow<<"��"<<endl;
	}else
	{
		cout<<"��Ʒ��¼������������items.txt�ı����ݺ͸�ʽ��"<<endl;
	}
	if(cardRow > 0)
	{
		cout<<"�ɹ����빺�￨��¼��"<<cardRow<<"��"<<endl;
	}else
	{
		cout<<"���￨��¼������������card.txt�ı����ݺ͸�ʽ��"<<endl;
	}
	if(memberRow > 0)
	{
		cout<<"�ɹ�������Ʒ��¼��"<<memberRow<<"��"<<endl;
	}else
	{
		cout<<"��Ʒ��¼������������member.txt�ı����ݺ͸�ʽ��"<<endl;
	}
	cout<<endl;
	return true;
}

bool DbUtil::UpdateCards(string cardCode,double newCardMoney)
{
	ostringstream oss;
	oss<<newCardMoney;
	string sql = "update card set card_money = " + oss.str() + " where card_code = " + cardCode;
	mysql_query(myConn,sql.c_str());//���� 
	long affectRow = mysql_affected_rows(myConn);//��ȡ���θ��µ�������0��ʾδ�ҵ�where����Ӧ���У�-1��ʾ����
	if(affectRow > 0)
	{
		return true;
	}else
	{
		return false;
	}
}
Cards *DbUtil::GetCards(string cardCode)
{
	string sql = "select * from card where card_code = " + cardCode;
	mysql_query(myConn,sql.c_str());//��ѯ
	MYSQL_RES *result = mysql_store_result(myConn);//�ý��
	unsigned int fieldCount = result->field_count;
	MYSQL_ROW row;
	Cards *card = new Cards();
	while(row = mysql_fetch_row(result))
	{
		card->setCardCode(row[1]);
		card->setCardMoney(atof(row[2]));
	}
	return card;
}
Items *DbUtil::GetItems(string itemCode)
{
	string sql = "select * from items where item_code = " + itemCode;
	mysql_query(myConn,sql.c_str());//��ѯ
	MYSQL_RES *result = mysql_store_result(myConn);//�ý��
	unsigned int fieldCount = result->field_count;
	MYSQL_ROW row;
	Items *item = new Items();
	while(row = mysql_fetch_row(result))
	{
		item->SetItemCode(row[1]);
		item->SetItemName(row[2]);
		item->SetItemPlace(row[3]);
		item->SetItemPrice(atof(row[4]));
	}
	return item;
}

void DbUtil::closeConn()
{
	Utils::closeConnect(myConn);
}

DbUtil::DbUtil()
{
	myConn = Utils::GetConn();
}
DbUtil::~DbUtil()
{
}
