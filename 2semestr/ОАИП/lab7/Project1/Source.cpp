#include "stack.h"
using namespace std;

int main() {
    Stack* myStk = nullptr;
    int choice;
    int value, result;
    string val;

    do {

        setlocale(LC_ALL, "rus");
        cout << "1. Добавить элемент\n2. Удалить элемент\n3. Вывести стек\n4. Очистить стек\n5. Записать в файл\n6. Считать из файла\n7. Подсчитать количество элементов стека, у которых равные соседи\n8. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите число: ";

            cin.ignore();
            getline(cin, val);

            for (int i = 0; i < val.length(); i++) {
                if (val[i] == '-'|| val[i] == '.'){

                }
                else if ((val[i] > '9') || (val[i] < '0')) {
                    cout << "вы ввели неправильно" << endl;
                    exit(0);
                    break;
                }
            }

            value = stoi(val);
           
            push(myStk, value);
            break;
        case 2:
            cout << "Удаленное число: " << pop(myStk) << endl;
            break;
        case 3:
            printStack(myStk);
            break;
        case 4:
            clear(myStk);
            break;
        case 5:
          
            toFile(myStk);
            break;
        case 6:
         
            fromFile(myStk);
            break;

        case 7:

            
            result = countEqualNeighbors(myStk);
            cout << "Результат: " << result << endl;
            break;
        case 8:
            clear(myStk);
            cout << "Выход из программы\n";
            break;
        default:
            cout << "Неверный выбор\n";
            break;
        }
    } while (choice != 8);

    return 0;
}