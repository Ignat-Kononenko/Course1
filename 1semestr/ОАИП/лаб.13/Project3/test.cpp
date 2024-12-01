#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int width;
    int height;
    cout << "enter matrix's size n x m: ";
    cin >> height >> width;

    int** Matrix = new int* [height];
    for (int i = 0; i < height; i++)
        Matrix[i] = new int[width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            Matrix[i][j] = rand() % 15 + 1;

    cout << "Matrix:" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int firstColumn, secondColumn;
    cout << "enter index of first column: ";
    cin >> firstColumn;
    cout << "enter index of second column: ";
    cin >> secondColumn;

    int* columnTemp = new int[height];
    for (int i = 0; i < height; i++) {
        columnTemp[i] = Matrix[i][secondColumn];
        Matrix[i][secondColumn] = Matrix[i][firstColumn];
        Matrix[i][firstColumn] = columnTemp[i];
    }

    cout << "Matrix result:" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    delete columnTemp;

    return 0;
}