#include <iostream>
#include <fstream>
#include "myStack.h"
#include<string>

using namespace std;

int sum = 0;

void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
	sum += 1;
}
double pop(Stack*& myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk == NULL || sum == 0)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack* e = myStk;        //е-переменная для хранения адреса элемента
		double x = myStk->data;    //запись элемента из поля data в перем. x 
		
		myStk = myStk->next;   //перенос вершины

		delete e;
		return x;
	}
}
void toFile(Stack*& myStk) //Запись в файл
{
	
	Stack* e = myStk;

	ofstream frm("mStack.txt");
	if (!frm.is_open())
	{
		cout << "\n Ошибка открытия файла";
		exit(0);
	}



	while (e)
	{
		frm << e->data << endl;
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.txt\n";
}

void fromFile(Stack*& myStk)          //Считывание из файла
{
	Stack* p = nullptr;

	ifstream frm("mStack.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
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

	cout << "\nСтек считан из файла mStack.txt\n\n";
}
void show(Stack*& myStk)  //Вывод стека с очисткой
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
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
		cout << "Стек пуст!" << endl;
		return 0; // Возвращаем 0, так как стек пуст
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

