#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 1, x[]{ 2.7, -5, 4,3.5,-7 }, n = 5;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > 0)
		{
			a =a+x[i];
		}
		else
		{
			b = b * x[i];
		}
	}
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;

	

	return 0;
}
