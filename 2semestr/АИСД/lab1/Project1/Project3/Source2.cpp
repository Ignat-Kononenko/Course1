#include<iostream>
#include<thread>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	double number, number_one = 0, number_two = 1, sum = 0, minutes = 0;
	int seconds;

	cout << "введите число: ";
	cin >> number;

	
	for (int i = 0; i < number - 1; i++) {

		sum = number_one + number_two;
		number_one = number_two;
		number_two = sum;
		
	}
	

	cout << "результат = " << number_one << endl;

	return 0;
}