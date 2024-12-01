#include<iostream>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

void letter(char* array);

int main(char) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	int size = 0;
	char* array = new char[256];
	puts("введите строку с буквой 'a'\n");
	gets_s(array, 256);
	letter(array);
	delete[] array;

}
void letter(char* array) {
	int i;
	for (i = 0; array[i] != '\0'; i++) {
		if (array[i] == 'а') {
			cout << array[i] << '!';
		}
		else {
			cout << array[i];
		}
		
	}
	
}
