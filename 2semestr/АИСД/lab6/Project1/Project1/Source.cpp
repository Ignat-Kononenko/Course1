#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <windows.h>
#include<iostream>
#include<chrono>

#define MAX_NAME_LEN 100
#define TABLE_SIZE 1000 // Choose an appropriate table size

struct Item {
    int phone_number;
    char owner_name[MAX_NAME_LEN];
};

Item* createHashTable() {
    Item* hashTable = new Item[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].phone_number = -1; // Initialize phone numbers to -1 (indicating empty)
        hashTable[i].owner_name[0] = '\0'; // Initialize owner names to empty strings
    }
    return hashTable;
}

void insert(Item* hashTable, int phone_number, const char* owner_name) {
    int index = phone_number % TABLE_SIZE;
    hashTable[index].phone_number = phone_number;
#pragma warning(disable : 4996)
    strncpy(hashTable[index].owner_name, owner_name, MAX_NAME_LEN);
}

const char* get(const Item* hashTable, int phone_number) {
    int index = phone_number % TABLE_SIZE;
    if (hashTable[index].phone_number == phone_number) {
        return hashTable[index].owner_name;
    }
    return nullptr; // Not found
}

void deleteItem(Item* hashTable, int phone_number) {
    int index = phone_number % TABLE_SIZE;
    hashTable[index].phone_number = -1; // Mark as deleted
    hashTable[index].owner_name[0] = '\0';
}

int main() {
    Item* hashTable = createHashTable();

    // Example usage
    insert(hashTable, 123456, "John Doe");
    insert(hashTable, 123456, "Alice Smith");

    std::cout << "Owner of phone number 123456: " << get(hashTable, 123456) << std::endl;
    std::cout << "Owner of phone number 987654: " << get(hashTable, 987654) << std::endl;

    deleteItem(hashTable, 123456);
 
    delete[] hashTable;
    return 0;
}