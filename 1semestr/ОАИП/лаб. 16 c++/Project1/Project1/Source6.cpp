#include <iostream>

using namespace std;

void result(int& height, int& width);

int main() {
	setlocale(LC_ALL, "rus");
	int width, height;
	cout << "введите ширину и высоту матрицы" << endl;
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
			cout << "¬ведите " << j + 1 << " элемент " << i + 1 << "-й строки ";
			cin >> Matrix[i][j];
		}

	}
	cout << "исходна€ матрица:" << endl;

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
		cout << "все строки содержат хот€ бы один элемент";
	}
	for (int i = 0; i < height; i++)
		delete[] Matrix[i];
	delete[] Matrix;
}
