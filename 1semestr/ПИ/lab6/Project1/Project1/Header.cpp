#include"Header.h"
#include<iostream>
using namespace std;
void header(char n[]) {
	int x, y, i;
	char N[32];
	for (i = 0; i < strlen(n); i++) {
		if (n[i] >= 'a' && n[i] <= 'z') {
			N[i] = n[i] - 32;
			x = (int)(abs(N[i] - n[i]));
			cout << "������� �������� ����� ����� " << x << endl;
		}
		else
			if (n[i] >= 'A' && n[i] <= 'Z') {
				N[i] = n[i] + 32;
				x = (int)(abs(N[i] - n[i]));
				cout << "������� �������� ����� ����� " << x << endl;
			}
			else {
				cout << "������ ������ �� ���������� ��������" << endl;
			}
	}
}
