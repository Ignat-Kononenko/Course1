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
//	cout << "�������� �������: " << endl;
//	cout << "1-���� ����������" << endl;
//	cout << "2-����� �� �����" << endl;
//	cout << "3-������ � ����" << endl;
//	cout << "4-������ �� �����" << endl;
//	cout << "5-�����" << endl;
//	cout << "6-����� �� ���������" << endl;
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
//		cout << "������ �������� ����� fin.txt" << endl;
//		exit(0);
//	}
//	cout << "���� ����������" << endl;
//	for (int i = current_size; i < current_size + 1; i++) {
//		cout << "������� ���: ";
//		cin.ignore();
//		cin.getline(employee_info.fio, MAX_LENGHT);
//		fout << employee_info.fio<<endl;
//
//		cout << "������� �����������: ";
//		cin.getline(employee_info.education, MAX_LENGHT);
//		fout << employee_info.education << endl;
//
//		cout << "������� �������������: ";
//		cin.getline(employee_info.speciality, MAX_LENGHT);
//		fout << employee_info.speciality << endl;
//
//		cout << "������� �������������: ";
//		cin.getline(employee_info.subdivision, MAX_LENGHT);
//		fout << employee_info.subdivision << endl;
//
//		cout << "������� ���������: ";
//		cin.getline(employee_info.job_title, MAX_LENGHT);
//		fout << employee_info.job_title << endl;
//
//		cout << "������� ��������: ";
//		cin.getline(employee_info.salary, MAX_LENGHT);
//		fout << employee_info.salary << endl;
//
//		cout << "������� ���� ����������� �� �����������: ";
//		cin.getline(employee_info.date_of_entry_into_the_enterprise, MAX_LENGHT);
//		fout << employee_info.date_of_entry_into_the_enterprise;
//		fout.close();
//	}
//	list[current_size] = employee_info;
//	current_size++;
//	
//	cout << "��� ������?" << endl;
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
//			cout << "�������� ����� " << i + 1 << ":" << endl;
//
//			cout << endl << "���:";
//			cout << list[i].fio;
//			
//			cout << endl << "O����������:";
//			cout << list[i].education;
//			
//			cout << endl << "C������������: ";
//			cout << list[i].speciality;
//			
//			cout << endl << "�������������:";
//			cout << list[i].subdivision;
//			
//			cout << endl << "���������:";
//			cout << list[i].job_title;
//			
//			cout << endl << "��������:";
//			cout << list[i].salary;
//		
//			cout << endl << "���� ����������� �� �����������: ";
//			cout << list[i].date_of_entry_into_the_enterprise;
//		
//			
//		}
//		fout.close();
//		cout <<endl << "��� ������?" << endl;
//	}
//
//}
//void write() {
//	
//
//	cout << "������ �������� � ����" << endl;
//	for (int p = 0; p < current_size; p++)
//	{
//
//		fout << list[p].fio << endl << list[p].education << endl << list[p].speciality << endl << list[p].subdivision << endl << list[p].job_title << endl << list[p].salary << endl << list[p].date_of_entry_into_the_enterprise << endl;
//	}
//
//	
//	cout << "��� ������?" << endl;
//
//}
//
//void read() {
//
//	ifstream fin("fout.txt");
//	if (!fin.is_open()) {
//		cout << "������";
//		exit(1);
//	}
//	int i = 0;
//
//	string line;
//	while (getline(fin, line)) {
//		if (i == 0 || i == 7 || i == 14 || i == 21) {
//			cout << endl << "���: " << endl;
//
//			
//			cout << line << endl;
//		}
//		else if (i == 1 || i == 8 || i ==15 || i == 22) {
//			cout << "O����������: " << endl;
//			
//			cout << line << endl;
//		}
//		else if (i == 2 || i == 9 || i == 16 || i == 23) {
//			cout << "C������������: " << endl;
//	
//			cout << line << endl;
//		}
//		else if (i == 3 || i == 10 || i == 17 || i == 24) {
//			cout << "�������������: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 4 || i == 11 || i == 18 || i == 25) {
//			cout << "���������: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 5 || i == 12 || i == 19 || i == 26) {
//			cout << "��������: " << endl;
//			cout << line << endl;
//		}
//		else if (i == 6 || i == 13 || i == 20 || i == 27) {
//			cout << "���� ����������� �� �����������: " << endl;
//			cout << line << endl;
//		}
//		i++;
//	}
//
//
//	fin.close();
//	cout << endl << "��� ������?" << endl;
//
//}
//
////void search() {
////		
////		char destination[STRING_LENGTH];
////		cout << "������� ���������: ";
////		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
////		gets_s(destination);
////
////		if (!fin.is_open()) {
////			std::cout << "�� ������� ������� ���� ��� ������" << std::endl;
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
//						cout << endl << "���: " << endl;
//
//
//						cout << line << endl;
//					}
//					else if (i == 1 || i == 8 || i == 15 || i == 22) {
//						cout << "O����������: " << endl;
//
//						cout << line << endl;
//					}
//					else if (i == 2 || i == 9 || i == 16 || i == 23) {
//						cout << "C������������: " << endl;
//
//						cout << line << endl;
//					}
//					else if (i == 3 || i == 10 || i == 17 || i == 24) {
//						cout << "�������������: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 4 || i == 11 || i == 18 || i == 25) {
//						cout << "���������: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 5 || i == 12 || i == 19 || i == 26) {
//						cout << "��������: " << endl;
//						cout << line << endl;
//					}
//					else if (i == 6 || i == 13 || i == 20 || i == 27) {
//						cout << "���� ����������� �� �����������: " << endl;
//						cout << line << endl;
//					}
//					i++;
//				}
//			}
//			current_size++;
//		}
//
//
//		std::cout << "��� ������?" << std::endl;
//	}*/
//
