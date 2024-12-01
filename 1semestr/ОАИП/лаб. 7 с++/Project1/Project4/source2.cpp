#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double g = 1, m = 4, z = 1, c = -0.045, b[]{ 0.9, 0.5,-7,2,0.91 };
	for (int j = 0; j < m; j++)
	{
		z=z*(b[j]+1)* (b[j] + 1);
	}
	g = c * z;
	cout << "g=" << g;



	return 0;
}