#include<iostream>
#include<chrono>

using namespace std;

unsigned int fibonachi(double);

int main() {

	setlocale(LC_ALL, "rus");
	double number, number_one = 0, number_two = 1, sum = 0, minutes = 0, seconds = 0 , microseconds, value;
	

	cout << "введите число: ";
	cin >> number;

	if (number < 0) {
		cout << "Ошибка ввода";
		exit(0);
	}

	auto start = chrono::high_resolution_clock::now();
	cout << "результат = " << fibonachi(number) << endl;
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end - start;

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

	cout << "Расчетное время циклом " << minutes << " минут " << seconds << " секунд " << microseconds << " микросекунд " << endl;
	cout << "duration =  " << duration.count() << endl;


	return 0;
}

unsigned int fibonachi(double n) {
	static int x1 = 0, x2 = 1;
	int x3;
	if (n > 1) {
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
		return(fibonachi(n - 1));
		
	}
	else {
		return x1;
	}
}