#include "stdafx.h"

using namespace std;

static void findCelebration(int quantity, int value) {

	if (quantity <= 59 + value) {
		if (quantity == 54) {
			cout << "���� ��������� ���������" << endl;
		}
		else if (quantity == 60) {
			cout << "29 february" << endl;
		}
		else {
			cout << "�������� �� ������ ���� ��� ���" << endl;
		}
	}
	else {
		
		if (quantity  == 67 + value) {
			cout << "������������� ������� ����" << endl;
		}
		else if (quantity  == 121 + value) {
			cout << "���� �����" << endl;
		}
		else if (quantity == 256) {
			cout << "���� ������������" << endl;
		}
		else if (quantity  == 311 + value) {
			cout << "���� ������� ����������� ���������������� ���������" << endl;
		}
		else if (quantity  == 244 + value) {
			cout << "���� ������" << endl;
		}
		else {
			cout << "�������� �� ������ ���� ��� ���" << endl;
		}
	}
}