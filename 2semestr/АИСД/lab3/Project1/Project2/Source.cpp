#include<iostream>
#include<ctime>
#include<chrono>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	srand(time(NULL));
	int N;

	cout << "Введите число N: ";
	cin >> N;

	int* massive = new int[N];
	int* massiveB = new int[N];
	int* massiveC = new int[N];
	int* massiveD = new int[N];
	int* massiveF = new int[N];


	for (int i = 0; i < N; i++) {
		massive[i] = rand() % 30;
	}

	for (int i = 0; i < N; i++) {
		cout << massive[i] << " ";
	}

	for (int i = 0; i < N; i++) {
		massiveB[i] = massive[i];
		massiveC[i] = massive[i];
		massiveD[i] = massive[i];
		massiveF[i] = massive[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (massiveB[j] > massiveB[j + 1]) {
				swap(massiveB[j], massiveB[j + 1]);
			}
		}
	}


	cout << endl << "kef" << endl;
	for (int i = 0; i < N; i++) {
		cout << massiveB[i] << " ";
	}



	//быстрая сортировка

//	int mid, count;
//	int f = first, l = last;
//	mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
//	do
//	{
//		while (mas[f] < mid) f++;
//		while (mas[l] > mid) l--;
//		if (f <= l) 				//перестановка элементов
//		{
//			count = mas[f];
//			mas[f] = mas[l];
//			mas[l] = count;
//			f++;
//			l--;
//		}
//	} while (f < l);
//	if (first < l) quicksort(mas, first, l);
//	if (f < last) quicksort(mas, f, last);
//}


	//cout << endl;
	////Сортировка выбором
	//int min, buf;
	//auto start = chrono::high_resolution_clock::now();
	//for (int i = 0; i < N; i++) {
	//	min = i;

	//	for (int j = i + 1; j < N; j++)
	//		min = (massiveD[j] < massiveD[min]) ? j : min;

	//	if (i != min) {
	//		buf = massiveD[i];
	//		massiveD[i] = massiveD[min];
	//		massiveD[min] = buf;
	//	}
	//}
	//auto end = chrono::high_resolution_clock::now();
	//chrono::duration<float> duration = end - start;

	//for (int i = 0; i < N; i++) {
	//	cout << massiveD[i] << " ";
	//}
	//double value, microseconds, seconds = 0, minutes = 0;
	//value = duration.count();
	//microseconds = value * pow(10, 6);

	//while (microseconds >= pow(10, 6)) {
	//	microseconds /= pow(10, 6);
	//	seconds += 1;
	//}


	//while (seconds >= 60) {
	//	seconds = seconds - 60.0;
	//	minutes += 1;
	//}

	//cout << endl << "Расчетное время циклом " << minutes << " минут " << seconds << " секунд " << microseconds << " микросекунд " << endl;

	//Сортировка вставками
	int buff, j;
	clock_t start = clock();
	for (int i = 1; i < N; i++) {
		buff = massiveF[i];
		for (j = i - 1; j >= 0 && massiveF[j] > buff; j--)
			massiveF[j + 1] = massiveF[j];

		massiveF[j + 1] = buff;
	}
	clock_t end = clock();
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

	cout << "kfefj " << elapsed_time << endl;

	for (int i = 0; i < N; i++) {
		cout << massiveF[i] << " ";
	}
	cout << endl;
	return 0;
}