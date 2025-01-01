#include<iostream>
#include<chrono>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	double number, number_one = 0, number_two = 1, sum = 0, minutes = 0, seconds = 0, microseconds, value;

	cout << "введите число: ";
	cin >> number;

	if (number < 0) {
		cout << "Ошибка ввода";
		exit(0);
	}

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < number - 1; i++) {
		
		sum = number_one + number_two;
		number_one = number_two;
		number_two = sum;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	 value = duration.count();
	 microseconds = value * pow(10,6);

		while (microseconds >= pow(10,6)) {
			microseconds /= pow(10, 6);
			seconds += 1;
		}

		while (seconds >= 60) {
			seconds = seconds - 60.0;
			minutes += 1;
		}
	
	cout << "результат = " << number_one << endl;
	cout << "Расчетное время циклом " << minutes << " минут " << seconds << " секунд "<< microseconds << " микросекунд " <<endl;

	cout << "duration =  " << duration.count() << endl;

	return 0;
}