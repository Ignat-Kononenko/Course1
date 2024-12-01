#include <iostream>

#include <ctime>

using namespace std;

int main()

{

    setlocale(LC_ALL, "rus");
    srand(time(0));

    int n, m, i, j, k, max, sum, proizv;

    cout << "Введите количество строк: ";

    cin >> n;

    cout << "Введите количество столбцов: ";

    cin >> m;

    int** a = new int* [n];

    for (i = 0; i < n; i++)

        a[i] = new int[m];

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)

            a[i][j] = rand() % 10 - 5;

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < m; j++)

            cout << a[i][j] << "\t";

        cout << endl;

    }

    cout << endl;

    for (i = 0; i < n; i++)

    {

        proizv = 1;

        for (j = 0; j < m; j++)

            if (a[i][j] >= 0)

                proizv *= a[i][j];

        cout << "Произведение элементов " << i + 1 << " строки: " << proizv << endl;

    }

    cout << endl;

    max = 0;

    for (k = 1; k < n; k++)

    {

        sum = 0;

        for (i = 0; i < n - k; i++)

            sum += a[i][i + k];

        if (sum > max)

            max = sum;

    }

    for (k = 1; k < m; k++)

    {

        sum = 0;

        for (j = 0; j < m - k; j++)

            sum += a[j + k][j];

        if (sum > max)

            max = sum;

    }

    cout << "Максимум среди сумм диагоналей, параллельных главной диагонали матрицы: " << max << endl;

    for (i = 0; i < n; i++)

        delete[] a[i];

    delete[] a;

    return 0;

}