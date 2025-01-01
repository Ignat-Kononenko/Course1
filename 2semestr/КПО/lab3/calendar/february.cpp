#include "stdafx.h"
#include "year.h"

using namespace std;

static void checkFebruary(int value, int year) {

	int result, leap = 29, day_of_february = 29;

	result = getYear(&year);
	if (value == day_of_february) {
		if (result != leap) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
		}
	}
}