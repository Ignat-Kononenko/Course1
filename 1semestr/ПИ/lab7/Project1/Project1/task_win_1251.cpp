#include "solve_win_1251.h"
#include<iostream>

using namespace std;

int solveWin1251(char symbolForParamentor) {

	char simbol;
	int y, functionResult;

	if (symbolForParamentor >= 'а' && symbolForParamentor <= 'я') {
		simbol = symbolForParamentor - 32;
		functionResult = (int)(abs(simbol - symbolForParamentor));
		return functionResult;
	}
	else if (symbolForParamentor >= 'А' && symbolForParamentor <= 'Я') {
		simbol = symbolForParamentor + 32;
		functionResult = (int)(abs(simbol - symbolForParamentor));
		return functionResult;
	}
	else {		
		cout << "ошибка";
	}
}
