#include<iostream>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	float a, b, c, s, p;
	printf("������� ������ ������� ������������ ");
	scanf("%f", &a);
	printf ( "������� ������ ������� ������������ ");
	scanf("%f", &b);
	printf ( "������� ������ ������� ������������ ");
	scanf("%f", &c);
	if (a + b > c and a + c > b and c + b > a)
	{		p = (a + b + c) / 2;

	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("������� ������������ ����� s=%f ", s);
}
	else
	{
		printf("����������� ������� ������� ������������");
	}
	return 0;
}