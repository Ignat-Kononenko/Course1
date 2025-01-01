#include"stdafx.h"
#include"year.h"

using namespace std;

static void getParametrOfYear(int value) {

	int leap = 29;

	if (value == leap) {
		cout<< "год високосный" << endl;
	}
	else {
		cout << "год невисокосный" << endl;
	}
}