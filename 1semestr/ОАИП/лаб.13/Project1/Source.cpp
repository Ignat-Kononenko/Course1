#include<iostream>
#include <ctime> 

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	const int N = 10, M = 10;
	int matrix[N][M], a, b, q, p,*pa,*pb, * px;
	cout << "������� ��������� ������(N,M),��� N-�������( N>0 && N<10) � ��� M-������( M>0 && M<10)\n";
	cin >> a;
	cin >> b;

	pa = &a;
	pb = &b;

	if (*pa > 0 && *pb > 0 && *pa < 11 && *pb < 11) {
		cout << "������:";
		for (int i = 0; i < *pa; i++) {
			for (int j = 0; j < *pb; j++)
			{
				*(*(matrix+i)+j) = rand() % 10;
				if (j % *pb == 0)
					cout << endl;
				cout << *(*(matrix + i) + j) << "\t";
			}
		}
		cout << endl;

		cout << "������� ������ ��������, ������� �� �� ������ ��������\n";
		cin >> p;
		cin >> q;

		for (int i = 0; i < *pa; i++) {
			int temp = *(*(matrix + i) + p);
			*(*(matrix + i) + p) = *(*(matrix + i) + q);
			*(*(matrix + i) + q) = temp;
		}

		cout << "�������� �������:";
		for (int i = 0; i < *pa; i++) {
			for (int j = 0; j < *pb; j++)
			{
				if (j % *pb == 0)
					cout << endl;
				cout << *(*(matrix + i) + j) << "\t";
			}
		}
		cout << endl;

	}
	else {
		cout << "������� ������ �������";
	}


	return 0;
}
