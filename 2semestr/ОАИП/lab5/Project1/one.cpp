#include<iostream>
#include<string>
#define S 100

using namespace std;

void input();
void output();
void del();
void search();

int current_size = 0;


struct information {

	enum { Toyota,
		Honda, 
		Bmw, 
		Audi 
} brand;//перечисление
	string color;
	string factory_number;
	struct DataRelease {
		unsigned int day : 4;
		unsigned int mounth : 4;
		unsigned int year : 8;
	} release;//биты
	string body;
	string technical_inspection;
	string owner;

};
struct information list[S];
struct information bad;

int main() {

	setlocale(LC_CTYPE, "Russian");

	cout << "Выберите вариант: " << endl;
	cout << "1-Ввод информации" << endl;
	cout << "2-Вывод записи" << endl;
	cout << "3-Удаление одной записи" << endl;
	cout << "4-Поиск записи" << endl;
	cout << "5-Выход из программы" << endl;
	int c;

	do {
		cin >> c;
		switch (c) {
		case 1:
			input();
			break;
		case 2:
 			output();
			break;
		case 3:
			del();
			break;
		case 4:
			search();
			break;
		default:
			break;
		}

	} while (c != 5);

	
	return 0;
}

void input() {

	struct information new_list;

	cout << "Ввод информации" << endl;

	cout << "Марка авто(1 - Toyota,2 - Honda,3 - Bmw, 4- Audi): " ;
	
	string num;
	cin.ignore();
	getline(cin, num);

	if (num.size() != 1) {
		cout << "вы ввели неправильно" << endl;
		exit(0);
	}

	for (int i = 0; i < num.length(); i++) {
		if ((num[i] > '4') || (num[i] < '0')) {
			cout << "вы ввели неправильно" << endl;
			exit(0);
		}
	}


	int number = stoi(num);

	
	switch (number) {
	case 1:
		new_list.brand = information::Toyota;
		
		break;
	case 2:
		new_list.brand = information::Honda;
		
		break;
	case 3:
		new_list.brand = information::Bmw;
		
		break;
	case 4:
		new_list.brand = information::Audi;
		
		break;
	default:
		cout << "Неверный номер марки авто" << endl;
		exit(0);
	}
	cout << "Цвет(может быть как словом, так и rgba): ";
	cin.ignore();
	getline(cin, new_list.color);
	cout << "Заводской номер (пример,WBAZZZ8A9KA123456): ";
	getline(cin, new_list.factory_number);

	cout << "Дата выпуска ДДММГГГГ: "<<endl;
	

	string val1, val2, val3;
	short value1, value2, value3;//string
	cout << "Введите день: ";

	getline(cin, val1);

	if (val1.length() != 2) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	for (int i = 0; i < val1.size(); i++) {
		if ((val1[i] > '9') || (val1[i] < '0')) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
			break;
		}
	}
	value1 = stoi(val1);

	new_list.release.day = value1;
	cout << "Введите месяц(01): ";
	
	getline(cin, val2);
	if (val2.size() != 2) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	for (int i = 0; i < val2.size(); i++) {
		if ((val2[i] > '9') || (val2[i] < '0')) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
			break;
		}
	}
	value2 = stoi(val2);

	new_list.release.mounth = value2;

	cout << "Введите год: ";

	getline(cin, val3);
	if (val3.size() != 4) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	for (int i = 0; i < val3.size(); i++) {
		if ((val3[i] > '9') || (val3[i] < '0')) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
			break;
		}
	}
	value3 = stoi(val3);
	new_list.release.year = value3;
	if (value1 <= 0 || value1 > 31|| value2 <= 0 || value2 > 12 || value3 <= 0 || ((value1 == 30) && (value2 == 2 )) || ((value1 == 31) && (value2 == 2)) || ((value1 == 29) && (value2 == 02) && (value3 == 2023))) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	// // // //
	if (value3 >= 2024) {
		if (value2 >= 04) {
			if (value1 > 1) {
				cout << "вы ввели неправильную дату" << endl;
				exit(0);
			}
		}
	}

	if (value2 == 2 || value2 == 4 || value2 == 6 || value2 == 9 || value2 == 11) {
		if (value1 == 31) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
		}
	}

	int day_of_February;
	if ((value3 % 4 == 0) || (value3 % 400 == 0)) {

		day_of_February = 29;

	}
	else if (value3 % 100 == 0) {

		day_of_February = 28;
		if (value2 == 2) {
			if (day_of_February + 1 == value1) {
				cout << "вы ввели неправильную дату" << endl;
				exit(0);
			}
		}
	}
	else {
		day_of_February = 28;
		if (value2 == 2) {
			if (day_of_February + 1 == value1) {
				cout << "вы ввели неправильную дату" << endl;
				exit(0);
			}
		}
	}

	cout << "Tип кузова (седан, универсал и т.д.): ";
	cin.ignore();
	getline(cin, new_list.body);
	cout << "Дата последнего техосмотра ДДММГГГГ: ";
	getline(cin, new_list.technical_inspection);

	if (new_list.technical_inspection.size() != 8) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	for (int i = 0; i < new_list.technical_inspection.size(); i++) {
		if ((new_list.technical_inspection[i] > '9') || (new_list.technical_inspection[i] < '0')) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
			break;
		}
	}

	string one(new_list.technical_inspection, 0, 2);
	string two(new_list.technical_inspection, 2, 2);
	string three(new_list.technical_inspection, 4, 4);

	int v1 = stoi(one);
	int v2 = stoi(two);
	int v3 = stoi(three);

	// // // // 
	if (v3 >= 2024) {
		if (v2 >= 04) {
			if (v1 > 1) {
				cout << "вы ввели неправильную дату" << endl;
				exit(0);
			}
		}
	}

	if (v2 == 2 || v2 == 4 || v2 == 6 || v2 == 9 || v2 == 11) {
		if (v1 == 31) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
		}
	}

	if (v1 <= 0 || v1 > 31 || v2 <= 0 || v2 > 12 || v3 <= 0 || ((v1 == 30) && (v2 == 2)) || ((v1 == 31) && (v2 == 2))) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}


	if (v1 <= 0 || v1 > 31 || v2 <= 0 || v2 > 12 || v3 <= 0 || ((v1 == 30) && (v2 == 2)) || ((v1 == 31) && (v2 == 2)) || ((v1 == 29) && (v2==02 ) && (v3 == 2023))) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}

	int day_of_F;
	if ((v3 % 4 == 0) || (v3 % 400 == 0)) {

		day_of_F = 29;
		
	}
	else if (v3 % 100 == 0) {

		day_of_F = 28;
		if (v2 == 2) {
			if (day_of_F + 1 == v3) {
				cout << "вы ввели неправильную дату" << endl;
			}
		}
	}
	else {
		day_of_F = 28;
		if (v2 == 2) {
			if (day_of_F + 1 == v3) {
				cout << "вы ввели неправильную дату" << endl;
			}
		}
	}

	string va1;
	short vale1;
	vale1 = stoi(new_list.technical_inspection);


	cout << "Владелец: ";
	getline(cin, new_list.owner);
	list[current_size] = new_list;
	current_size++;

	cout <<  "Что дальше?" << endl;
}


static void detectError(int value) {
	if (value == 31) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}

}










void output() {
	int sw, n;
	cout << endl << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1) {
		cout << "номер выводимой строки " << endl;
		cin >> n;

		cout << "наименование товара:" << endl;

		cout << endl << "Марка авто:";
		cout << list[n - 1].brand;
		cout << endl << "Цвет:";
		cout << list[n - 1].color;
		cout << endl << "Заводской номер: ";
		cout << list[n - 1].factory_number;
		cout << endl << "Дата выпуска ДДММГГГГ:";
		cout << endl << "День:";
		cout << list[n - 1].release.day;
		cout << endl << "Месяц:";
		cout << list[n - 1].release.mounth;
		cout << endl << "Год:";
		cout << list[n - 1].release.year;
		cout << endl << "Tип кузова (седан, универсал и т.д.): " ;
		cout << list[n - 1].body;
		cout << endl << "Дата последнего техосмотра ДДММГГГГ: ";
		cout << list[n - 1].technical_inspection;
		cout << endl << "Владелец: ";
		cout << list[n - 1].owner<<endl;
	}
	if (sw == 2) {
		if (current_size == 1) {
			current_size -= 1;
		}
		for (int i = 0; i <= current_size; i++) {
			cout << endl;
			if (list[i].color.length() == 0) {


			}
			else {

				cout << "наименование товара "<< i + 1 <<":" << endl;

				cout << endl << "Марка авто:";
				//Toyota,2 - Honda,3 - Bmw, 4- Audi): " ;
	
				if (list[i].brand == 0) {
					cout << "Toyota";
				}
				else if (list[i].brand == 1) {
					cout << "Honda";
				}
				else if (list[i].brand == 2) {
					cout << "Bmw";
				}
				else {
					cout << "Audi";
				}
				cout << endl << "Цвет:";
				cout << list[i].color;
				cout << endl << "Заводской номер: ";
				cout << list[i].factory_number;
				cout << endl << "Дата выпуска:";
				cout << endl << "День:";
				cout << list[i].release.day;
				cout << endl << "Месяц:";
				cout << list[i].release.mounth;
				cout << endl << "Год:";
				cout << list[i].release.year;
				cout << endl << "Tип кузова (седан, универсал и т.д.): ";
				cout << list[i].body;
				cout << endl << "Дата последнего техосмотра ДДММГГГГ: ";
				cout << list[i].technical_inspection;
				cout << endl << "Владелец: ";
				cout << list[i ].owner << endl;
				
			}
		}

	}
	cout << "Что дальше?" << endl;
}
void del() {
	int d, dd;
	cout << endl << "номер строки(начиная с 1), которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d <= 0) {
		cout << "Ошибка" << endl;
		exit(0);
	}

	if (d != 99) {
		for (int j = (d - 1); j < current_size; j++) {
			if (j == (d - 1)) {
				list[j] = bad;
				list[j] = list[j + 1];
			}
			else {
				list[j] = list[j + 1];
			}
		}
		current_size = current_size - 1;
	}
	if (d == 99) {
		for (int i = 0; i < S; i++) {
			list[i] = bad;
		}
		dd = d;

	}
	cout << "что дальше?" << endl;
}
void search() {
	string value;
	cout << "введите заводской номер : ";
	cin.ignore();
	
	getline(cin, value);


	for (int k = 0; k <= current_size; k++) {
	if (value == list[k].factory_number) {
		cout << "Марка авто: ";
			if (list[k].brand == 0) {
				cout << "Toyota";
			}
			else if (list[k].brand == 1) {
				cout << "Honda";
			}
			else if (list[k].brand == 2) {
				cout << "Bmw";
			}
			else {
				cout << "Audi";
			}
		
			
		cout<<endl << "Цвет: " << list[k ].color << endl;
		cout << "Дата выпуска: ";
			

		cout << endl << "День:";
		cout << list[k].release.day;
		cout << endl << "Месяц:";
		cout << list[k].release.mounth;
		cout << endl << "Год:"<<endl;
		cout << list[k].release.year;
			
		cout << "Tип кузова (седан, универсал и т.д.): " << list[k].body<<endl;
		cout << "Дата последнего техосмотра ДДММГГГГ: " << list[k].technical_inspection << endl;
		cout << "Владелец: " << list[k].owner << endl;
	}
	/*if (value == list[k + 5].price) {
		cout << "наименование товара: " << list[k + 4].name << endl;
		cout << "количество: " << list[k + 6].amount << endl;
		cout << "процент торговой надбавки: " << list[k + 7].percent << endl;
	}
	if (value == list[k + 9].price) {
		cout << "наименование товара: " << list[k + 8].name << endl;
		cout << "количество: " << list[k + 10].amount << endl;
		cout << "процент торговой надбавки: " << list[k + 11].percent << endl;
	}*/
	
}
	cout << "что дальше?" << endl;
}