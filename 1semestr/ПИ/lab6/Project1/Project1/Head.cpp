#include<iostream>
#include "Head.h"
using namespace std;
void head(char u[]) {
	int y, i;
	char U[32];
	for (i = 0; i < strlen(u); i++) {
		if (u[i] >= '�' && u[i] <= '�') {
			U[i] = u[i] - 32;
			y = (int)(abs(U[i] - u[i]));
			cout << "������� �������� ����� ����� " << y<<endl;
		}
		else
			if (u[i] >= '�' && u[i] <= '�')	{
				U[i] = u[i] + 32;
				y = (int)(abs(U[i] - u[i]));
				cout << "������� �������� ����� ����� " << y<<endl;
			}
			else {
				cout << "������ ������ �� �������� ��������" << endl;
			}
	}
}
