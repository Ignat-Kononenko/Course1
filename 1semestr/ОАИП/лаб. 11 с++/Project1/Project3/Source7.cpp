
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int N = 20;
    int x[N],k,sz;
    cout << "Введите число массива(N<20) " << endl;
    cin >> sz;
    cout << "Массив: " << endl;
    if (sz > 0 && sz < 20)
    {
        srand((unsigned)time(NULL));
        for (int j = 0; j < sz; j++)
        {
            x[j] = rand() % 5;
            cout << x[j] << " ";
        }




        cout << "\nвведите k " << endl;
        cin >> k;
        for (int i = 0; i < sz; i++) {
            if (k > x[i]) {
                cout << "k больше элемента массива под номером " << i  << endl;
            }
            else if (k < x[i]) {
                cout << "k меньше элемента массива под номером " << i  << endl;
            }
            else {
                cout << "k равен элементу массива под номером " << i  << endl;
            }

        }

    }
    else {
        cout << "введен недопустимый размер";
    }

    return 0;
}

