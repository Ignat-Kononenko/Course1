#include<iostream>
using namespace std;
int main()
{
	double b = -5.4, m = 4, u = 0.005e-4, v, w, k[]{ 6, 4,0.3,-7};
	for (int i = 0; i < 4; i++)
	{
		v = u + b - 2 * sqrt(0.7 * k[i] + m);
		w = 100 * exp(-0.2 * k[i]) - log(8.1 * u);
		cout << "v=" << v << endl;
		cout << "w=" << w << endl;
	}
	return 0;
} 