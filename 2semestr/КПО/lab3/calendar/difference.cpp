#include "stdafx.h"
#include"year.h"
#include"month_and_day.h"

using namespace std;

static int findDifference(int first, int second, int year) {

	int number, leap = 29, result, result_of_birthday,serial_day, year_of_birthday = year + 1;

	result = getYear(&year);
	result_of_birthday = getYear(&year_of_birthday);

	if (first > second) {
		
		if ((result == leap) || (result_of_birthday != leap)) {
			if (second - 59 > 0) {
				serial_day = 365;
			}
			else {
				serial_day = 366;
			}
			number = serial_day - first + second;
		}
		else if ((result != leap) || (result_of_birthday == leap)) {

			if (second - 59 > 0) {
				serial_day = 366;
			}
			else {
				serial_day = 365;
			}
			number = serial_day - first + second;
		}
		else if ((result != leap) || (result_of_birthday != leap)) {
			number = 365 - first + second;
		}
		
	}
	else {
		number = second - first;
	}

	return number;
}