#include <stdio.h>
#include<iostream>

#define HIGH 100
#define LOW 1
int main()
{
	setlocale(LC_ALL, "rus");
	int guess = (HIGH + LOW) / 2;
	int highest = HIGH;
	int lowest = LOW;
	char response;
	printf(" ��������� ����� �� %d �� %d. � ��������", LOW, HIGH);
	printf(" ������� ���.\n ��������� q, ���� ��� ������� ���������,");
	printf(" d, ���� \n ������, � a, ����");
	printf(" ������. \n");
	printf("���� ... ���� ����� %d?\n", guess);
	while ((response = getchar()) != 'q')
	{
		if (response != ' \n')
		{
			if (response == 'd')
			{/* ���������� �������� �������. ���� ������-
			������ �������� ������� ������ */
				highest = guess - 1;
				guess = (highest + lowest) / 2;
				printf(" �� ... ������� ������. ���� ����� %d?\n", guess);
			}
			else if (response == 'a')
				{/* ���������� ������� �������, ���� ������������ �������� ������� ���� */
					lowest = guess + 1;
					guess = (highest + lowest) / 2;
					printf("�� ... ������� ����.���� ����� % d ? \n", guess);
				}
				else
				{/* ��������� ������������ � ����������� ������ */
					printf("� �� �������; �������, ����������, �, �");
					printf(" ��� �.\n");
				}
		}
		
	}
	printf("� �����, ��� ����� ������� ���!\n");
}