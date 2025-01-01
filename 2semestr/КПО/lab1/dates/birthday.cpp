#include"stdafx.h"

using namespace std;

static void getParametersOfBirthday(int year, int month, int month_of_birthday, int day, int day_of_birthday) {

	int four = 4, fourhungreed = 400;
	if (month > month_of_birthday || ((day > day_of_birthday) && (month == month_of_birthday))) {
		if (((year + 1) % four == 0) || ((year + 1) % fourhungreed == 0)) {
			cout << "год високосный:" << endl;

		}
		else if ((year + 1) % 100 == 0) {
			cout << "год невисокосный:" << endl;
		}
		else {
			cout << "год невисокосный:" << endl;
		}
	}
}