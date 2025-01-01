#include<iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите число товаров (от 1 до 1000): " ;
	cin >> n;

	if (n <= 0 || n > 1000) {
		cout << "Проверьте значение" << endl;
		exit(0);
	}

	cout << "Введите цены товаров: " << endl;

	int* massive = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Цена " << i + 1 << " товара (от 1 до 100): ";
		massive[i] = 1 + rand() % 99;
			cout<< massive[i] <<endl;
	}

	int sum = 0;

	//Сортировка выбором

	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		int maxIndex = i;
		if (i % 2 != 0) {
			for (int j = i + 1; j < n; j++) {
				if (massive[j] < massive[minIndex]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				swap(massive[i], massive[minIndex]);
			}
		}
		else {
			for (int j = i + 1; j < n; j++) {
				if (massive[j] > massive[maxIndex]) {
					maxIndex = j;
				}
			}
			if (maxIndex != i) {
				swap(massive[i], massive[maxIndex]);
			}
			sum += massive[i];
			
		}
		
	}

	if (n % 2 != 0) {
		sum += massive[n - 1];
	}

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++) {
		cout << massive[i] << "\t";
	}

	delete[] massive;

	cout << endl << "Ваш итог за покупки: " << sum;


	return 0;
}