#include<iostream>
#include<ctime>
#include<chrono>
#include"star.cpp"

void quicksort(int massiveC[], int f, int l);

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	srand(time(NULL));
	int N;

	cout << "Введите число N: ";
	cin >> N;

	if (N <= 0) {
		cout << "Ошибка ввода";
		exit(0);
	}

	int* massive = new int[N];
	int* massiveB = new int[N];
	int* massiveC = new int[N];
	int* massiveD = new int[N];
	int* massiveF = new int[N];

	cout << "Ваш массив: " << endl;
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
	

	//пузырьковая сортировка
	cout << endl;
	writeStar();
	cout << "пузырьковая сортировка: " << endl;


	auto start_time = chrono::high_resolution_clock::now();
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (massiveB[j] > massiveB[j + 1]) {
				swap(massiveB[j], massiveB[j + 1]);
			}
		}
	}
	auto end_time = chrono::high_resolution_clock::now();
	chrono::duration<float> times = end_time - start_time;


	for (int i = 0; i < N; i++) {
		cout << massiveB[i] << " ";
	}

	double val, microsec, sec = 0, min = 0;
	val = times.count();
	microsec = val * pow(10, 6);

	while (microsec >= pow(10, 6)) {
		microsec /= pow(10, 6);
		sec += 1;
	}


	while (sec >= 60) {
		sec = sec - 60.0;
		min += 1;
	}

	cout << endl << "Расчетное время циклом " << min << " минут " << sec << " секунд " << microsec << " микросекунд " << endl;



	//быстрая сортировка
	writeStar();
	
	cout << "быстрая сортировка: " << endl;
	auto start_te = chrono::high_resolution_clock::now();
	quicksort(massiveC, 0, N - 1);
	auto end_ti = chrono::high_resolution_clock::now();
	chrono::duration<float> t = end_ti - start_te;

	double v, micro, se = 0, mi = 0;
	v = t.count();
	micro = v * pow(10, 6);

	while (micro >= pow(10, 6)) {
		micro /= pow(10, 6);
		se += 1;
	}


	while (se >= 60) {
		se = se - 60.0;
		mi += 1;
	}

	


	for (int i = 0; i < N; i++) {
		std::cout << massiveC[i] << " ";
	}

	cout << endl << "Расчетное время циклом " << mi << " минут " << se << " секунд " << micro << " микросекунд " << endl;

cout << endl;
//Сортировка выбором
writeStar();

cout << "Сортировка выбором: " << endl;
auto start = chrono::high_resolution_clock::now();
int  mins, buf;

for (int i = 0; i < N - 1; i++) {
	int minIndex = i;
	for (int j = i + 1; j < N; j++) {
		if (massiveD[j] < massiveD[minIndex]) {
			minIndex = j;
		}
	}
	if (minIndex != i) {
		swap(massiveD[i], massiveD[minIndex]);
	}
}

auto end = chrono::high_resolution_clock::now();
chrono::duration<float> duration = end - start;

for (int i = 0; i < N; i++) {
	cout << massiveD[i] << " ";
}
double value, microseconds, seconds = 0, minutes= 0;
value = duration.count();
microseconds = value * pow(10, 6);

while (microseconds >= pow(10, 6)) {
	microseconds /= pow(10, 6);
	seconds += 1;
}


while (seconds >= 60) {
	seconds = seconds - 60.0;
	minutes += 1;
}

cout << endl << "Расчетное время циклом " << minutes << " минут " << seconds << " секунд " << microseconds << " микросекунд " << endl;

//Сортировка вставками

writeStar();

int buff, j;
cout << "Сортировка вставками: " << endl;
auto starts = chrono::high_resolution_clock::now();
for (int i = 1; i < N; i++) {
	buff = massiveF[i];
	for (j = i - 1; j >= 0 && massiveF[j] > buff; j--)
		massiveF[j + 1] = massiveF[j];

	massiveF[j + 1] = buff;
}
auto ends = chrono::high_resolution_clock::now();
chrono::duration<float> massC = ends - starts;



for (int i = 0; i < N; i++) {
	cout << massiveF[i] << " ";
}
double values, microsecond, second = 0, minute = 0;

values = massC.count();
microsecond = values * pow(10, 6);

while (microsecond >= pow(10, 6)) {
	microsecond /= pow(10, 6);
	second += 1;
}


while (second >= 60) {
	second = second - 60.0;
	minute += 1;
}

cout << endl << "Расчетное время циклом " << minute << " минут " << second << " секунд " << microsecond << " микросекунд " << endl;



cout << endl;
return 0;
}

void quicksort(int massiveC[], int first, int last) {
	
	int count;
	int f = first, l = last;
	int mid = massiveC[(f + l) / 2]; // вычисление опорного элемента


	do {
		while (massiveC[f] < mid) {
			f++;
		}
		while (massiveC[l] > mid) {
			l--;
		}
		if (f <= l) { // перестановка элементов
			count = massiveC[f];
			massiveC[f] = massiveC[l];
			massiveC[l] = count;
			f++;
			l--;
		}
	} while (f < l);

	if (first < l) {
		quicksort(massiveC, first, l);
	}
	if (f < last) {
		quicksort(massiveC, f, last);
	}
}

//void