#include"Header.h"
void menu(){ 
	std::vector<logpass>admins;
	data_admin_file(admins);
	std::vector <logpass> users;
	data_user_file(users);
	system("cls");
	std::string a;
	while (true) {
	system("cls");
	std::cout << "�������: \n 1.���� �� ����� ��������������. \n 2.���� �� ����� ������������. \n 3.������ ����� �� ���������" << std::endl;
	getline(std::cin, a);
	if (a != "1" && a != "2" && a != "3")continue;
    else break;
	}
	if (a=="1"){
	system("cls");
	Admin_haveAccount(admins);
    }
   if (a == "2") {
   system("cls");
    User_haveAccount(users);}
   if (a == "3") {
	system("cls");
	std::cout << "\n�� ������� ����� �� ���������." << std::endl;
	exit(0);
   }
 return;
}	
void Admin_haveAccount(std::vector<logpass>&admins) {
	std::string a;
	bool run = true;
	Admin admin;
	while (true) {
		system("cls");
		std::cout << "�� ����� �������������? \n �������: \n 1.��.\n 2.���." << std::endl;
		getline(std::cin, a);
		if (a != "1" && a != "2")continue;
		else break;
	}
	if (a == "1") {
		system("cls");
		admin.enterAccount(admins);
	}
	if (a == "2") {
		system("cls");
		std::cout << "������� ��� ������������ ���� ����������������� � ��������������" << std::endl;
		Sleep(2000);
		menu();
	}
	}
void data_admin_file(std::vector<logpass>& admins) {
std::ifstream file("admins.txt");
while (file)
{	logpass temp;
	getline(file, temp.login);
	getline(file, temp.password);
    admins.push_back(temp);
}
if (!admins.empty()) admins.erase(admins.end() - 1);
file.close();
}
void Admin::enterAccount(std::vector<logpass>&admins) {
	system("cls");
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			human.login=login(1, access, exit);
		}
		if(!access) {
			human.login=login(2, access, exit);
		};
		if (exit) {
			break;
		};
	human.password=password(exit);
		if (exit) {
			break;
		};
		access = true;
		logpass check(human.login,sha256(human.password));
		if (std::find(admins.begin(), admins.end(), check) == admins.end()) {
			access = false;
		}

	} while (!access);
	if (exit) {
		menu();
	}
	if (access) {
		adminMenu();
	}

};
void Admin::adminMenu() {
	std::string choice5 = "";
	std::string choice4 = "";
	std::string choice7 = "";
	std::string vibor = "";
	bool check = true;
	std::string choice8=admin_choise(" ���� ��������������  \n  �������: \n 1.��������� ����� �������. \n 2.�������������� ���������� � ������������. \n 3.�������� ����������� ���������. \n 4.����� � ���������� ������. \n 5.���������� ������ � ������ ������ ������������ ��� ���������� � ���. \n 6.�������� ������������ �� ����(������������ � ������ ��� ������). \n 7.��� 10 ����� �������� ��������. \n 8.��������� � ������� ����." );
	if (choice8 == "1") {
		system("cls");
		choice8 = yes_no("������ ����� ����� � ������? ������� yes ��� no.");
		while (true) {
			bool l=false;
			if (choice8 == "yes") {
				check = true;
				check = check_login_once();
				if (!check) {
					system("cls");
					std::cout << "������������ � ����� ������� �� ����������." << std::endl;
					std::cout << "�������� ��� � ����." << std::endl;
					system("pause");
					l = addlogpass();
				}
			}
			else {
				system("cls");
				std::cout << "�������� ���������� � ������������." << std::endl;
				system("pause");
				l = addlogpass();
			}
			if (l) {adminMenu(); return;}
			else break;
		}
		system("pause");
		choice5 = yes_no("������ ����� ����������� ������ � ����? ������� yes ��� no.");
		if (choice5 == "yes") {
			check = add_client_code_into_dogovor();
			if (check) {
				system("cls");
				std::cout << "���������� �� ���� ������������ �� ���� � �� �������� ��� ����������������� ����� � ����." << std::endl;
				std::cout << "������� ���������� � ������������." << std::endl;
				system("pause");
				add_user_information_dogovor();
				std::cout << "������ ������� ���������." << std::endl;
				system("pause");
				add_dogovor();
			}
			else {
				system("cls");
				std::cout << "������ ������� ��� ���� � ����." << std::endl;
				system("pause");
				add_dogovor();
			}
		}
		else {
			check = add_client_code_into_dogovor();
			if (check) {
				system("cls");
				std::cout << "���������� �� ���� ������������ �� ���� � �� �������� ��� ����������������� ����� � ����." << std::endl;
				std::cout << "������� ���������� � ������������." << std::endl;
				system("pause");
				add_user_information_dogovor();
				std::cout << "������ ������� ���������." << std::endl;
				system("pause");
				add_dogovor();
				return;

			}
			else {
				system("cls");
				std::cout << "������ ������� ��� ���� � ����." << std::endl;
				system("pause");
				add_dogovor();
				return;
			}

		}
		
	}
	if (choice8 == "2") {
		system("cls");
		choice7.clear();
		while (true) {
			system("cls");
			std::cout << " �������:  \n 1.���� ������ �������� ������ ������ � ������ \n 2.���� ������ �������� ���������� � ������������. \n 3.��������� � ���� ������ " << std::endl;
			getline(std::cin, choice7);
			if (choice7 != "1" && choice7 != "2" && choice7 != "3")
				continue;
			else break;
		}
		system("cls");
		if (choice7 == "1") { changelogpass();}
		if (choice7 == "2") { changeinfo(); }
		if (choice7 == "3") { adminMenu(); return; }
		system("pause");
		choice5.clear();
		choice5 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice5 == "yes") { adminMenu(); return; }
		else { menu(); return; }
		return;
	}
	if (choice8 == "3") {
		system("cls");
		vivod();
		return;
	}
	if (choice8 == "4") {
		system("cls");
		choice5.clear();
		vibor = vibor_1_2_3_4_5_6(" ������� : \n 1. ���� ������ ����������� ����� �� ������ ��������. \n 2. ���� ������ ����������� ����� �� ������ �������� \n 3. ���� ������ ����������� ����� �� ������ ������. \n 4. ���� ������ ����������� ����� �� ����. \n 5. ���� ������ ����������� ���������� � ������������. \n 6. ���� ������ ����������� �� ���� ������. \n 7. ��������� � ���� �������������.");
		system("cls");
		if (vibor == "1") find_dogovor_number();
		if (vibor == "2") find_passport();
		if (vibor == "3") find_service();
		if (vibor == "4") find_date();
		if (vibor == "5") find_user();
		if (vibor == "6") sort();
		if (vibor == "7") { adminMenu(); return; }
		choice5.clear();
		system("pause");
		choice5 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice5 == "yes")adminMenu();
		else menu();
		return;
	}
	if (choice8 == "5") {
		system("cls");
		choice7.clear();
		while (true) {
			system("cls");
			std::cout << " �������:  \n 1.���� ������ �������� ����� � ������ \n 2.���� ������ �������� ���������� � ������������. \n 3.��������� � ���� ��������������. " << std::endl;
			getline(std::cin, choice7);
			if (choice7 != "1" && choice7 != "2" && choice7 != "3")
				continue;
			else break;
		}
		if (choice7 == "1") {
			bool n = addlogpass();
			if (n) {
				adminMenu();
			}
		}
		if (choice7 == "2") add_information();
		if (choice7 == "3") adminMenu(); 
		system("pause");
		choice5.clear();
		choice5 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice5 == "yes") adminMenu();
		else menu(); 
		return;

	}
	if (choice8 == "6") {
		system("cls");
		std::string choice0 = yes_no("�� ����� ������� � ���, ��� ������ ������� ������������? \n 1.������� 'yes',���� �� \n 2.������� 'no',���� ��� ��� ��� ���� ��������� �������. ��������� � ���� ��������������.");
		if (choice0 == "yes") delete_user(); 
		if (choice0 == "no")  adminMenu(); 
		choice4 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice4 == "yes") adminMenu();
		else menu();
		return;
	}
	if (choice8 == "7") {
		system("cls");
		top_10();
		system("pause");
		choice5.clear();
		choice5 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice5 == "yes")adminMenu();
		else  menu(); 
		return;
	}
	if (choice8 == "8") {
		system("cls");
		menu();
		return;
	}
}
bool Admin::add_client_code_into_dogovor() {
	system("cls");
	int u = 0;
	bool next;
	information user;
	std::vector<information> passport;
	data_passport_file(passport);
	user.client_code = client_code("������� ����� ��������.");
	for (auto i : passport) {
	 if (i.client_code == user.client_code) {
		u++;
		system("cls");
	  std::ofstream file2("dogovor.txt", std::ios::app);
	  file2 << user.client_code<< std::endl;
	  file2.close();
	  std::ofstream file3("magic.txt", std::ios::app);
	  file3 << user.client_code << std::endl << i.name << std::endl << i.surname << std::endl;
	  file3.close();
      next = false;
		}
	  }
	if(u==0){
		std::ofstream file("passport.txt", std::ios::app);
		file << user.client_code<< std::endl;
		file.close();
		std::ofstream file1("dogovor.txt", std::ios::app);
		file1 << user.client_code << std::endl;
		file1.close();
		std::ofstream file4("magic.txt", std::ios::app);
		file4 << user.client_code << std::endl;
		file4.close();
		std::ofstream file5("info.txt", std::ios::app);
		file5 << user.client_code << std::endl;
		file5.close();
		next = true;
	}
return next;
}
void Admin::add_user_information_dogovor(){
	system("cls");
	information user;
	user.name = ns("������� ���.");
	user.surname = ns("������� �������.");
	user.telephone_number = telephone_number("������� ����� �������� �������.");
	user.country = ccs("������� ������ ����������");
	user.city = ccs("������� ����� ����������.");
	user.street = ccs("������� ����� ����������.");
	user.housenumber = hf("������� ����� ����.");
	user.flatnumber = hf("������� ����� ��������. ������� 0, ���� ������ ��������� � ������� ����.");
	std::ofstream file("magic.txt",std::ios::app);
	file << user.name << std::endl << user.surname << std::endl;
	file.close();
	std::ofstream file1("info.txt", std::ios::app);
	file1 << user.name << std::endl << user.surname << std::endl << user.telephone_number << std::endl << user.country << std::endl << user.city << std::endl << user.street << std::endl << user.housenumber << std::endl << user.flatnumber << std::endl;
	file1.close();
	std::ofstream file2("passport.txt", std::ios::app);
	file2 << user.name << std::endl << user.surname << std::endl;
	file2.close();
	return;
}
bool addlogpass() {
	system("cls");
	logpass human;
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			human.login = login(1, access, exit);
		}
		else {
			human.login = login(3, access, exit);
		}
		if (exit) break;
		std::ifstream file("users.txt");
		while (file)
		{
			std::string tmp;
			getline(file, tmp);
			if (tmp == human.login)
			{
				access = false;
				break;
			}
			else {
				access = true;
			}
			getline(file, tmp);
		}
		file.close();
		if (access) {
		human.password = password(exit);
	    }
		if (exit) break;
	} while (!access);
	if (!exit)
	{
		std::ofstream file1("users.txt", std::ios::app);
		file1  << human.login << std::endl << sha256( human.password )<< std::endl;
		file1.close();
		system("cls");
		std::cout << "�� �������� ������������ � ����." << std::endl;
	}
	return exit;
}
bool Admin::check_login_once() {
	system("cls");
	bool check = true;
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			this->human.login = login(1, access, exit);
		}
		if (exit) break;
		access = true;
		std::vector<logpass> users;
		data_user_file(users);
		if (users.empty()) {
			check = false;
		}
		for (auto i : users)
		{
			if (i.login == this->human.login)
			{
				system("cls");
				std::cout << "������������ � ����� ������� ������������� ����." << std::endl;
				check = true;
				access = true;
				break;
			}
			else {
				check = false;
			}
		}
	} while (!access);
	if (exit) {
		adminMenu();
	}
	return check;
}
void Admin::add_dogovor() {
	std::vector <dogovor> documentCode;
	dogovor_code(documentCode);
	system("cls");
	dogovor dogovor;
	std::cout << "������� ������ ��������." << std::endl;
	dogovor.service_code = service_code("������� ����� ������.\n 1111 - ������������. \n 2222 - ������� �������. \n 3333 - ���������. \n 4444 - ������������. \n 5555 - �������������� �������. \n 6666 - ���������� ����������� ���������. \n 7777 - ���������� �� ������ ���������. \n 8888 - ���������� �� ����� ������� �� ������. \n 9999 - ��������. ");
	dogovor.name = dogovor_name(dogovor.service_code);
	system("cls");
	dogovor.summ=summ("������� ����� �� 100.000.000");
	dogovor.commition = summ ("������� ������������.");
	std::ofstream file8("dogovor.txt", std::ios::app);
	file8 << dogovor.service_code << std::endl << dogovor.name << std::endl << dogovor.summ << std::endl << dogovor.commition << std::endl;
	file8.close();
	add_document_code();
	Sleep(3000);
	std::string choice = yes_no("��� �� ������ ����������? ������� 'yes' , ���� ������ ��������� � ���� �������������� � 'no', ���� � ��������� ����.");
	if (choice == "yes") adminMenu();
	else menu();
	return;

}
std::string admin_choise(std::string message) {
	std::string vibor;
	while (true) {
		system("cls");
		std::cout << message << std::endl;
		getline(std::cin, vibor);
		if (vibor != "1" && vibor != "2" && vibor != "3" && vibor != "4" && vibor != "5" && vibor != "6" && vibor != "7" && vibor != "8")
			continue;
		else break;
	}
	return vibor;
}