#include"Header.h"

void User_haveAccount(std::vector<logpass>&users) {
	int a;
	bool run = true;
	Client user;
	while (true) {
		while (run) {
			a = getInt("У вас есть аккаунт? \n Нажмите: \n 1.Да.\n 2.Нет.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				user.enterAccount(users);
				break;
			case 2:
				system("cls");
				std::cout << "Обратитесь к админестратору,чтобы зарегистрироваться." << std::endl;
				Sleep(2000);
				menu();
			default:
				system("cls");
				std::cout << "Попробуйте ввести еще раз. Неверный ввод." << std::endl;
				Sleep(2000);
				system("cls");
				run = true;
				break;

			}
		}
	}


}
void data_user_file(std::vector<logpass>& users){	 
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
		userMenu();
	}


};
std::string login(int type, bool& access, bool& exit) {
	bool run = true;
	int u=0;
	std::string login ;
	switch (type) {
	case 0:
		system("cls");
		login = getString("Введите логин.Для выхода введите menu.");
		break;
	case 1: 
		system("cls");
		login = getString("Введите логин.Для выхода введите menu.");
		login = getString("Введите логин.Для выхода введите menu.");
		break;
	 case 2:
		system("cls");
		login = getString("Вы ввели неверные логин или пароль. Введите логин еще раз. Для выхода введите menu.");
		break;
	 case 3:
		system("cls");
		login = getString("Такой логин уже существует. Введите логин еще раз или для выхода введите menu.");
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
			login = getString("Введите логин от 5 до 15 символов. Для выхода введите menu."); 
			continue;
		}

		for (unsigned int i = 0; i < login.size(); ++i)
			if (!((login[i] >= 'a' && login[i] <= 'z')
				|| (login[i] >= 'A' && login[i] <= 'Z')
				|| (login[i] >= '0' && login[i] <= '9')))
			{
				login = getString("Логин содержит недопустимые символы. Для выхода введите menu.");
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
	password = getString("Введите пароль. Для выхода введите menu.");
	do {
		u = 0;
		if (password == "menu")
		{
			exit = true;
			break;
		}
		if (password.size() < 8 || password.size() > 12)
		{
			
			password = getString("Пароль должен содержать  от 8 до 12 символов. Для выхода введите menu.");
			continue;
		}

		for (auto a : password) {
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')))
			{
				password = getString("Пароль содержит недопустимые символы. Для выхода введите menu.");
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
void Client::userMenu() {
	system("cls");
	std::string choise = user_choise("МЕНЮ ПОЛЬЗОВАТЕЛЯ \n 1.Найти договор по его номеру. \n 2.Найти договор по номеру паспорта. \n 3.Найти договор по дате заключения. \n 4.Изменить логин или пароль. \n 5.Изменить информацию о себе. \n 6.Выйти в главное меню.");
	if (choise == "1") find_dogovor_number();
	if (choise == "2") find_passport();
	if (choise == "3")find_date();
	if (choise == "4")changelogpass();
	if (choise == "5")changeinfo();
	if (choise == "6")menu();
	system("pause");
	std::string next = yes_no("Введите: \n 1.'yes',eсли хотите вернуться в меню пользователя. \n 2.'no',eсли хотите вернуться в главное меню ");
	if (next == "yes") {
		userMenu();
		return;
	}
	if (next == "no") {
		menu();
		return;
	}
	return;
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
		file << i.login << std::endl << i.password << std::endl;

	file.close();
	return;
}
void rewrite_information_file(std::vector <information>& userss) {
	std::ofstream file("info.txt", std::ios::trunc);
	for (auto i : userss)
		file << i.client_code << std::endl << i.name << std::endl << i.surname << std::endl << i.telephone_number << std::endl << i.country << std::endl << i.city << std::endl << i.street << std::endl << i.housenumber << std::endl << i.flatnumber << std::endl;
	file.close();
	return;
}
void rewrite_passport_file(std::vector <information>& passport) {
	std::ofstream file("passport.txt", std::ios::trunc);
	for (auto i : passport)
		file << i.client_code << std::endl << i.name << std::endl << i.surname << std::endl;
	file.close();
	return;

}
void rewrite_magic_file(std::vector <information>& magic) {
	std::ofstream file("magic.txt", std::ios::trunc);
	for (auto i : magic)
		file << i.client_code << std::endl << i.name << std::endl << i.surname << std::endl;
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
	tp.AddColumn("Номер паспорта", 14);
	tp.AddColumn("Код услуги", 11);
	tp.AddColumn("Название договора", 37);
	tp.AddColumn("Сумма", 9);
	tp.AddColumn("Комиссия", 9);
	tp.AddColumn("Номер договора", 14);
	tp.AddColumn("Дата подписания", 15);
	tp.PrintHeader();
	for (auto i : dogovors) {
		tp << i.client_code << i.service_code << i.name << i.summ << i.comission << i.document_code << i.date << bprinter::endl();
		tp.PrintFooter();
	}
	system("pause");
	std::string choise = yes_no("Вы хотите вернуться в меню админестратора ? \n Введите 'yes', если да или 'no', чтобы перейти в главное меню. ");
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
				std::cout << "Введите логин от 5 до 15 символов." << std::endl;
				break;
			}
			if (login1[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < login1.size(); i++) {

				if (login1[i] >= 'a' && login1[i] <= 'z' || login1[i] >= '0' && login1[i] <= '9' || login1[0] >= 'A' && login1[0] <= 'Z')
					u++;
				else {
					std::cout << "Используйте буквы латинского алфавита и цифры и  для ввода" << std::endl;
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
				std::cout << "Пароль должен содержать  от 8 до 12 символов." << std::endl;
				break;
			}
			if (password1[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < password1.size(); i++) {

				if (password1[i] >= 'a' && password1[i] <= 'z' || password1[i] >= '0' && password1[i] <= '9' || password1[0] >= 'A' && password1[0] <= 'Z')
					u++;
				else {
					std::cout << "Используйте буквы латинского алфавита и цифры и  для ввода" << std::endl;
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
void delete_user() {
	system("cls");
	std::vector<logpass> users;
	data_user_file(users);
	std::vector<information> userss;
	data_client_file(userss);
	std::vector <information> passport;
	data_passport_file(passport);
	std::string login = login1("Введите логин пользователя, который хотите удалить.");
	int a = users.size();
	users.erase(std::remove_if(users.begin(), users.end(), [=](logpass& s) { return s.login == login; }), users.end());
	int k = users.size();
	if (a == k) {
		std::cout << "Пользователя с таким логином не существует." << std::endl;
		return;
	}
	else {
		while (true) {
			std::string passport_code = client_code("Введите номер паспорта клиента");
			a = userss.size();
			userss.erase(std::remove_if(userss.begin(), userss.end(), [=](information& a) { return a.client_code == passport_code; }), userss.end());
			k = userss.size();
			if (a == k) {
				std::cout << "Вы ввели некорректрый номер паспорта повторите еще раз." << std::endl;
				continue;
			}
			else {
				passport.erase(std::remove_if(passport.begin(), passport.end(), [=](information& r) { return r.client_code == passport_code; }), passport.end());
				rewrite_user_file(users);
				rewrite_information_file(userss);
				rewrite_passport_file(passport);
				break;
			}
		}
	}
	return;
};
void add_information() {
	system("cls");
	information user;
	std::vector<information> passport;
	data_passport_file(passport);
	while (true) {
		int w = 0;
		user.client_code = client_code("Введите номер паспорта");
		system("cls");
		for (auto a : passport) {
			if (user.client_code == a.client_code) {
				w++;
				std::cout << "Такой номер паспорта уже существует. Повторите ввод.";
				break;
			}
		}
		if (w == 0) { break; }
		else { continue; }
	}
	user.name = ns("Введите имя.");
	user.surname = ns("Введите фамилию.");
	user.telephone_number = telephone_number("Введите номер телефона клиента.");
	user.country = ccs("Введите страну проживания");
	user.city = ccs("Введите город проживания.");
	user.street = ccs("Введите улицу проживания.");
	user.housenumber = hf("Введите номер дома.");
	user.flatnumber = hf("Введите номер квартиры. Введите 0, если клиент проживает в частном доме.");
	std::ofstream file("info.txt", std::ios::app);
	file << user.client_code << std::endl<<  user.name << std::endl << user.surname << std::endl << user.telephone_number << std::endl << user.country << std::endl << user.city << std::endl << user.street << std::endl << user.housenumber << std::endl << user.flatnumber << std::endl;
	file.close();
	std::ofstream file1("passport.txt",std::ios::app);
	file1 << user.client_code << std::endl << user.name << std::endl << user.surname << std::endl;
	file1.close();
	return;
}
std::string user_choise(std::string message) {
	std::string vibor;
	while (true) {
		system("cls");
		std::cout << message << std::endl;
		getline(std::cin, vibor);
		if (vibor != "1" && vibor != "2" && vibor != "3" && vibor != "4" && vibor != "5" && vibor != "6")
			continue;
		else break;
	}
	return vibor;
}




