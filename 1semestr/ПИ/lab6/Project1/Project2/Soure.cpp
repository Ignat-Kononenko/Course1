#include<iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int k, x, y,c;
	char n, N, U, u;
	char a[] = { 255 };
	puts("выберите вариант(1,2,3)");
	cin >> k;
	switch (k)
	{
	case 1:puts("напишите символ латинского алфавита");
	{
		cin >> n;
		if((int)a>strlen)
			while (strlen < a)
			{
				if (n >= 'a' && n <= 'z')
				{
					N = n - 32;
					x = (int)(abs(N - n));
					cout << "разница значений кодов равна " << x;

				}
				else
					if (n >= 'A' && n <= 'Z')
					{
						N = n + 32;
						x = (int)(abs(N - n));
						cout << "разница значений кодов равна " << x;
					}
				c=strlen + 1;
			}
			else
			{
				cout << "ошибка";
			}
		break;
	}

	case 2:puts("напишите символ русского алфавита");
	{
		cin >> u;

		if (u >= 'а' && u <= 'я')
		{
			U = u - 32;
			y = (int)(abs(U - u));
			cout << "разница значений кодов равна " << y;

		}
		else
			if (u >= 'А' && u <= 'Я')
			{
				U = u + 32;
				y = (int)(abs(U - u));
				cout << "разница значений кодов равна " << y;
			}
			else
			{
				cout << "ошибка";
			}
		break;
	}
	case 3:puts("напишите десятичную цифру");
	{
		char s;
		int g;
		cin >> s;
		if (s >= '0' && s <= '9')
		{
			g = (int)s;


			cout << "код символа равен " << g;
		}
		else
		{
			cout << "ошибка";
		}
		break;
	}

	default:puts("некоретный вариант");



	}
	return 0;
}