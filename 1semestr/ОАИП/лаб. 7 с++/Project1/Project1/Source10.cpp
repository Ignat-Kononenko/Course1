#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double q = 0, n = 6, x[]{ 3,-2,0.7,-1,-2.7 }, y[]{1.5,-1.2,6,9,-4};
	for (int i = 0; i < n; i++)
	{
		q = q + x[i] * y[i];
	}
	cout << "q=" << q;
	return 0;
}