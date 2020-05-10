#pragma once
#include "table_printer.h"
#define _USE_MATH_DEFINES
#include <math.h>
#if defined(USE_BOOST_KARMA)
#include <boost/spirit/include/karma.hpp>
namespace karma = boost::spirit::karma;
#endif
using bprinter::TablePrinter;
#include "Sha256.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include<Windows.h>
#include <locale.h>
#include <vector>
#include <conio.h>
#include<algorithm>
class logpass;
class information;
class dogovor;
class data;
class Client;
class Vivod;

void add_information();//добавить информацию о пользователе
void User_haveAccount(std::vector<logpass>&);//âîïðîñ î èìåíèè àêêàóíòà
void Admin_haveAccount(std::vector<logpass>&);//âîïðîñ î ïåðñîíàëèçàöèè ëè÷íîñòè
int getInt(std::string);// ïîëó÷åíèå öåëîãî
void menu();//ìåíþ 1-ãî óðîâíÿ
void data_user_file(std::vector<logpass>& );//ïîëó÷åíèå äàííûõ ëîãèíà/ïàðîëÿ ïîëüçîâàòåëÿ, ÷òåíèå ôàéëà
void data_admin_file(std::vector<logpass>&);//ïîëó÷åíèå äàííûõ ëîãèíà/ïàðîëÿ àäìèíà, ÷òåíèå ôàéëà
void admin_enter_account(std::vector<logpass>&);//âõîä ïîä àäìèíîì
std::string getString(std::string);//ïîëó÷åíèå ñòðîêè ñ ñîîáùåíèåì
void data_client_file(std::vector<information>&);//ïîëó÷åíèå èíôû î êëèåíòå èç ôàéëà,÷òåíèå ôàéëà
void rewrite_user_file(std::vector<logpass>&);
void data_passport_file(std::vector<information>&);//ïîëó÷åíèå èäåíòèôèêàöèîííîãî íîìåðà èç ôàéëà
std::string yes_no(std::string);//ïîëó÷åíèå îòâåòà äà/íåò
std::string login(int, bool&, bool&);//ïðîâåðêà íà ââîä ëîãèíà
std::string password(bool&);//ïðîâåðêà íà ââîä ïàðîëÿ
void top_10();//10 ñàìûõ àêòèâíûõ êëèåíòîâ
std::string ns(std::string);//ïðîâåðêà íà ââîä èìåíè è ôàìèëèè
std::string client_code(std::string);//ïðîâåðêà íà ââîä êîäà êëèåíòà
std::string telephone_number(std::string);//ïðîâåðêà íà òåëåôîííûé íîìåð
std::string ccs(std::string);// ïðîâåðêà íà ââîä ñòðàíû, ãîðîäà è óëèöû
std::string hf(std::string);// ïðîâåðêà íà íîìåð äîìà è êâàðòèðû
std::string date(std::string);//ââîä äàòû
std::string service_code(std::string);//âçÿòèå íîìåðà äîãîâîðà
std::string dogovor_name(std::string);//âçÿòèå íàçâàíèÿ äîãîâîðà
void add_document_code();//äîáàâëåíèå íîìåðà äîãîâîðà
std::string document_code(int, bool&);//ïðîâåðêà ââîäà äîãîâîðà
void dogovor_code(std::vector<dogovor>&);//÷òåíèå ôàéëà ñ íîìåðàìè äîãîâîðîâ
std::string summ(std::string);//ïðîâåðêà íà ñóììó
void  data_dogovor_file(std::vector<Vivod>&);//÷òåíèå ôàéëà ñ äîãîâîðàìè
void find_dogovor_number();//ïîèñê ïî íîìåðó äîãîâîðà
std::string dogovor_code1(std::string);// ïðîâåðêà íà ââîä äàííûõ äîãîâîðà
std::string vibor_1_2_3_4_5_6(std::string);// ôóíêöèÿ äëÿ âûáîðà ñîðòèðîâêè è ïîèñêà
void find_date();// ïîèñê äîãîâîðâ ïî äàòå
void find_passport();// ïîèñê äîãîâîðîâ ïî íîìåðó ïàñïîðòà
void find_service();// ïîèñê äîãîâîðîâ ïî êîäó óñëóãè
void sort();//ñîðòèðîâêà ïî êîäó óñëóãè
void changelogpass();//ôóíêöèÿ äëÿ èçìåíåíèÿ ëîãèíà è ïàðîëÿ
std::string login1(std::string );// äëÿ ïðîâåðêè ëîãèíà
std::string password1(std::string);//äëÿ ïðîâåðêè ïàðîëÿ
void changeinfo();// îáíîâèòü èíôîðìàöèþ î ïîëüçîâàòåëå
void data_magic_file(std::vector<information>&);//âçÿòèå äàííûõ î êîëè÷åñòâå çàêëþ÷åííûõ ëþäüìè äîãîâîðîâ
void rewrite_information_file(std::vector <information>&);//ïåðåçàïèñàòü ôàéë ñ èíôîðìàöèåé
void rewrite_passport_file(std::vector <information>&);//ïåðåçïèñàòü ôàéë ñ ïàñïîðòíûìè äàííûìè
void rewrite_magic_file(std::vector <information>&);//ïåðåïèçàïèñàòü ôàéë ñ êîëè÷åñâîì çàêëþ÷åííûõ äîãîâîðîâ
void delete_user();//óäàëåíèå ïîëüçîâàòåëÿ
std::string admin_choise(std::string);//âûáîð ïóíêòà ìåíþ àäìèíåñòðàòîðà
bool addlogpass();//äîáàâèòü ïàðîëü
std::string user_choise(std::string);//âûáîð ïîëüçîâàòåëÿ ìåíþ






class logpass {
public:
	logpass(std::string, std::string);// êîíñòðóêòîð ëîãèí + ïàðîëü
	std::string password;//ïàðîëü
	std::string login;//ëîãèí
	bool operator==(logpass human);// ïåðåãðóçêà îïåðàòîðà ==
	logpass();// êîíñòðóêòîð ïî óìîë÷àíèþ
	

};
class information {
public:
	information(std::string, std::string, std::string, std::string,std::string,std::string,std::string);// êîíñòðóêòîð äëÿ âñåõ ïîëåé êðîìå êîäà êëèåíòà
	std::string client_code;// êîä êëèåíòà/íîìåð ïàñïîðòà
	std::string name;//Èìÿ
	std::string surname;//Ôàìèëèÿ
	std::string telephone_number;//Íîìåð òåëåôîíà
	std::string country;//Ñòðàíà
	std::string city;//Ãîðîä
	std::string street;//Óëèöà
	std::string housenumber;//Íîìåð äîìà
	std::string flatnumber;//Íîìåð êâàðòèðû
    std::string kolichestvo;//êîëè÷åñòâî çàêëþ÷åííûõ äîãîâîðîâ
	information(std::string);
	information();//Êîíñòðóêòîð ïî óìîë÷àíèþ
	information(std::string, std::string, std::string);//êîíñòðóêòîð äëÿ íîìåðà ïàñïîðòà,èìåíè è ôàìèëèè
   bool operator == ( information user );//ïåðåãðóçêà îïåðàòîðà ==
};
class dogovor {
public:
	std::string name;//Íàçâàíèå äîãîâîðà
	std::string document_code;//Êîä äîãîâîðà
	std::string service_code;// Êîä óñëóãè
	std::string summ;//Ñóììà
	std::string commition;//Êîììèñèîííûå
	dogovor();
	dogovor(std::string);
	dogovor(std::string, std::string, std::string, std::string);
};
class data {
public:
	std::string date;
	data(std::string);
	data();
};
class Client {
public:
	logpass human;
	information user;
	dogovor dogovorka;
	data datas;
	virtual void enterAccount(std::vector<logpass>&);//Âõîä â àêêàóíò
	void userMenu();// ìåíþ ïîëüçîâàòåëÿ
	
 };
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) override ;//âõîä â àêêàóíò
	void adminMenu();//ìåíþ àäìèíà
	void add_user_information_dogovor();//äîáàâèòü èíôîðìàöèþ î ïîëüçîâàòåëå
     bool add_client_code_into_dogovor();// ïðîâåðèòü êîä êëèåíòà è äîáàâèòü åãî â ôàéë ñ äîãîâîðîì
	void add_dogovor();//äîáàâèòü äîãîâîð
	bool check_login_once();//Äëÿ ïðîâåðêè åñòü ëè òàêîé ïîëüçîâàòåëü â áàçå
	void vivod();
};
class Vivod {
public:
	std::string client_code;
	std::string service_code;
	std::string name;
	std::string summ;
	std::string comission;
	std::string document_code;
	std::string date;
};
