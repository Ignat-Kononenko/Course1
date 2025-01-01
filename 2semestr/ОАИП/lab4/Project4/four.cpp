#include<iostream>
#include<string>
#include <fstream>


#define size 250

using namespace std;

void enter_new();
void out();
void del();
void search();
void input();
void output();

struct stock {
	char name[50];
	char price[10];
	int amount;
	int percent;
};


struct stock list[size];
int current_size = 0;

struct stock bad;

ifstream fin("fout.txt");;
ofstream fout;




int main() {
	setlocale(LC_ALL, "rus");
	int number;
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
	cout << "���� ����������" << endl;

	if (current_size < size) {

		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "������������ ������:" << endl;
		cin.ignore();
		cin.getline(list[current_size].name, size);
		cout << "����:" << endl;
		cin >> list[current_size].price;
		cout << "����������:" << endl;
		cin >> list[current_size].amount;
		cout << "������� �������� ��������:" << endl;
		cin >> list[current_size].percent;
		current_size++;
	}
	else {
		cout << "������� ������������ ���-�� �����" << endl;;
	}
	cout << "��� ������?" << endl;
}

void out() {

	int sw, n;
	cout << "1-����� 1 ������" << endl;
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
	cout << endl;
	cout << "��� ������?" << endl;
}

void del() {

	int d;
	cout << "����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;

	if (d != 99) {
		for (int j = (d - 1); j < current_size; j++) {
			list[j] = list[j + 1];
			current_size = current_size - 1;
		}
	}
	if (d == 99) {
		for (int i = 0; i < size; i++) {
			list[i] = bad;
		}
	}
	cout << "��� ������?" << endl;
}

void search() {

	char value[25];
	cout << "������� ����: ";
	cin >> value;
	for (int k = 0; k < current_size; k++) {
		if (strcmp(value, list[k].price) == 0) {
			cout << "������������ ������ / ���������� / ������� �������� �������� " << endl;
			cout << list[k].name << "\t" << list[k].amount << "\t" << list[k].percent << endl;
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
	stock buf = { ' ', ' ', ' ', ' ' };
	cout << "���� ����������" << endl;
	for (int p = 0; p < 1; p++)
	{
		cout << "������������ ������: ";
		cin.ignore();
		cin.getline(buf.name, 50);
		cout << "����: "; 	cin >> buf.price;
		cout << "����������: "; 	cin >> buf.amount;
		cout << "������� �������� ��������: "; 	cin >> buf.percent;
		fout << buf.name << endl << buf.price << endl << buf.amount << endl << buf.percent << endl;
	}

	fout.close();
	cout << "��� ������?" << endl;
}

void output() {
	stock buf{};
	ifstream fin("fout.txt");
	if (!fin.is_open()) {
		cout << "������";
		exit(1);
	}
	cout << "������������ ������/ ���� / ���������� / ������� �������� �������� " << endl;
	string line;
	while (getline(fin, line)) {
		cout << line << "\t\t";
	}

	fin.close();
	cout << endl << "��� ������?" << endl;
}