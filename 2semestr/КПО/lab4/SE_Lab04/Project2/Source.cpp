#include <iostream>
#include <string>

using namespace std;

// Псевдонимы типов данных для удобства использования
typedef double Area;
typedef int NumRooms;        // Количество жилых комнат
typedef int BuildYear;       // Год постройки
typedef int Floor;           // Этаж
typedef bool HasKitchen;
typedef bool HasBathroom;
typedef bool HasToilet;      // Наличие туалета
typedef bool HasBasement;    // Наличие подвала
typedef bool HasBalcony;     // Наличие балкона


struct Apartment {
    Area area;
    NumRooms numRooms;
    BuildYear buildYear;
    Floor floor;
    HasKitchen kitchen;
    HasBathroom bathroom;
    HasToilet toilet;
    HasBasement basement;
    HasBalcony balcony;
};

// Перегрузка оператора == для сравнения двух квартир по параметрам
bool operator==(const Apartment& apt1, const Apartment& apt2) {
    return apt1.area == apt2.area &&
        apt1.numRooms == apt2.numRooms &&
        apt1.buildYear == apt2.buildYear &&
        apt1.floor == apt2.floor &&
        apt1.kitchen == apt2.kitchen &&
        apt1.bathroom == apt2.bathroom &&
        apt1.toilet == apt2.toilet &&
        apt1.basement == apt2.basement &&
        apt1.balcony == apt2.balcony;
}

// Перегрузка оператора != для сравнения двух квартир по параметрам всей квартиры
bool operator!=(const Apartment& apt1, const Apartment& apt2) {
    return !(apt1 == apt2);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Пример, где квартиры идентичны
    Apartment apt1 = { 80.5, 3, 1990, 5, true, true, true, false, true };
    Apartment apt2 = { 80.5, 3, 1990, 5, true, true, true, false, true };

    // Проверка оператора ==
    if (apt1 == apt2) {
        cout << "Пример 1(==): Квартиры идентичны" << endl;
    }
    else {
        cout << "Пример 1(==): Квартиры различаются" << endl;
    }

    // Проверка оператора !=
    if (apt1 != apt2) {
        cout << "Пример 1(!=): Квартиры различаются" << endl;
    }
    else {
        cout << "Пример 1(!=): Квартиры идентичны" << endl;
    }

    // Пример, где квартиры не идентичны
    Apartment apt3 = { 75.0, 2, 1985, 3, true, true, true, true, false };
    Apartment apt4 = { 80.5, 3, 1990, 5, true, true, true, false, true };

    // Проверка оператора ==
    if (apt3 == apt4) {
        cout << "Пример 2(==): Квартиры идентичны" << endl;
    }
    else {
        cout << "Пример 2(==): Квартиры различаются" << endl;
    }

    // Проверка оператора !=
    if (apt3 != apt4) {
        cout << "Пример 2(!=): Квартиры различаются" << endl;
    }
    else {
        cout << "Пример 2(!=): Квартиры идентичны" << endl;
    }

    return 0;
}
