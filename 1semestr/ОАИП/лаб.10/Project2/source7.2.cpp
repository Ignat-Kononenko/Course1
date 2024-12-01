#include<iostream>
#include <bitset>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B, maskA = 480, maskB = 5207; char tmp[33];
	cout << "Введите число " << endl;
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число в двоичном виде = " << tmp << endl;
	cout << "Введите число " << endl;
	cin >> B;
	_itoa_s(B, tmp, 2);
	cout << "Число в двоичном виде = " << tmp << endl;
	_itoa_s(maskA, tmp, 2);
	cout << " Маска для А: " << tmp << endl;
	_itoa_s(A & maskA, tmp, 2);
	cout << " Результат: " << tmp << endl;
	
	_itoa_s((A & maskA) >> 5, tmp, 2);
	cout << " Результат: " << tmp << endl;
	cout << "Число B = " << B << endl;
	_itoa_s(B, tmp, 2);
	cout << "Число в двоичном виде = " << tmp << endl;

	_itoa_s(B, tmp, 2);
	cout << " Результат: " << tmp;
	_itoa_s((A & maskA) >> 5, tmp, 2);
	cout <<tmp << endl;

}