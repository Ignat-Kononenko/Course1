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

void insert(list*&, int); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
float del(list*&, int);   //������� ��������, ���������� ����� ������ � ������, ������� ��������� 
int IsEmpty(list*);         //�������, ������� ���������, ���� �� ������
void printList(list*);      //������� ������
void menu(void);     //�������, ������������ ����
void sum7(list*);  //������� �������� ����� �����, ������� 7  
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
    menu();    // ������� ���� 
    cout << " ? ";
    cin >> choice;
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:  	cout << "������� ����� "; // �������� ����� � ������
            cin.ignore();
            getline(cin, value);

            
            //char c : value
            for (int i = 0; i < value.length(); i++) {
                if (value[i] == '-') {

                

                    if (value.length() == 1) {
                        cout << "�� ����� �����������" << endl;
                        exit(0);
                        break;
                    }
                    


                    values = +1;


                }


                else if ((value[i] > '9') || (value[i] < '0')) {
                    cout << "�� ����� �����������" << endl;
                    exit(0);
                    break;
                }
            }
            if (values > 1) {
                cout << "�� ����� �����������" << endl;
                exit(0);
                break;
            }


            value2 = stoi(value);

            insert(first, value2);

            break;
        case 2:   if (!IsEmpty(first)) // ������� ����� �� ������
        {
            cout << "������� ��������� ����� ";
            cin.ignore();
            getline(cin, v);

            for (int i = 0; i < v.length(); i++) {
                if (v[i] == '-') {

                 

                    if (v.length() == 1) {
                        cout << "�� ����� �����������" << endl;
                        exit(0);
                        break;
                    }

                }
                else if ((v[i] > '9') || (v[i] < '0')) {
                    cout << "�� ����� �����������" << endl;
                    exit(0);
                    break;
                }
            }

            val = stoi(v);



            if (del(first, val))
            {
                cout << "������� ����� " << val << endl;
                printList(first);
            }
            else
                cout << "����� �� �������" << endl;
        }
              else
            cout << "������ ����" << endl;
            break;
        case 3:   sum7(first);	// ���������� �����	
            break;
        case 4:
            cout << "������� ����� ";
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

        default:  cout << "������������ �����" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "�����" << endl;
    return 0;
}

void menu(void)  //����� ���� 
{
    cout << "�������� �����:" << endl;
    cout << " 1 - ���� �����" << endl;
    cout << " 2 - �������� �����" << endl;
    cout << " 3 - ���������� ����� ������ ���� ������������� ����������� ��������� �����" << endl;
    cout << " 4 - ����� ��������" << endl;
    cout << " 5 - ����� ������" << endl;
    cout << " 6 - ������ � ����" << endl;
    cout << " 7 - ���������� �� �����" << endl;
    cout << " 8 - �����" << endl;
}

void insert(list*& p, int value) //���������� ����� value � ������ 
{
    list* newP = new list;

    if (newP != NULL)     //���� �� �����?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "�������� ���������� �� ���������" << endl;
}

float del(list*& p, int value)  // �������� ����� 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // ����������� ���� 
        delete temp;      //���������� ������������� ���� 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // ������� � ���������� 
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

int IsEmpty(list* p) //������  ������? (1-��, 0-���) 
{
    return p == NULL;
}

void printList(list* p)  //����� ������ 
{
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sum7(list* p)  // ������� ����� ������ ���� ������������� ����������� ���������  
{
    float sm = 0;
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0 && (p->number / 10)> -10 && (p->number / 10) < 0)
                sm = sm + (p->number);

            p = p->next;
        }
        if (sm == 0) {
            cout << "������������� ����������� �������� ����� �� �������" << endl;
        }
        else {
            cout << "����� = " << sm << endl;
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
        cout << "\n ������ �������� �����";
        exit(1);
    }
    while (temp)
    {
        frm << temp->number << endl; // ���������� ������ � ���� ���������
        temp = temp->next;
    }
    frm.close();
    cout << "������ ������� � ���� mList.txt\n";
}

void fromFile(list*& p)          //���������� �� �����
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* first = nullptr;
    int data;

    ifstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
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
    cout << "\n������ ������ �� ����� mList.txt\n";
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
        cout << "����� �������" << endl;
    }
    else {
        cout << "�� �������" << endl;
    }
}