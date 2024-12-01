#include<iostream>
using namespace std;
int main()
 {
	double a = -4.2, i = 4, d, f, t[]{5,1,-3,9,-1};
	for (int b = 0; b < 5; b++)
	{
		d = i + 2 * t[b] * (1 + sqrt(3 * a * a));
		cout << "d=" << d << endl;
		if (d >= t[b] *(t[b] + i))
			f=t[b]* i;
		else
			f=exp(t[b] - d) + 9;
		cout << "f=" << f << endl;
	}
	return 0; 
 }