#include<iostream>
#include<string>

using namespace std;



int ackermann(int m, int n) {

	if (m == 0) {
		return n + 1;
	}
	else if (m > 0 && n == 0) {
		return ackermann(m - 1, 1);
	}
	else if (m > 0 && n > 0) {
		return ackermann(m - 1, ackermann(m, n - 1));
	}
	return -1;
}


int main() {

	string first, second;
	int m, n;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите целые не отрицательные m и n." << endl;
	getline(cin, first);

	for (int i = 0; i < first.length(); i++) {
		if (first[i] > '9' || first[i] < '0') {
			cout << "ошибка ввода" << endl;
			exit(0);
		}
	}

	getline(cin, second);
	for (char c : second) {
		if (c > '9' || c < '0') {
			cout << "ошибка ввода" << endl;
			exit(0);
		}
	}

	m = stoi(first);
	n = stoi(second);

	
	cout << "–езультат функции: "<< ackermann(m,n)<<endl;




	return 0;
}