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
		while (!file.eof())
		{
			logpass temp;
			getline(file, temp.login);
			getline(file, temp.password);
			users.push_back(temp);
		}
		
		file.close();

	}
void data_passport_file(std::vector<information>&passport) {
	std::ifstream file("passport.txt");
	while (!file.eof())
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

		if (login.size() < 5)
		{
			
			login = getString("������� ����� �� 5 ��� ����� ��������. ��� ������ ������� menu.");
			continue;
		}

		for (unsigned int i = 0; i < login.size(); ++i)
			if (!((login[i] >= 'a' && login[i] <= 'z')
				|| (login[i] >= 'A' && login[i] <= 'Z')
				|| (login[i] >= '0' && login[i] <= '0')))
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
	std::ifstream file("data.txt");
	while (!file.eof()) {
		information temp;
		getline(file, temp.telephone_number);
		getline(file, temp.country);
		getline(file, temp.city);
		getline(file, temp.street);
		getline(file, temp.housenumber);
		getline(file, temp.flatnumber);
		file.close();
	}
}
void rewrite_user_file(std::vector<logpass>&users)
{
	std::ofstream file("users.txt", std::ios::trunc);

	for (auto i : users)
		file << i.login << std::endl << i.password << std::endl;

	file.close();
}




