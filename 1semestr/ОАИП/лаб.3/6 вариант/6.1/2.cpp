#include <iostream>
#include <windows.h>
#pragma warning(disable : 4996)

using namespace std;
int main()
{

	float x1, x2, y1, y2, d;

	printf("x1=");
	scanf("%f",&x1);
	
	
	printf("x2=");
	scanf("%f", &x2);
	

	printf("y1=");
	scanf("%f", &y1);


	printf("y2=");
	scanf("%f", &y2);


	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	printf("d=%f",d);

		return 0;
}