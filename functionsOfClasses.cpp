#include"Header.h"
logpass::logpass(std::string login, std::string password) {
	this->login = login;
	this->password = password;
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
	getline(std::cin, mystring);
	return mystring;
}
int getInt(std::string message) {
	int c;
	std::cout << message << std::endl;
	while (true) {
		std::cin >> c;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("cls");
			std::cout << "��������� ����� �����." << std::endl;
			std::cout << message << std::endl;
			continue;

		}

		break;
	};
	return c;
}
std::string client_code(std::string message) {
	std::string client_code;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, client_code);
		system("cls");
		if (client_code.empty())continue;
		for (unsigned int i = 0; i < client_code.size(); i++) {
			if (client_code.size() != 8) {
				s++;
				std::cout << "��� ������� ������ ��������� 8 ��������." << std::endl;
				break;
			}
			if (client_code[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < client_code.size(); i++) {

				if (client_code[i] >= 'a' && client_code[i] <= 'z' || client_code[i] >= '0' && client_code[i] <= '9' || client_code[0] >= 'A' && client_code[0] <= 'Z')
					u++;
				else {
					std::cout << "����������� ����� ���������� �������� � ����� �  ��� �����" << std::endl;
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
		else { continue; }
		
			
		if (u == client_code.size()) {
			break;

		}
	}
	return client_code;
}
std::string ccs(std::string message){
std::string ccs;
for (int k = 0;;) {
	std::cout << message << std::endl;
	int u = 0;
	int s = 0;
	std::getline(std::cin, ccs);
	system("cls");
for (unsigned int i = 0; i < ccs.size(); i++) {
			if (ccs.size() < 3 || ccs.size() >= 20) {
				std::cout << "������� 3 �������. �������� 20." << std::endl;
				break;
			}
			if (ccs[0] >= 'A' && ccs[0] <= 'Z')
				i = 1;
			else
			{
				std::cout << "������ ����� ������ ���� ���������.\n" << std::endl;
				break;
			}

			for (i; i < ccs.size(); i++) {
				if (ccs[i] >= 'a' && ccs[i] <= 'z' || ccs[i]>='A' && ccs[i]<='Z' || ccs[i]=='.')
					u++;

				else {
					std::cout << "����������� �� ����� ����� ���������� �������� � �����." << std::endl;
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
		year = getInt("������� ���");
		if (year < 1866 || year > 2050) {
			system("cls");
			std::cout << "������������ ������� ��������� � 1866. ������ ��������� �������� �� 2050 ����." << std::endl;
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
		month = getInt("������� �����");
		if (month < 1 || month > 12) {
			system("cls");
			std::cout << "� ���� 12 �������" << std::endl;
			continue;
		}
		break;
	}

	system("cls");
	while (true) {
		day = getInt("������� ����.");
		if (day < 1 || day>31) {
			system("cls");
			std::cout << "� ������ �������� 31 ����." << std::endl;
			continue;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			system("cls");
			if (day > 30) {
				std::cout << "� ������, ����, �������� � ������ 30 ����." << std::endl;
				continue;
			}
		}
		if (month == 2 && isLeap == true) {
			system("cls");
			if (day > 29) {
				std::cout << "� ���������� ���� � ������� 29 ����." << std::endl;
				continue;
			}
		}
		if (month == 2 && isLeap == false) {
			system("cls");
			if (day > 28) {
				std::cout << " � ������� 28 ����." << std::endl;
				continue;
			}
		}

		break;
	}
   std::string day1 = std::to_string(day);
	std::string month1 = std::to_string(month);
	std::string year1 = std::to_string(year);
	if (day1 == "1" || day1 == "2" || day1 == "3" || day1 == "4" || day1 == "5" || day1 == "6" || day1 == "7" || day1 == "8" || day1 == "9"  ) { day1 = "0" + day1; }
	if (month1 == "1" || month1 == "2" || month1 == "3" || month1 == "4" || month1 == "5" || month1 == "6" || month1 == "7" || month1 == "8" || month1 == "9") { month1 = "0" + month1; }
	std::string date = day1 + "." + month1 + "." + year1;
	return date;

}
std::string telephone_number(std::string message) {
	std::string telephone_number;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, telephone_number);
		system("cls");
		if (telephone_number.empty()) continue; 
		for (unsigned int i = 0; i < telephone_number.size(); i++) {
			if (telephone_number.size() != 9) {
				s++;
				std::cout << "����� �������� ������ ��������� 9 ��������." << std::endl;
				break;
			}
			if (telephone_number[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < telephone_number.size(); i++) {

				if (telephone_number[i] >= '0' && telephone_number[i] <= '9')
					u++;
				else {
					std::cout << "����������� ����� ��� �����" << std::endl;
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
std::string hf(std::string message) {
	std::string hf;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, hf);
		system("cls");
		if (hf.empty())continue;
		for (unsigned int i = 0; i < hf.size(); i++) {
			if (hf.size() > 3) {
				s++;
				std::cout << "�������� 3 �������." << std::endl;
				break;
			}
			if (hf[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < hf.size(); i++) {

				if (hf[i] >= '0' && hf[i] <= '9')
					u++;
				else {
					std::cout << "����������� ����� ��� �����" << std::endl;
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
std::string ns(std::string message) {
	std::string ns;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin,ns);
		system("cls");
		if (ns.empty())continue;
		for (unsigned int i = 0; i < ns.size(); i++) {
			if (ns[i] == ' ') {
				s++;
				std::cout << "�� ����������� �������." << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < ns.size(); i++) {
				if (ns.size() < 3 || ns.size() > 15) {
					std::cout << " ������� 3 �������. �������� 15." << std::endl;
					break;
				}
				if (ns[0] >= 'A' && ns[0] <= 'Z')
					i = 1;
				else
				{
					std::cout << "����������� ����� ���������� ��������. ������ ������ ������ ���� ��������� ������.������� ��� ��� ���\n" << std::endl;
					break;
				}

				for (i; i < ns.size(); i++) {
					if (ns[i] >= 'a' && ns[i] <= 'z')
						u++;
					else {
						std::cout << " ����������� ����� ���������� �������� .\n ��������� ������� - �������� �����.������� ��� ��� ���." << std::endl;
						u = 0;
						break;
					}

				}
				if (u == 0)break;
				if (u == ns.size() - 1) break;
			}
		}
		if (u == ns.size() - 1)
			break;
	}
	return ns;
}
std::string yes_no(std::string message) {
	std::string vibor;
	while (true) {
		system("cls");
		std::cout << message << std::endl;
		getline(std::cin,vibor);
		if (vibor != "yes" && vibor != "no")
			continue;
		else break;
	}
	return vibor;
}
void top_10() {
	information temp;
	std::vector<information> kolvo;
	std::vector<information>userss;
	std::string client_code;
	data_magic_file(userss);
	int c;
	again:
	for (auto i : userss) {
		client_code = i.client_code;
		c = 0;
		for (auto i : userss) {
			if (i.client_code == client_code)  c++; 
		}
		userss.erase(std::remove_if(userss.begin(), userss.end(), [=](information& i) { return i.client_code == client_code; }), userss.end());
		if (c >= 1) {
			temp.client_code = i.client_code;
			temp.name = i.name;
			temp.surname = i.surname;
			std::string a = std::to_string(c);
			temp.kolichestvo = a;
			kolvo.push_back(temp);
		}
		goto again;
	}
	std::sort(kolvo.begin(), kolvo.end(), [](information& a, information& b) {
		return a.kolichestvo > b.kolichestvo;
	});
	if (kolvo.size() > 10) {
		kolvo.erase(kolvo.begin() + 9, kolvo.end());
	}
	TablePrinter tp(&std::cout);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("���", 15);
	tp.AddColumn("�������", 15);
	tp.AddColumn("���������� ����������� ���������", 35);
	tp.PrintHeader();
	for (auto i : kolvo) {
		tp << i.client_code << i.name << i.surname << i.kolichestvo << bprinter::endl();
		tp.PrintFooter();
	}
	return;
};
std::string service_code(std::string message) {
	std::string service_code;
	while (true) {
		system("cls");
		std::cout << message << std::endl;
		getline(std::cin, service_code);
		if (service_code != "1111" && service_code != "2222" && service_code != "3333" && service_code != "4444" && service_code !="5555" && service_code !="6666" && service_code != "7777" && service_code != "8888" && service_code !="9999" )
			continue;
		else break;
	}
	return service_code;
}
std::string dogovor_name(std::string code) {
	std::string name;
	if (code == "1111") name = "Power of attorney";
	if (code == "2222") name = "Marriage contract";
	if (code == "3333") name = "Bequest";
	if (code == "4444") name = "Privatization";
	if (code == "5555") name = "Executive inscriptions";
	if (code == "6666") name = "Alienation of real estate";
	if (code == "7777") name = "Alimony Agreement";
	if (code == "8888") name = "Agreement on a child traveling abroad";
	if (code == "9999") name = "Agreement";
	return name;

}
void dogovor_code(std::vector<dogovor> &documentCode) {
	std::ifstream file("document_code.txt");
	while (file) {
		dogovor temp;
		getline(file, temp.document_code);
		documentCode.push_back(temp);
	}
	if (!documentCode.empty()) documentCode.erase(documentCode.end() - 1);
	file.close();
	return;
}
void add_document_code() {
	system("cls");
	dogovor dogovorka;
	data datas;
	bool access = true;
	do {
		if (access) {
			dogovorka.document_code = document_code(1, access);
		}
		else {
			dogovorka.document_code = document_code(2, access);
		}
		std::ifstream file("document_code.txt", std::ios::app);
		while (file) {
			std::string tmp;
			getline(file, tmp);
			if (tmp == dogovorka.document_code)
			{
				access = false;
				break;
			}
			else {
				access = true;
			}
		}
		file.close();
	} while (!access);
	system("cls");
	datas.date = date("������� ����."); 
	std::ofstream file1("dogovor.txt", std::ios::app);
	file1 << dogovorka.document_code << std::endl<<datas.date << std::endl;
	file1.close();
	std::ofstream file2("document_code.txt", std::ios::app);
	file2 << dogovorka.document_code << std::endl ;
	file2.close();
	system("cls");
	std::cout << "�� �������� �������." << std::endl;
	return;
}
std::string document_code(int type, bool& access) {
	bool run = true;
	int u = 0;
	std::string document_code;
	switch (type) {
	case 1:
		system("cls");
		if (access) document_code = getString("������� ����� ��������.");
		else document_code = getString("������� ��� ��������� ��� ���.");
		break;
	case 2:
		system("cls");
		document_code = getString("����� ����� �������� ��� ���������� � ����. ������� ����� ��������� ��� ���.");
		break;
	};
		do {
			u = 0;
			if (document_code.size() != 10)
			{
				document_code = getString("��� �������� ������ ��������� 10 ��������.");
				continue;
			}

			for (unsigned int i = 0; i < document_code.size(); ++i)
				if (!((document_code[i] >= 'a' && document_code[i] <= 'z')
					|| (document_code[i] >= 'A' && document_code[i] <= 'Z')
					|| (document_code[i] >= '0' && document_code[i] <= '9')))
				{
					document_code = getString("��� �������� �������� ������������ �������.");
					break;
				}
				else u++;
				if (u == document_code.size())break;
		} while (true);
	return document_code;
}
std::string summ(std::string message) {
	std::string summ;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, summ);
		system("cls");
		for (unsigned int i = 0; i < summ.size(); i++) {
			if (summ.size() >= 9) {
				s++;
				std::cout << "����� ������� ������." << std::endl;
				break;
			}
			if (summ[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������." << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < summ.size(); i++) {

				if (summ[i] >= '0' && summ[i] <= '9')
					u++;
				else {
					std::cout << "����������� ����� ��� �����" << std::endl;
					u = 0;
					break;
				}
				if (u == 0)break;
				if (u == summ.size()) break;
			}
		}
		if (u == summ.size())break;
    }
	return summ;
}
std::string dogovor_code1(std::string message) {
	std::string dogovor_code;
	for (int k = 0;;) {
		std::cout << message << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, dogovor_code);
		system("cls");
		if (dogovor_code.empty())continue;
		for (unsigned int i = 0; i < dogovor_code.size(); i++) {
			if (dogovor_code.size() != 10) {
				s++;
				std::cout << "����� �������� ������ ��������� 10 ��������." << std::endl;
				break;
			}
			if (dogovor_code[i] == ' ') {
				s++;
				std::cout << " ������� ��� ��������" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < dogovor_code.size(); i++) {

				if (dogovor_code[i] >= 'a' && dogovor_code[i] <= 'z' || dogovor_code[i] >= '0' && dogovor_code[i] <= '9' || dogovor_code[0] >= 'A' && dogovor_code[0] <= 'Z')
					u++;
				else {
					std::cout << "����������� ����� ���������� �������� � ����� �  ��� �����" << std::endl;
					u = 0;
					break;
				}
				if (u == 0)break;
				if (u == dogovor_code.size()) break;
			}
		}
		if (u == dogovor_code.size()) break;
	}
	return dogovor_code;
}
void find_dogovor_number() {
	system("cls");
	int u=0;
	std::string dogovor_number;
	dogovor_number = dogovor_code1("������� ����� ��������.");
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	TablePrinter tp(&std::cout);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.AddColumn("���� ����������", 15);
	tp.AddColumn("����� ��������", 14);
	tp.PrintHeader();
	for (auto i : dogovors) {
		if (dogovor_number == i.document_code) {
			u++;
			tp << i.document_code << i.service_code << i.name << i.summ << i.comission << i.date << i.client_code << bprinter::endl();
			tp.PrintFooter();
		}
	}
	if (u == 0) {
		tp << " " << bprinter::endl();
		tp.PrintFooter();
		std::cout << "������ ������ �������� � ���� �� ����������." << std::endl;
	}
	return;
} 
void find_date() {
	system("cls");
	int u = 0;
	std::string date1;
	date1 = date("������� ����.");
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	TablePrinter tp(&std::cout);
	tp.AddColumn("���� ����������", 15);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.PrintHeader();
	for (auto i : dogovors) {
		if (date1 == i.date) {
			u++;
			tp << i.date << i.client_code << i.document_code << i.service_code << i.name << i.summ << i.comission << bprinter::endl();
			tp.PrintFooter();
		}
	}
	if (u == 0) {
		tp << " " << bprinter::endl();
		tp.PrintFooter();
		std::cout << "� ����� ���� ������� �� ���������." << std::endl;
	}
	return;
}
void find_passport() {
	system("cls");
	int u = 0;
	std::string passport;
	passport = client_code("������� ����� ��������.");
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	TablePrinter tp(&std::cout);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.AddColumn("���� ����������", 15);
	tp.PrintHeader();
	for (auto i : dogovors) {
		if (passport == i.client_code) {
			u++;
			tp << i.client_code << i.document_code << i.service_code << i.name << i.summ << i.comission << i.date  << bprinter::endl();
			tp.PrintFooter();
		}
	}
	if (u == 0) {
		tp << " " << bprinter::endl();
		tp.PrintFooter();
		std::cout << "�� ���� ����� �������� �� ��������������� �������." << std::endl;
	}
	return;
}
void find_service() {
	system("cls");
	int u = 0;
	std::string service;
	service = service_code("������� ����� ������.\n 1111 - ������������. \n 2222 - ������� �������. \n 3333 - ���������. \n 4444 - ������������. \n 5555 - �������������� �������. \n 6666 - ���������� ����������� ���������. \n 7777 - ���������� �� ������ ���������. \n 8888 - ���������� �� ����� ������� �� ������. \n 9999 - ��������. ");
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	TablePrinter tp(&std::cout);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.AddColumn("���� ����������", 15);
	tp.PrintHeader();
	for (auto i : dogovors) {
		if (service == i.service_code) {
			u++;
			tp << i.service_code << i.name << i.document_code << i.client_code  << i.summ << i.comission << i.date << bprinter::endl();
			tp.PrintFooter();
		}

	}
	if (u == 0) {
		tp << " " << bprinter::endl();
		tp.PrintFooter();
		std::cout << "������� ������ ���� �� ����������." << std::endl;
	}
	return;
}
void find_user() {
	system("cls");
	int u = 0;
	std::string passport;
	passport = client_code("������� ����� ��������.");
	std::vector<information> info;
	data_client_file(info);
	TablePrinter tp(&std::cout);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("��� � �������", 15);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("������ � �����", 20);
	tp.AddColumn("�����", 20);
	tp.AddColumn("����� ����", 10);
	tp.AddColumn("����� ��������", 14);
	tp.PrintHeader();
	for (auto i : info) {
		if (passport == i.client_code) {
			u++;
			tp << i.client_code << i.name << i.telephone_number << i.country <<i.street<< i.housenumber << i.flatnumber << bprinter::endl();
			tp<<" "  << i.surname<< " " <<i.city<<" "<<" "<<" " << bprinter::endl(); ;
			tp.PrintFooter();
		}

	}
	if (u == 0) {
		tp << " " << bprinter::endl();
		tp.PrintFooter();
		std::cout << "����� ������ �������� ��� � ����." << std::endl;
	}
	return;

}
std::string vibor_1_2_3_4_5_6(std::string message) {
	std::string vibor;
	while (true) {
		system("cls");
		std::cout << message << std::endl;
		getline(std::cin, vibor);
		if (vibor != "1" && vibor != "2" && vibor != "3" && vibor != "4" && vibor != "5" && vibor != "6" && vibor != "7")continue;
		else break;
	}
	return vibor;
}
void sort() {
	system("cls");
	std::vector<Vivod> dogovors;
	data_dogovor_file(dogovors);
	std::sort(dogovors.begin(), dogovors.end(), [](Vivod& a, Vivod& b) {
		return a.service_code < b.service_code;
	});
	TablePrinter tp(&std::cout);
	tp.AddColumn("��� ������", 11);
	tp.AddColumn("�������� ��������", 37);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("����� ��������", 14);
	tp.AddColumn("�����", 9);
	tp.AddColumn("��������", 9);
	tp.AddColumn("���� ����������", 15);
	tp.PrintHeader();
	for (auto i : dogovors) {
		tp << i.service_code << i.name << i.document_code << i.client_code << i.summ << i.comission << i.date << bprinter::endl();
			tp.PrintFooter();
		}
	return;
}
void changelogpass() {
	system("cls");
	std::vector<logpass> users;
	data_user_file(users);
	std::string choice;
	std::string login = login1("������� �����.");
	system("cls");
	int a = users.size();
   users.erase(std::remove_if(users.begin(), users.end(), [=](logpass& a) { return a.login == login  ; }), users.end());
   int k = users.size();
   if (a == k) std::cout << "�� ����� ������������ ������. ������������ � ����� ������� �� ����������." << std::endl;
   if(a!=k){
	   while (true) {
		   system("cls");
		   std::cout << " �������:  \n 1.���� ������ �������� ������.\n 2.���� ������ �������� ����� � ������. " << std::endl;
		   getline(std::cin, choice);
		   if (choice != "1" && choice != "2")
			   continue;
		   else break;
	   }
	  if (choice == "1") {
		  system ("cls");
		   logpass temp;
		   temp.login = login;
		   temp.password = sha256(password1("������� ����� ������."));
		   users.push_back(temp);
		   rewrite_user_file(users);
		}
	   if (choice == "2") {
		   system("cls");
	   logpass tmp;
	   tmp.login = login1("������� ����� �����.");
	   tmp.password =sha256( password1("������� ����� ������"));
	    users.push_back(tmp);
	   rewrite_user_file(users);
	 }
   }
   return;
}
void changeinfo() {
	system("cls");
	std::vector<information> userss;
	data_client_file(userss);
	std::string passport_code = client_code("������� ����� �������� ��� ���������� ����������.");
	int a = userss.size();
	userss.erase(std::remove_if(userss.begin(), userss.end(), [=](information& s) { return s.client_code == passport_code; }), userss.end());
	int k = userss.size();
	if (k != a) {
		information temp;
		temp.client_code = passport_code;
		temp.name = ns("������� ���.");
		temp.surname = ns("������� �������.");
		temp.telephone_number = telephone_number("������� ����� ��������.");
		temp.country = ccs("������� ������ ����������.");
		temp.city = ccs("������� ����� ����������.");
		temp.street = ccs("������� ����� ����������.");
		temp.housenumber = hf("������� ����� ����.");
		temp.flatnumber = hf("������� ����� ��������, ������� 0 ,���� ������ ��������� � ������� ����.");
		userss.push_back(temp);
		rewrite_information_file(userss);
		std::vector <information> passport;
		data_passport_file(passport);
		passport.erase(std::remove_if(passport.begin(), passport.end(), [=](information& s) { return s.client_code == passport_code; }), passport.end());
		information tmp;
		tmp.client_code = passport_code;
		tmp.name = temp.name;
		tmp.surname = temp.surname;
		passport.push_back(tmp);
		rewrite_passport_file(passport);
		std::vector <information> magic;
		data_magic_file(magic);
		int n = 0;
		for (auto i : magic) {
			if (i.client_code == passport_code) n++;
		}
		magic.erase(std::remove_if(magic.begin(), magic.end(), [=](information& s) { return s.client_code == passport_code; }), magic.end());
		for (int i = 0; i < n; i++) {
			magic.push_back(tmp);
		}
		rewrite_magic_file(magic);
		return;
	}
	else {
		std::cout << "������ ������ �������� � ������������ ���� ���." << std::endl;
		return;
	}
	return;
}
