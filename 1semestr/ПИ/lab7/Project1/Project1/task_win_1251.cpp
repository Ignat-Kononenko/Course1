#include "solve_win_1251.h"
#include<iostream>

using namespace std;

int solveWin1251(char symbolForParamentor) {

	char simbol;
	int y, functionResult;

	if (symbolForParamentor >= '�' && symbolForParamentor <= '�') {
		simbol = symbolForParamentor - 32;
		functionResult = (int)(abs(simbol - symbolForParamentor));
		return functionResult;
	}
	else if (symbolForParamentor >= '�' && symbolForParamentor <= '�') {
		simbol = symbolForParamentor + 32;
		functionResult = (int)(abs(simbol - symbolForParamentor));
		return functionResult;
	}
	else {		
		cout << "������";
	}
}
