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
	puts("�������� �������(1,2,3)");
	cin >> k;
	switch (k) {
	case 1:puts("�������� ������ ���������� ��������");
	{
		cin >>str;
		header(str);
		break;
	}

	case 2:puts("�������� ������ �������� ��������");
	{
		cin >> str;
		head(str);
		break;
	}
	case 3:puts("�������� ���������� �����");
	{
		cin >> str;
		he(str);
		break;
	}
	default:puts("���������� �������");
	}
	return 0;
}