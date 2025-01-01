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
	cout << "1. Ввод элементов структуры с клавиатуры" << endl;
	cout << "2. Вывод элементов структуры в консольное окно" << endl;
	cout << "3. Удаление заданной структурированной переменной" << endl;
	cout << "4. Поиск информации" << endl;
	cout << "5. Запись информации в файл" << endl;
	cout << "6. Чтение данных из файла" << endl;
	cout << "7. Выход" << endl;

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
	cout << "Ввод информации" << endl;

	if (current_size < size) {

		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование товара:" << endl;
		cin.ignore();
		cin.getline(list[current_size].name, size);
		cout << "Цена:" << endl;
		cin >> list[current_size].price;
		cout << "Количество:" << endl;
		cin >> list[current_size].amount;
		cout << "Процент торговой надбавки:" << endl;
		cin >> list[current_size].percent;
		current_size++;
	}
	else {
		cout << "Введено максимальное кол-во строк" << endl;;
	}
	cout << "Что дальше?" << endl;
}

void out() {

	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;
		cin >> n;

		cout << "Наименование товара:" << endl;
		cout << list[n - 1].name;
		cout << endl << "Цена:" << endl;
		cout << list[n - 1].price;
		cout << endl << "Количество:" << endl;
		cout << list[n - 1].amount;
		cout << endl << "Процент торговой надбавки:" << endl;
		cout << list[n - 1].percent;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++) {
			cout << endl;
			cout << "Наименование товара:" << endl;
			cout << list[i].name;
			cout << endl << "Цена:" << endl;
			cout << list[i].price;
			cout << endl << "Количество:" << endl;
			cout << list[i].amount;
			cout << endl << "Процент торговой надбавки:" << endl;
			cout << list[i].percent;
		}
	}
	cout << endl;
	cout << "Что дальше?" << endl;
}

void del() {

	int d;
	cout << "Номер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
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
	cout << "Что дальше?" << endl;
}

void search() {

	char value[25];
	cout << "Введите цену: ";
	cin >> value;
	for (int k = 0; k < current_size; k++) {
		if (strcmp(value, list[k].price) == 0) {
			cout << "Наименование товара / количество / процент торговой надбавки " << endl;
			cout << list[k].name << "\t" << list[k].amount << "\t" << list[k].percent << endl;
		}
	}
	cout << "Что дальше?" << endl;
}

void input() {

	fout.open("fout.txt");

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла fin.txt" << endl;
		exit(0);
	}
	stock buf = { ' ', ' ', ' ', ' ' };
	cout << "Ввод информации" << endl;
	for (int p = 0; p < 1; p++)
	{
		cout << "Наименование товара: ";
		cin.ignore();
		cin.getline(buf.name, 50);
		cout << "Цена: "; 	cin >> buf.price;
		cout << "Количество: "; 	cin >> buf.amount;
		cout << "Процент торговой надбавки: "; 	cin >> buf.percent;
		fout << buf.name << endl << buf.price << endl << buf.amount << endl << buf.percent << endl;
	}

	fout.close();
	cout << "Что дальше?" << endl;
}

void output() {
	stock buf{};
	ifstream fin("fout.txt");
	if (!fin.is_open()) {
		cout << "Ошибка";
		exit(1);
	}
	cout << "Наименование товара/ цена / количество / процент торговой надбавки " << endl;
	string line;
	while (getline(fin, line)) {
		cout << line << "\t\t";
	}

	fin.close();
	cout << endl << "Что дальше?" << endl;
}