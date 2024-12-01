#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double h = 0, n = 5,c=0, d = 12.5e-4, a[]{0.8, 4,-7,2,0.91};
	for (int i = 0; i < n; i++)
	{
		c=c + a[i] * a[i];
	}
	h = d + c;
	cout << "h=" << h;
	return 0;
}
