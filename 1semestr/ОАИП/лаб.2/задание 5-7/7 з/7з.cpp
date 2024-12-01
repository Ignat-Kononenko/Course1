#include<iostream>
using namespace std;
int main()
{
	double w, y, m = 6, x = 1.4, z = 0.05e-5;
	w = 0.6 * z - 2 * exp(-2*y * m);
	y = sqrt(1 + x) - cos(2 / m);

	cout << "w=" << w << endl;
	cout << "y=" << y << endl;
	return 0;
}