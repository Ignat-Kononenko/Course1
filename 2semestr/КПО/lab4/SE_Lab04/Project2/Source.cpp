#include <iostream>
#include <string>

using namespace std;

// ���������� ����� ������ ��� �������� �������������
typedef double Area;
typedef int NumRooms;        // ���������� ����� ������
typedef int BuildYear;       // ��� ���������
typedef int Floor;           // ����
typedef bool HasKitchen;
typedef bool HasBathroom;
typedef bool HasToilet;      // ������� �������
typedef bool HasBasement;    // ������� �������
typedef bool HasBalcony;     // ������� �������


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

// ���������� ��������� == ��� ��������� ���� ������� �� ����������
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

// ���������� ��������� != ��� ��������� ���� ������� �� ���������� ���� ��������
bool operator!=(const Apartment& apt1, const Apartment& apt2) {
    return !(apt1 == apt2);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ������, ��� �������� ���������
    Apartment apt1 = { 80.5, 3, 1990, 5, true, true, true, false, true };
    Apartment apt2 = { 80.5, 3, 1990, 5, true, true, true, false, true };

    // �������� ��������� ==
    if (apt1 == apt2) {
        cout << "������ 1(==): �������� ���������" << endl;
    }
    else {
        cout << "������ 1(==): �������� �����������" << endl;
    }

    // �������� ��������� !=
    if (apt1 != apt2) {
        cout << "������ 1(!=): �������� �����������" << endl;
    }
    else {
        cout << "������ 1(!=): �������� ���������" << endl;
    }

    // ������, ��� �������� �� ���������
    Apartment apt3 = { 75.0, 2, 1985, 3, true, true, true, true, false };
    Apartment apt4 = { 80.5, 3, 1990, 5, true, true, true, false, true };

    // �������� ��������� ==
    if (apt3 == apt4) {
        cout << "������ 2(==): �������� ���������" << endl;
    }
    else {
        cout << "������ 2(==): �������� �����������" << endl;
    }

    // �������� ��������� !=
    if (apt3 != apt4) {
        cout << "������ 2(!=): �������� �����������" << endl;
    }
    else {
        cout << "������ 2(!=): �������� ���������" << endl;
    }

    return 0;
}
