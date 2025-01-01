#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<string>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int k, x, y, c,i;
	char n[32], N[32], U, u, string[255], A;
	cin >> n;

	for(i=0;i<strlen(n);i++)
	{

		if (n[i] >= 'a' && n[i] <= 'z')
		{
			N[i] = n[i] - 32;
			x = (int)(abs(N[i] - n[i]));
			cout << "разница значений кодов равна " << x<<endl;

		}
		else
			if (n[i] >= 'A' && n[i] <= 'Z')
			{
				N[i] = n[i] + 32;
				x = (int)(abs(N[i] - n[i]));
				cout << "разница значений кодов равна " << x<<endl;
			}

			else
			{
				cout << "ошибка";
			}
	}
	return 0;
}