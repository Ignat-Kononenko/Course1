#include "stdafx.h"
#include"error.cpp"
#include"month_and_day.h"
#include"difference.cpp"
#include"february.cpp"
#include"condition.cpp"
#include"leap_and_non-leap.cpp"
#include"month.cpp"
#include"star.cpp"
#include"switch.cpp"
#include"celebrations.cpp"

using namespace std;

int main() {

	setlocale(LC_CTYPE, "rus");

	const int TWELVE = 12;
	int four = 4, fourhungreed = 400, eight = 8, sum = 0, zero = 0, thirty = 30, thirty_one = 31, result, result_of_birthday, result_of_year, result_of_birthdays_year, three = 3, number, variable;
	string date, birthday;

	cout << "введите дату в форме ДДММГГГГ:" << endl;
	getline(cin, date);

	checkCondition(date, eight);

	findError(date);

	string days(date, 0, 2);
	string monthes(date, 2, 2);
	string years(date, 4, 4);
	string exception(date, 0, 4);

	int day = stoi(days);
	int month = stoi(monthes);
	int year = stoi(years);
	int exceptions = stoi(exception);

	cout << "введите дату рождения в форме ДДММ: " << endl;
	getline(cin, birthday);

	checkCondition(birthday, four);

	findError(birthday);

	string days_of_birthday(birthday, 0, 2);
	string monthes_of_birthday(birthday, 2, 2);
	string expception_birthday(birthday, 0, 4);

	int day_of_birthday = stoi(days_of_birthday);
	int month_of_birthday = stoi(monthes_of_birthday);
	int expceptions_birthday = stoi(expception_birthday);
	int year_of_birthday = year + 1;

	writeStar();

	int quantity;
	cout << "введите порядковый номер " << endl;
	cin>> quantity;

	cout << "выберите: 1 - год високосный, 2 - невисокосный " << endl;
	cin >> number;
	variable = switchValue(number);

	if (quantity > 0 || quantity <= 366) {
		findCelebration(quantity, variable);
	}
	else {
		cout << "вы ввели неправильный порядок" << endl;
	}



	if (day <= zero || day > thirty_one || month <= zero || month > TWELVE || year <= zero || day_of_birthday <= zero || day_of_birthday > thirty_one || month_of_birthday <= zero || month_of_birthday > TWELVE || (expceptions_birthday == 3002) || (expceptions_birthday == 3102) || (exceptions == 3002) || (exceptions == 3102)) {
		cout << "вы ввели неправильную дату" << endl;
	}
	else {

		checkFebruary(day, year);
		result_of_year = getYear(&year);
		

		result = findDayAndMonth(day, month, year);
		result_of_birthday = findDayAndMonth(day_of_birthday, month_of_birthday, year);	

		if (result > result_of_birthday) {
			checkFebruary(day_of_birthday, year_of_birthday);
			result_of_birthdays_year = getYear(&year_of_birthday);
		}
		else {
			checkFebruary(day_of_birthday, year);
			result_of_birthdays_year = getYear(&year);
		}

		writeStar();

		cout <<"Порядковый номер первой даты: "<< result << endl;
		getNameOfMonth(month);
		getParametrOfYear(result_of_year);
		writeStar();
		cout <<"Порядковый номер дня рождения: "<< result_of_birthday << endl;
		getNameOfMonth(month_of_birthday);
		getParametrOfYear(result_of_birthdays_year);

		int result_of_difference = findDifference(result, result_of_birthday, year);
		writeStar();
	    cout << "Количество дней, которое осталось до дня рождения: " << result_of_difference  << endl;
	}

	return 0;
}
