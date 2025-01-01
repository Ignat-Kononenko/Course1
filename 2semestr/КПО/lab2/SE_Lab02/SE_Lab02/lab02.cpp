#include<iostream>

using namespace std;

int sum(int first, int second) {
	return first + second;
}

int sub(int first, int second) {
	return first - second;
}

int(*result)(int, int);

int main() {

	setlocale(LC_ALL, "rus");

	bool t = true;
	//01;
	bool f = false;
	//00
	int lb = sizeof(bool);

	char latin = 'o';
	//0x008FFC03
	//6f
	char russian = 'о';
	//0x0000005A0F0FFBB4
	//ee
	wchar_t latins = L'K';
	//0x0000003457FEF954
	//4b 00
	wchar_t russians = L'К';
	//0x000000A0A8CFFAA4
	//ca ff
	short x = 15;
	//x = n + 5
	//0f 00
	
	//0000 0000 0000 1111 
	//0000 0000 - 00
	//0000 1111 - 0f
	//0f 00
	//f

	short minus_x = -15;
	//f1 ff
	//f1

	//0000 0000 0000 1111 (15)
	//1111 1111 1111 0001 доп.код(-15)
	//fff1

	//f1 ff

	short max = 0x7FFF;
	//32767
	short min = 0x8000;
	//-32768
	unsigned short maximum = 0xFFFF;
	//65535
	unsigned short minimum = 0x0000;
	//0

	int y = 16;
	//y = n + 6
	//0x0000009B709CFC14
	//10 00 00 00
	int u = sizeof(y);
	int minus_y = -16;
	//0x0000000C3CD6FC14
	//f0 ff ff ff
	int maximum_of_int = 0x7fffffff;
	//2147483647
	
	//2147483647:16 = 134217727
	//2147483647 - 2147483632 = 15(f)

	//134217727:16 = 8388607
	//134217727 - 134217712 = 15(f)

	//8388607:16 = 524287	
	//8388607 - 8388592 = 15(f)

	//524287:16	= 32767	
	//524287 - 524272 = 15(f)

	//32767:16 = 2047
	//32767 - 32752 = 15(f)
		
	//2047:16 = 127
	//2047 - 2032 = 15(f)
	
	//127:16 = 7
	//127 -112 = 15(f)

	//7f ff ff ff - в памяти
	int minimum_of_int = 0x80000000 ;
	//-2147483648


	unsigned int maximum_of_unsigned_int = 0xffffffff;
	//4294967295
	unsigned int minimum_of_unsigned_int = 0x00000000;
	//0

	long z = 17;
	//z = 11 + n
	
	//11 00 00 00 00
	long minus_z = -17;
	
	//ef ff ff ff

	long max_of_long = 0x7fffffff;
	//2147483647

	long min_of_long = 0x80000000;
	//-2147483648

	unsigned long max_of_unsignes_long = 0xffffffff;
	//4294967295

	unsigned long min_of_unsignes_long = 0x00000000;
	//0
	
	float number = -32.5;
	//32 = 10000
	// 0.5 = 0.1
	// 10000.1 = 1.00001(+5)
	// 127 + 5 = 132 (10000100) - показатель
	// 1     10000100   00000100000000000000
	//знак |показатель| мантисса
	//разделяем на четыре символа
	//1100 \0010\0000\0010\0000\0000\0000\0000
	//c2 02 00 00
	//00 00 02 c2 - в памяти компьютера

	float number_float = 32.5;
	//00 00 02 42

	float max_of_float =0x9ec97f7f;
	// 3.4e38
	float min_of_float =0x9ec97fff;
	//-3.4e38

	float infinity = 3.5e38;
	//00 00 80 7f
	float minus_infinity = - 3.5e38;
	//00 00 80 ff
	float ind = -infinity / infinity;
	//00 00 c0 ff
	cout << ind << endl;

	char* symbol = &latin;
	char* sum_of_char = symbol + 3;
	//43 fa 4f 00
	//46 fa 4f 00
	wchar_t* symbol_of_wchar_t = &latins;
	wchar_t* sum_of_wchar_t = symbol_of_wchar_t + 3;

	short* number_of_short = &x;
	short* sum_of_short = number_of_short + 3;

	int* number_of_int = &y;
	int* sum_of_int = number_of_int + 3;

	
	float* number_of_float = &number;
	float* sum_of_float = number_of_float + 3;

	result = sum;
	int first = result(5, 7);

	result = sub;
	int second = result(5, 7);

	return 0;
}