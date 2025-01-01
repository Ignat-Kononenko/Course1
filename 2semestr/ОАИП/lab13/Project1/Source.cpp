#include "Hash.h"
#include <iostream>
#include <ctime> 
#include <iostream>
#include <chrono>
#include <ctime>
#include <string> 
#include <limits> // ��� ������� ������ �����
#include <cctype> // ��� �������� ��������
#include <cstdlib> 

using namespace std;

using namespace std::chrono;


struct AAA {
    int key;
    char* mas;
    AAA(int k, char* z) {
        key = k;
        mas = z;
    }
    AAA() {}
};

int key(void* d) {
    AAA* f = (AAA*)d;
    return f->key;
}

void AAA_print(void* d) {
    cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
double times = 0.003, searching_times;
int main() {


    setlocale(LC_ALL, "rus");
    int siz = 10, choice, k;
    clock_t start, end;
    double searching_time;
    cout << "������� ������ ���-�������: " << endl;

    // �������� �� ���������� ���� ������� �������
    while (true) {
        if (cin >> siz && siz > 0 && siz <= 32768 && cin.peek() == '\n') {
            break;
        }
        else {
            cout << "������������ ����." << endl;
            cin.clear(); // ������� ���� ������ �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }
    Object H = create(siz, key);
    Object H1 = create(32, key);
    Object H2 = create(64, key);
    Object H3 = create(128, key);

    for (;;) {
        cout << "1 - ����� ���-�������" << endl;
        cout << "2 - ���������� ��������" << endl;
        cout << "3 - �������� ��������" << endl;
        cout << "4 - ����� ��������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl;

        string input;
        cin >> input;

        bool invalidInput = false;
        for (char c : input) {
            if (!isdigit(c)) {
                invalidInput = true;
                break;
            }
        }

        if (!invalidInput) {
            int choice = atoi(input.c_str());
            switch (choice) {
            case 0:
                exit(0);
            case 1:
                H.scan(AAA_print);
                break;
            case 2: {
                AAA* a = new AAA;
                char* str = new char[20];

                cout << "������� ����: ";
                string input;
                int k;

                // ��������� ������������ ����� �����
                while (true) {
                    cin >> input;

                    // ���� ��������� ������ - ������ ����� ������, ������, � ������ ������ ��� ��������
                    // � � ��� ��� ��������, ����� ��������� ���� ��� ���
                    if (cin.peek() == '\n') {
                        // ���������, ��� ��������� ������ ������� ������ �� ����
                        bool validInput = true;
                        for (char c : input) {
                            if (!isdigit(c)) {
                                validInput = false;
                                break;
                            }
                        }

                        // ���� ��������� ������ ������� ������ �� ����
                        if (validInput) {
                            // ������� ������������� ������ � ����� �����
                            try {
                                k = stoi(input);
                                // ���������, ��� ��������� �������� ���������������
                                if (k >= 0) {
                                    break; // ��� � �������, ��������� ����
                                }
                                else {
                                    cout << "������! ";
                                }
                            }
                            catch (...) {
                                cout << "������! ";
                            }
                        }
                        else {
                            cout << "������! ";
                        }
                    }
                    else {
                        cout << "������! ";
                    }

                    // ������� ����� �����, ����� �������� ������
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                a->key = k;
                cout << "������� ������" << endl;
                /*cin >> str;*/
                cin.ignore();
                if (cin.peek() == '\n') {
                    cin.ignore(); // ���������� ������ ����� ������, ���� �� ����
                }
                cin.getline(str, 256);




                a->mas = str;
                if (H.N == H.size && H1.N == H1.size && H2.N == H2.size && H3.N == H3.size)
                    cout << "������� ���������" << endl;
                else {
                    H.insert(a);
                    H1.insert(a);
                    H2.insert(a);
                    H3.insert(a);
                }
            }
                  break;

            case 3: {
                bool validInput = false; // ���� ��� �������� ������������ �����

                do {
                    cout << "������� ���� ��� ��������" << endl;
                    string input;
                    cin >> input;

                    // ���������, ��� ������� ������ �����
                    bool isNumber = true;
                    for (char c : input) {
                        if (!isdigit(c)) {
                            isNumber = false;
                            break;
                        }
                    }

                    if (!isNumber) {
                        cout << "������������ ��������. ����������, ������� ������ �����." << endl;
                    }
                    else {
                        // ����������� ������ ����� � int
                        k = stoi(input);
                        validInput = true; // ������������� ���� ����������� �����
                    }
                } while (!validInput); // ��������� ����, ���� ���� �� ����� ����������

                // ���������, ����� �� �������
                if (H.N == 0) {
                    cout << "���-������� �����. ��� ��������� ��� ��������." << endl;
                }
                else {
                    // ���������, ���� �� ������� � ��������� ������
                    void* item = H.search(k);
                    if (item == nullptr) {
                        cout << "������� � ������ " << k << " �� ������." << endl;
                    }
                    else {
                        // ������� ������� ������ ���� �� ����������
                        H.deleteByKey(k);
                        cout << "������� � ������ " << k << " ������� ������." << endl;
                    }
                }
            }

                  break;

            case 4: {
                bool validInput = false; // ���� ��� �������� ������������ �����

                do {
                    cout << "������� ���� ��� ������" << endl;
                    string input;
                    cin >> input;

                    // ���������, ��� ������� ������ �����
                    bool isNumber = true;
                    for (char c : input) {
                        if (!isdigit(c)) {
                            isNumber = false;
                            break;
                        }
                    }

                    if (!isNumber) {
                        cout << "������������ ��������." << endl;
                    }
                    else {
                        // ����������� ������ ����� � int
                        k = stoi(input);
                        validInput = true; // ������������� ���� ����������� �����
                    }
                } while (!validInput); // ��������� ����, ���� ���� �� ����� ����������

                // ��������� ����� �������� �� ���������� �����
                start = clock();
                if (H.search(k) == NULL) {
                    cout << "������� � ������ " << k << " �� ������." << endl;
                }
                else {
                    AAA_print(H.search(k));
                }
                end = clock();
                searching_time = (double)(end - start) / CLOCKS_PER_SEC;
                searching_times = times + searching_time;
                cout << "����� ������ (������������) ������������������ �����������: " << searching_time << endl;
                cout << "����� ������ (������������) ���������� �����������: " << searching_times << endl;
               
                  }
                  break;
            }
        }
        else {
            cout << "������������ ����. ����������, ������� ���� �� ���� 0-4." << endl;
        }

    }


    return 0;
}


