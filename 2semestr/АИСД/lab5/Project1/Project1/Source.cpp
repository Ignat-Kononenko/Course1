#include <iostream>
#include <stack>��// ���������� ���������� ��� ������������� �����
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	stack <int> steck; 
	int i = 0;
	cout << "������� ����� ����� ����� �����: " << endl; // ���������� ������������ 
	// ������ 6 �����
	while (i != 6) {
		int a;
		cin >> a;

		steck.push(a);
		i++;
	}

	cout << "������� ������� �����: " << steck.top() << endl; // ������� ������� �������

	steck.pop();
	return 0;
}
