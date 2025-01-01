#include "stdafx.h"

using namespace std;

static void findError(string value) {
	for (int i = 0; i < value.size(); i++) {
		if ((value[i] > '9') || (value[i] < '0')) {
			cout << "вы ввели неправильную дату" << endl;
			exit(0);
			break;
		}
	}
}