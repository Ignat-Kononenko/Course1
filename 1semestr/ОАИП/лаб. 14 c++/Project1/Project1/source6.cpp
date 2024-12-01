# include <iostream>
using namespace std;
void massiv();
void matrix();

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
	{
		cout << endl;
		cout << "�������" << endl;
		cout << "1-���������� ������" << endl;
		cout << "2-������ � ��������" << endl;
		cout << "3-�����" << endl;
		cin >> c;
		switch (c)
		{
		case 1: massiv(); break;
		case 2: matrix(); break;
		case 3: break;
		}
	} while (c != 3);
}


void massiv()
{

		setlocale(LC_ALL, "rus");
		int size = 0, min, negative, sum = 0;
		cout << "\n������� ������ �������" << endl;
		cin >> size;

		int* arr = new int[size];

		for (int i = 0; i < size; i++) {
			cout << "������� " << i + 1 << " ������� ";
			cin >> *(arr + i);
		}


		min = abs(*(arr + 0));
		for (int i = 1; i < size; i++) {

			if (abs(*(arr + i)) < abs(min)) {
				min = abs(*(arr + i));
			}
		}
		cout << "min = " << min;

		for (int i = 0; i < size; i++) {

			if (*(arr + i) < 0) {
				negative = i;
				break;
			}

		}

		for (int i = negative + 1; i < size; i++) {

			sum += abs(*(arr + i));

		}
		cout << "\nsum = " << sum;
		delete[] arr;

		
}
//������
void matrix()
{
	setlocale(LC_ALL, "rus");
	int width, height, max, sum;
	cout << "������� ������ � ������ ���������� �������" << endl;
	cin >> height;
	 width= height;
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
	
}
