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

	puts("выберите вариант(1,2,3)");
	cin >> taskNumber;

	switch (taskNumber) {
	case 1:puts("напишите символ латинского алфавита");
	{
		cin >> str;

		cout << solveAskii(str);
	
		break;
	}
	case 2:puts("напишите символ русского алфавита");
	{
		cin >> str;

		if (str >= 'а' && str <= 'я') {
			functionResult = solveWin1251(str);
			cout << "разница значений кодов равна " << functionResult;
		}
		else if (str >= 'А' && str <= 'Я') {
			functionResult = solveWin1251(str);
			cout << "разница значений кодов равна " << functionResult;
		}
		else {
			cout << "ошибка";
		}

		break;
	}
	case 3:puts("напишите десятичную цифру");
	{
		cin >> str;

		if (str >= '0' && str <= '9') {	
			functionResult = solveNumber(str);
			cout << "код символа равен " << functionResult;
		}
		else {
			cout << "ошибка";
		}

		break;
	}
	default:puts("некоретный вариант");
	}

	return 0;
}

