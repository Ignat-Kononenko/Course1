
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 20;
    int x[N],k,sz;
    cout << "������� ����� �������(N<20) " << endl;
    cin >> sz;
    cout << "������: " << endl;
    if (sz > 0 && sz < 20)
    {
        srand((unsigned)time(NULL));
        for (int j = 0; j < sz; j++)
        {
            x[j] = rand() % 5;
            cout << x[j] << " ";
        }




        cout << "\n������� k " << endl;
        cin >> k;
        for (int i = 0; i < sz; i++) {
            if (k > x[i]) {
                cout << "k ������ �������� ������� ��� ������� " << i  << endl;
            }
            else if (k < x[i]) {
                cout << "k ������ �������� ������� ��� ������� " << i  << endl;
            }
            else {
                cout << "k ����� �������� ������� ��� ������� " << i  << endl;
            }

        }

    }
    else {
        cout << "������ ������������ ������";
    }

    return 0;
}

