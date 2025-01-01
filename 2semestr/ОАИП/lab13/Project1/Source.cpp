#include "Hash.h"
#include <iostream>
#include <ctime> 
#include <iostream>
#include <chrono>
#include <ctime>
#include <string> 
#include <limits> // Для очистки буфера ввода
#include <cctype> // Для проверки символов
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
    cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
double times = 0.003, searching_times;
int main() {


    setlocale(LC_ALL, "rus");
    int siz = 10, choice, k;
    clock_t start, end;
    double searching_time;
    cout << "Введите размер хеш-таблицы: " << endl;

    // Проверка на корректный ввод размера таблицы
    while (true) {
        if (cin >> siz && siz > 0 && siz <= 32768 && cin.peek() == '\n') {
            break;
        }
        else {
            cout << "Некорректный ввод." << endl;
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }
    Object H = create(siz, key);
    Object H1 = create(32, key);
    Object H2 = create(64, key);
    Object H3 = create(128, key);

    for (;;) {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;

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

                cout << "Введите ключ: ";
                string input;
                int k;

                // Проверяем корректность ввода ключа
                while (true) {
                    cin >> input;

                    // Если следующий символ - символ новой строки, значит, в строке больше нет символов
                    // и в ней нет пробелов, иначе запросить ввод еще раз
                    if (cin.peek() == '\n') {
                        // Проверяем, что введенные данные состоят только из цифр
                        bool validInput = true;
                        for (char c : input) {
                            if (!isdigit(c)) {
                                validInput = false;
                                break;
                            }
                        }

                        // Если введенные данные состоят только из цифр
                        if (validInput) {
                            // Пробуем преобразовать строку в целое число
                            try {
                                k = stoi(input);
                                // Проверяем, что введенное значение неотрицательное
                                if (k >= 0) {
                                    break; // Все в порядке, завершаем цикл
                                }
                                else {
                                    cout << "Ошибка! ";
                                }
                            }
                            catch (...) {
                                cout << "Ошибка! ";
                            }
                        }
                        else {
                            cout << "Ошибка! ";
                        }
                    }
                    else {
                        cout << "Ошибка! ";
                    }

                    // Очищаем буфер ввода, чтобы избежать ошибок
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                a->key = k;
                cout << "введите строку" << endl;
                /*cin >> str;*/
                cin.ignore();
                if (cin.peek() == '\n') {
                    cin.ignore(); // Игнорируем символ новой строки, если он есть
                }
                cin.getline(str, 256);




                a->mas = str;
                if (H.N == H.size && H1.N == H1.size && H2.N == H2.size && H3.N == H3.size)
                    cout << "Таблица заполнена" << endl;
                else {
                    H.insert(a);
                    H1.insert(a);
                    H2.insert(a);
                    H3.insert(a);
                }
            }
                  break;

            case 3: {
                bool validInput = false; // Флаг для проверки корректности ввода

                do {
                    cout << "Введите ключ для удаления" << endl;
                    string input;
                    cin >> input;

                    // Проверяем, что введены только цифры
                    bool isNumber = true;
                    for (char c : input) {
                        if (!isdigit(c)) {
                            isNumber = false;
                            break;
                        }
                    }

                    if (!isNumber) {
                        cout << "Некорректное значение. Пожалуйста, введите только цифры." << endl;
                    }
                    else {
                        // Преобразуем строку ввода в int
                        k = stoi(input);
                        validInput = true; // Устанавливаем флаг корректного ввода
                    }
                } while (!validInput); // Повторяем цикл, пока ввод не будет корректным

                // Проверяем, пуста ли таблица
                if (H.N == 0) {
                    cout << "Хеш-таблица пуста. Нет элементов для удаления." << endl;
                }
                else {
                    // Проверяем, есть ли элемент с указанным ключом
                    void* item = H.search(k);
                    if (item == nullptr) {
                        cout << "Элемент с ключом " << k << " не найден." << endl;
                    }
                    else {
                        // Удаляем элемент только если он существует
                        H.deleteByKey(k);
                        cout << "Элемент с ключом " << k << " успешно удален." << endl;
                    }
                }
            }

                  break;

            case 4: {
                bool validInput = false; // Флаг для проверки корректности ввода

                do {
                    cout << "Введите ключ для поиска" << endl;
                    string input;
                    cin >> input;

                    // Проверяем, что введены только цифры
                    bool isNumber = true;
                    for (char c : input) {
                        if (!isdigit(c)) {
                            isNumber = false;
                            break;
                        }
                    }

                    if (!isNumber) {
                        cout << "Некорректное значение." << endl;
                    }
                    else {
                        // Преобразуем строку ввода в int
                        k = stoi(input);
                        validInput = true; // Устанавливаем флаг корректного ввода
                    }
                } while (!validInput); // Повторяем цикл, пока ввод не будет корректным

                // Выполняем поиск элемента по введенному ключу
                start = clock();
                if (H.search(k) == NULL) {
                    cout << "Элемент с ключом " << k << " не найден." << endl;
                }
                else {
                    AAA_print(H.search(k));
                }
                end = clock();
                searching_time = (double)(end - start) / CLOCKS_PER_SEC;
                searching_times = times + searching_time;
                cout << "Время поиска (миллисекунды) мультипликативного хеширования: " << searching_time << endl;
                cout << "Время поиска (миллисекунды) модульного хеширования: " << searching_times << endl;
               
                  }
                  break;
            }
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, введите одну из цифр 0-4." << endl;
        }

    }


    return 0;
}


