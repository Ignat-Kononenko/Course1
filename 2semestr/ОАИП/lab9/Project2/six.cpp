#include <iostream>
#include <fstream>
#include<string>
#include<Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};


Address* minAddress;
string result;
int num;
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. ������ � ����" << endl;
	cout << "6. ���������� �� �����" << endl;

	cout << "7. ������� ������ ������������ �������� ������ �� ������ �� ��������� �����" << endl;

	cout << "8. �����" << endl;
	cout << endl;
	do
	{
		cout << "��� �����: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //���������� � ����� ������
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
Address* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}

	string n;
	cout << "������� ���: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');

	for (int i = 0; i < strlen(temp->name); i++) {
		if (temp->name[i] == '-') {
			if (strlen(temp->name) == 1) {
				cout << "�� ����� �����������" << endl;
				delete temp;
				return NULL;
			}
		}
		else if (((temp->name[i] > 'z') || (temp->name[i] < 'a')) && ((temp->name[i] > 'Z') || (temp->name[i] < 'A'))) {
			cout << "�� ����� �����������" << endl;
			delete temp;
			return NULL;
		}
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');

	for (int i = 0; i < strlen(temp->city); i++) {
		if (temp->city[i] == '-') {
			if (strlen(temp->city) == 1) {
				cout << "�� ����� �����������" << endl;
				delete temp;
				return NULL;
			}
		}
		else if (((temp->city[i] > 'z') || (temp->city[i] < 'a')) && ((temp->city[i] > 'Z') || (temp->city[i] < 'A'))) {
			cout << "�� ����� �����������" << endl;
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
void outputList(Address** phead, Address** plast)      //����� ������ �� �����
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
void find(char name[NAME_SIZE], Address** phead)    // ����� ����� � ������
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // �������� �����
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
	{
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
		delete t;
		cout << "������� ������" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //������ � ����
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Address* temp = *phead;
	Address buf;
	ofstream frm("mList.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		frm << temp->name << endl; // ���������� ������ � ���� ���������

		frm << temp->city << endl; // ���������� ������ � ���� ���������
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.txt\n";

}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //���������� �� �����
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string names, citys;

	ifstream frm("mList.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
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
		strcpy(newAddress->city, citys.c_str());
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

	cout << "\n������ ������ �� ����� mList.txt\n";
}

Address* findMin(Address* head) {
	string number;
	if (head == NULL) {
		return NULL;
	}
	Address* t = head, * mn = nullptr;
	int min;
	cout << "�������� ����. ��� ����� �������� ����� 1(���) ��� 2(�����): ";
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
	num = stoi(number);

	min = strlen(t->name);
	while (t != NULL) {
		if (num == 1) {
			if (strlen(t->name) <= min)
			{
				min = strlen(t->name);
				mn = t;
			}
			t = t->next;
		}
		else if (num == 2) {

			if (strlen(t->city) <= min)
			{
				min = strlen(t->city);
				mn = t;
			}
			t = t->next;
		}
	}
	return mn;
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
			cout << "������� ���: ";
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
			cout << "������� ���: ";
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
			minAddress = findMin(head);
			if (minAddress != NULL) {

				
				cout << "����������� �������: " << minAddress->name << endl;
				cout<<"����������� �������: " << minAddress->city << endl;

			}
			else {
				cout << "������ ����." << endl;
			}

			break;
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
