#pragma once
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


void User_haveAccount(std::vector<logpass>&);//вопрос о имении аккаунта
void Admin_haveAccount(std::vector<logpass>&);//вопрос о персонализации личности
int getInt(std::string);// получение целого
void menu();//меню 1-го уровня
void data_user_file(std::vector<logpass>& );//получение данных логина/пароля пользователя
void data_admin_file(std::vector<logpass>&);//получение данных логина/пароля админа
void admin_enter_account(std::vector<logpass>&);//вход под админом
std::string getString(std::string);//получение строки с сообщением
void data_client_file(std::vector<information>&);//получение инфы о клиенте из файла
void rewrite_user_file(std::vector<logpass>&);
void data_passport_file(std::vector<information>&);//получение идентификационного номера из файла
std::string yes_no(std::string);//получение ответа да/нет
std::string login(int, bool&, bool&);//проверка на ввод логина
std::string password(bool&);//проверка на ввод пароля
void user_file(std::vector<std::string>&, std::vector<std::string>&);//основа для самого частого пользователя
void trololo();//основа для самого частого пользователя
std::string ns(std::string);//проверка на ввод имени и фамилии
std::string client_code(std::string);//проверка на ввод кода клиента
std::string telephone_number(std::string);//проверка на телефонный номер
std::string ccs(std::string);// проверка на ввод страны, города и улицы
std::string hf(std::string);// проверка на номер дома и квартиры
std::string date(std::string);








class logpass {
public:
	logpass(std::string, std::string);// конструктор логин + пароль
	std::string password;//пароль
	std::string login;//логин
	bool operator==(logpass human);// перегрузка оператора ==
	logpass();// конструктор по умолчанию
	

};
class information {
public:
	information(std::string, std::string, std::string, std::string,std::string,std::string);// конструктор для всех полей кроме кода клиента
	std::string client_code;// код клиента/номер паспорта
	std::string name;//Имя
	std::string surname;//Фамилия
	std::string telephone_number;//Номер телефона
	std::string country;//Страна
	std::string city;//Город
	std::string street;//Улица
	std::string housenumber;//Номер дома
	std::string flatnumber;//Номер квартиры
	information();//Конструктор по умолчанию
	information(std::string, std::string, std::string);//конструктор для номера паспорта,имени и фамилии
	bool operator==(information user);//перегрузка оператора ==
};
class dogovor {
public:
	std::string name;//Название договора
	std::string document_code;//Код договора
	std::string service_code;// Код услуги
	std::string summ;//Сумма
	std::string commition;//Коммисионные
	dogovor();
	dogovor(std::string, std::string, std::string, std::string, std::string);
};
class data {
public:
	data(std::string);//конструктор даты
	data();//конструктор по умолчанию
	std::string day;//день
	std::string month;//месяц
	std::string year;//год
};
class Client {
public:
	logpass human;
	information user;
	dogovor dogovorka;
	data datas;
	Client();//конструктор по умолчанию
	Client(std::string);
	virtual void enterAccount(std::vector<logpass>&);
	void userMenu(std::vector<logpass>&);// меню пользователя
    void changelogpass(std::vector<logpass>&);//сменить пароль и логин
	int checkPasswords();//проверка на пароли
	
	


};
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) override ;//вход в аккаунт
	void CreateAccount(std::vector<logpass>&);//создание аккаунта
	void deleteAccount(std::vector<logpass>&);//удаление аккаунта
	void addlogpass();//добавить пользователя(логин и пароль)
	void adminMenu();//меню админа
	void add_user_information_dogovor();//добавить информацию о пользователе
	void changeinfo();
	bool add_client_code_into_dogovor();// проверить код клиента и добавить его в файл с договором
	void add_dogovor();//добавить договор
	bool check_login_once();//Для проверки есть ли такой пользователь в базе
};
