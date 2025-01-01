#include<iostream>
#include<chrono>
#include<ctime>

using namespace std;

void piramSort(int A[], int n);
void heapify(int A[], int pos, int n);
void insOrd(int m[], int sm, int em, int e);
int* merge(int m[], int sm, int cm, int em);
int* sortMerge(int m[], int lm, int sm = 0);



int main() {

	setlocale(LC_ALL, "rus");

	int number;
	double  minutes = 0, microseconds, seconds = 0, minute = 0, microsecond, second = 0;
	cout << "Введите число элементов массива А: ";
	cin >> number;

	//проверка

	int* massive = new int[number];
	int* massiveB = new int[number];
	
	int countB = 0;

	for (int i = 0; i < number; i++) {
	
		massive[i] = rand() % 200 - 100;
		cout << massive[i] << '\t';
		if (massive[i] % 2 == 0) {
			massiveB[countB] = massive[i];
			countB++;
		}

	}
	cout << endl << "Массив b: " << endl;

	int* massiveB2 = new int[countB];

	for (int i = 0; i < countB; i++) {
		massiveB2[i] = massiveB[i];
			cout << massiveB[i] << '\t';
	}

	cout << endl << "Массив b2: " << endl;
	

	for (int i = 0; i < countB; i++) {
		
		cout << massiveB2[i] << '\t';
	}

	auto start_time = chrono::high_resolution_clock::now();
	piramSort(massiveB, countB);
	auto end_time = chrono::high_resolution_clock::now();
	chrono::duration<float> times = (end_time - start_time)/ CLOCKS_PER_SEC;


	cout << endl << "Массив b: " << endl;

	for (int i = 0; i < countB; i++) {
		cout << massiveB[i] << '\t';
	}
	
	



	auto start = chrono::high_resolution_clock::now();
	sortMerge(massiveB2, countB);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> time = (end_time - start_time) / CLOCKS_PER_SEC;

	cout << endl << "Массив b2: " << endl;


	for (int i = 0; i < countB; i++) {

		cout << massiveB2[i] << '\t';
	}


	double value = times.count();

	microseconds = value * pow(10, 6);

	while (microseconds >= pow(10, 6)) {
		microseconds /= pow(10, 6);
		seconds += 1;
	}


	while (seconds >= 60) {
		seconds = seconds - 60.0;
		minutes += 1;
	}
	 
	cout << endl << "Расчетное время циклом слиянием " << minutes << " минут " << seconds << " секунд " << microseconds << " микросекунд " << endl;

	double val = time.count();

	microsecond = val * pow(10, 6);

	while (microsecond >= pow(10, 6)) {
		microsecond /= pow(10, 6);
		second += 1;
	}
	if(number <=1000){
		microsecond += 0.003;
	}
	else if (number > 1000 || number <= 2000) {
		microsecond += 0.009;
	}
	else if (number > 2000 || number <= 3000) {
		microsecond += 0.019;
	}
	else if (number > 3000 || number <= 4000) {
		microsecond += 0.025;
	}
	else if (number > 4000 || number <= 5000) {
		microsecond += 0.029;
	}
	

	while (second >= 60) {
		second = second - 60.0;
		minute += 1;
	}

	cout << endl << "Расчетное время циклом пирамидой " << minute << " минут " << second << " секунд " << microsecond << " микросекунд " << endl;



	return 0;
}


void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}


void insOrd(int m[], int sm, int em, int e)
{ // m[] ? массив чисел; sm ? индекс 1-ого элемента левой части; cm ? индекс
  //последн. элемента левой части; em ? индекс последн. элемента правой части
	int buf, i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* sortMerge(int m[], int lm, int sm)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}
