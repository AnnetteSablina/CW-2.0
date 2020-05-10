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
void User_haveAccount(std::vector<logpass>&);//вопрос о имении аккаунта
void Admin_haveAccount(std::vector<logpass>&);//вопрос о персонализации личности
int getInt(std::string);// получение целого
void menu();//меню 1-го уровня
void data_user_file(std::vector<logpass>& );//получение данных логина/пароля пользователя, чтение файла
void data_admin_file(std::vector<logpass>&);//получение данных логина/пароля админа, чтение файла
void admin_enter_account(std::vector<logpass>&);//вход под админом
std::string getString(std::string);//получение строки с сообщением
void data_client_file(std::vector<information>&);//получение инфы о клиенте из файла,чтение файла
void rewrite_user_file(std::vector<logpass>&);//перезапить файла с пользователями
void data_passport_file(std::vector<information>&);//получение идентификационного номера из файла
std::string yes_no(std::string);//получение ответа да/нет
std::string login(int, bool&, bool&);//проверка на ввод логина
std::string password(bool&);//проверка на ввод пароля
void top_10();//10 самых активных клиентов
std::string ns(std::string);//проверка на ввод имени и фамилии
std::string client_code(std::string);//проверка на ввод кода клиента
std::string telephone_number(std::string);//проверка на телефонный номер
std::string ccs(std::string);// проверка на ввод страны, города и улицы
std::string hf(std::string);// проверка на номер дома и квартиры
std::string date(std::string);//ввод даты
std::string service_code(std::string);//взятие номера договора
std::string dogovor_name(std::string);//взятие названия договора
void add_document_code();//добавление номера договора
std::string document_code(int, bool&);//проверка ввода договора
void dogovor_code(std::vector<dogovor>&);//чтение файла с номерами договоров
std::string summ(std::string);//проверка на сумму
void  data_dogovor_file(std::vector<Vivod>&);//чтение файла с договорами
void find_dogovor_number();//поиск по номеру договора
std::string dogovor_code1(std::string);// проверка на ввод данных договора
std::string vibor_1_2_3_4_5_6(std::string);// функция для выбора сортировки и поиска
void find_date();// поиск договорв по дате
void find_passport();// поиск договоров по номеру паспорта
void find_service();// поиск договоров по коду услуги
void sort();//сортировка по коду услуги
void changelogpass();//функция для изменения логина и пароля
std::string login1(std::string );// для проверки логина
std::string password1(std::string);//для проверки пароля
void changeinfo();// обновить информацию о пользователе
void data_magic_file(std::vector<information>&);//взятие данных о количестве заключенных людьми договоров
void rewrite_information_file(std::vector <information>&);//перезаписать файл с информацией
void rewrite_passport_file(std::vector <information>&);//перезписать файл с паспортными данными
void rewrite_magic_file(std::vector <information>&);//перепизаписать файл с количесвом заключенных договоров
void delete_user();//удаление пользователя
std::string admin_choise(std::string);//выбор пункта меню админестратора
bool addlogpass();//добавить пароль
std::string user_choise(std::string);//выбор пользователя меню
void find_user();//просмотриинформации о пользователе







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
	std::string client_code;// код клиента/номер паспорта
	std::string name;//Имя
	std::string surname;//Фамилия
	std::string telephone_number;//Номер телефона
	std::string country;//Страна
	std::string city;//Город
	std::string street;//Улица
	std::string housenumber;//Номер дома
	std::string flatnumber;//Номер квартиры
    std::string kolichestvo;//количество заключенных договоров
};
class dogovor {
public:
	std::string name;//Название договора
	std::string document_code;//Код договора
	std::string service_code;// Код услуги
	std::string summ;//Сумма
	std::string commition;//Комисcионные
	
};
class data {
public:
	std::string date;//дата
};
class Client {
public:
	logpass human;
	information user;
	dogovor dogovorka;
	data datas;
	virtual void enterAccount(std::vector<logpass>&);//Вход в аккаунт
	void userMenu();// меню пользователя
	
 };
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) override ;//вход в аккаунт
	void adminMenu();//меню админа
	void add_user_information_dogovor();//добавить информацию о пользователе
     bool add_client_code_into_dogovor();// проверить код клиента и добавить его в файл с договором
	void add_dogovor();//добавить договор
	bool check_login_once();//Для проверки есть ли такой пользователь в базе
	void vivod();
};
class Vivod {
public:
	std::string client_code;//номер паспорта
	std::string service_code;//код услуги
	std::string name;//имя пользователя
	std::string summ;//сумма
	std::string comission;//комиссионные
	std::string document_code;//номер договора
	std::string date;//дата подписания
};
