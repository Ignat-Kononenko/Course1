#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	int k;
	puts("�� ������ ������? (1-��, 2-���)");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1: {puts("������ ����� ��� ��������? (1-�������, 2-������, 3-�������)");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1: puts("��� ����������)"); break;
		case 2: puts("��� ����� �������)"); break;
		case 3: puts("��� �������)"); break;
		default: puts("���������� �������");
		}
		break;
		
	}
	case 2:puts("��, ������"); break;
	default: puts("���������� �������");
		
	}
	return 0;
}