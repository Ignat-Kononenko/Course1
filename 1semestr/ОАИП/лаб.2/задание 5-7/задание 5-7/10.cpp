#include<iostream>
using namespace std;
int main()
{
	double y,s , z = 1.7, m = 3, a= 4e-8, n=3;
	y = (z+log(z))/(exp(-3)+sqrt(a));
	s = (1 + m * n) / log(1 + z);

	cout << "y=" << y << endl;
	cout << "s=" << s << endl;
	return 0;
}