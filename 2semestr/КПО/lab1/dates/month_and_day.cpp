#include"stdafx.h"

using namespace std;

static int findDayAndMonth(int day, int month ...) {

	int four = 4, fourhungreed = 400, eight = 8, sum = 0, zero = 0, thirty = 30, thirty_one = 31, result;

	if (month >= 2) {
		for (int i = 0; i < month - 1; i++) {
			if (i % 2 == 0) {
				sum += thirty_one;
			}
			else {
				sum += thirty;
			}
		}

		if (month == 2 || month == 9 || month == 11) {
			result = sum + day;
		}

		else {
			result = sum - 1 + day;
		}
	}
	else {
		result = day;
	}
	return result;
}