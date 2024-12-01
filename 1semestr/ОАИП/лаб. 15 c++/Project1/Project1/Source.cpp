#include<iostream>

using namespace std;

float integ(float(*) (float), float, float, float);
float f(float); //прототипы

float integ(float(*f) (float), float a , float b, float n) {
	float x = a,s=0,h;
	h = (b - a) / n;

	while (x < (b - h))

	{
		s +=  h * (f(x)+f(x+h));
		x = x + h;
	}
	return s / 2;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, n,z;
	cout << "¬ведите (a): " << endl;
	cin >> a;
	cout << "¬ведите (b): " << endl;
	cin >> b;
	cout << "¬ведите (n): " << endl;
	cin >> n;
	z = integ(f, (float)a, (float)b, (float)n);
	cout << "integral = " << z;
}
float f(float x )
{
	return (1 + pow(x, 3) );
}
