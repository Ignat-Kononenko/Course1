#include<iostream>
#include<ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int width, height, max, sum;
	cout << "enter matrix size nxm" << endl;
	cin >> height >> width;

	int** Matrix = new int* [height];
	for (int i = 0; i < height; i++)
		Matrix[i] = new int[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			cout << "������� " << i + 1 << " ������� " << j + 1 << "-� ������ ";
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
		int multipl = 1;
		for (int j = 0; j < width; j++)
		{
			if (Matrix[i][j] > 0) {
				multipl *= Matrix[i][j];
			}
			else {
				multipl = 0;

			}

		}
		cout << "������������ ��������� " << i + 1 << " ������: " << multipl << endl;
	}

	max = 0;



	for (int k = 0; k < width; k++) {
		sum = 0;

		for (int i = 0; i < width - k; i++)

			sum += Matrix[i][i + k];

		if (sum > max)

			max = sum;

	}


	for (int k = 0; k < height; k++)

	{

		sum = 0;

		for (int j = 0; j < height - k; j++)

			sum += Matrix[j + k][j];

		if (sum > max)

			max = sum;

	}

	cout << "�������� ����� ���� ����������, ������������ ������� ��������� �������: " << max << endl;

	delete[] Matrix;





	return 0;
}