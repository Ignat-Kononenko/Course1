#include<iostream>
#include <ctime> 

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	const int N = 10, M = 10;
	int matrix[N][M], a ,b,q,p;
	cout << "введите двумерный массив(N,M),где N-столбец( N>0 && N<10) и где M-строка( M>0 && M<10)\n";
	cin >> a;
	cin >> b;
	if (a>0 && b>0 && a < 11 && b < 11) {
		cout << "Массив:";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++)
			{
				matrix[i][j] = rand() % 10;
				if (j % b == 0) {
					cout << endl;
				}
				cout << matrix[i][j] << "\t";
			}
		}
		cout << endl;

		cout << "введите номера столбцов, которые вы бы хотели поменять\n";
		cin >> p;
		cin >> q;
		for (int i = 0; i < a; i++){	
				int temp = matrix[i][p]; 
				matrix[i][p] = matrix[i][q]; 
				matrix[i][q] = temp;        
			}
		cout << "исходная матрица:" ;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++)
			{
				if (j % b == 0)
					cout << endl;
				cout<< matrix[i][j]<<"\t";
			}
		}
		cout << endl;
	}
	else {
		cout << "неверно введен массива";
	}


	return 0;
}
