#include "stdafx.h"

using namespace std;

static int switchValue(int value) {

	int variable, leap = 1, non_leap = 2, plus_day_to_leap_year = 1, plus_day_to_non_leap_year = 0;
	if (value == leap) {
		variable = plus_day_to_leap_year;
	}
	else if (value == non_leap) {
		variable = plus_day_to_non_leap_year;
	}
	else{
		cout << "вы ввели неправильное значение" << endl;
		exit(0);
	}
		
	
	return variable;
}