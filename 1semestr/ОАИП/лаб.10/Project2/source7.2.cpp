#include<iostream>
#include <bitset>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B, maskA = 480, maskB = 5207; char tmp[33];
	cout << "������� ����� " << endl;
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "����� � �������� ���� = " << tmp << endl;
	cout << "������� ����� " << endl;
	cin >> B;
	_itoa_s(B, tmp, 2);
	cout << "����� � �������� ���� = " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << " ����� ��� �: " << tmp << endl;
	_itoa_s(A & maskA, tmp, 2);
	cout << " ���������: " << tmp << endl;
	
	_itoa_s((A & maskA) >> 5, tmp, 2);
	cout << " ���������: " << tmp << endl;
	cout << "����� B = " << B << endl;
	_itoa_s(B, tmp, 2);
	cout << "����� � �������� ���� = " << tmp << endl;

	_itoa_s(B, tmp, 2);
	cout << " ���������: " << tmp;
	_itoa_s((A & maskA) >> 5, tmp, 2);
	cout <<tmp << endl;

}