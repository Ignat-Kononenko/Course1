#include<iostream>
#include<string>
#include <fstream>


#define s 250

using namespace std;

void enter_new();
void out();
void del();
void search();
void input();
void output();

struct stock {
	string name;
	string price;
	string amount;
	string percent;
};


struct stock list[s];
int current_size = 0;

struct stock bad;

ifstream fin("fout.txt");;
ofstream fout;




int main() {
	setlocale(LC_ALL, "rus");
	int number;
	int dd;
	cout << "1. ���� ��������� ��������� � ����������" << endl;
	cout << "2. ����� ��������� ��������� � ���������� ����" << endl;
	cout << "3. �������� �������� ����������������� ����������" << endl;
	cout << "4. ����� ����������" << endl;
	cout << "5. ������ ���������� � ����" << endl;
	cout << "6. ������ ������ �� �����" << endl;
	cout << "7. �����" << endl;

	do {
		cin >> number;
		switch (number) {

		case 1:
			enter_new();
			break;
		case 2:
			out();
			break;
		case 3:
			
			del();
			break;
		case 4:
			search();
			break;
		case 5:
			input();
			break;
		case 6:
			output();
			break;
		case 7:
		default:
			break;
		}
	} while (number != 7);

	return 0;
}

void enter_new() {


	struct stock new_list;
	cout << "���� ����������" << endl;

	if (current_size < s) {

		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "������������ ������:" << endl;
		cin.ignore();
		getline(cin, new_list.name);
		cout << "����:" << endl;
		cin >> new_list.price;

		string str = new_list.price;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '.') {

			}
			else if ((str[i] > '9') || (str[i] < '0')) {
				cout << "������ �����" << endl;
				exit(0);
			}
		}
		cout << "����������:" << endl;
		cin >> new_list.amount;

		string st = new_list.amount;
		for (int i = 0; i < st.size(); i++) {
			if ((st[i] > '9') || (st[i] < '0')) {
				cout << "������ �����" << endl;
				exit(0);
			}
		}
		cout << "������� �������� ��������:" << endl;
		cin >> new_list.percent;

		string strl = new_list.percent;
		for (int i = 0; i < strl.size(); i++) {
			if (strl[i] == '.') {
				break;
			}
			else if ((strl[i] > '9') || (strl[i] < '0')) {
				cout << "������ �����" << endl;
				exit(0);
				break;
			}
		}
		list[current_size] = new_list;
		current_size++;

	}
	else {
		cout << "������� ������������ ���-�� �����" << endl;;
	}

	cout << "��� ������?" << endl;
}

void out() {

	int sw, n;
	cout << endl << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;
		cin >> n;

		cout << "������������ ������:" << endl;
		cout << list[n - 1].name;
		cout << endl << "����:" << endl;
		cout << list[n - 1].price;
		cout << endl << "����������:" << endl;
		cout << list[n - 1].amount;
		cout << endl << "������� �������� ��������:" << endl;
		cout << list[n - 1].percent;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++) {
			cout << endl;
			if (list[i].name.length() == 0) {
				

			}
			else {

				cout << "������������ ������:" << endl;
				cout << list[i].name;
				cout << endl << "����:" << endl;
				cout << list[i].price;
				cout << endl << "����������:" << endl;
				cout << list[i].amount;
				cout << endl << "������� �������� ��������:" << endl;
				cout << list[i].percent;
			}
		}
	}

	cout << endl;
	cout << "��� ������?" << endl;
}

void del() {

	int d, dd;
	cout << endl << "����� ������(������� � 1), ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d <= 0) {
		cout << "������" << endl;
		exit(0);
	}

	if (d != 99) {
		for (int j = (d-1) ; j < current_size; j++) {
			if (j == (d - 1)) {
				list[j] = bad;
			}
			for (int i = j; i < current_size; i++) {
				list[i] = list[i + 1];
				current_size = current_size - 1;
			}
		}
	}
	if (d == 99) {
		for (int i = 0; i < s; i++) {
			list[i] = bad;
		}
		dd = d;

	}
	cout << "��� ������?" << endl;
}

void search() {

	string value;
	cout << "������� ����: ";
	cin >> value;
	


	for (int k = 0; k < current_size; k++) {

		if (value == list[(k + 1) / 4].price) {
			cout << "������������ ������: " << list[k / 4].name << endl;
			cout << "����������: " << list[(k + 2) / 4].amount << endl;
			cout << "������� �������� ��������: " << list[(k + 3) / 4].percent << endl;
			break;
		}
		if (value == list[(k + 5) / 4].price) {
			cout << "������������ ������: " << list[(k + 4) / 4].name << endl;
			cout << "����������: " << list[(k + 6) / 4].amount << endl;
			cout << "������� �������� ��������: " << list[(k + 7) / 4].percent << endl;
			break;
		}
		if (value == list[(k + 9) / 4].price) {
			cout << "������������ ������: " << list[(k + 8) / 4].name << endl;
			cout << "����������: " << list[(k + 10) / 4].amount << endl;
			cout << "������� �������� ��������: " << list[(k + 11) / 4].percent << endl;
			break;
		}

		if (value == list[k + 1].price) {
			cout << "������������ ������: " << list[k].name << endl;
			cout << "����������: " << list[k + 2].amount << endl;
			cout << "������� �������� ��������: " << list[k + 3].percent << endl;
		}
		if (value == list[k + 5].price) {
			cout << "������������ ������: " << list[k + 4].name << endl;
			cout << "����������: " << list[k + 6].amount << endl;
			cout << "������� �������� ��������: " << list[k + 7].percent << endl;
		}
		if (value == list[k + 9].price) {
			cout << "������������ ������: " << list[k + 8].name << endl;
			cout << "����������: " << list[k + 10].amount << endl;
			cout << "������� �������� ��������: " << list[k + 11].percent << endl;
		}
		
	}
	
	cout << "��� ������?" << endl;
}



void input() {

	fout.open("fout.txt");

	if (!fin.is_open()) {
		cout << "������ �������� ����� fin.txt" << endl;
		exit(0);
	}

	cout << "������ �������� � ����" << endl;
	for (int p = 0; p < current_size; p++)
	{

		fout << list[p].name << endl << list[p].price << endl << list[p].amount << endl << list[p].percent << endl;
	}

	fout.close();
	cout << "��� ������?" << endl;
}

void output() {


	for (int i = 0; i < s; i++) {
		list[i] = bad;
	}

	ifstream fin("fout.txt");
	if (!fin.is_open()) {
		cout << "������";
		exit(1);
	}
	int i = 0;

	string line;
	while (getline(fin, line)) {
		if (i == 0 || i == 4 || i == 8 || i == 12) {
			cout << endl << "������������ ������: " << endl;

			list[i/4].name  = line;
			cout << line << endl;
		}
		else if (i == 1 || i == 5 || i == 9 || i == 13) {
			cout << "����: " << endl;
			list[i/4].price = line;
			cout << line << endl;
		}
		else if (i == 2 || i == 6 || i == 10 || i == 14) {
			cout << "����������: " << endl;
			list[i/ 4].amount = line;
			cout<< line << endl;
		}
		else if (i == 3 || i == 7 || i == 11 || i == 15) {
			cout << "������� �������� ��������: " << endl;
			list[i / 4].percent = line;
			cout << line << endl;
		}

		i++;
	}

	
	fin.close();
	cout << endl << "��� ������?" << endl;
}