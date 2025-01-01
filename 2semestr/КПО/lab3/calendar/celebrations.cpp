#include "stdafx.h"

using namespace std;

static void findCelebration(int quantity, int value) {

	if (quantity <= 59 + value) {
		if (quantity == 54) {
			cout << "День защитника Отечества" << endl;
		}
		else if (quantity == 60) {
			cout << "29 february" << endl;
		}
		else {
			cout << "Праздник не указан либо его нет" << endl;
		}
	}
	else {
		
		if (quantity  == 67 + value) {
			cout << "Международный женский день" << endl;
		}
		else if (quantity  == 121 + value) {
			cout << "День труда" << endl;
		}
		else if (quantity == 256) {
			cout << "День программиста" << endl;
		}
		else if (quantity  == 311 + value) {
			cout << "День Великой Октябрьской социалистической революции" << endl;
		}
		else if (quantity  == 244 + value) {
			cout << "День знаний" << endl;
		}
		else {
			cout << "Праздник не указан либо его нет" << endl;
		}
	}
}