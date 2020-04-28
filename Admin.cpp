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
		a = getInt("Нажмите: \n 1.Вход от имени администратора. \n 2.Вход от имени пользователя.");
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
			std::cout << "Попробуйте ввести еще раз. Неверный ввод." << std::endl;
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
			a = getInt("Вы точно админестратор? \n Нажмите: \n 1.Да.\n 2.Нет.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				admin.enterAccount(admins);
				break;
			case 2:
				system("cls");
				std::cout << "Войдите как пользователь либо зарегистрируйтесь у админестратора"<< std::endl;
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
		a = getInt(" МЕНЮ АДМИНЕСТРАТОРА  \n  Нажмите: \n 1.Заключить новый договор. \n 2.Редактирование информации о пользователе. \n 3.Просмотр заключенных договоров. \n 4.Поиск и сортировка данных. \n 5.Добавление логина и пароля нового пользователя или информации о нем. \n 6.Выход в главное меню.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			choise = yes_no("Клиент имеет логин и пароль? Введите yes или no.");
			if (choise == "yes") {
				check=check_login_once();
				if (!check) {
					system("cls");
					std::cout << "Пользователя с таким логином не существует." << std::endl;
					std::cout << "Добавьте информацию о пользователе." << std::endl;
					system("pause");
					addlogpass();
					
				}
			}
			else {
				system("cls");
				std::cout << "Добавьте информацию о пользователе." << std::endl;
				system("pause");
				addlogpass();
				
			}
			system("pause");
			choise1 = yes_no("Клиент имеет заполненные данные в базе? Введите yes или no.");
			if (choise1 == "yes") {
				check=add_client_code_into_dogovor();
				if (check) {
					system("cls");
					std::cout << "Информации об этом пользователе не было и вы добавили его идентификационный номер в базу." << std::endl;
					std::cout << "Добавим информацию о пользователе." << std::endl;
					system("pause");
					add_user_information_dogovor();
					std::cout << "Данные успешно добавлены." << std::endl;
					system("pause");
					add_dogovor();
					return;
					
				}
				else {
					system("cls");
					std::cout << "Данные клиента уже есть в базе." << std::endl;
					system("pause");
					add_dogovor();
					return;
					
				}
			}
			else {
				check = add_client_code_into_dogovor();
				if (check) {
					system("cls");
					std::cout << "Информации об этом пользователе не было и вы добавили его идентификационный номер в базу." << std::endl;
					std::cout << "Добавим информацию о пользователе." << std::endl;
					system("pause");
					add_user_information_dogovor();
					std::cout << "Данные успешно добавлены." << std::endl;
					system("pause");
					add_dogovor();
					return;
					
				}
				else {
					system("cls");
					std::cout << "Данные клиента уже есть в базе." << std::endl;
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
				std::cout << " Введите:  \n 1.Если хотите данные логина и пароля \n 2.Если хотите обновить информацию о пользователе. " << std::endl;
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
			vibor = vibor_1_2_3_4_5_6(" Введите : \n 1. Если хотите осуществить поиск по номеру договора. \n 2. Если хотите осуществить поиск по номеру паспорта \n 3. Если хотите осуществить поиск по номеру услуги. \n 4. Если хотите осуществить поиск по дате. \n 5. Если хотите сортировать по коду услуги. ");
			system("cls");
			if (vibor == "1") {
			find_dogovor_number();
			system("pause");
			choise2 = yes_no("Введите 'yes', если хотите остаться в меню админестратора и  'no', чтобы вернуться в главное меню. ");
			if (choise2 == "yes") adminMenu();
			else menu();
			}
			if (vibor == "2") {
				choise2.clear();
				find_passport();
				system("pause");
				choise2 = yes_no("Введите 'yes', если хотите остаться в меню админестратора и  'no', чтобы вернуться в главное меню. ");
				if (choise2 == "yes") adminMenu();
				else menu();

			}
			if (vibor == "3") {
				choise2.clear();
				find_service();
				system("pause");
				choise2 = yes_no("Введите 'yes', если хотите остаться в меню админестратора и  'no', чтобы вернуться в главное меню. ");
				if (choise2 == "yes") adminMenu();
				else menu();

			}
			if (vibor == "4") {
				choise2.clear();
				find_date();
				system("pause");
				choise2 = yes_no("Введите 'yes', если хотите остаться в меню админестратора и  'no', чтобы вернуться в главное меню. ");
				if (choise2 == "yes") adminMenu();
				else menu();
			}
			if (vibor == "5") {
				choise2.clear();
				sort();
				system("pause");
				choise2 = yes_no("Введите 'yes', если хотите остаться в меню админестратора и  'no', чтобы вернуться в главное меню. ");
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
		user.client_code = client_code("Введите код клиента.");
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
	user.name = ns("Введите имя.");
	user.surname = ns("Введите фамилию.");
	user.telephone_number = telephone_number("Введите номер телефона клиента.");
	user.country = ccs("Введите страну проживания");
	user.city = ccs("Введите город проживания.");
	user.street = ccs("Введите улицу проживания.");
	user.housenumber = hf("Введите номер дома.");
	user.flatnumber = hf("Введите номер квартиры. Введите 0, если клиент проживает в частном доме.");
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
		std::cout << "Вы добавили пользователя в базу." << std::endl;
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
				std::cout << "Пользователь с таким логином действительно есть." << std::endl;
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
	std::cout << "Добавим данные договора." << std::endl;
	dogovor.service_code = service_code("Введите номер услуги.\n 1111 - Доверенность. \n 2222 - Брачный договор. \n 3333 - Завещание. \n 4444 - Приватизация. \n 5555 - Исполнительные надписи. \n 6666 - Отчуждение недвижимого имущества. \n 7777 - Соглашение об уплате алиментов. \n 8888 - Соглашение на выезд ребенка из страны. \n 9999 - Согласие. ");
	dogovor.name = dogovor_name(dogovor.service_code);
	system("cls");
	dogovor.summ=summ("Введите сумму до 100.000.000");
	dogovor.commition = summ ("Введите комиссионные.");
	std::ofstream file8("dogovor.txt", std::ios::app);
	file8 << dogovor.service_code << std::endl << dogovor.name << std::endl << dogovor.summ << std::endl << dogovor.commition << std::endl;
	file8.close();
	add_document_code();
	Sleep(3000);
	std::string choice = yes_no("Как вы хотите продолжить? Введите 'yes' , если хотите вернуться в меню админа и 'no', если в начальное меню.");
	if (choice == "yes") adminMenu();
	else menu();
	

}