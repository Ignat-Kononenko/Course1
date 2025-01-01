#include"stdafx.h"
#include"birthday.cpp"

using namespace std;

static int getParameters(int year, int result, int result_of_birthday, int month, int month_of_birthday, int day, int day_of_birthday) {

	int four = 4, fourhungreed = 400, score_of_date = 0, score_of_birthday = 0;

	if ((year % four == 0) || (year % fourhungreed == 0)) {
		cout << "год високосный:" << endl;
		cout << result << endl;
		getParametersOfBirthday(year, month, month_of_birthday, day, day_of_birthday);


	}
	else if (year % 100 == 0) {
		cout << "год невисокосный:" << endl;
		if ((year + 1) % 100 == 0) {
			result_of_birthday -= 1;

		}

		result -= 1;

		cout << result << endl;
		getParametersOfBirthday(year, month, month_of_birthday, day, day_of_birthday);


	}
	else {
		cout << "год невисокосный:" << endl;
		if ((year + 1) % 100 != 0 || (year + 1) % four != 0) {
			result_of_birthday -= 1;

		}
		result -= 1;

		cout << result << endl;
		getParametersOfBirthday(year, month, month_of_birthday, day, day_of_birthday);

	}
	return result_of_birthday;
}