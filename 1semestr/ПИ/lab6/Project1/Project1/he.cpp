#include<iostream>
#include"he.h"
using namespace std;
void he(char s[]) {
	int y, i, g;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			g = (int)s[i];
			cout << "��� ������� ����� " << g << endl;
		}
		else {
			cout << "������� �� ���������� �����" << endl;
		}
	}
}
