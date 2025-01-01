#include<iostream>
#include<cmath>
#include<string>

using namespace std;

double f(double x) {
	
	return x * 3 - x - 2;
}

double bisection(double a, double b, double e) {
	if (fabs(b - a) <= 2*e) {
		return (a + b) / 2;
	}
	else {
		double c = (a + b) / 2;
		if (f(a) * f(c) <= 0) {
			return bisection(a, c, e);
		}
		else {
			return bisection(c, b, e);
		}
	}
}

int main() {

	string first, second;
	double a, b, e = 0.01;
	setlocale(LC_ALL, "rus");
	cout << "Введите вещественные a и b." << endl;
	getline(cin, first);

	for (char c : first) {
		if (c == '-') {
			if (first.length() == 1) {
				cout << "ошибка ввода" << endl;
				exit(0);
			}

		}
		else if (c == '.') {
			if (first.length() == 1) {
				cout << "ошибка ввода" << endl;
				exit(0);
			}
		}
		else if (c > '9' || c < '0') {
			cout << "ошибка ввода" << endl;
			exit(0);
		}
	}

	getline(cin, second);
	for (char c : second) {
		if (c == '-') {
			if (second.length() == 1) {
				cout << "ошибка ввода" << endl;
				exit(0);
			}

		}
		else if (c == '.') {
			if (second.length() == 1) {
				cout << "ошибка ввода" << endl;
				exit(0);
			}
		}
		else if (c > '9' || c < '0') {
			cout << "ошибка ввода" << endl;
			exit(0);
		}
	}

	a = stod(first);
	b = stod(second);

	if (f(a) * f(b) < 0) {
		cout << "Метод бисекции не может быть применен, потому что умножение этих чисел >= 0 ";
		return 0;
	}

	cout << "Результат функции: " << bisection(a, b, e) << endl;




	return 0;
}