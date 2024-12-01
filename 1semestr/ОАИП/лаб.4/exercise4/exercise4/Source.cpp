#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	float a, b, c, d,x1,x2;
	printf("введите а,в,с\n");
	printf("а= ");
	scanf_s("%f", &a);
	printf("b= ");
	scanf_s("%f", &b);
	printf("c= ");
	scanf_s("%f", &c);
	d = pow(b, 2) - 4*a*c;
	if (d < 0)
	{
		printf("нет корней\n");
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