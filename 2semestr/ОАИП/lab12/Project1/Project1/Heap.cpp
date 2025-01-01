#include "Heap.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void AAA::print()
{
	std::cout << x;
}
namespace heap
{
	int pozmin = -100000, minnum = 10000000;// Глобальные переменные для поиска минимума
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];// Временное сохранение элемента с индексом i
		storage[i] = storage[j];// Замена элемента с индексом i на элемент с индексом j
		storage[j] = buf;// Замена элемента с индексом j на временно сохраненный элемент
	}
	void Heap::heapify(int ix) // Определение метода heapify класса Heap, для преобразования в кучу
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x, int k)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))// Пока индекс не является корневым и значение родительского элемента больше значения вставляемого элемента
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;// Инициализация указателя на извлеченный элемент как nullptr
		if (!isEmpty())
		{
			rc = storage[0]; // Сохранение максимального элемента
			storage[0] = storage[size - 1];// Перемещение последнего элемента в корень
			size--;
			heapify(0);// Преобразование кучи в кучу, начиная с корня
		} return rc;
	}
	void Heap::extractMin(heap::Heap& h3, heap::Heap& h1)
	{
		if (h1.size == 0) {
			cout << "Куча пуста\n";
			return;
		}
		for (int i = 0; i < size; i++) {
#define A1 ((AAA*)h1.storage[i])//Макроопределение для удобства доступа к элементам кучи h1
			if (A1->x < minnum) {// Если значение текущего элемента меньше текущего минимума
				minnum = A1->x;// Обновить значение минимума
				pozmin = i;// Обновить индекс минимального элемента
			}
		}
		storage[pozmin] = storage[size - 1];// Заменить минимальный элемент последним элементом
		h1.size--;
		if (!isEmpty())
		{
			while (!h1.isEmpty()) {
#define A1 ((AAA*)h1.storage[0])
				h3.insert(A1, A1->x);// Вставить минимальный элемент в кучу h3
				h1.extractMax();// Извлечь максимальный элемент из кучи h1
			}
		}
		pozmin = -100000, minnum = 10000000;// Сброс переменных для поиска минимума
	}
	void* Heap::extractI(int h)
	{
		void* rc = nullptr;
		if (h >= size || h < 0) {
			cout << "Некорректный номер\n";
			return nullptr;
		}
		if (!isEmpty())
		{
			rc = storage[h];// Сохранение элемента по указанному индексу
			if (h != size - 1) {// Если извлекаемый элемент не является последним элементом
				swap(h, size - 1);
			}
			size--;
			heapify(0);// Преобразование кучи в кучу, начиная с корня
			heapify(h);// Преобразование кучи в кучу, начиная с элемента по указанному индексу
		} return rc;
	}
	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		//vector<int> a = { 34 };
		//vector<int> b = { 20, 16, 20 };
		//vector<int> c = { 12, 8, 12, 4, 12, 8, 12};
		//vector<int> d = { 8, 6, 4, 4, 4, 6, 4, 4, 4, 6, 4, 4, 4, 6, 8 };
		//vector<int> vnesh = { 40, 22, 12, 6, 2, 1};
		vector<int> a = { 52 };// Вектор для определения ширины вывода элементов на разных уровнях
		vector<int> b = { 26, 24, 28 };
		vector<int> c = { 16, 10, 16, 8, 16, 12, 16 };
		vector<int> d = { 8, 8, 6, 6, 6, 8, 6, 4, 6, 8, 8, 4, 8, 8, 8 };
		vector<int> e = { 4, 4, 4, 4, 4, 4, 3, 4, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 4, 3, 3, 4, 4, 4, 4, 4 };
		vector<int> vnesh = { 66, 40, 28, 20, 16, 12 };
		int y = 0;
		int level = 0;
		bool t = false;
		int current = 0;
		int j;
		std::cout << '\n';
		if (size == 0) {
			std::cout << "Куча пуста\n";
			return;
		}
		std::cout << std::setw(vnesh[level]) << std::setfill(' ');// Установка отступа для первого уровня
		level++;
		((AAA*)storage[current])->print(); // Вывод значения текущего элемента кучи
		current++;
		cout << '\n';
		y = 2;
		for (int i = 0; current < size; i++) {
			if (!t) {
				std::cout << std::setw(vnesh[level]) << std::setfill(' ');
				t = true;
				j = 0;
			}
			((AAA*)storage[current])->print();
			if (level == 1 && j < a.size()) {
				std::cout << std::setw(a[j]) << std::setfill(' ');
				j++;
			}
			else if (level == 2 && j < b.size()) {
				std::cout << std::setw(b[j]) << std::setfill(' ');
				j++;
			}
			else if (level == 3 && j < c.size()) {
				//Если текущий уровень равен 3 и индекс j меньше размера вектора c
				std::cout << std::setw(c[j]) << std::setfill(' ');
				j++;
			}
			else if (level == 4 && j < d.size()) {
				std::cout << std::setw(d[j]) << std::setfill(' ');
				j++;
			}
			else if (level == 5 && j < e.size()) {
				std::cout << std::setw(e[j]) << std::setfill(' ');
				j++;
			}
			current++;
			if (current > y) {
				cout << '\n';
				level++;
				y += pow(2, level);
				t = false;
			}
		}
		cout << '\n';
	}
	void Heap::unionHeap(heap::Heap buf, heap::Heap& h1) {
		while (!buf.isEmpty()) {// Цикл пока куча buf не станет пустой
#define A1 ((AAA*)buf.storage[0])// Макроопределение для удобства доступа к минимальному элементу кучи buf
			h1.insert(A1, A1->x);// Вставка минимального элемента кучи buf в кучу h1
			buf.extractMax();// Извлечение максимального элемента из кучи buf
		}
	}
}
