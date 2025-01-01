#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>

using namespace std;

int user(string);
int addition(string);


int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "rus");

    cout << "введите строку: " << endl;
    string str;
    getline(cin, str);
    cout << "Прочитанная строчка из файла: ";
    user(str);

    

    return 0;
}

int user(string str) {

    ofstream fout("fin.txt");

    if (!fout.is_open()) {
        cout << "error";
        exit(1);

    }

    fout << str;
    fout << "\n";

    fout.close();

    ifstream fin("fin.txt");
    if (!fin.is_open()) {
        cout << "error";
        exit(1);
    }

    string line;
    while (getline(fin, line)) {
        cout<< line << endl;
        cout << "Группы с четными символами: " << endl;

        addition(line);

    }


    fin.close();
    return 0;
}

int addition(string line) {

    string group = "";
    for (char c : line) {
        if (isdigit(c) || c == '0') {
            group += c;
        }
        else {
            if (group.size() % 2 == 0 && group.size() > 0) {
                cout << group << endl;
            }
            group = "";
        }
    }
    if (group.size() % 2 == 0 && group.size() > 0) {
        cout << group << endl;
    }
    return 0;
}