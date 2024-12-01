#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	char c, probel;
	probel = ' ';
	cout << "Введите символ ";
	cin >> c;
	cout << setw(24) << setfill(probel) << probel; 
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(22) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(22) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(24) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(25) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(18) << setfill(probel) << probel;
	cout << setw(15) << setfill(c) << c << endl;
	cout << setw(25) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(25) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(25) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(24) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << setw(1)<< setfill(probel)<<probel<<setw(1)<<setfill(c)<<c<< endl;
	cout << setw(23) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << setw(3) << setfill(probel) << probel << setw(1) << setfill(c) << c << endl;
	cout << setw(22) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << setw(5) << setfill(probel) << probel << setw(1) << setfill(c) << c << endl;

	return 0;
}