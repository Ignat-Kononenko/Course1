#include <iostream>

using namespace std;

int main()

{

	double a = 0, b = 0.5, e = 0.0001, x;

	while (abs(a - b) > (2 * e))

	{

		x = (a + b) / 2;

		if ((pow(a, 3) + 2 * a - 1) * (pow(x, 3) + 2 * x - 1) <= 0)

			b = x;

		else

			a = x;

	}

	cout << x << endl;

}