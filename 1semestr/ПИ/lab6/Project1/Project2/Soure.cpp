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
	puts("�������� �������(1,2,3)");
	cin >> k;
	switch (k)
	{
	case 1:puts("�������� ������ ���������� ��������");
	{
		cin >> n;
		if((int)a>strlen)
			while (strlen < a)
			{
				if (n >= 'a' && n <= 'z')
				{
					N = n - 32;
					x = (int)(abs(N - n));
					cout << "������� �������� ����� ����� " << x;

				}
				else
					if (n >= 'A' && n <= 'Z')
					{
						N = n + 32;
						x = (int)(abs(N - n));
						cout << "������� �������� ����� ����� " << x;
					}
				c=strlen + 1;
			}
			else
			{
				cout << "������";
			}
		break;
	}

	case 2:puts("�������� ������ �������� ��������");
	{
		cin >> u;

		if (u >= '�' && u <= '�')
		{
			U = u - 32;
			y = (int)(abs(U - u));
			cout << "������� �������� ����� ����� " << y;

		}
		else
			if (u >= '�' && u <= '�')
			{
				U = u + 32;
				y = (int)(abs(U - u));
				cout << "������� �������� ����� ����� " << y;
			}
			else
			{
				cout << "������";
			}
		break;
	}
	case 3:puts("�������� ���������� �����");
	{
		char s;
		int g;
		cin >> s;
		if (s >= '0' && s <= '9')
		{
			g = (int)s;


			cout << "��� ������� ����� " << g;
		}
		else
		{
			cout << "������";
		}
		break;
	}

	default:puts("���������� �������");



	}
	return 0;
}