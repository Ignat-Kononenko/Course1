#pragma once

struct Stack
{
	int data;     //�������������� �������
	Stack* next;	 //��������� �� ��������� �������
};
void show(Stack*& myStk);
double pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
double amount(Stack*& myStk);

