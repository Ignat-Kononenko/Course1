#include<iostream>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char str1[50], str2[50];
	int i, n, m, j;
	puts ( "¬ведите строку 1" );
	gets_s(str1, 50);
	puts ( "¬ведите строку 2");
	gets_s(str2, 50);
	cout << "¬ведите длину подстроки " << endl;
	cin >> n;
	cout << "\n¬ведите позицию " << endl;
	cin >> m;
	for (j = 0;str2[j] !='\0'; j++) {
		if (j == (m)) {
			for (i = 0; i < n; i++) {
				cout << str1[i];
			}
			cout << str2[j];
		}
		else {
			cout << str2[j];
		}
	}

	return 0;
}