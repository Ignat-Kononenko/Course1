
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 20;
    int x[N], k, sz, * pj, * pk;
    cout << "������� ����� �������(N<20) " << endl;
    cin >> sz;
    cout << "������: " << endl;
    if (sz > 0 && sz < 20)
    {
        srand((unsigned)time(NULL));
        for (pj = x; pj < x + sz; pj++)
        {
            *pj = rand() % 5;
            cout << *pj << " ";
        }




        cout << "\n������� k " << endl;
        cin >> k;

        pk = &k;

        for (int i = 0; i < sz; i++) {
            if (*pk > *(x + i)) {
                cout << "k ������ �������� ������� ��� ������� " << i << endl;
            }
            else if (*pk < *(x + i)) {
                cout << "k ������ �������� ������� ��� ������� " << i << endl;
            }
            else {
                cout << "k ����� �������� ������� ��� ������� " << i << endl;
            }

        }

    }
    else {
        cout << "������ ������������ ������";
    }

    return 0;
}



