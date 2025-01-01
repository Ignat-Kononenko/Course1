#include "solve_askii.h"
#include<iostream>

using namespace std;

int solveAskii(char symbolForAscii) {

	char number;
	int functionResult;

	if (symbolForAscii >= 'a' && symbolForAscii <= 'z') {
		number = symbolForAscii - 32;
		functionResult = (int)(abs(number - symbolForAscii));
		return functionResult;
	}
	else if (symbolForAscii >= 'A' && symbolForAscii <= 'Z') {
		number = symbolForAscii + 32;
		functionResult = (int)(abs(number - symbolForAscii));
		return functionResult;
	}
}
