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

Tree* makeTree(Tree* Root);       // Создание дерева
Tree* list(int i, char* s);       // Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  // Добавление нового элемента
Tree* search(Tree* n, int key);   // Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); // Удаление элемента по ключу
int view(Tree* t, int level);     // Вывод дерева 
int count(Tree* t, char letter);  // Подсчет количества слов
bool delAll(Tree* t);             // Очистка дерева

int c = 0;         // Количество слов
Tree* Root = NULL; // Указатель на корень


void collectLevelOrder(Tree* root, int level, vector<pair<int, char*>>& levelElements) {
    // Базовый случай: если узел пустой, не делаем ничего
    if (root == nullptr) {
        return;
    }

    // Если текущий уровень равен 1, добавляем содержимое текущего узла в массив для этого уровня
    if (level == 1) {
        levelElements.push_back(make_pair(root->key, root->text));
    }
    // Если текущий уровень больше 1, рекурсивно вызываем эту функцию для левого и правого поддеревьев
    else if (level > 1) {
        collectLevelOrder(root->Left, level - 1, levelElements);
        collectLevelOrder(root->Right, level - 1, levelElements);
    }
}

int height(Tree* root) { // вычисляет максимальную длинну дерева
    if (root == nullptr) {
        return 0;
    }
    else {
        // Рекурсивно находим высоту левого и правого поддеревьев
        int leftHeight = height(root->Left);
        int rightHeight = height(root->Right);

        // Высота дерева - это максимальная из высот левого и правого поддеревьев, плюс 1 (текущий узел)
        return max(leftHeight, rightHeight) + 1;
    }
}

void printLevelOrder(Tree* root) {
    // Определяем высоту дерева
    int h = height(root);

    // Для каждого уровня от 1 до высоты дерева выводим элементы этого уровня
    for (int i = 1; i <= h; i++) {
        // Создаем массив для элементов текущего уровня
        vector<pair<int, char*>> levelElements;
        // Собираем все элементы текущего уровня в массив
        collectLevelOrder(root, i, levelElements);
        // Выводим все элементы текущего уровня вместе
        cout << "Level " << i - 1 << ": ";
        for (const auto& elem : levelElements) {
            cout << elem.first << " " << elem.second << " ";
        }
        cout << endl;
    }
}

Tree* makeTree(Tree* Root) // Создание дерева
{
    int key; char s[25];
    cout << "Конец ввода - отрицательное число\n\n";
    if (Root == NULL)    // если дерево не создано
    {
        while (true) {
            cout << "\nВведите ключ: ";
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
                cout << "Ошибка: ключ должен быть целым числом.\n";
                continue;
            }

            key = stoi(keyInput);
            break;

        }

        while (true) {
            cout << "Введите слово: ";
            cin >> s;

            // Проверка, содержит ли строка s только буквы и дефисы
            bool validWord = true;
            for (int i = 0; s[i] != '\0'; i++) {
                if (!isalpha(s[i]) && s[i] != '-') {
                    validWord = false;
                    break;
                }
            }

            if (!validWord) {
                cout << "Ошибка: слово должно содержать только буквы и дефисы.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            list(key, s);
            break;
        }

        Root = list(key, s);    // установка указателя на корень
    }

    while (true) {
        while (true) {
            cout << "\nВведите ключ: ";
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
                cout << "Ошибка: ключ должен быть целым числом.\n";
                continue;
            }

            key = stoi(keyInput);
            if (key < 0) break;
            break;

        }
        if (key < 0) break;
        while (true) {
            cout << "Введите слово: ";
            cin >> s;

            // Проверка, содержит ли строка s только буквы и дефисы
            bool validWord = true;
            for (int i = 0; s[i] != '\0'; i++) {
                if (!isalpha(s[i]) && s[i] != '-') {
                    validWord = false;
                    break;
                }
            }

            if (!validWord) {
                cout << "Ошибка: слово должно содержать только буквы и дефисы.\n";
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

Tree* list(int i, char* s) // Создание нового элемента
{
    Tree* t = new Tree;
    t->key = i;
    for (i = 0; i < 25; i++)
        *((t->text) + i) = *(s + i);
    t->Left = t->Right = NULL;
    return t;
}

Tree* insertElem(Tree* t, int key, char* s) // Добавление нового элемента
{
    Tree* Prev = NULL;	      // Prev - элемент перед текущим
    int find = 0;        // признак поиска
    while (t && !find)
    {
        Prev = t;
        if (key == t->key)
            find = 1;	   // ключи должны быть уникальны
        else
            if (key < t->key)
                t = t->Left;
            else
                t = t->Right;
    }
    if (!find)              // найдено место с адресом Prev
    {
        t = list(key, s);        // создается новый узел 
        if (Prev == nullptr) {
            t->key = key;
            strcpy_s(t->text, s);
        }
        else if (key < Prev->key)     // и присоединяется либо 
            Prev->Left = t;      // переход на левую ветвь,
        else
            Prev->Right = t;    // либо на правую 
    }
    return t;
}

Tree* delet(Tree* Root, int key) // Удаление элемента по ключу
{    // Del, Prev_Del - удаляемый элемент и его предыдущий;
    // R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
    Tree* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->key != key) // поиск элемента и его родителя 
    {
        Prev_Del = Del;
        if (Del->key > key)
            Del = Del->Left;
        else
            Del = Del->Right;
    }
    if (Del == NULL)              // элемент не найден
    {
        puts("\nНет такого ключа");
        return Root;
    }
    if (Del->Right == NULL)     // поиск элемента R для замены
        R = Del->Left;
    else
        if (Del->Left == NULL)
            R = Del->Right;
        else
        {
            Prev_R = Del;      // поиск самого правого элемента в левом поддереве
            R = Del->Left;
            while (R->Right != NULL)
            {
                Prev_R = R;
                R = R->Right;
            }
            if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
                R->Right = Del->Right;
            else
            {
                R->Right = Del->Right;
                Prev_R->Right = R->Left;
                R->Left = Prev_R;
            }
        }
    if (Del == Root) Root = R;    // удаление корня и замена его на R
    else
        // поддерево R присоединяется к родителю удаляемого узла
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R;  // на левую ветвь 
        else
            Prev_Del->Right = R;    // на правую ветвь
    int tmp = Del->key;
    cout << "\nУдален элемент с ключом " << tmp << endl;
    delete Del;
    return Root;
}

Tree* search(Tree* n, int key)  // Поиск элемента по ключу 
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
        cout << "Нет такого элемента\n";
    return rc;
}

int count(Tree* t, char letter) // Подсчет количества слов
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

int view(Tree* t, int level) // Вывод дерева 
{
    if (t)
    {
        view(t->Right, level + 1);    // вывод правого поддерева
        for (int i = 0; i < level; i++)
            cout << "      ";
        int tm = t->key;
        cout << tm << ' ';
        puts(t->text);
        view(t->Left, level + 1);    // вывод левого поддерева
        return 0;
    }
    return 1;
}

bool delAll(Tree* t) // Очистка дерева
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
        cout << "1 -	создание дерева\n";
        cout << "2 -	добавление элемента\n";
        cout << "3 -	поиск по ключу\n";
        cout << "4 -	удаление элемента\n";
        cout << "5 -	вывод дерева\n";
        cout << "6 -	подсчет количества букв\n";
        cout << "7 -	очистка дерева\n";
        cout << "8 -	вывод всех элементов дерева по уровням\n";
        cout << "0 -	выход\n";
        cout << "ваш выбор?\n";
        char input[100];
        cin >> input;
        if (strlen(input) != 1 || !isdigit(input[0])) {
            cout << "Ошибка: введите одну цифру от 0 до 8.\n";
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
                   cout << "\nВведите ключ: ";
                   cin >> key;
                   cout << "Введите слово: ";
                   cin >> s;
                   insertElem(Root, key, s);
                   break;
               }*/
        case 2: {
            while (true) {
                cout << "\nВведите ключ: ";
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
                    cout << "Ошибка: ключ должен быть целым числом.\n";
                    continue;
                }

                key = stoi(keyInput);
                break;
            }

            while (true) {

                cout << "Введите слово: ";
                cin >> s;

                // Проверка, содержит ли строка s только буквы и дефисы
                bool validWord = true;
                for (int i = 0; s[i] != '\0'; i++) {
                    if (((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z')) && s[i] != '-') {
                        validWord = false;
                        break;
                    }
                }

                if (!validWord) {
                    cout << "Ошибка: слово должно содержать только буквы и дефисы.\n";
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
                cout << "\nВведите ключ: ";
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
                    cout << "Ошибка: ключ должен быть целым числом.\n";
                    continue;
                }

                key = stoi(keyInput);
                break;
            }

            rc = search(Root, key);
            if (rc) {
                cout << "Найденное слово= ";
                puts(rc->text);
            }
            break;
        }
        case 4: {
            while (true) {
                cout << "\nВведите удаляемый ключ: ";
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
                    cout << "Ошибка: ключ должен быть целым числом.\n";
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
                    cout << "Дерево повернуто на 90 град. вправо" << endl;
                    view(Root, 0);
                }
            }
            else cout << "Дерево пустое\n";
            break;
        }
        case 6: {

            while (true) {

                cout << "\nВведите букву: ";
                cin >> letter;

                if (letter > 'A' && letter < 'Z' || letter > 'a' && letter < 'z') {
                    break;
                }
                else {
                    cout << "Ошибка: это должна быть буква.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
            }
            n = count(Root, letter);
            cout << "Количество слов, начинающихся с буквы " << letter;
            cout << " равно " << n << endl;
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
