#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	float a, b, c, d,x1,x2;
	printf("������� �,�,�\n");
	printf("�= ");
	scanf_s("%f", &a);
	printf("b= ");
	scanf_s("%f", &b);
	printf("c= ");
	scanf_s("%f", &c);
	d = pow(b, 2) - 4*a*c;
	if (d < 0)
	{
		printf("��� ������\n");
	}
	else
	{
		printf("x1= ");
		printf("x2= ");
		x1 = (-b + sqrt(b)) / 2 * a;
		x2 = (-b - sqrt(b)) / 2 * a;
	}
	return 0;
}