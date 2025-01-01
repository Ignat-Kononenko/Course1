#include <iostream>
#include <cstdarg>
using namespace std;
int sum(int n, ...) {
	va_list fact;
	va_start(fact, n);
	int r = 0, t, k = va_arg(fact, int);
	for (int i = 1; i < n; i++) {
		t = va_arg(fact, int);
		r += (i % 2 * 2 - 1) * k * t;
		k = t;

	}
	va_end(fact);
	return r;
}
int main() {
	cout << sum(4, 1, 2, 3, 4) << endl;
	cout << sum(5, 2, 3, 4, 6, 4) << endl;
	cout << sum(12, 5, 12, 21, 13, 9, 5, 6, 7, 8, 10, 10, 10) << endl;
}