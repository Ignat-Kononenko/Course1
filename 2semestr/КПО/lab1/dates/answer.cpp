#include"stdafx.h"

using namespace std;

static int getAnswer(int result, int result_of_birthday, int day, int day_of_birthday, int year) {

	int number;

	if ((result > result_of_birthday) && (year % 4 == 0) && ((year + 1) % 100 != 0) && ((year + 1) % 4 != 0)) {
		number = 366 + 1 - result + result_of_birthday;
	}
	else if ((result > result_of_birthday) && (year % 4 != 0 || year % 400 != 0) && ((year + 1) % 100 != 0) && ((year + 1) % 4 == 0 || (year + 1) % 400 == 0)) {
		number = 365 + 2 - result + result_of_birthday;
	}
	else if ((result > result_of_birthday) && (year % 4 != 0 || year % 400 != 0) && ((year + 1) % 100 != 0) && ((year + 1) % 4 != 0 || (year + 1) % 400 != 0)) {
		number = 365 + 2 - result + result_of_birthday;
	}
	else if (result <= (result_of_birthday + 1)) {
		number = result_of_birthday - result + 1;
	}

	return number;
}