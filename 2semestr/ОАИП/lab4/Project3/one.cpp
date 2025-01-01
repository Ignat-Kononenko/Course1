
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
        printf("\n1. ���� ���������� � ������\n");
        printf("2. ����� ���������� � �������\n");
        printf("3. �������� ���������� � ������\n");
        printf("4. ����� ���������� � ������\n");
        printf("5. ������ ���������� � ����\n");
        printf("6. ������ ���������� �� �����\n");
        printf("0. �����\n");
        printf("�������� ��������: ");
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
            printf("��������� ���������.\n");
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    } while (choice != 0);
}

void inputItem() {
    if (num_items < MAX_ITEMS) {
        int error = 0;
        struct Item new_item;
        printf("������� �������� ������ �������: "); getchar();
        cin.getline(new_item.client_name, MAX_NAME_LENGTH);
        printf("������� ������������ ������: ");
        cin.getline(new_item.item_name, MAX_NAME_LENGTH);
        do
        {
            error = 0;
            printf("������� ��������� ���������: ");
            scanf_s("%f", &new_item.estimated_value); cin.ignore();
            if (new_item.estimated_value < 0) {
                cout << "�������� ������ �� ������������� �������" << endl;
                error = 1;
            }
        } while (error);
        do
        {
            error = 0;
            printf("������� �����, �������� ��� �����: ");
            scanf_s("%f", &new_item.loan_amount); cin.ignore();
            if (new_item.loan_amount < 0) {
                cout << "�������� ������ �� ������������� �������" << endl;
                error = 1;
            }
        } while (error);
        do
        {
            error = 0;
            printf("������� ���� ����� � ������� ��������: ");
            cin.getline(new_item.date_received, MAX_NAME_LENGTH);
            if (strlen(new_item.date_received) != 8) {
                cout << "�������� ������ �� ������������� �������" << endl;
                error = 1;
            }
            for (unsigned int i = 0; i < strlen(new_item.date_received); i++)
            {
                if (new_item.date_received[i] < '0' || new_item.date_received[i] > '9') {
                    cout << "�������� ������ �������� �������" << endl;
                    error = 1;
                }
            }
            if (!error) {
                string days(new_item.date_received, 0, 2), months(new_item.date_received, 2, 2), years(new_item.date_received, 4, 4);
                int Ndays = stoi(days), Nmonths = stoi(months), Nyears = stoi(years);
                if (Ndays > 31 ||  Ndays < 1 || Nmonths > 12 || Nmonths < 1 || Nyears < 0 || (Nmonths == 2 && Ndays > 29 && Nyears % 4 == 0) || (Nmonths == 2 && Ndays > 28 && Nyears % 4 != 0)) {
                    cout << "������������ �������� ������" << endl;
                    error = 1;
                }
            }
        } while (error);
        do
        {
            error = 0;
            printf("������� ���� �������� (� ����): ");
            scanf_s("%d", &new_item.storage_period); cin.ignore();
            if (new_item.storage_period < 0) {
                cout << "�������� ������ �� ������������� �������" << endl;
                error = 1;
            }
        } while (error);

        items[num_items] = new_item;
        num_items++;
    }
    else {
        printf("���������� ������������ ���������� �������.\n");
    }
}

void displayItems() {
    if (num_items == 0) {
        printf("��� ���������� � �������.\n");
    }
    else {
        for (int i = 0; i < num_items; i++) {
            printf("����� %d:\n", i + 1);
            printf("�������� ������ �������: %s\n", items[i].client_name);
            printf("������������ ������: %s\n", items[i].item_name);
            printf("��������� ���������: %.2f\n", items[i].estimated_value);
            printf("�����, �������� ��� �����: %.2f\n", items[i].loan_amount);
            printf("���� �����: %s\n", items[i].date_received);
            printf("���� ��������: %d ����\n", items[i].storage_period);
        }
    }
}

void deleteItem() {
    if (num_items == 0) {
        printf("��� ���������� � ������� ��� ��������.\n");
    }
    else {
        int index, found = 0;
        char delete_name[MAX_NAME_LENGTH];
        printf("������� ������������ ������ ��� ��������: "); getchar();
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
            printf("�������� ����� ������.\n");
        }
        else {
            for (int i = index; i < num_items - 1; i++) {
                items[i] = items[i + 1];
            }
            num_items--;
            printf("���������� � ������ �������.\n");
        }
    }
}


void searchItem() {
    if (num_items == 0) {
        printf("��� ���������� � ������� ��� ������.\n");
    }
    else {
        char search_name[MAX_NAME_LENGTH];
        printf("������� ������������ ������ ��� ������: "); getchar();
        cin.getline(search_name, MAX_NAME_LENGTH);

        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(items[i].item_name, search_name) == 0) {
                printf("����� ������:\n");
                printf("�������� ������ �������: %s\n", items[i].client_name);
                printf("������������ ������: %s\n", items[i].item_name);
                printf("��������� ���������: %.2f\n", items[i].estimated_value);
                printf("�����, �������� ��� �����: %.2f\n", items[i].loan_amount);
                printf("���� �����: %s\n", items[i].date_received);
                printf("���� ��������: %d ����\n", items[i].storage_period);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("����� �� ������.\n");
        }
    }
}


void writeToFile() {
    ofstream file("items.txt");
    if (!file.is_open()) {
        printf("������ �������� �����.\n");
    }
    else {
        for (int i = 0; i < num_items; i++) {
            if (i != 0) file << endl << items[i].client_name << endl << items[i].item_name << endl << items[i].estimated_value << endl << items[i].loan_amount << endl << items[i].date_received << endl << items[i].storage_period;
            else file << items[i].client_name << endl << items[i].item_name << endl << items[i].estimated_value << endl << items[i].loan_amount << endl << items[i].date_received << endl << items[i].storage_period;
        }
        file.close();
        printf("���������� ������� �������� � ����.\n");
    }
}

void readFromFile() {
    ifstream file("items.txt");
    if (!file.is_open()) {
        printf("������ �������� �����.\n");
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
        printf("���������� ������� ��������� �� �����.\n");
    }
}