#include <iostream>
#include <cstdio>
#include<iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    FILE* F1;
    FILE* F2;
    int i = 0;
    char str[255];
    errno_t err;

    err = fopen_s(&F1, "f1.txt", "r");
    if (err != 0) {
        cout << "Ошибка открытия файла f1.txt." << endl;
        return 1;
    }

    err = fopen_s(&F2, "f2.txt", "w");
    if (err != 0) {
        cout << "Ошибка открытия файла f2.txt." << endl;
        fclose(F1);
        return 1;
    }

    while (i < 100 && fgets(str, 255, F1) != NULL) {
        if (i % 2 == 0) {
            fputs(str, F2);
        }
        i++;
    }

    fclose(F1);
    fclose(F2);

    return 0;
}