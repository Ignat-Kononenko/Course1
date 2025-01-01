#include<iostream>
#include<Windows.h>
#include<stdlib.h>

#include "solve_askii.h"
#include "solve_win_1251.h"
#include "solve_number.h"

using namespace std;

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int taskNumber, functionResult;
	char str;

	puts("�������� �������(1,2,3)");
	cin >> taskNumber;

	switch (taskNumber) {
	case 1:puts("�������� ������ ���������� ��������");
	{
		cin >> str;

		cout << solveAskii(str);
	
		break;
	}
	case 2:puts("�������� ������ �������� ��������");
	{
		cin >> str;

		if (str >= '�' && str <= '�') {
			functionResult = solveWin1251(str);
			cout << "������� �������� ����� ����� " << functionResult;
		}
		else if (str >= '�' && str <= '�') {
			functionResult = solveWin1251(str);
			cout << "������� �������� ����� ����� " << functionResult;
		}
		else {
			cout << "������";
		}

		break;
	}
	case 3:puts("�������� ���������� �����");
	{
		cin >> str;

		if (str >= '0' && str <= '9') {	
			functionResult = solveNumber(str);
			cout << "��� ������� ����� " << functionResult;
		}
		else {
			cout << "������";
		}

		break;
	}
	default:puts("���������� �������");
	}

	return 0;
}

