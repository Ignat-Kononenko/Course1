#include<iostream>

using namespace std;

static void writeStar() {

	char star[120];

	for (int i = 0; i < sizeof(star); i++) {

		star[i] = '*';
		cout << star[i];
	}
}