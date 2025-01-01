#include"stdafx.h"
#include"year.h"

using namespace std;

int getYear(int* value) {

	int day_of_February;
	if ((*value % 4 == 0) || (*value % 400 == 0)) {
		
		day_of_February = 29;
	}
	else if (*value % 100 == 0) {
	
		day_of_February = 28;
	}
	else {
		day_of_February = 28;
	}

	return day_of_February;
}
