#pragma once

struct Stack
{
	int data;     //информационный элемент
	Stack* next;	 //указатель на следующий элемент
};
void show(Stack*& myStk);
double pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
double amount(Stack*& myStk);

