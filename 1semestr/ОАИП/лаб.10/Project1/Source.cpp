
#include <bitset>
#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A; char tmp[33];
	cout << "Введите число " << endl;
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число в двоичном виде = " << tmp << endl;
	if (A < 8) {
		_itoa_s(0x2, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0x2, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else if(A>=8 && A<16){
		_itoa_s(0x5, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0x5, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else if(A>=16 && A<32){
		_itoa_s(0xA, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0xA, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else if (A >= 32 && A < 64) {
		_itoa_s(0x15, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0x15, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else if (A >= 64 && A < 128) {
		_itoa_s(0x2A, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0x2A, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else if (A >= 128 && A < 256) {
		_itoa_s(0x55, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0x55, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}
	else {
		_itoa_s(0xAA, tmp, 2);
		cout << " Маска для А: " << tmp << endl;
		_itoa_s(A | 0xAA, tmp, 2);
		cout << " Результат: " << tmp << endl;
	}

}



