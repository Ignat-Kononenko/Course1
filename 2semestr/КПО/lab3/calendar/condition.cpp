#include "stdafx.h"

using namespace std;

static int checkCondition(string value, int number) {

	if (value.size() != number) {
		cout << "�� ����� ������������ ����" << endl;
		exit(0);
	}
}