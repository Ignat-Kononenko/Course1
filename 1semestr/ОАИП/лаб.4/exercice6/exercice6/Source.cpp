#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	int k;
	puts("вы любите яблоки? (1-да, 2-нет)");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1: {puts("какого цвета вам нравятся? (1-зеленое, 2-желтое, 3-красное)");
		scanf_s("%d", &k);
		switch (k)
		{
		case 1: puts("они кисленькие)"); break;
		case 2: puts("они самые вкусные)"); break;
		case 3: puts("они сладкие)"); break;
		default: puts("некоретный вариант");
		}
		break;
		
	}
	case 2:puts("ну, бывает"); break;
	default: puts("некоретный вариант");
		
	}
	return 0;
}