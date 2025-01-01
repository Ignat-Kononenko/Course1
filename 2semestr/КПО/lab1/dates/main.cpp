#include "stdafx.h"
#include"month_and_day.cpp"
#include"parameters.cpp"
#include"answer.cpp"

using namespace std;
 
int main() {

	setlocale(LC_CTYPE, "rus");
	int c = 1;
	
	do {
		
		const int TWELVE = 12;
		int four = 4, fourhungreed = 400, eight = 8, sum = 0, zero = 0, thirty = 30, thirty_one = 31, result, result_of_birthday, quantity;
		string date, birthday;

		cout << "введите дату в форме ДДММГГГГ:" << endl;
		getline(cin, date);

		for (int i = 0; i < date.size(); i++) {
			if ((date[i] > '9') || (date[i] < '0')) {
				cout << "вы ввели неправильную дату" << endl;
				exit(0);
				break;
			}
		}
		
		if (date.size() == eight) {

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
			
				if (birthday.size() == four) {

					for (int i = 0; i < birthday.size(); i++) {
						if ((birthday[i] > '9') || (birthday[i] < '0')) {
							cout << "вы ввели неправильную дату" << endl;
							exit(0);
							break;
						}
					}

					string days_of_birthday(birthday, 0, 2);
					string monthes_of_birthday(birthday, 2, 2);
					string expception_birthday(birthday, 0, 4);

					int day_of_birthday = stoi(days_of_birthday);
					int month_of_birthday = stoi(monthes_of_birthday);
					int expceptions_birthday = stoi(expception_birthday);

					if (day < zero || day > thirty_one || month < zero || month > TWELVE || year < zero || day_of_birthday < zero || day_of_birthday > thirty_one || month_of_birthday < zero || month_of_birthday > TWELVE || (expceptions_birthday == 3002) || (expceptions_birthday == 3102) || (exceptions == 3002) || (exceptions == 3102)) {
						cout << "вы ввели неправильную дату" << endl;
					}
					else {

						result = findDayAndMonth(day, month);

						result_of_birthday = findDayAndMonth(day_of_birthday, month_of_birthday);

						result_of_birthday = getParameters(year, result, result_of_birthday, month, month_of_birthday, day, day_of_birthday);
						cout << result_of_birthday;

						quantity = getAnswer(result, result_of_birthday, day, day_of_birthday, year);
						cout << "\nрезультат = " << quantity;
					}
				}
				else {
					cout << "вы ввели неправильную дату" << endl;
				}
			}
		else {
			cout << "вы ввели неправильную дату" << endl;
		}
		cout << "\nвведите 1, чтобы продолжить, 2, чтобы закончить:" << endl;
		cin >> c;
		}
	 while (c != 2);
	}
