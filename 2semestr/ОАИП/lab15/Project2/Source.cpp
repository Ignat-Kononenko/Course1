#include<iostream>

using namespace std;

int main() {


	char mass[50];

	cin.getline(mass, 60);

	for (int i = 0; i < strlen(mass); i++)
		cout << mass[i];

	return 0;
}