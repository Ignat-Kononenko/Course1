#include "stdafx.h"

using namespace std;

static int checkCondition(string value, int number) {

	if (value.size() != number) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
}