#include<iostream>
#include<stdio.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
    FILE* F1;
    FILE* F2;
    int k, i = 0;
    char str[255];
    errno_t err;
    err = fopen_s(&F1, "f1.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        fflush(stdin);
        printf("������� ������ %d : \n", i + 1);
        gets_s(str);
        fputs(str, F1);
        fputs("\n", F1);
    }
    fclose(F1);
    fclose(F1);
    err = fopen_s(&F1, "f1.txt", "r");
    err = fopen_s(&F2, "f2.txt", "w");

    for (int i = 0; i < 10 && fgets(str, 255, F1) != NULL; i++)
    {
        if (i % 2 == 0)
            fputs(str, F2);
    }

    fclose(F1);
    fclose(F2);

	return 0;
}

