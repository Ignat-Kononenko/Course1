#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int i = 0, j = 0,sz,ss, x[120], y[120], * pn, * pk, * ph, * pj;

    cout << "Введите число массива(N<20) " << endl;
    cin >> sz;
    if (sz > 0 && sz < 20)
    {
        cout << "введите массив" << endl;

        for (ph = x; ph < x + sz; ph++) {
            cin >> *ph;

        }
        cout << "Введите число массива(N<20) " << endl;
        cin >> ss;
        if (ss > 0 && ss < 20)
        {
            cout << "\nвведите второй массив" << endl;

            for (pj = y; pj < y + ss; pj++) {
                cin >> *pj;

            }
            pn = &sz;
            pk = &ss;

            while (i < *pn && j < *pk) {
                if (x[i] == y[j]) {
                    j++;
                }
                i++;
            }

            if (j == *pk) {
                cout << "\nВторая последовательность является подпоследовательностью первой" << endl;
            }
            else {
                cout << "\nВторая последовательность не является подпоследовательностью первой" << endl;
            }
        }
        else {
            cout << "введен недопустимый размер";
        }
    }
    else {
        cout << "введен недопустимый размер";
    }
    return 0;
}
