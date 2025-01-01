#include "stdafx.h"

using namespace std;

static void detectError(int value) {
	if (value == 31) {
		cout << "вы ввели неправильную дату" << endl;
		exit(0);
	}
	
}