#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char myString[4];
	cout << "������� ������: " << '\n';
	cin.getline(myString, 4);
	cout << "�� �����: " << myString;

	
	return 0;
}
