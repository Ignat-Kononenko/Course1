#include<iostream>
using namespace std;
int main()
{
	double a = 1, b = 5, n=200,h,s=0,x;
	h = (b - a) / n;
	x = a;
	while (x < (b - h))
	
	{
		s = s + h * (1 + pow(x, 3) + 1 + pow((x + h), 3)) / 2;
		x = x + h;
	}
	cout << "s=" << s;
	return 0;
}