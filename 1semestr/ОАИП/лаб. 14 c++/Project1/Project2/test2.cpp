#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int size = 0,min, negative,sum=0;
	cout << "������� ������ �������" << endl;
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "������� " << i + 1<<" ������� ";
		cin >> *(arr + i);
	}


	min = abs(*(arr + 0));
	for (int i = 1; i < size; i++) {
		
	if (abs(*(arr + i)) < abs(min)) {
		min =abs(*(arr + i));
	}
	}
	cout << "min = " << min;

	for (int i = 0; i < size; i++) {

		if (*(arr + i) < 0) {
			negative = i;
			break;
		}
	
	}

	for (int i = negative+1; i < size; i++) {

		sum += abs(*(arr + i));

	}
	cout << "\nsum = " << sum;
	delete[] arr;

	return 0;
}