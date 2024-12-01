#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	char c, probel; probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c<< endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(24) << setfill(probel) << probel;
	cout << setw(23) << setfill(c) << c << endl;
	cout << setw(26) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(28) << setfill(probel) << probel;
	cout << setw(15) << setfill(c) << c << endl;
	cout << setw(30) << setfill(probel) << probel;
	cout << setw(11) << setfill(c) << c << endl;
	cout << setw(29) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c <<  setw(3)<< setfill(probel) << probel  << setw(5) << setfill(c) << c <<endl;

	
	cout << setw(28) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c  << setw(9) << setfill(probel) << probel  << setw(3) << setfill(c) << c  << endl;
	cout << setw(27) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << setw(15) << setfill(probel) << probel<< setw(1) << setfill(c) << c << endl;

	
}