#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    char tmp[33];
    int A,B,n,m;

    cout << "������ ����� �=";

    cin >> A;

    cout << "������ ����� �=";

    cin >> B;

   
    cout << "������� ������� n: ";
    cin >> n;
    int maskA = 14 << (n - 1);

   
    cout << "������� ������� m: ";
    cin >> m;
    int maskB = ~(7 << (m - 1));

    _itoa_s(A, tmp, 2);
    cout << "A=" << tmp << endl;

    _itoa_s(B, tmp, 2);
    cout << "B=" << tmp << endl;

    _itoa_s(maskA, tmp, 2);
    cout << "����� ��� �: " << tmp << endl;

    _itoa_s((A & maskA) >> (n-1 ), tmp, 2);
    cout << "���������� ���� �: " << tmp << endl;

    _itoa_s(maskB, tmp, 2);
    cout << "����� ��� �: " << tmp << endl;

    _itoa_s((B & maskB) | ((A & maskA) >> (n - 1) << (m - 1)), tmp, 2);
    cout << "��������� B=" << tmp << endl;

}

