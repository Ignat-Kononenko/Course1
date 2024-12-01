#include<iostream>
#include<ctime>
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	const int N = 100;
	int sz, i, s, A[N];
	cout << "Введите число массива (N<100): ";
	cin >> sz;
	if (sz >= 0 && sz <= 99)
	{
		srand((unsigned)time(NULL));
		for (i = 0; i < sz; i++)
		{
			A[i] = rand() % 99;
			cout << A[i] << " ";
		}
		cout << "\nВведите число, которое хотели бы убрать ";
		cin >> s;
		for (int i = 0; i < sz; i++) {
			if (A[i] != s) {

				cout << A[i] << " ";
			}
			else {

				cout << '\b' << ' ';

			}

		}
		cout << "\nДобавим перед четным значением элемент со значением 1\n";
		{
			for (int i = 0; i < sz; i++)

			{
				if (A[i] != s) {
					if (A[i] % 2 == 0) {
						A[i - 1] = 1;
						cout << A[i - 1] << " " << A[i] << " ";
					}
					else {
						cout << A[i] << " ";
					}
				}
				else {

					cout << '\b' << ' ';

				}
				
				
			}

		}
	}
	else {
		cout << "no";
	}

	return 0;
}