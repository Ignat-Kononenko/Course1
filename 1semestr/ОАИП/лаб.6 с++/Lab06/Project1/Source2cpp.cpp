#include<iostream>
using namespace std;
int main()
{ 
	int a = 9;
	while (a >= 1)
	{
		for (int b = 9; b >= 1; b--)
		{
			if (a != b)
				cout << a << b << endl;
			
		}
		a = a - 1;
		
	}
	return 0;
}

