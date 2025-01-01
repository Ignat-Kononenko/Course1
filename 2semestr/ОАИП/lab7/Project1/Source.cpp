#include "stack.h"
using namespace std;

int main() {
    Stack* myStk = nullptr;
    int choice;
    int value, result;
    string val;

    do {

        setlocale(LC_ALL, "rus");
        cout << "1. �������� �������\n2. ������� �������\n3. ������� ����\n4. �������� ����\n5. �������� � ����\n6. ������� �� �����\n7. ���������� ���������� ��������� �����, � ������� ������ ������\n8. �����\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������� �����: ";

            cin.ignore();
            getline(cin, val);

            for (int i = 0; i < val.length(); i++) {
                if (val[i] == '-'|| val[i] == '.'){

                }
                else if ((val[i] > '9') || (val[i] < '0')) {
                    cout << "�� ����� �����������" << endl;
                    exit(0);
                    break;
                }
            }

            value = stoi(val);
           
            push(myStk, value);
            break;
        case 2:
            cout << "��������� �����: " << pop(myStk) << endl;
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
            cout << "���������: " << result << endl;
            break;
        case 8:
            clear(myStk);
            cout << "����� �� ���������\n";
            break;
        default:
            cout << "�������� �����\n";
            break;
        }
    } while (choice != 8);

    return 0;
}