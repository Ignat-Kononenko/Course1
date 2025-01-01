#include "Hash_Chain.h"
#include <iostream>
#include<string>

using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = nullptr;
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "Введите номер маршрута: ";
			string input;
			int k;

			// Проверяем корректность ввода ключа
			while (true) {
				cin >> input;

				// Если следующий символ - символ новой строки, значит, в строке больше нет символов
				// и в ней нет пробелов, иначе запросить ввод еще раз
				if (cin.peek() == '\n') {
					// Проверяем, что введенные данные состоят только из цифр
					bool validInput = true;
					for (char c : input) {
						if (!isdigit(c)) {
							validInput = false;
							break;
						}
					}

					// Если введенные данные состоят только из цифр
					if (validInput) {
						// Пробуем преобразовать строку в целое число
						try {
							k = stoi(input);
							// Проверяем, что введенное значение неотрицательное
							if (k >= 0) {
								break; // Все в порядке, завершаем цикл
							}
							else {
								cout << "Ошибка! ";
							}
						}
						catch (...) {
							cout << "Ошибка! ";
						}
					}
					else {
						cout << "Ошибка! ";
					}
				}
				else {
					cout << "Ошибка! ";
				}

				// Очищаем буфер ввода, чтобы избежать ошибок
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			a->key = k;
			cout << "введите маршрут" << endl;
			cin.ignore();
			if (cin.peek() == '\n') {
				cin.ignore(); // Игнорируем символ новой строки, если он есть
			}
			cin.getline(str, 256);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {
			AAA* b = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Первый элемент с данным ключом" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
