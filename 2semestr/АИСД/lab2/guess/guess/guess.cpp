#include<iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	int low = 1, average, number,second_number, sum = 1, second_sum = 1, result;
	char input;

	

	cout << "������� ����� N , �� �������� ����������� ������ (1 <=X <= N) " << endl;
	cin >> number;
	second_number = number;

	if (number < 1) {
		cout << "������" << endl;
		exit(0);
	}

	while (second_number != 1) {
		
		second_number /= 2;
		second_sum += 1;

	}

	cout << "��������� ����� �� 1 �� " << number << ", � � �������� ��������" << endl;
	average = (number + low) / 2;
	cout << "���� ����� " << average << "?" << endl;
	cout << "�������:q - �� , d - ������, a - ������" << endl;

	while ((input = getchar()) != 'q') {
		if (input != '\n') {
			if (input == 'd') {
				low = average + 1;
				average = (number + low) / 2;
				cout << "���� ����� " << average << "?" << endl;
				sum += 1;
			}
			else if (input == 'a') {
				number = average - 1;
				average = (number + low) / 2;
				cout << "���� ����� " << average << "?" << endl;
				sum += 1;
			}
			else {
				cout << "� �� �������. ������� q, d ��� a" << endl;
			}


		}

	}

	cout << "� �����, ��� ����� ��� �������!"<<endl;
	cout <<"��������� �������� ���������� ����� ��������� ������: " << sum << endl;
	cout << "������������ ���������� ����� ��������� ������: " << second_sum << endl;
	
	return 0;
}