#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	char u, U;
	int y;
	cin >> u;
	if (u >= 'А' && u <= 'я')
	{
		U = u +32;
		y = (int)(abs(U - u));
		cout << "разница значений кодов равна " << y;
	}
	else
	{
		cout << "ошибка";
	}
	return 0;
}
/* (s >= 48 && s <= 57)*/