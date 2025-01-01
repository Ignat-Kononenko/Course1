#include "stack.h"
using namespace std;

void push(Stack*& myStk, int value) {
    Stack* newP = new Stack;
    newP->data = value;
    newP->next = myStk;
    myStk = newP;
}

int pop(Stack*& myStk) {
    if (!isEmpty(myStk)) {
        int value = myStk->data;
        Stack* old = myStk;
        myStk = myStk->next;
        delete old;
        return value;
    }
    else {
        cout << "Стек пуст" << endl;
        return -1;
    }
}

bool isEmpty(Stack* myStk) {
    return myStk == nullptr;
}

void printStack(Stack* myStk) {
    while (myStk) {
        cout << myStk->data << " ";
        myStk = myStk->next;
    }
    cout << endl;
}

void clear(Stack*& myStk) {
    while (!isEmpty(myStk)) {
        pop(myStk);
    }
}

void toFile(Stack* myStk) {
    ofstream file("file.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        exit(0);
    }
    while (myStk) {
        file << myStk->data << endl;
        myStk = myStk->next;
    }
    file.close();
}

void fromFile(Stack*& myStk) {
    ifstream file("file.txt");
    int value;
    while (!isEmpty(myStk)) {
        pop(myStk);
    }
    while (file >> value) {
        push(myStk, value);
        cout << value << "\t";
    }
    cout << endl;
    file.close();
}

int countEqualNeighbors(Stack* myStk) {
    int count = 0;
    if (myStk && myStk->next) {
        int prev = myStk->data;
        myStk = myStk->next;
        while (myStk) {
            if (myStk->data == prev) {
                count++;
            }
            prev = myStk->data;
            myStk = myStk->next;
        }
    }
    return count;
}