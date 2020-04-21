#include"Header.h"
logpass::logpass(std::string login, std::string password) {
	this->login = login;
	this->password = password;
} // конструктор логин +пароль
Client::Client(std::string login) {
	this->human.login = login;
}
Client::Client() {

}
bool logpass::operator==(logpass human) {
	if (this->login == human.login && this->password == human.password)
		return true;
	else
		return false;
};
logpass::logpass() {
}
std::string getString(std::string p)
{
	system("cls");
	std::string mystring;
	std::cout << p << std::endl;
	std::getline(std::cin, mystring);
	return mystring;
}
int getInt(std::string massage) {
	int c;
	std::cout << massage << std::endl;
	while (true) {
		std::cin >> c;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("cls");
			std::cout << "Используй целое число." << std::endl;
			std::cout << massage << std::endl;
			continue;

		}

		break;
	};
	return c;
}
information::information( std::string telephone_number, std::string country, std::string city, std::string street, std::string housenumber, std::string flatnumber) {

	this->telephone_number = telephone_number;
	this->country = country;
	this->city = city;
	this->street = street;
	this->housenumber = housenumber;
	this->flatnumber = flatnumber;
}
information::information(){
}
information::information(std::string client_code,std::string name, std::string surname) {
	this->client_code = client_code;
	this->name = name;
	this->surname = surname;
}
bool information::operator==(information user) {
	if (this->client_code == user.client_code)
		return true;
	else
		return false;
};
data::data() {

}
dogovor::dogovor() {
};
dogovor::dogovor(std::string name,std::string document_code,std::string service_code, std::string summ, std::string commission) {
	this->name = name;
	this->document_code = document_code;
	this->service_code = service_code;
	this->summ = summ;
	this->commition = commission;
}

std::string client_code(std::string massage) {
	std::string client_code;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, client_code);
		system("cls");
		for (unsigned int i = 0; i < client_code.size(); i++) {
			if (client_code.size() != 8) {
				s++;
				std::cout << "Код клиента должен содержать 8 символов." << std::endl;
				break;
			}
			if (client_code[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < client_code.size(); i++) {

				if (client_code[i] >= 'a' && client_code[i] <= 'z' || client_code[i] >= '0' && client_code[i] <= '9' || client_code[0] >= 'A' && client_code[0] <= 'Z')
					u++;
				else {
					std::cout << "Используйте буквы латинского алфавита и цифры и  для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == client_code.size()) {
					break;

				}
			}
		}
		
			
		if (u == client_code.size()) {
			break;

		}
	}
	return client_code;
}
std::string ccs(std::string massage){
std::string ccs;
for (int k = 0;;) {
	std::cout << massage << std::endl;
	int u = 0;
	int s = 0;
	std::getline(std::cin, ccs);
	system("cls");
for (unsigned int i = 0; i < ccs.size(); i++) {
			if (ccs.size() < 3) {
				std::cout << " Введено слишком мало символов. Минимум 3 символа." << std::endl;
				break;
			}
			if (ccs[0] >= 'A' && ccs[0] <= 'Z')
				i = 1;
			else
			{
				std::cout << "Первая буква должна быть заглавной.\n" << std::endl;
				break;
			}

			for (i; i < ccs.size(); i++) {
				if (ccs[i] >= 'a' && ccs[i] <= 'z' || ccs[i]>='A' && ccs[i]<='Z' || ccs[i]=='.')
					u++;

				else {
					std::cout << "Используйте за ввода буквы латинского алфавита и точку." << std::endl;
					u = 0;
					break;
				}

			}

			if (u == 0)
				break;
			if (u == ccs.size() - 1) {
				break;
			}

		}
	

	if (u == ccs.size() - 1)
		break;
}
return ccs;
	}
std::string date(std::string message) {
	int year;
	int month;
	int day;
	bool isLeap;
	while (true) {
		isLeap = false;
		year = getInt("Введите год");
		if (year < 1866 || year > 2050) {
			system("cls");
			std::cout << "Нотариальные конторы появились в 1866. Работа программы продлена до 2050 года." << std::endl;
			continue;
		}
		if (year % 4 == 0) {
			system("cls");
			isLeap = true;
		}

		break;
	}
	system("cls");
	while (true) {
		month = getInt("Введите месяц");
		if (month < 1 || month > 12) {
			system("cls");
			std::cout << "В году 12 месяцев" << std::endl;
			continue;
		}
		break;
	}

	system("cls");
	while (true) {
		day = getInt("Ввелите день.");
		if (day < 1 || day>31) {
			system("cls");
			std::cout << "В месяце максимум 31 день." << std::endl;
			continue;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			system("cls");
			if (day > 30) {
				std::cout << "В апреле, июне, сентябре и ноябре 30 дней." << std::endl;
			}continue;
		}
		if (month == 2 && isLeap == true) {
			system("cls");
			if (day > 29) {
				std::cout << "В високосном году в феврале 29 дней." << std::endl;
				continue;
			}
		}
		if (month == 2 && isLeap == false) {
			system("cls");
			if (day > 28) {
				std::cout << " В феврале 28 дней." << std::endl;
				continue;
			}
		}
		break;
	}
	
	std::string date = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	return date;

}
std::string telephone_number(std::string massage) {
	std::string telephone_number;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, telephone_number);
		system("cls");
		for (unsigned int i = 0; i < telephone_number.size(); i++) {
			if (telephone_number.size() != 9) {
				s++;
				std::cout << "Номер телефона должен содержать 9 символов." << std::endl;
				break;
			}
			if (telephone_number[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < telephone_number.size(); i++) {

				if (telephone_number[i] >= '0' && telephone_number[i] <= '9')
					u++;
				else {
					std::cout << "Используйте цифры для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == telephone_number.size()) {
					break;

				}
			}
		}
		if (u == telephone_number.size()) {
			break;

		}
	}
	return telephone_number;
}
std::string hf(std::string massage) {
	std::string hf;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, hf);
		system("cls");
		for (unsigned int i = 0; i < hf.size(); i++) {
			if (hf.size() > 3) {
				s++;
				std::cout << "Максимум 3 символа." << std::endl;
				break;
			}
			if (hf[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < hf.size(); i++) {

				if (hf[i] >= '0' && hf[i] <= '9')
					u++;
				else {
					std::cout << "Используйте цифры для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == hf.size()) {
					break;

				}
			}
		}
		if (u == hf.size()) {
			break;

		}
	}
	return hf;
}
std::string ns(std::string massage) {
	std::string ns;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin,ns);
		system("cls");
		for (int i = 0; i < ns.size(); i++) {

			if (ns[i] == ' ') {
				s++;
				std::cout << "Не используйте пробелы." << std::endl;
				break;
			}

		}
		if (s == 0) {
			for (int i = 0; i < ns.size(); i++) {
				if (ns.size() < 3) {
					std::cout << " Введите еще раз. Недостаточно символов. Минимум 3 символа." << std::endl;
					break;
				}
				if (ns[0] >= 'A' && ns[0] <= 'Z')
					i = 1;
				else
				{
					std::cout << "Используйте буквы латинского алфавита. Первый символ должен быть заглавной буквой.Введите имя еще раз\n" << std::endl;
					break;
				}

				for (i; i < ns.size(); i++) {
					if (ns[i] >= 'a' && ns[i] <= 'z')
						u++;

					else {
						std::cout << " Используйте буквы латинского алфавита .\n Остальные символы - строчные буквы.Введите имя еще раз." << std::endl;
						u = 0;
						break;
					}

				}

				if (u == 0)
					break;
				if (u == ns.size() - 1) {
					break;
				}

			}
		}

		if (u == ns.size() - 1)
			break;
	}
	return ns;
}
std::string yes_no(std::string massage) {
	std::string trololo;
	while (true) {
		system("cls");
		std::cout << massage << std::endl;
		getline(std::cin, trololo);
		if (trololo != "yes" && trololo != "no")
			continue;
		else break;
	}
	return trololo;
}
void user_file(std::vector<std::string> &users, std::vector<std::string> &password) {
	{
		std::string temp;
		std::string tr;
		std::ifstream file("users.txt");
		while (!file.eof())
		{
		    getline(file, temp);
			std::cout << temp.size() << std::endl;
			users.push_back(temp);
			getline(file, tr);
			std::cout << temp.size() << std::endl;
			password.push_back(tr);
		}
		file.close();
		if (!password.empty()) password.erase(password.end() - 1);

	}
	for (int i=0; i < users.size(); i++) {
		std::cout << users[i] << std::endl;
	}
	for (int i = 0; i < password.size(); i++) {
		std::cout << password[i] << std::endl;
	}
}
void trololo() {
	int count = 0;
	std::string str;
	std::vector <std::string> users;
	std::vector<std::string> password;
	user_file(users,password);
	int maxcount(0), nn(0);
	for (int i = 0; i < users.size(); i++) {
		 count=0;
		for (int j = i; j < users.size(); j++) {
			if (users[i] == users[j])
				count++; 
		
		}
		if (maxcount < count) {
			maxcount = count;
			nn = i;
		}
	}
	std::cout << users[nn] << " " << password[nn]<<" " << maxcount;
};
