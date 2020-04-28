#include"Header.h"

void User_haveAccount(std::vector<logpass>&users) {
	int a;
	bool run = true;
	Client user;
	while (true) {
		while (run) {
			a = getInt("� ��� ���� �������? \n �������: \n 1.��.\n 2.���.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				user.enterAccount(users);
				break;
			case 2:
				system("cls");
				std::cout << "���������� � ��������������,����� ������������������." << std::endl;
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
void data_user_file(std::vector<logpass>& users)	 
	{
		std::ifstream file("users.txt");
		while (file)
		{
			logpass temp;
			getline(file, temp.login);
			getline(file, temp.password);
			users.push_back(temp);
		}
		if (!users.empty()) users.erase(users.end() - 1);
		file.close();

	}
void data_passport_file(std::vector<information>&passport) {
	std::ifstream file("passport.txt");
	while (file)
	{
		information temp;
		std::getline(file, temp.client_code);
		std::getline(file, temp.name);
		std::getline(file, temp.surname);
		passport.push_back(temp);
	}
	if (!passport.empty()) passport.erase(passport.end() - 1);
	file.close();
}
void data_magic_file(std::vector<information>& magic) {
	std::ifstream file("magic.txt");
	while (file)
	{
		information temp;
		std::getline(file, temp.client_code);
		std::getline(file, temp.name);
		std::getline(file, temp.surname);
		magic.push_back(temp);
	}
	if (!magic.empty()) magic.erase(magic.end() - 1);
	file.close();

}
void Client::enterAccount(std::vector<logpass>& users) {
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
		logpass check(human.login, sha256( human.password));
		if (std::find(users.begin(), users.end(), check) == users.end())
			access = false;

	} while (!access);
	if (exit) {
		menu();
	};
	if (access) {
		userMenu(users);
	}


};
std::string login(int type, bool& access, bool& exit) {
	bool run = true;
	int u=0;
	std::string login;
	switch (type) {
	case 1:
		system("cls");
		if (access) {
			login = getString("������� �����. ��� ������ ������� menu.");
		}
		else {
			login = getString("������� ����� ��� ���. ��� ������ ������� menu.");
		};
		break;
	case 2:
		system("cls");
		login = getString("�� ����� �������� ����� ��� ������. ������� ����� ��� ���. ��� ������ ������� menu.");
		break;
	case 3:
		system("cls");
		login = getString("����� ����� ��� ����������. ������� ����� ��� ��� ��� ��� ������ ������� menu.");
		break;
	};
	
	do
	{
		u = 0;
		if (login == "menu")
		{
			exit = true;
			break;
		}

		if (login.size() < 5 || login.size() > 15 )
		{
			
			login = getString("������� ����� �� 5 �� 15 ��������. ��� ������ ������� menu.");
			continue;
		}

		for (unsigned int i = 0; i < login.size(); ++i)
			if (!((login[i] >= 'a' && login[i] <= 'z')
				|| (login[i] >= 'A' && login[i] <= 'Z')
				|| (login[i] >= '0' && login[i] <= '9')))
			{
				login = getString("����� �������� ������������ �������. ��� ������ ������� menu.");
				break;
			}
			else {
				u++;
			}
		if (u == login.size()) {
			break;
		}

	} while (true);
	return login;
};
std::string password(bool& exit) {
	int u = 0;
	std::string password;
	password = getString("������� ������. ��� ������ ������� menu.");
	do {
		u = 0;
		if (password == "menu")
		{
			exit = true;
			break;
		}
		if (password.size() < 8 || password.size() > 12)
		{
			password = getString("������ ������ ���������  �� 8 �� 12 ��������. ��� ������ ������� menu.");
			continue;
		}

		for (auto a : password) {
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')))
			{
				password = getString("������ �������� ������������ �������. ��� ������ ������� menu.");
				break;
			}
			else {
				u++;
			}
		}
		if (u == password.size()) {
			break;
		}

	} while (true);
	return password;
};
void Client::userMenu(std::vector<logpass>& users) {
	system("cls");
	std::cout << "user menu" << std::endl;
}
void data_client_file(std::vector<information>& userss) {
	std::ifstream file("info.txt");
	while (file) {
		information temp;
		getline(file, temp.client_code);
		getline(file, temp.name);
		getline(file, temp.surname);
		getline(file, temp.telephone_number);
		getline(file, temp.country);
		getline(file, temp.city);
		getline(file, temp.street);
		getline(file, temp.housenumber);
		getline(file, temp.flatnumber);
		userss.push_back(temp);
	}
	if (!userss.empty()) userss.erase(userss.end() - 1);
	file.close();
}
void rewrite_user_file(std::vector<logpass>&users)
{
	std::ofstream file("users.txt", std::ios::trunc);

	for (auto i : users)
		file << i.login << std::endl << sha256(i.password) << std::endl;

	file.close();
	return;
}
void data_dogovor_file(std::vector<Vivod> &dogovors) {
	std::ifstream file("dogovor.txt");
	while (file) {
		Vivod temp;
		getline(file, temp.client_code);
		getline(file, temp.service_code);
		getline(file, temp.name);
		getline(file, temp.summ);
		getline(file, temp.comission);
		getline(file, temp.document_code);
		getline(file, temp.date);
		dogovors.push_back(temp);
		}
	if (!dogovors.empty()) dogovors.erase(dogovors.end() - 1);
	file.close();
	return;

}
void Admin::vivod() {
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	TablePrinter tp(&std::cout);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("���� ����������", 15);
	tp.PrintHeader();
	for (auto i : dogovors) {
		tp << i.client_code << i.service_code << i.name << i.summ << i.comission << i.document_code << i.date << bprinter::endl();
		tp.PrintFooter();
	}
	system("pause");
	std::string choise = yes_no("�� ������ ��������� � ���� �������������� ? \n ������� 'yes', ���� �� ��� 'no', ����� ������� � ������� ����. ");
	if (choise == "yes") adminMenu();
	else menu();
};
std::string login1(std::string message) {
	std::string login1;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, login1);
		system("cls");
		for (unsigned int i = 0; i < login1.size(); i++) {
			if (login1.size() < 5 || login1.size() > 15) {
				s++;
				std::cout << "������� ����� �� 5 �� 15 ��������." << std::endl;
				break;
			}
			if (login1[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < login1.size(); i++) {

				if (login1[i] >= 'a' && login1[i] <= 'z' || login1[i] >= '0' && login1[i] <= '9' || login1[0] >= 'A' && login1[0] <= 'Z')
					u++;
				else {
					std::cout << "����������� ����� ���������� �������� � ����� �  ��� �����" << std::endl;
					u = 0;
					break;
				}
				if (u == 0)
					break;
				if (u == login1.size()) {
					break;

				}
			}
		}
		if (u == login1.size()) {
			break;

		}
	}
	return login1;
}
std::string password1(std::string message) {
	std::string password1;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, password1);
		system("cls");
		for (unsigned int i = 0; i < password1.size(); i++) {
			if (password1.size() < 8 || password1.size() > 12) {
				s++;
				std::cout << "������ ������ ���������  �� 8 �� 12 ��������." << std::endl;
				break;
			}
			if (password1[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < password1.size(); i++) {

				if (password1[i] >= 'a' && password1[i] <= 'z' || password1[i] >= '0' && password1[i] <= '9' || password1[0] >= 'A' && password1[0] <= 'Z')
					u++;
				else {
					std::cout << "����������� ����� ���������� �������� � ����� �  ��� �����" << std::endl;
					u = 0;
					break;
				}
				if (u == 0)
					break;
				if (u == password1.size()) {
					break;
				}
			}
		}
		if (u == password1.size()) {
			break;

		}
	}
	return password1;

}




