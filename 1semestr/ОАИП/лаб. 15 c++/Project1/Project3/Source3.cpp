#include<iostream>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string>


using namespace std;

char *letter(char *p);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	int size = 0;
	char* array = new char[256];
	puts("введите строку с буквой 'a'\n");
	cin.getline(array, 256);
	char* result= letter(array);
	cout << "result: " << result << endl;
	delete[] array;

}
char* letter(char *p) {
	
	char* array = p;
	int length = strlen(array);
	for (int i = 0; i < length; i++) {
		if (array[i] == 'а') {
			for (int j = length; j > i; j--) {
				array[j + 1] = array[j];
			}
			array[i + 1] = '!'; 
			length++; 
			i++; 
		}
	}
		
	return array;
}
