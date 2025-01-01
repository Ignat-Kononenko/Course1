#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <windows.h>
#include<iostream>
#include<chrono>


#define MAX_NAME_LEN 100

using namespace std;

typedef struct Item {
    int phone_number;
    char owner_name[MAX_NAME_LEN];
    struct Item* next;
} Item;

Item** createHashTable(int size) {
    Item** hashTable = (Item**)malloc(size * sizeof(Item*));
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

unsigned int hasher(int key, int size) {
    float A = (sqrt(5)-1)/2 ; //Кнут
    return floor(size * fmod(key * A, 1));//floor - округляет
}

void insert(Item** hashTable, int size, int phone_number, const char* owner_name) {
    unsigned int index = hasher(phone_number, size);
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->phone_number = phone_number;
#pragma warning(disable : 4996)
    strncpy(newItem->owner_name, owner_name, MAX_NAME_LEN);
    newItem->next = hashTable[index];
    hashTable[index] = newItem;
}


char* get(Item** hashTable, int size, int phone_number) {
    unsigned int index = hasher(phone_number, size);
   
    Item* item = hashTable[index];
    while (item != NULL) {
        if (item->phone_number == phone_number) {
            return item->owner_name;
        }
        item = item->next;
    }
    return 0;
}

void deleteItem(Item** hashTable, int size, int phone_number) {
    unsigned int index = hasher(phone_number, size);
    Item* item = hashTable[index];
    Item* prev = NULL;
    while (item != NULL) {
        if (item->phone_number == phone_number) {
            if (prev == NULL) {
                hashTable[index] = item->next;
            }
            else {
                prev->next = item->next;
            }
            free(item);
            return;
        }
        prev = item;
        item = item->next;
    }
}

void printHashTable(Item** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Индекс: " <<i<< endl;
     
        Item* item = hashTable[i];
        while (item != NULL) {
            cout << "Номер телефона: " << item->phone_number << "Имя владельца" << item->owner_name << endl;
            item = item->next;
        }
    }
}

int main() {

    setlocale(LC_ALL, "rus");
    
    int sizes[] = { 16, 128 };
    for (int i = 0; i < 2; i++) {
        int size = sizes[i];
        cout << "Размер хеш-таблицы равен " << size << endl;
        Item** hashTable = createHashTable(size);

        while (1) {
            cout << "Выберите действие:" << endl;
            cout << "1. Добавить элемент" << endl;
            cout << "2. Удалить элемент" << endl;
            cout << "3. Найти элемент" << endl;
            cout << "4. Вывести таблицу" << endl;
            cout << "5. Выход" << endl;
       
               int choice;
               cin >> choice;

            if (choice == 1) {
                int phone_number;
                char owner_name[MAX_NAME_LEN];
                cout << "Введите номер телефона:";
                cin>>phone_number;  
                cout << "Введите имя владельца:";
                cin.ignore();
                cin.getline(owner_name, MAX_NAME_LEN);

                for (int i = 0; i <strlen(owner_name); i++) {

                    if (owner_name[i] == '-' || owner_name[i] == ' ' || owner_name[i] == '\t') {

                    }
                    else if ((owner_name[i] < 'A' || owner_name[i] > 'Z') && (owner_name[i] < 'a' || owner_name[i] >'z')) {
                        cout << "Ошибка ввода" << endl;
                        exit(0);

                    }
                }
                insert(hashTable, size, phone_number, owner_name);
            }
            else if (choice == 2) {
                int phone_number;
                cout << "Введите номер телефона:";
                cin >> phone_number;
                deleteItem(hashTable, size, phone_number);
            }
            else if (choice == 3) {
                int phone_number;
                cout << "Введите номер телефона:";
                cin >> phone_number;
                auto start = chrono::high_resolution_clock::now();
              

                char* owner_names = get(hashTable, size, phone_number);
                if (owner_names[0] == NULL) {
                    cout << "Нет владельцев для номера телефона " << phone_number << endl;
                }
                else {
                    cout << "Владелец номера телефона " << phone_number << " являeтся:" <<owner_names<< endl;
                   
                }
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<float> duration = end - start;
                double count = duration.count();
                cout << "Time = " << count << endl;
            }
            else if (choice == 4) {
                printHashTable(hashTable, size);
            }
            else if (choice == 5) {
                break;
            }
            else {
                cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            }
        }

        free(hashTable);
    }

    return 0;
}