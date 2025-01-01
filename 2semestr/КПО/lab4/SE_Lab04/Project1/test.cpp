#include<iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
	day dd;
	month mm;
	year yyyy;
};
	bool operator ==(const Date& one, const Date& other) {
		return one.dd == other.dd && one.mm == other.mm && one.yyyy == other.yyyy;
	}

	bool operator <(const Date& one, const Date& other) {
		if (one.yyyy < other.yyyy) {
			return true;
		}
		else if (one.yyyy == other.yyyy) {
			if (one.mm < other.mm) {
				return true;
			}
			else if (one.mm == other.mm) {
				if (one.dd < other.dd) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator >(const Date& one, const Date& other) {
		if (one.yyyy > other.yyyy) {
			return true;
		}
		else if (one.yyyy == other.yyyy) {
			if (one.mm > other.mm) {
				return true;
			}
			else if (one.mm == other.mm) {
				if (one.dd > other.dd) {
					return true;
				}
			}
		}
		return false;
	}





int main() {

	
	Date date1 = { 8,10,2003 };
	Date date2 = { 5,12,2006 };
	Date date3 = { 5,1,2005 };

	if (date1 < date2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (date1< date3)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (date3 == date2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}