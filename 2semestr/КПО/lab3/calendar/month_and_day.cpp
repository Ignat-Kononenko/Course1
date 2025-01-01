#include"stdafx.h"
#include"detection.cpp"
#include"year.h"

using namespace std;

int findDayAndMonth(int day, int month, int year) {

	int four = 4, fourhungreed = 400, eight = 8, sum = 0, zero = 0, thirty = 30, thirty_one = 31, result;
 
	for (int i = 0; i < month ; i++) {
		
		if (i == 0) {
			sum = day;
		}
		else if (i == 2) {
			sum += getYear(&year);
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			
			sum += thirty;
		}
		else if (i == 12) {
			sum += 0;
		}
		else {
			detectError(day);
			sum += thirty_one;
		}
	}
	result = sum;

	return result;
}