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
		a = getInt("�������: \n 1.���� �� ����� ��������������. \n 2.���� �� ����� ������������.");
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
	{
		std::ifstream file("admins.txt");
		while (file)
		{
			logpass temp;
			getline(file, temp.login);
			getline(file, temp.password);
			admins.push_back(temp);
		}
		if (!admins.empty()) admins.erase(admins.end() - 1);
		file.close();

	}
}
void Admin::enterAccount(std::vector<logpass>&admins) {
	system("cls");
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			this->human.login=login(1, access, exit);
		}
		else {
			this->human.login=login(2, access, exit);
		};
		if (exit) {
			break;
		};
		this->human.password=password(exit);
		if (exit) {
			break;
		};
		access = true;
		logpass check(human.login,sha256(human.password));
		if (std::find(admins.begin(), admins.end(), check) == admins.end())
			access = false;

	} while (!access);
	if (exit) {
		menu();
	}
	if (access) {
		adminMenu();
	}

};
void Admin::adminMenu() {
	system("cls");
	int a,b,c,d,e;
	std::string choise = "";
	std::string choise1 = "";
	std::string vibor = "";
	std::string choise2 = "";
	std::string choise3 = "";
	bool check=true;
	bool check1 = true;
	bool run = true;
	bool run1 = true;
	bool run2 = true;
	bool run3 = true;
	while (run) {
		a = getInt(" ���� ��������������  \n  �������: \n 1.��������� ����� �������. \n 2.�������������� ���������� � ������������. \n 3.�������� ����������� ���������. \n 4.����� � ���������� ������. \n 5.���������� ������ � ������ ������ ������������ ��� ���������� � ���. \n 6.����� � ������� ����.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			choise = yes_no("������ ����� ����� � ������? ������� yes ��� no.");
			if (choise == "yes") {
				check=check_login_once();
				if (!check) {
					system("cls");
					std::cout << "������������ � ����� ������� �� ����������." << std::endl;
					std::cout << "�������� ���������� � ������������." << std::endl;
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
			choise1 = yes_no("������ ����� ����������� ������ � ����? ������� yes ��� no.");
			if (choise1 == "yes") {
				check=add_client_code_into_dogovor();
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

			}break;
		case 2:
			system("cls");
			choise3.clear();
			while (true) {
				system("cls");
				std::cout << " �������:  \n 1.���� ������ ������ ������ � ������ \n 2.���� ������ �������� ���������� � ������������. " << std::endl;
				getline(std::cin, choise3);
				if (choise3 != "1" && choise3 != "2")
					continue;
				else break;
			}
			if (choise3 == "1") { changelogpass(); return;}
			if (choise3 == "2") {changeinfo(); return;}
		 	break;
		 case 3:
			system("cls");
			vivod();
			break;
		 case 4:
			system("cls");
			choise2.clear();
			vibor = vibor_1_2_3_4_5_6(" ������� : \n 1. ���� ������ ����������� ����� �� ������ ��������. \n 2. ���� ������ ����������� ����� �� ������ �������� \n 3. ���� ������ ����������� ����� �� ������ ������. \n 4. ���� ������ ����������� ����� �� ����. \n 5. ���� ������ ����������� �� ���� ������. ");
			system("cls");
			if (vibor == "1") {
			find_dogovor_number();
			system("pause");
			choise2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
			if (choise2 == "yes") adminMenu();
			else menu();
			}
			if (vibor == "2") {
				choise2.clear();
				find_passport();
				system("pause");
				choise2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
				if (choise2 == "yes") adminMenu();
				else menu();

			}
			if (vibor == "3") {
				choise2.clear();
				find_service();
				system("pause");
				choise2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
				if (choise2 == "yes") adminMenu();
				else menu();

			}
			if (vibor == "4") {
				choise2.clear();
				find_date();
				system("pause");
				choise2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
				if (choise2 == "yes") adminMenu();
				else menu();
			}
			if (vibor == "5") {
				choise2.clear();
				sort();
				system("pause");
				choise2 = yes_no("������� 'yes', ���� ������ �������� � ���� �������������� �  'no', ����� ��������� � ������� ����. ");
				if (choise2 == "yes") { adminMenu(); return; }
				else { menu(); return; }
				 
			}
			break;
		 case 5:
			 system("cls");
			 break;
		 case 6:
			 system("cls");
			 break;
		}
		
	}
}
bool Admin::add_client_code_into_dogovor() {
	system("cls");
	int u = 0;
	bool next;
	bool neban = true;
	information user;
	std::vector<information> passport;
	data_passport_file(passport);
	do {
		user.client_code = client_code("������� ��� �������.");
		neban = true;
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
				neban = true;
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

		
	} while (!neban);
	
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
	
	
	
}
void Admin::addlogpass() {
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
		human.password = password(exit);
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
		if (exit) break;
	} while (!access);
	 
	if (exit) {
		adminMenu();
	}
	if (!exit)
	{
		std::ofstream file1("users.txt", std::ios::app);
		file1  << human.login << std::endl << sha256( human.password )<< std::endl;
		file1.close();
		system("cls");
		std::cout << "�� �������� ������������ � ����." << std::endl;
	}
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
	std::string choice = yes_no("��� �� ������ ����������? ������� 'yes' , ���� ������ ��������� � ���� ������ � 'no', ���� � ��������� ����.");
	if (choice == "yes") adminMenu();
	else menu();
	

}