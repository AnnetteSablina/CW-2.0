#include"Header.h"
void menu()
{  std::vector<logpass>admins;
	data_admin_file(admins);
	std::vector <logpass> users;
	data_user_file(users);
	system("cls");
	int a;
	bool run = true;
	while (run) {
		a = getInt("�������: \n 1.���� �� ����� ��������������. \n 2.���� �� ����� ������������. \n 3.������ ����� �� ���������.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			Admin_haveAccount(admins);
			break;
		case 2:
			system("cls");
			User_haveAccount(users);
			break;
		case 3:
			system("cls");
			std::cout << "\n�� ������� ����� �� ���������." << std::endl;
			exit(0);
			break;
		default:
			std::cout << "���������� ������ ��� ���. �������� ����." << std::endl;
			Sleep(2000);
			system("cls");
			run = true;
			break;
		}

	}
	return;
}	
void Admin_haveAccount(std::vector<logpass>&admins) {
	int a;
	bool run = true;
	Admin admin;
	while (true) {
		while (run) {
			a = getInt("�� ����� �������������? \n �������: \n 1.��.\n 2.���.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				admin.enterAccount(admins);
				break;
			case 2:
				system("cls");
				std::cout << "������� ��� ������������ ���� ����������������� � ��������������"<< std::endl;
				Sleep(2000);
				menu();
			default:
				system("cls");
				std::cout << "���������� ������ ��� ���. �������� ����." << std::endl;
				Sleep(2000);
				system("cls");
				run = true;
				break;

			}
		}
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
	std::string choice1 = "";
	std::string choice2 = "";
	std::string choice3 = "";
	std::string vibor = "";
	bool check = true;
	std::string choice=admin_choise(" ���� ��������������  \n  �������: \n 1.��������� ����� �������. \n 2.�������������� ���������� � ������������. \n 3.�������� ����������� ���������. \n 4.����� � ���������� ������. \n 5.���������� ������ � ������ ������ ������������ ��� ���������� � ���. \n 6.�������� ������������ �� ����(������������ � ������ ��� ������). \n 7.��� 10 ����� �������� ��������. \n 8.��������� � ������� ����." );
	if (choice == "1") {
		system("cls");
		choice = yes_no("������ ����� ����� � ������? ������� yes ��� no.");
		if (choice == "yes") {
			check = true;
			check = check_login_once();
			if (!check) {
				system("cls");
				std::cout << "������������ � ����� ������� �� ����������." << std::endl;
				std::cout << "�������� ��� � ����." << std::endl;
				system("pause");
				addlogpass();
			}
		}
		else {
			system("cls");
			std::cout << "�������� ���������� � ������������." << std::endl;
			system("pause");
			addlogpass();

		}
		system("pause");
		choice1 = yes_no("������ ����� ����������� ������ � ����? ������� yes ��� no.");
		if (choice1 == "yes") {
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
	if (choice == "2") {
		system("cls");
		choice3.clear();
		while (true) {
			system("cls");
			std::cout << " �������:  \n 1.���� ������ �������� ������ ������ � ������ \n 2.���� ������ �������� ���������� � ������������. \n 3.��������� � ���� ������ " << std::endl;
			getline(std::cin, choice3);
			if (choice3 != "1" && choice3 != "2" && choice3 != "3")
				continue;
			else break;
		}
		system("cls");
		if (choice3 == "1") { changelogpass();}
		if (choice3 == "2") { changeinfo(); }
		if (choice3 == "3") { adminMenu(); return; }
		system("pause");
		choice1.clear();
		choice1 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice1 == "yes") { adminMenu(); return; }
		else { menu(); return; }
		return;
	}
	if (choice == "3") {
		system("cls");
		vivod();
		return;
	}
	if (choice == "4") {
		system("cls");
		choice1.clear();
		vibor = vibor_1_2_3_4_5_6(" ������� : \n 1. ���� ������ ����������� ����� �� ������ ��������. \n 2. ���� ������ ����������� ����� �� ������ �������� \n 3. ���� ������ ����������� ����� �� ������ ������. \n 4. ���� ������ ����������� ����� �� ����. \n 5. ���� ������ ���������� � ������������. \n 6. ���� ������ ����������� �� ���� ������. \n 7. ��������� � ���� �������������.");
		system("cls");
		if (vibor == "1") find_dogovor_number();
		if (vibor == "2") find_passport();
		if (vibor == "3") find_service();
		if (vibor == "4") find_date();
		if (vibor == "5") find_user();
		if (vibor == "6") sort();
		if (vibor == "7") { adminMenu(); return; }
		choice1.clear();
		system("pause");
		choice1 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice1 == "yes") { adminMenu(); return; }
		else { menu(); return; }
	}
	if (choice == "5") {
		system("cls");
		choice3.clear();
		while (true) {
			system("cls");
			std::cout << " �������:  \n 1.���� ������ �������� ����� � ������ \n 2.���� ������ �������� ���������� � ������������. \n 3.��������� � ���� ��������������. " << std::endl;
			getline(std::cin, choice3);
			if (choice3 != "1" && choice3 != "2" && choice3 != "3")
				continue;
			else break;
		}
		if (choice3 == "1") {
			bool n = addlogpass();
			if (n) {
				adminMenu();
			}
		}
		if (choice3 == "2") add_information();
		if (choice3 == "3") { adminMenu(); return; }
		system("pause");
		choice1.clear();
		choice1 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice1 == "yes") { adminMenu(); return; }
		else { menu(); return; }
		return;

	}
	if (choice == "6") {
		system("cls");
		std::string choice4 = yes_no("�� ����� ������� � ���, ��� ������ ������� ������������? \n 1.������� 'yes',���� �� \n 2.������� 'no',���� ��� ��� ��� ���� ��������� �������. ��������� � ���� ��������������.");
		if (choice4 == "yes") { delete_user(); return; }
		if (choice4 == "no") { adminMenu(); return; }
		choice2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice2 == "yes") { adminMenu(); return; }
		else { menu(); return; }
		return;
	}
	if (choice == "7") {
		system("cls");
		top_10();
		system("pause");
		choice1.clear();
		choice1 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
		if (choice1 == "yes") { adminMenu(); return; }
		else { menu(); return; }
		return;
	}
	if (choice == "8") {
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
			human.login = login(0, access, exit);
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
			this->human.login = login(0, access, exit);
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