#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	char u, U;
	int y;
	cin >> u;
	if (u >= '�' && u <= '�')
	{
		U = u +32;
		y = (int)(abs(U - u));
		cout << "������� �������� ����� ����� " << y;
	}
	else
	{
		cout << "������";
	}
	return 0;
}
/* (s >= 48 && s <= 57)*/