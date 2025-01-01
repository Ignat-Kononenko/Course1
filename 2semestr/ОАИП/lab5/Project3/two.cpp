//#include<iostream>
//#include<string>
//#include<fstream>
//#define STRING_LENGTH 100
//
//#define MAX_LENGHT 256
//#define MAX_BUFFER_SIZE 10
//
//using namespace std;
//
//ifstream fin("fout.txt");
//ofstream fout;
//
//void input();
//void output();
//void write();
//void read();
//void search(char*);
//
//struct Department {
//
//	char fio[MAX_LENGHT];
//	char education[MAX_LENGHT];
//	char speciality[MAX_LENGHT];
//	char subdivision[MAX_LENGHT];
//	char job_title[MAX_LENGHT];
//	char salary[MAX_LENGHT];
//	char date_of_entry_into_the_enterprise[MAX_LENGHT];
//
//}employee_info;
//
//union DD {
//	char title[MAX_LENGHT];
//	char sal[MAX_LENGHT];
//};
//union Department list[MAX_LENGHT];
//int current_size = 0;
//
//int main() {
//
//	setlocale(LC_CTYPE, "Russian");
//
//	cout << "Выберите вариант: " << endl;
//	cout << "1-Ввод информации" << endl;
//	cout << "2-Вывод на экран" << endl;
//	cout << "3-Запись в файл" << endl;
//	cout << "4-Чтение из файла" << endl;
//	cout << "5-Поиск" << endl;
//	cout << "6-Выход из программы" << endl;
//	int c;
//
//	do {
//		cin >> c;
//		switch (c) {
//		case 1:
//			input();
//			break;
//		case 2:
//			output();
//			break;
//		case 3:
//			 write();
//
//			break;
//		case 4:
//			read();
//		
//			break;
//		case 5:
//			
//			search();
//			break;
//
//		default:
//			break;
//		}
//
//	} while (c != 6);
//
//
//	return 0;
//}
//
//void input() {
//
//	fout.open("fout.txt");
//
//	if (!fin.is_open()) {
//		cout << "ошибка открытия файла fin.txt" << endl;
//		exit(0);
//	}
//	cout << "Ввод информации" << endl;
//	for (int i = current_size; i < current_size + 1; i++) {
//		cout << "Введите ФИО: ";
//		cin.ignore();
//		cin.getline(employee_info.fio, MAX_LENGHT);
//		fout << employee_info.fio<<endl;
//
//		cout << "Введите образование: ";
//		cin.getline(employee_info.education, MAX_LENGHT);
//		fout << employee_info.education << endl;
//
//		cout << "Введите специальность: ";
//		cin.getline(employee_info.speciality, MAX_LENGHT);
//		fout << employee_info.speciality << endl;
//
//		cout << "Введите подразделение: ";
//		cin.getline(employee_info.subdivision, MAX_LENGHT);
//		fout << employee_info.subdivision << endl;
//
//		cout << "Введите должность: ";
//		cin.getline(employee_info.job_title, MAX_LENGHT);
//		fout << employee_info.job_title << endl;
//
//		cout << "Введите зарплату: ";
//		cin.getline(employee_info.salary, MAX_LENGHT);
//		fout << employee_info.salary << endl;
//
//		cout << "Введите дату поступления на предприятие: ";
//		cin.getline(employee_info.date_of_entry_into_the_enterprise, MAX_LENGHT);
//		fout << employee_info.date_of_entry_into_the_enterprise;
//		fout.close();
//	}
//	list[current_size] = employee_info;
//	current_size++;
//	
//	cout << "Что дальше?" << endl;
//	
//}
//
//void output() {
//
//	for (int i = 0; i < current_size; i++) {
//		cout << endl;
//		if (list[i].fio.lenght() == 0) {
//
//
//		}
//		else {
//
//			cout << "Работник номер " << i + 1 << ":" << endl;
//
//			cout << endl << "ФИО:";
//			cout << list[i].fio;
//			
//			cout << endl << "Oбразование:";
//			cout << list[i].education;
//			
//			cout << endl << "Cпециальность: ";
//			cout << list[i].speciality;
//			
//			cout << endl << "Подразделение:";
//			cout << list[i].subdivision;
//			
//			cout << endl << "Должность:";
//			cout << list[i].job_title;
//			
//			cout << endl << "Зарплата:";
//			cout << list[i].salary;
//		
//			cout << endl << "Дата поступления на предприятие: ";
//			cout << list[i].date_of_entry_into_the_enterprise;
//		
//			
//		}
//		fout.close();
//		cout <<endl << "Что дальше?" << endl;
//	}
//
//}
//void write() {
//	
//
//	cout << "данные записаны в файл" << endl;
//	for (int p = 0; p < current_size; p++)
//	{
//
//		fout << list[p].fio << endl << list[p].education << endl << list[p].speciality << endl << list[p].subdivision << endl << list[p].job_title << endl << list[p].salary << endl << list[p].date_of_entry_into_the_enterprise << endl;
//	}
//
//	
//	cout << "что дальше?" << endl;
//
//}
//
//void read() {
//
//	ifstream fin("fout.txt");
//	if (!fin.is_open()) {
//		cout << "ошибка";
//		exit(1);
//	}
//	int i = 0;
//
//	string line;
//	while (getline(fin, line)) {
//		if (i == 0 || i == 7 || i == 14 || i == 21) {
//			cout << endl << "ФИО: " << endl;
//
//			
//			cout << line << endl;
//		}
//		else if (i == 1 || i == 8 || i ==15 || i == 22) {
//			cout << "Oбразование: " << endl;
//			
//			cout << line << endl;
//		}
//		else if (i == 2 || i == 9 || i == 16 || i == 23) {
//			cout << "Cпециальность: " << endl;
//	
//			cout << line << endl;
//		}
//		else if (i == 3 || i == 10 || i == 17 || i == 24) {
//			cout << "Подразделение: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 4 || i == 11 || i == 18 || i == 25) {
//			cout << "Должность: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 5 || i == 12 || i == 19 || i == 26) {
//			cout << "Зарплата: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 6 || i == 13 || i == 20 || i == 27) {
//			cout << "Дата поступления на предприятие: " << endl;
//			cout << line << endl;
//		}
//		i++;
//	}
//
//
//	fin.close();
//	cout << endl << "что дальше?" << endl;
//
//}
//
////void search() {
////		
////		char destination[STRING_LENGTH];
////		cout << "Введите должность: ";
////		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
////		gets_s(destination);
////
////		if (!fin.is_open()) {
////			std::cout << "Не удалось открыть файл для чтения" << std::endl;
////			return;
////		}
////
////		Department list[STRING_LENGTH];
////		int current_size = 0;
////		string line;
////		int i = 0;
//
//		/*for (int k = 0; k <= current_size; k++) {
//					if (i == 0 || i == 7 || i == 14 || i == 21) {
//						cout << endl << "ФИО: " << endl;
//
//
//						cout << line << endl;
//					}
//					else if (i == 1 || i == 8 || i == 15 || i == 22) {
//						cout << "Oбразование: " << endl;
//
//						cout << line << endl;
//					}
//					else if (i == 2 || i == 9 || i == 16 || i == 23) {
//						cout << "Cпециальность: " << endl;
//
//						cout << line << endl;
//					}
//					else if (i == 3 || i == 10 || i == 17 || i == 24) {
//						cout << "Подразделение: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 4 || i == 11 || i == 18 || i == 25) {
//						cout << "Должность: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 5 || i == 12 || i == 19 || i == 26) {
//						cout << "Зарплата: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 6 || i == 13 || i == 20 || i == 27) {
//						cout << "Дата поступления на предприятие: " << endl;
//						cout << line << endl;
//					}
//					i++;
//				}
//			}
//			current_size++;
//		}
//
//
//		std::cout << "Что дальше?" << std::endl;
//	}*/
//
