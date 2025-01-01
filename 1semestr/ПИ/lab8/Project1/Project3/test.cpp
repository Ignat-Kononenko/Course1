#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char myString[4];
	cout << "Введите строку: " << '\n';
	cin.getline(myString, 4);
	cout << "Вы ввели: " << myString;

	
	return 0;
}
