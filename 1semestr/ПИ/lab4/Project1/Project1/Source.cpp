#include<iostream>
using namespace std;
int main(){
	char NAME[] = "K";
	char name[] = "k";
	char s = (char)((int)NAME[1] -(int) name[1]);
		
	cout <<s<< "\t" << endl;
	return 0;
}