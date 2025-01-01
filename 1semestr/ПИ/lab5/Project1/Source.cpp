#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	char S;
	cout << "Введите первую латинскую букву вашей фамилии"<<endl;
	cin >> S;
	if (S > 'A' && S < 'Z')
	{
		char s = (char)((int)S + 32);
		cout << s;
	}
	else
		if(S > 'a' && S < 'z')
	{
		char s = (char)((int)S - 32);
		cout << s;
	}
		else
		{
			cout << "Неверно введено";
		}
	
	return 0;
}