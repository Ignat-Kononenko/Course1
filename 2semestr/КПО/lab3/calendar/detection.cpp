#include "stdafx.h"

using namespace std;

static void detectError(int value) {
	if (value == 31) {
		cout << "�� ����� ������������ ����" << endl;
		exit(0);
	}
	
}