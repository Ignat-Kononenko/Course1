#include<iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите число призеров (от 1 до 10000): ";
	cin >> n;

	if (n <= 0 || n > 10000) {
		cout << "Проверьте значение" << endl;
		exit(0);
	}

	cout << "Введите результаты участников: " << endl;

	int* massive = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Результат " << i + 1 << "-го участника (от 1 до 100): ";
		massive[i] = 1 + rand() % 99;
		cout << massive[i] << endl;

	}

	int sum = 0;
	//Сортировка выбором
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (massive[j] < massive[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(massive[i], massive[minIndex]);
		}
	}

	int number = 0, m = 0;

	for (int i = 0; i < 3; i++) {

		int	max = massive[n - 1 - sum];

		for (int j = 0; j < n; j++) {
			if (max == massive[j]) {
				sum++;
				if (i == 1) {
					m++;
				}
			}
		}

	}

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << massive[i] << "\t";
	}

	cout << endl << "Число призеров: " << sum << endl;
	cout << "Максимальные баллы: " << massive[n - 1] << "\t";
	cout << massive[n - 1 - m] << "\t";
	cout << massive[n - sum] << endl;

	delete[] massive;

	return 0;
}