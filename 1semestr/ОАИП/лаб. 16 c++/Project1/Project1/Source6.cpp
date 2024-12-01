#include <iostream>

using namespace std;

void result(int& height, int& width);

int main() {
	setlocale(LC_ALL, "rus");
	int width, height;
	cout << "������� ������ � ������ �������" << endl;
	cin >> height >> width;
	result(height, width);
}

void result(int& height, int& width) {
	setlocale(LC_ALL, "rus");
	int max, sum;
	int number = height;
	int** Matrix = new int* [height];
	for (int i = 0; i < height; i++)
		Matrix[i] = new int[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			cout << "������� " << j + 1 << " ������� " << i + 1 << "-� ������ ";
			cin >> Matrix[i][j];
		}

	}
	cout << "�������� �������:" << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			if (Matrix[i][j] == 0) {
				number--;
				break;
			}
		}

	}
	if (number != 0) {

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
			{
				if (Matrix[i][j] < 0) {
					Matrix[i][j] = 0;
					cout << Matrix[i][j] << "\t";
				}
				else {
					cout << Matrix[i][j] << "\t";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	else {
		cout << "��� ������ �������� ���� �� ���� �������";
	}
	for (int i = 0; i < height; i++)
		delete[] Matrix[i];
	delete[] Matrix;
}
