#include<iostream>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
 
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	char str[50];
	int i;
	puts( "Введите строку с символом *\n");
	gets_s(str, 50);
	for (i = 0; str[i] !='\0'; i++) {
		if(str[i] != '*'){
			cout << str[i];
			cout << str[i];
		}
	}

	return 0;
 }