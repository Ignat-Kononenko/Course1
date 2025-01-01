#include "solve_number.h"
#include<iostream>

using namespace std;

int solveNumber(char symbolForNumber) {

	int functionResult;

	if (symbolForNumber >= '0' && symbolForNumber <= '9') {
		functionResult = (int)symbolForNumber;
		return functionResult;
	}
	else {
		cout << "ошибка";
	}
}
