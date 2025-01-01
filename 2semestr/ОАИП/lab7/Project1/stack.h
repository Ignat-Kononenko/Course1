#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct Stack {
    int data;
    Stack* next;
};

void push(Stack*& myStk, int value);
int pop(Stack*& myStk);
bool isEmpty(Stack* myStk);
void printStack(Stack* myStk);
void clear(Stack*& myStk);
void toFile(Stack* myStk);
void fromFile(Stack*& myStk);
int countEqualNeighbors(Stack* myStk);