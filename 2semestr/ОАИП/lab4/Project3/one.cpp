
#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100

struct Item {
    char client_name[MAX_NAME_LENGTH];
    char item_name[MAX_NAME_LENGTH];
    float estimated_value;
    float loan_amount;
    char date_received[MAX_NAME_LENGTH];
    int storage_period;
};

struct Item items[MAX_ITEMS];
int num_items = 0;

void inputItem();
void displayItems();
void deleteItem();
void searchItem();
void writeToFile();
void readFromFile();

void main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        printf("\n1. Ввод информации о товаре\n");
        printf("2. Вывод информации о товарах\n");
        printf("3. Удаление информации о товаре\n");
        printf("4. Поиск информации о товаре\n");
        printf("5. Запись информации в файл\n");
        printf("6. Чтение информации из файла\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            inputItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            deleteItem();
            break;
        case 4:
            searchItem();
            break;
        case 5:
            writeToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            printf("Программа завершена.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);
}

void inputItem() {
    if (num_items < MAX_ITEMS) {
        int error = 0;
        struct Item new_item;
        printf("Введите анкетные данные клиента: "); getchar();
        cin.getline(new_item.client_name, MAX_NAME_LENGTH);
        printf("Введите наименование товара: ");
        cin.getline(new_item.item_name, MAX_NAME_LENGTH);
        do
        {
            error = 0;
            printf("Введите оценочную стоимость: ");
            scanf_s("%f", &new_item.estimated_value); cin.ignore();
            if (new_item.estimated_value < 0) {
                cout << "Введённые данные не соответствуют формату" << endl;
                error = 1;
            }
        } while (error);
        do
        {
            error = 0;
            printf("Введите сумму, выданную под залог: ");
            scanf_s("%f", &new_item.loan_amount); cin.ignore();
            if (new_item.loan_amount < 0) {
                cout << "Введённые данные не соответствуют формату" << endl;
                error = 1;
            }
        } while (error);
        do
        {
            error = 0;
            printf("Введите дату сдачи в формате ДДММГГГГ: ");
            cin.getline(new_item.date_received, MAX_NAME_LENGTH);
            if (strlen(new_item.date_received) != 8) {
                cout << "Введённые данные не соответствуют формату" << endl;
                error = 1;
            }
            for (unsigned int i = 0; i < strlen(new_item.date_received); i++)
            {
                if (new_item.date_received[i] < '0' || new_item.date_received[i] > '9') {
                    cout << "Введённые данные содержат символы" << endl;
                    error = 1;
                }
            }
            if (!error) {
                string days(new_item.date_received, 0, 2), months(new_item.date_received, 2, 2), years(new_item.date_received, 4, 4);
                int Ndays = stoi(days), Nmonths = stoi(months), Nyears = stoi(years);
                if (Ndays > 31 ||  Ndays < 1 || Nmonths > 12 || Nmonths < 1 || Nyears < 0 || (Nmonths == 2 && Ndays > 29 && Nyears % 4 == 0) || (Nmonths == 2 && Ndays > 28 && Nyears % 4 != 0)) {
                    cout << "Некорректные введённые данные" << endl;
                    error = 1;
                }
            }
        } while (error);
        do
        {
            error = 0;
            printf("Введите срок хранения (в днях): ");
            scanf_s("%d", &new_item.storage_period); cin.ignore();
            if (new_item.storage_period < 0) {
                cout << "Введённые данные не соответствуют формату" << endl;
                error = 1;
            }
        } while (error);

        items[num_items] = new_item;
        num_items++;
    }
    else {
        printf("Достигнуто максимальное количество товаров.\n");
    }
}

void displayItems() {
    if (num_items == 0) {
        printf("Нет информации о товарах.\n");
    }
    else {
        for (int i = 0; i < num_items; i++) {
            printf("Товар %d:\n", i + 1);
            printf("Анкетные данные клиента: %s\n", items[i].client_name);
            printf("Наименование товара: %s\n", items[i].item_name);
            printf("Оценочная стоимость: %.2f\n", items[i].estimated_value);
            printf("Сумма, выданная под залог: %.2f\n", items[i].loan_amount);
            printf("Дата сдачи: %s\n", items[i].date_received);
            printf("Срок хранения: %d дней\n", items[i].storage_period);
        }
    }
}

void deleteItem() {
    if (num_items == 0) {
        printf("Нет информации о товарах для удаления.\n");
    }
    else {
        int index, found = 0;
        char delete_name[MAX_NAME_LENGTH];
        printf("Введите наименование товара для удаления: "); getchar();
        cin.getline(delete_name, MAX_NAME_LENGTH);
        for (int i = 0; i < num_items; i++)
        {
            if (strcmp(items[i].item_name, delete_name) == 0) {
                index = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Неверный номер товара.\n");
        }
        else {
            for (int i = index; i < num_items - 1; i++) {
                items[i] = items[i + 1];
            }
            num_items--;
            printf("Информация о товаре удалена.\n");
        }
    }
}


void searchItem() {
    if (num_items == 0) {
        printf("Нет информации о товарах для поиска.\n");
    }
    else {
        char search_name[MAX_NAME_LENGTH];
        printf("Введите наименование товара для поиска: "); getchar();
        cin.getline(search_name, MAX_NAME_LENGTH);

        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(items[i].item_name, search_name) == 0) {
                printf("Товар найден:\n");
                printf("Анкетные данные клиента: %s\n", items[i].client_name);
                printf("Наименование товара: %s\n", items[i].item_name);
                printf("Оценочная стоимость: %.2f\n", items[i].estimated_value);
                printf("Сумма, выданная под залог: %.2f\n", items[i].loan_amount);
                printf("Дата сдачи: %s\n", items[i].date_received);
                printf("Срок хранения: %d дней\n", items[i].storage_period);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Товар не найден.\n");
        }
    }
}


void writeToFile() {
    ofstream file("items.txt");
    if (!file.is_open()) {
        printf("Ошибка открытия файла.\n");
    }
    else {
        for (int i = 0; i < num_items; i++) {
            if (i != 0) file << endl << items[i].client_name << endl << items[i].item_name << endl << items[i].estimated_value << endl << items[i].loan_amount << endl << items[i].date_received << endl << items[i].storage_period;
            else file << items[i].client_name << endl << items[i].item_name << endl << items[i].estimated_value << endl << items[i].loan_amount << endl << items[i].date_received << endl << items[i].storage_period;
        }
        file.close();
        printf("Информация успешно записана в файл.\n");
    }
}

void readFromFile() {
    ifstream file("items.txt");
    if (!file.is_open()) {
        printf("Ошибка открытия файла.\n");
    }
    else {
        while (!file.eof()) {
            string str;
            getline(file, str); strcpy_s(items[num_items].client_name, str.c_str());
            getline(file, str); strcpy_s(items[num_items].item_name, str.c_str());
            getline(file, str); items[num_items].estimated_value = stof(str);
            getline(file, str); items[num_items].loan_amount = stof(str);
            getline(file, str); strcpy_s(items[num_items].date_received, str.c_str());
            getline(file, str); items[num_items].storage_period = stoi(str);
            num_items++;
        }
        file.close();
        printf("Информация успешно прочитана из файла.\n");
    }
}