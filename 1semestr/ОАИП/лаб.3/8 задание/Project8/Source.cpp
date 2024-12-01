#include<iostream>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	float a, b, c, s, p;
	printf("Введите первую сторону треугольника ");
	scanf("%f", &a);
	printf ( "Введите вторую сторону треугольника ");
	scanf("%f", &b);
	printf ( "Введите третью сторону треугольника ");
	scanf("%f", &c);
	if (a + b > c and a + c > b and c + b > a)
	{		p = (a + b + c) / 2;

	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("Площадь треугольника равна s=%f ", s);
}
	else
	{
		printf("Неправильно введены стороны треугольника");
	}
	return 0;
}