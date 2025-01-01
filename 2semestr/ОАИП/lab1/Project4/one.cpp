#include<iostream>

using namespace std;

float metod(double(*f) (float), float a, float b, float e, float x);
double f1(float x);
double f2(float x);


int main() {

	setlocale(LC_ALL, "rus");

	float a, b, e = 0.001, x = 0, z, t;

	cout << "¬ведите левую границу интервала(а): ";
	cin >> a;

	cout << "¬ведите правую границу интервала (b): ";
	cin >> b;

	z = metod(*f1, a, b, e, x);

	cout << "¬ведите левую границу интервала (а): ";
	cin >> a;

	cout << "¬ведите правую границу интервала (b): ";
	cin >> b;

	t = metod(*f2, a, b, e, x);

	cout << "ответ первого уравнени€:  " << z << endl;
	cout << "ответ второго уравнени€:  " << t << endl;

	return 0;
}


float metod(double(*f)(float), float a, float b, float e, float x)
{
	while (abs(a - b) > (2 * e)) {
		x = (a + b) / 2;
		if (f(a) * f(x) <= 0) {
			b = x;
		}
		else {
			a = x;
		}

	}
	return f(x);
}

double f1(float x) {
	return(x * x + 4 * x - 2);

}

double f2(float x) {
	return(sin(x) + 0.1);

}
