#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 20;
    int i = 0, j = 0,sz,ss, n = 5, k = 3, x[N], y[N], * pn, * pk, * ph, * pj;

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
        

        cout << "\n������� ����� �������(N<20) " << endl;
        cin >> ss;
        cout << "������: " << endl;
        if (ss > 0 && ss < 20)
        {
           
            for (pj = y; pj < y + ss; pj++)
            {
                cin >> *pj;
                
            }
            cout << *pj << " ";
            pn = &n;
            pk = &k;

            while (i < *pn && j < *pk) {
                if (x[i] == y[j]) {
                    j++;
                }
                i++;
            }

            if (j == *pk) {
                cout << "\n������ ������������������ �������� ���������������������� ������" << endl;
            }
            else {
                cout << "\n������ ������������������ �� �������� ���������������������� ������" << endl;
            }
        }
    }
    else {
        cout << "������ ������������ ������";
    }

    return 0;
}
