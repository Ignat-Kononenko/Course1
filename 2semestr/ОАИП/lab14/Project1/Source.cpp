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
	cout << "������� ������ ���-�������" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "������� ����� ��������: ";
			string input;
			int k;

			// ��������� ������������ ����� �����
			while (true) {
				cin >> input;

				// ���� ��������� ������ - ������ ����� ������, ������, � ������ ������ ��� ��������
				// � � ��� ��� ��������, ����� ��������� ���� ��� ���
				if (cin.peek() == '\n') {
					// ���������, ��� ��������� ������ ������� ������ �� ����
					bool validInput = true;
					for (char c : input) {
						if (!isdigit(c)) {
							validInput = false;
							break;
						}
					}

					// ���� ��������� ������ ������� ������ �� ����
					if (validInput) {
						// ������� ������������� ������ � ����� �����
						try {
							k = stoi(input);
							// ���������, ��� ��������� �������� ���������������
							if (k >= 0) {
								break; // ��� � �������, ��������� ����
							}
							else {
								cout << "������! ";
							}
						}
						catch (...) {
							cout << "������! ";
						}
					}
					else {
						cout << "������! ";
					}
				}
				else {
					cout << "������! ";
				}

				// ������� ����� �����, ����� �������� ������
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			a->key = k;
			cout << "������� �������" << endl;
			cin.ignore();
			if (cin.peek() == '\n') {
				cin.ignore(); // ���������� ������ ����� ������, ���� �� ����
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
			cout << "������� ����" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "������� ����" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "������� �� ������" << endl;
			else
			{
				cout << "������ ������� � ������ ������" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
