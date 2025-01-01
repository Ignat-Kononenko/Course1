#include<iostream>
#include "Head.h"
using namespace std;
void head(char u[]) {
	int y, i;
	char U[32];
	for (i = 0; i < strlen(u); i++) {
		if (u[i] >= 'а' && u[i] <= 'я') {
			U[i] = u[i] - 32;
			y = (int)(abs(U[i] - u[i]));
			cout << "разница значений кодов равна " << y<<endl;
		}
		else
			if (u[i] >= 'А' && u[i] <= 'Я')	{
				U[i] = u[i] + 32;
				y = (int)(abs(U[i] - u[i]));
				cout << "разница значений кодов равна " << y<<endl;
			}
			else {
				cout << "введен символ не русского алфавита" << endl;
			}
	}
}
