#include <iostream>
#include <queue>
#include <vector>
#include <cctype> 
#include<string>
using namespace std;

struct Tree {
    int key;
    char text[25];
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       // �������� ������
Tree* list(int i, char* s);       // �������� ������ ��������
Tree* insertElem(Tree* Root, int key, char* s);  // ���������� ������ ��������
Tree* search(Tree* n, int key);   // ����� �������� �� ����� 
Tree* delet(Tree* Root, int key); // �������� �������� �� �����
int view(Tree* t, int level);     // ����� ������ 
int count(Tree* t, char letter);  // ������� ���������� ����
bool delAll(Tree* t);             // ������� ������

int c = 0;         // ���������� ����
Tree* Root = NULL; // ��������� �� ������


void collectLevelOrder(Tree* root, int level, vector<pair<int, char*>>& levelElements) {
    // ������� ������: ���� ���� ������, �� ������ ������
    if (root == nullptr) {
        return;
    }

    // ���� ������� ������� ����� 1, ��������� ���������� �������� ���� � ������ ��� ����� ������
    if (level == 1) {
        levelElements.push_back(make_pair(root->key, root->text));
    }
    // ���� ������� ������� ������ 1, ���������� �������� ��� ������� ��� ������ � ������� �����������
    else if (level > 1) {
        collectLevelOrder(root->Left, level - 1, levelElements);
        collectLevelOrder(root->Right, level - 1, levelElements);
    }
}

int height(Tree* root) { // ��������� ������������ ������ ������
    if (root == nullptr) {
        return 0;
    }
    else {
        // ���������� ������� ������ ������ � ������� �����������
        int leftHeight = height(root->Left);
        int rightHeight = height(root->Right);

        // ������ ������ - ��� ������������ �� ����� ������ � ������� �����������, ���� 1 (������� ����)
        return max(leftHeight, rightHeight) + 1;
    }
}

void printLevelOrder(Tree* root) {
    // ���������� ������ ������
    int h = height(root);

    // ��� ������� ������ �� 1 �� ������ ������ ������� �������� ����� ������
    for (int i = 1; i <= h; i++) {
        // ������� ������ ��� ��������� �������� ������
        vector<pair<int, char*>> levelElements;
        // �������� ��� �������� �������� ������ � ������
        collectLevelOrder(root, i, levelElements);
        // ������� ��� �������� �������� ������ ������
        cout << "Level " << i - 1 << ": ";
        for (const auto& elem : levelElements) {
            cout << elem.first << " " << elem.second << " ";
        }
        cout << endl;
    }
}

Tree* makeTree(Tree* Root) // �������� ������
{
    int key; char s[25];
    cout << "����� ����� - ������������� �����\n\n";
    if (Root == NULL)    // ���� ������ �� �������
    {
        while (true) {
            cout << "\n������� ����: ";
            string keyInput;
            cin >> keyInput;

            bool validKey = true;
            for (char c : keyInput) {
                if (!isdigit(c) && c != '-') {
                    validKey = false;
                    break;
                }
            }

            if (!validKey) {
                cout << "������: ���� ������ ���� ����� ������.\n";
                continue;
            }

            key = stoi(keyInput);
            break;

        }

        while (true) {
            cout << "������� �����: ";
            cin >> s;

            // ��������, �������� �� ������ s ������ ����� � ������
            bool validWord = true;
            for (int i = 0; s[i] != '\0'; i++) {
                if (!isalpha(s[i]) && s[i] != '-') {
                    validWord = false;
                    break;
                }
            }

            if (!validWord) {
                cout << "������: ����� ������ ��������� ������ ����� � ������.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            list(key, s);
            break;
        }

        Root = list(key, s);    // ��������� ��������� �� ������
    }

    while (true) {
        while (true) {
            cout << "\n������� ����: ";
            string keyInput;
            cin >> keyInput;

            bool validKey = true;
            for (char c : keyInput) {
                if (!isdigit(c) && c != '-') {
                    validKey = false;
                    break;
                }
            }

            if (!validKey) {
                cout << "������: ���� ������ ���� ����� ������.\n";
                continue;
            }

            key = stoi(keyInput);
            if (key < 0) break;
            break;

        }
        if (key < 0) break;
        while (true) {
            cout << "������� �����: ";
            cin >> s;

            // ��������, �������� �� ������ s ������ ����� � ������
            bool validWord = true;
            for (int i = 0; s[i] != '\0'; i++) {
                if (!isalpha(s[i]) && s[i] != '-') {
                    validWord = false;
                    break;
                }
            }

            if (!validWord) {
                cout << "������: ����� ������ ��������� ������ ����� � ������.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            insertElem(Root, key, s);
            break;
        }
    }
    return Root;
}

Tree* list(int i, char* s) // �������� ������ ��������
{
    Tree* t = new Tree;
    t->key = i;
    for (i = 0; i < 25; i++)
        *((t->text) + i) = *(s + i);
    t->Left = t->Right = NULL;
    return t;
}

Tree* insertElem(Tree* t, int key, char* s) // ���������� ������ ��������
{
    Tree* Prev = NULL;	      // Prev - ������� ����� �������
    int find = 0;        // ������� ������
    while (t && !find)
    {
        Prev = t;
        if (key == t->key)
            find = 1;	   // ����� ������ ���� ���������
        else
            if (key < t->key)
                t = t->Left;
            else
                t = t->Right;
    }
    if (!find)              // ������� ����� � ������� Prev
    {
        t = list(key, s);        // ��������� ����� ���� 
        if (Prev == nullptr) {
            t->key = key;
            strcpy_s(t->text, s);
        }
        else if (key < Prev->key)     // � �������������� ���� 
            Prev->Left = t;      // ������� �� ����� �����,
        else
            Prev->Right = t;    // ���� �� ������ 
    }
    return t;
}

Tree* delet(Tree* Root, int key) // �������� �������� �� �����
{    // Del, Prev_Del - ��������� ������� � ��� ����������;
    // R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
    Tree* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->key != key) // ����� �������� � ��� �������� 
    {
        Prev_Del = Del;
        if (Del->key > key)
            Del = Del->Left;
        else
            Del = Del->Right;
    }
    if (Del == NULL)              // ������� �� ������
    {
        puts("\n��� ������ �����");
        return Root;
    }
    if (Del->Right == NULL)     // ����� �������� R ��� ������
        R = Del->Left;
    else
        if (Del->Left == NULL)
            R = Del->Right;
        else
        {
            Prev_R = Del;      // ����� ������ ������� �������� � ����� ���������
            R = Del->Left;
            while (R->Right != NULL)
            {
                Prev_R = R;
                R = R->Right;
            }
            if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
                R->Right = Del->Right;
            else
            {
                R->Right = Del->Right;
                Prev_R->Right = R->Left;
                R->Left = Prev_R;
            }
        }
    if (Del == Root) Root = R;    // �������� ����� � ������ ��� �� R
    else
        // ��������� R �������������� � �������� ���������� ����
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R;  // �� ����� ����� 
        else
            Prev_Del->Right = R;    // �� ������ �����
    int tmp = Del->key;
    cout << "\n������ ������� � ������ " << tmp << endl;
    delete Del;
    return Root;
}

Tree* search(Tree* n, int key)  // ����� �������� �� ����� 
{
    Tree* rc = n;
    if (rc != NULL)
    {
        if (key < (key, n->key))
            rc = search(n->Left, key);
        else
            if (key > (key, n->key))
                rc = search(n->Right, key);
    }
    else
        cout << "��� ������ ��������\n";
    return rc;
}

int count(Tree* t, char letter) // ������� ���������� ����
{
    if (t)
    {
        count(t->Right, letter);
        if (*(t->text) == letter)
            c++;
        count(t->Left, letter);
    }
    return c;
}

int view(Tree* t, int level) // ����� ������ 
{
    if (t)
    {
        view(t->Right, level + 1);    // ����� ������� ���������
        for (int i = 0; i < level; i++)
            cout << "      ";
        int tm = t->key;
        cout << tm << ' ';
        puts(t->text);
        view(t->Left, level + 1);    // ����� ������ ���������
        return 0;
    }
    return 1;
}

bool delAll(Tree* t) // ������� ������
{
    if (t != NULL)
    {
        delAll(t->Left);
        delAll(t->Right);
        delete t;
        return true;
    }
    return false;

}

int main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    Tree* rc; char s[25], letter;
    for (;;)
    {
        cout << "1 -	�������� ������\n";
        cout << "2 -	���������� ��������\n";
        cout << "3 -	����� �� �����\n";
        cout << "4 -	�������� ��������\n";
        cout << "5 -	����� ������\n";
        cout << "6 -	������� ���������� ����\n";
        cout << "7 -	������� ������\n";
        cout << "8 -	����� ���� ��������� ������ �� �������\n";
        cout << "0 -	�����\n";
        cout << "��� �����?\n";
        char input[100];
        cin >> input;
        if (strlen(input) != 1 || !isdigit(input[0])) {
            cout << "������: ������� ���� ����� �� 0 �� 8.\n";
            continue;
        }
        choice = input[0] - '0';
        cout << "\n";
        switch (choice)
        {
        case 1: {
            Root = makeTree(Root);
            break;
        }
              /* case 2: {
                   cout << "\n������� ����: ";
                   cin >> key;
                   cout << "������� �����: ";
                   cin >> s;
                   insertElem(Root, key, s);
                   break;
               }*/
        case 2: {
            while (true) {
                cout << "\n������� ����: ";
                string keyInput;
                cin >> keyInput;

                bool validKey = true;
                for (char c : keyInput) {
                    if (!isdigit(c)) {
                        validKey = false;
                        break;
                    }
                }

                if (!validKey) {
                    cout << "������: ���� ������ ���� ����� ������.\n";
                    continue;
                }

                key = stoi(keyInput);
                break;
            }

            while (true) {

                cout << "������� �����: ";
                cin >> s;

                // ��������, �������� �� ������ s ������ ����� � ������
                bool validWord = true;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z')) && s[i] != '-') {
                        validWord = false;
                        break;
                    }
                }

                if (!validWord) {
                    cout << "������: ����� ������ ��������� ������ ����� � ������.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                insertElem(Root, key, s);
                break;
            }
            break;
        }


        case 3: {
            while (true) {
                cout << "\n������� ����: ";
                string keyInput;
                cin >> keyInput;

                bool validKey = true;
                for (char c : keyInput) {
                    if (!isdigit(c)) {
                        validKey = false;
                        break;
                    }
                }

                if (!validKey) {
                    cout << "������: ���� ������ ���� ����� ������.\n";
                    continue;
                }

                key = stoi(keyInput);
                break;
            }

            rc = search(Root, key);
            if (rc) {
                cout << "��������� �����= ";
                puts(rc->text);
            }
            break;
        }
        case 4: {
            while (true) {
                cout << "\n������� ��������� ����: ";
                string keyInput;
                cin >> keyInput;

                bool validKey = true;
                for (char c : keyInput) {
                    if (!isdigit(c)) {
                        validKey = false;
                        break;
                    }
                }

                if (!validKey) {
                    cout << "������: ���� ������ ���� ����� ������.\n";
                    continue;
                }

                key = stoi(keyInput);
                break;
            }

            Root = delet(Root, key);
            break;
        }
        case 5: {
            if (Root != NULL || Root != nullptr) {
                if (Root->key >= 0)
                {
                    cout << "������ ��������� �� 90 ����. ������" << endl;
                    view(Root, 0);
                }
            }
            else cout << "������ ������\n";
            break;
        }
        case 6: {

            while (true) {

                cout << "\n������� �����: ";
                cin >> letter;

                if (letter > 'A' && letter < 'Z' || letter > 'a' && letter < 'z') {
                    break;
                }
                else {
                    cout << "������: ��� ������ ���� �����.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
            }
            n = count(Root, letter);
            cout << "���������� ����, ������������ � ����� " << letter;
            cout << " ����� " << n << endl;
            break;
        }
        case 7: {
            delAll(Root);
            Root = NULL;

            break;
        }
        case 8: {
            printLevelOrder(Root);
            break;
        }
        case 0: {
            exit(0);
        }
        }
    }
    return 0;
}
