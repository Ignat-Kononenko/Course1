#include <iostream>
#include <fstream>
#include "myStack.h"
#include<string>

using namespace std;

int sum = 0;

void push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
	sum += 1;
}
double pop(Stack*& myStk)   //���������� (��������) �������� �� �����
{
	if (myStk == NULL || sum == 0)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� (-1) 
	}
	else
	{
		Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
		double x = myStk->data;    //������ �������� �� ���� data � �����. x 
		
		myStk = myStk->next;   //������� �������

		delete e;
		return x;
	}
}
void toFile(Stack*& myStk) //������ � ����
{
	
	Stack* e = myStk;

	ofstream frm("mStack.txt");
	if (!frm.is_open())
	{
		cout << "\n ������ �������� �����";
		exit(0);
	}



	while (e)
	{
		frm << e->data << endl;
		e = e->next;
	}
	frm.close();
	cout << "���� ������� � ���� mStack.txt\n";
}

void fromFile(Stack*& myStk)          //���������� �� �����
{
	Stack* p = nullptr;

	ifstream frm("mStack.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}

	int data;
	while (frm >> data)
	{
		Stack* newElem = new Stack;
		newElem->data = data;
		newElem->next = p;
		p = newElem;

		cout << data << "\t";
	}

	frm.close();

	myStk = p;

	cout << "\n���� ������ �� ����� mStack.txt\n\n";
}
void show(Stack*& myStk)  //����� ����� � ��������
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "���� ����!" << endl;
	for(int i = 0; i < sum; i ++)
		cout << pop(e) << " ";
	int del = sum;
	for (int j = 0; j < del; j++)
		sum -= 1;
	cout << endl;
}

double amount(Stack*& myStk) {
	Stack* e = myStk;
	int count = 0;

	if (e->data > 1400000000 || e->data <-1400000000) {
		cout << "���� ����!" << endl;
		return 0; // ���������� 0, ��� ��� ���� ����
	}

	int prev = e->data;
	e = e->next;

	while (e != NULL) {
		int current = e->data;
		Stack* temp = e;
		e = e->next;

		if (current == prev) {
			count++;
		}

		prev = current;
	}

	count += 1;
	return count;
}

