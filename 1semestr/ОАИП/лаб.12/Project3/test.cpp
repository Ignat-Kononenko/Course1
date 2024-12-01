#include<iostream>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	char str[50], *ps;
	int i;
	puts("Введите строку с символом *\n");
	gets_s(str, 50);
	for (ps = str; *ps != '\0'; ps++) {
		if (*ps != '*') {
			cout << *ps;
			cout << *ps;
		}
	}

	return 0;
}