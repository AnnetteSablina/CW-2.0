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
class logpass;
class information;
class dogovor;
class data;
class Client;
class Vivod;


void User_haveAccount(std::vector<logpass>&);//������ � ������ ��������
void Admin_haveAccount(std::vector<logpass>&);//������ � �������������� ��������
int getInt(std::string);// ��������� ������
void menu();//���� 1-�� ������
void data_user_file(std::vector<logpass>& );//��������� ������ ������/������ ������������, ������ �����
void data_admin_file(std::vector<logpass>&);//��������� ������ ������/������ ������, ������ �����
void admin_enter_account(std::vector<logpass>&);//���� ��� �������
std::string getString(std::string);//��������� ������ � ����������
void data_client_file(std::vector<information>&);//��������� ���� � ������� �� �����,������ �����
void rewrite_user_file(std::vector<logpass>&);
void data_passport_file(std::vector<information>&);//��������� ������������������ ������ �� �����
std::string yes_no(std::string);//��������� ������ ��/���
std::string login(int, bool&, bool&);//�������� �� ���� ������
std::string password(bool&);//�������� �� ���� ������
void user_file(std::vector<std::string>&, std::vector<std::string>&);//������ ��� ������ ������� ������������
void trololo();//������ ��� ������ ������� ������������
std::string ns(std::string);//�������� �� ���� ����� � �������
std::string client_code(std::string);//�������� �� ���� ���� �������
std::string telephone_number(std::string);//�������� �� ���������� �����
std::string ccs(std::string);// �������� �� ���� ������, ������ � �����
std::string hf(std::string);// �������� �� ����� ���� � ��������
std::string date(std::string);//���� ����
std::string service_code(std::string);//������ ������ ��������
std::string dogovor_name(std::string);//������ �������� ��������
void add_document_code();//���������� ������ ��������
std::string document_code(int, bool&);//�������� ����� ��������
void dogovor_code(std::vector<dogovor>&);//������ ����� � �������� ���������
std::string summ(std::string);//�������� �� �����
void  data_dogovor_file(std::vector<Vivod>&);




class logpass {
public:
	logpass(std::string, std::string);// ����������� ����� + ������
	std::string password;//������
	std::string login;//�����
	bool operator==(logpass human);// ���������� ��������� ==
	logpass();// ����������� �� ���������
	

};
class information {
public:
	information(std::string, std::string, std::string, std::string,std::string,std::string);// ����������� ��� ���� ����� ����� ���� �������
	std::string client_code;// ��� �������/����� ��������
	std::string name;//���
	std::string surname;//�������
	std::string telephone_number;//����� ��������
	std::string country;//������
	std::string city;//�����
	std::string street;//�����
	std::string housenumber;//����� ����
	std::string flatnumber;//����� ��������
	information();//����������� �� ���������
	information(std::string, std::string, std::string);//����������� ��� ������ ��������,����� � �������
	bool operator==(information user);//���������� ��������� ==
};
class dogovor {
public:
	std::string name;//�������� ��������
	std::string document_code;//��� ��������
	std::string service_code;// ��� ������
	std::string summ;//�����
	std::string commition;//������������
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
	Client();//����������� �� ���������
	Client(std::string);
	virtual void enterAccount(std::vector<logpass>&);
	void userMenu(std::vector<logpass>&);// ���� ������������
    void changelogpass(std::vector<logpass>&);//������� ������ � �����
	int checkPasswords();//�������� �� ������
	
	


};
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) override ;//���� � �������
	void CreateAccount(std::vector<logpass>&);//�������� ��������
	void deleteAccount(std::vector<logpass>&);//�������� ��������
	void addlogpass();//�������� ������������(����� � ������)
	void adminMenu();//���� ������
	void add_user_information_dogovor();//�������� ���������� � ������������
	void changeinfo();
	bool add_client_code_into_dogovor();// ��������� ��� ������� � �������� ��� � ���� � ���������
	void add_dogovor();//�������� �������
	bool check_login_once();//��� �������� ���� �� ����� ������������ � ����
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