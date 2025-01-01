#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>



using namespace std;
struct list
{
    int number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum7(list*);  //функция подсчета суммы чисел, больших 7  
void toFile(list*& p);
void fromFile(list*& p);
void search(list*&, int);

long int value2;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    string value, v;
    int val;
    int values = 0;
    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin.ignore();
            getline(cin, value);

            
            //char c : value
            for (int i = 0; i < value.length(); i++) {
                if (value[i] == '-') {

                

                    if (value.length() == 1) {
                        cout << "вы ввели неправильно" << endl;
                        exit(0);
                        break;
                    }
                    


                    values = +1;


                }


                else if ((value[i] > '9') || (value[i] < '0')) {
                    cout << "вы ввели неправильно" << endl;
                    exit(0);
                    break;
                }
            }
            if (values > 1) {
                cout << "вы ввели неправильно" << endl;
                exit(0);
                break;
            }


            value2 = stoi(value);

            insert(first, value2);

            break;
        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin.ignore();
            getline(cin, v);

            for (int i = 0; i < v.length(); i++) {
                if (v[i] == '-') {

                 

                    if (v.length() == 1) {
                        cout << "вы ввели неправильно" << endl;
                        exit(0);
                        break;
                    }

                }
                else if ((v[i] > '9') || (v[i] < '0')) {
                    cout << "вы ввели неправильно" << endl;
                    exit(0);
                    break;
                }
            }

            val = stoi(v);



            if (del(first, val))
            {
                cout << "Удалено число " << val << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sum7(first);	// вычисление суммы	
            break;
        case 4:
            cout << "Введите число ";
            int val;
            cin >> val;
            search(first, val);
            break;
        case 5: printList(first);
            break;
        case 6: toFile(first);
            break;
        case 7: fromFile(first);
            break;

        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы целого типа отрицательных двухзначных элементов чисел" << endl;
    cout << " 4 - Поиск элемента" << endl;
    cout << " 5 - Вывод списка" << endl;
    cout << " 6 - Запись в файл" << endl;
    cout << " 7 - Считывание из файла" << endl;
    cout << " 8 - Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;

    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}

void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum7(list* p)  // Подсчет суммы целого типа отрицательных двухзначных элементов  
{
    float sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0 && (p->number / 10)> -10 && (p->number / 10) < 0)
                sm = sm + (p->number);

            p = p->next;
        }
        if (sm == 0) {
            cout << "отрицательные двухзначные элементы чисел не найдены" << endl;
        }
        else {
            cout << "Сумма = " << sm << endl;
        }
    }
}

void toFile(list*& p)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* temp = p;
    list buf;
    ofstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        frm << temp->number << endl; // Записываем данные в файл построчно
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* first = nullptr;
    int data;

    ifstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (frm >> data)
    {
        insert(first, data);
        cout << "-->" << data;
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    value2 = data;
    cout << "\nСписок считан из файла mList.txt\n";
}

void search(list*& p, int value) {

    list* current = p;
    bool found = false;

    while (current != nullptr) {
        if (current->number == value) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found) {
        cout << "Число найдено" << endl;
    }
    else {
        cout << "Не найдено" << endl;
    }
}