#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"
#include "Head.h"
#include "he.h"
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int k, y;
	char str[255];
	puts("выберите вариант(1,2,3)");
	cin >> k;
	switch (k) {
	case 1:puts("напишите символ латинского алфавита");
	{
		cin >>str;
		header(str);
		break;
	}

	case 2:puts("напишите символ русского алфавита");
	{
		cin >> str;
		head(str);
		break;
	}
	case 3:puts("напишите десятичную цифру");
	{
		cin >> str;
		he(str);
		break;
	}
	default:puts("некоретный вариант");
	}
	return 0;
}