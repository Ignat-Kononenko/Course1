#include<iostream>
#include<string>

using namespace std;

// ���������� ����� ������ ��� �������� �������������
typedef string fio;
typedef int age; 
typedef char sx;
typedef string specilization; 
typedef unsigned char course; 
typedef unsigned char group; 
typedef float avarage_score;
typedef unsigned char exam;


struct Student {
	fio name;
	age old;
	sx gen;
	specilization spec;
	course number_of_course;
	group number_of_group;
	avarage_score average;
	exam grade;
};

	// ���������� ��������� == ��� ��������� ������������� ���� ������� 
	bool operator == (const Student& one, const Student & other) {
		return one.old == other.old && one.gen == other.gen && one.spec == other.spec && one.number_of_course == other.number_of_course && one.number_of_group == other.number_of_group && one.average == other.average && one.grade == other.grade;
	}

	// ���������� ��������� > ��� ��������� ����� ������� ������ � �������� ���� ������� 
	bool operator > (const Student& any, const Student& another) {
		return (any.average + any.grade)> (another.average + another.grade);
	}

	 





int main() {

	setlocale(LC_ALL, "rus");


	// ������, ��� �������������� ���������
	Student student1{ "������ ���� ����������", 12, '�',"���������", 2, 3,5.5, 1};
	Student student2{ "������ ���� ����������", 12, '�',"���������", 2, 3,5.5, 1};

	// �������� ��������� ==
	if (student1 == student2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	// ������, ��� �������������� �� ���������
	Student student3{ "���������� ������ ����������", 13, '�',"������������ ����", 2, 3,5.5, 6 };
	Student student4{ "������������ ����� ����������", 12,'�',"������ ���������" , 2, 3,7.5, 1 };

	// �������� ��������� !=
	if (student3 > student4)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}