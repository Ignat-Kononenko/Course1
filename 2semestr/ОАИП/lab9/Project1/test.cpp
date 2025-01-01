#include <iostream>
#include <fstream>
#include<string>

#include<Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 100;
const unsigned int CITY_SIZE = 100;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

//vector<Address*> minAddresses;
//
//Address* minAddress;
struct Node {
	Address* address;
	Node* next;
};
Node* minAddresses;
string result;
int num;
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Считывание из файла" << endl;

	cout << "7. функция поиска минимального элемента списка по одному из выбранных полей" << endl;
	
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

	string n;
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');

	for (int i = 0; i < strlen(temp->name); i++) {
		if (temp->name[i] == '-') {
			if (strlen(temp->name) == 1) {
				cout << "вы ввели неправильно" << endl;
				delete temp;
				return NULL;
			}
		}
		else if (((temp->name[i] > 'z') || (temp->name[i] < 'a')) && ((temp->name[i] > 'Z') || (temp->name[i] < 'A'))) {
			cout << "вы ввели неправильно" << endl;
			delete temp;
			return NULL;
		}
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');

	for (int i = 0; i < strlen(temp->city); i++) {
		if (temp->city[i] == '-') {
			if (strlen(temp->city) == 1) {
				cout << "вы ввели неправильно" << endl;
				delete temp;
				return NULL;
			}
		}
		else if (((temp->city[i] > 'z') || (temp->city[i] < 'a')) && ((temp->city[i] > 'Z') || (temp->city[i] < 'A'))) {
			cout << "вы ввели неправильно" << endl;
			delete temp;
			return NULL;
		}
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
//void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
//{
//	Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name)) break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "Имя не найдено" << endl;
//	else
//		cout << t->name << ' ' << t->city << endl;
//}
 


void find(char name[NAME_SIZE], Address** phead)    // Поиск всех элементов с заданным именем в списке
{
	Address* t = *phead;
	bool found = false;
	while (t)
	{
		if (!strcmp(name, t->name)) {
			cout << t->name << ' ' << t->city << endl;
			found = true;
		}
		t = t->next;
	}
	if (!found)
		cerr << "Имя не найдено" << endl;
}


//-----------------------------------------------------------
//void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
//{
//	struct Address* t = *phead;
//	while (t)
//	{
//		if (!strcmp(name, t->name))  break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "Имя не найдено" << endl;
//	else
//	{
//		if (*phead == t)
//		{
//			*phead = t->next;
//			if (*phead)
//				(*phead)->prev = NULL;
//			else
//				*plast = NULL;
//		}
//		else
//		{
//			t->prev->next = t->next;
//			if (t != *plast)
//				t->next->prev = t->prev;
//			else
//				*plast = t->prev;
//		}
//		delete t;
//		cout << "Элемент удален" << endl;
//	}
//}





void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление всех элементов с заданным именем
{
	struct Address* t = *phead;
	bool found = false;
	while (t)
	{
		if (!strcmp(name, t->name)) {
			found = true;
			Address* toDelete = t;
			if (*phead == t)
			{
				*phead = t->next;
				if (*phead)
					(*phead)->prev = NULL;
				else
					*plast = NULL;
			}
			else
			{
				t->prev->next = t->next;
				if (t != *plast)
					t->next->prev = t->prev;
				else
					*plast = t->prev;
			}
			t = t->next;
			delete toDelete;
			cout << "Элемент удален" << endl;
		}
		else {
			t = t->next;
		}
	}
	if (!found)
		cerr << "Имя не найдено" << endl;
}

//-----------------------------------------------------------
void writeToFile(Address** phead)       //Запись в файл
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Address* temp = *phead;
	Address buf;
	ofstream frm("mList.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		frm << temp->name << endl; // Записываем данные в файл построчно

		frm << temp->city << endl; // Записываем данные в файл построчно
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.txt\n";

}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //Считывание из файла
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string names, citys;

	ifstream frm("mList.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;

	while (getline(frm, names) && getline(frm, citys))
	{
		Address* newAddress = new Address();
#pragma warning(suppress : 4996)
		strcpy(newAddress->name, names.c_str());
#pragma warning(suppress : 4996)
		strcpy(newAddress->city , citys.c_str());
		newAddress->next = NULL;
		newAddress->prev = *plast;

		if (*phead == NULL) {
			*phead = newAddress;
		}
		else {
			(*plast)->next = newAddress;
		}
		*plast = newAddress;
		cout << names << endl;
		cout << citys << endl;

	}

	frm.close();

	cout << "\nСписок считан из файла mList.txt\n";
}

//Address *findMin(Address* head) {
//	string number;
//	if (head == NULL) {
//		return NULL;
//	}
//	Address* t = head, * mn = nullptr;
//	int min;
//	cout << "Выберите поле. Для этого запишите цифру 1(ммя) или 2(город): ";
//	getline(cin,number);
//
//	for (char c : number) {
//		if (c > '2' || c < '1') {
//			cout << "error" << endl;
//			exit(0);
//		}
//	}
//	if (number.length() > 1 || number.length() == 0) {
//		cout << "error" << endl;
//		exit(0);
//	}
//	 num = stoi(number);
//
//	 min = strlen(t->name);
//			while (t != NULL) {
//				if (num ==1 ) {
//					if (strlen(t->name) <= min)
//					{
//						min = strlen(t->name);
//						mn = t;
//					}
//					t = t->next;
//				}
//				else if(num == 2 ){
//
//					if (strlen(t->city) <= min)
//					{
//						min = strlen(t->city);
//						mn = t;
//					}
//					t = t->next;	
//			}
//		}
//			return mn;
//}

//vector<Address*> findMin(Address* head) {
//	string number;
//	if (head == NULL) {
//		return vector<Address*>();
//	}
//	Address* t = head;
//	int min;
//	cout << "Выберите поле. Для этого запишите цифру 1(имя) или 2(город): ";
//	getline(cin, number);
//
//	for (char c : number) {
//		if (c > '2' || c < '1') {
//			cout << "error" << endl;
//			exit(0);
//		}
//	}
//	if (number.length() > 1 || number.length() == 0) {
//		cout << "error" << endl;
//		exit(0);
//	}
//	num = stoi(number);
//
//	min = strlen(t->name);
//	vector<Address*> minAddresses;
//	while (t != NULL) {
//		if (num == 1) {
//			if (strlen(t->name) < min) {
//				min = strlen(t->name);
//				minAddresses.clear();
//				minAddresses.push_back(t);
//			}
//			else if (strlen(t->name) == min) {
//				minAddresses.push_back(t);
//			}
//		}
//		else if (num == 2) {
//			if (strlen(t->city) < min) {
//				min = strlen(t->city);
//				minAddresses.clear();
//				minAddresses.push_back(t);
//			}
//			else if (strlen(t->city) == min) {
//				minAddresses.push_back(t);
//			}
//		}
//		t = t->next;
//	}
//	return minAddresses;
//}



Node* findMin(Address* head) {
	string number;
	if (head == NULL) {
		return NULL;
	}
	Address* t = head;
	int min;
	cout << "Выберите поле. Для этого запишите цифру 1(имя) или 2(город): ";
	getline(cin, number);

	for (char c : number) {
		if (c > '2' || c < '1') {
			cout << "error" << endl;
			exit(0);
		}
	}
	if (number.length() > 1 || number.length() == 0) {
		cout << "error" << endl;
		exit(0);
	}
	int num = stoi(number);

	min = strlen(t->name);
	Node* minAddresses = NULL;
	while (t != NULL) {
		if (num == 1) {
			if (strlen(t->name) < min) {
				min = strlen(t->name);
				while (minAddresses != NULL) {
					Node* temp = minAddresses;
					minAddresses = minAddresses->next;
					delete temp;
				}
				minAddresses = new Node{ t, NULL };
			}
			else if (strlen(t->name) == min) {
				Node* newNode = new Node{ t, minAddresses };
				minAddresses = newNode;
			}
		}
		else if (num == 2) {
			if (strlen(t->city) < min) {
				min = strlen(t->city);
				while (minAddresses != NULL) {
					Node* temp = minAddresses;
					minAddresses = minAddresses->next;
					delete temp;
				}
				minAddresses = new Node{ t, NULL };
			}
			else if (strlen(t->city) == min) {
				Node* newNode = new Node{ t, minAddresses };
				minAddresses = newNode;
			}
		}
		t = t->next;
	}
	return minAddresses;
}



int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;

		case 5: writeToFile(&head);
			break;
		case 6:  
			readFromFile(&head, &last);
			break;

		case 7:
		/*	 minAddresses = findMin(head);
			if (!minAddresses.empty()) {
				cout << "Минимальные элементы: " << endl;
				for (Address* address : minAddresses) {
					cout << address->name << "," << address->city << endl;
				}
			}
			else {
				cout << "Список пуст." << endl;
			}*/

			 minAddresses = findMin(head);
			if (minAddresses != NULL) {
				cout << "Минимальные элементы: " << endl;
				Node* currentNode = minAddresses;
				while (currentNode != NULL) {
					Address* address = currentNode->address;
					cout << address->name << "," << address->city << endl;
					currentNode = currentNode->next;
				}
			}
			else {
				cout << "Список пуст." << endl;
			}

			break;
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
