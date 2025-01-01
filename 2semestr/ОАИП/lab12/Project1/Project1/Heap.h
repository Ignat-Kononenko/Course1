#pragma once

struct AAA
{
	int x;
	void print();
};
namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap
	{
		int size;// Поле size для хранения текущего размера кучи
		int maxSize;
		void** storage;// Поле storage для хранения указателей на элементы кучи
		CMP(*compare)(void*, void*);
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxsize];
			compare = f;
		};
		int left(int ix);
		int right(int ix);
		int parent(int ix);
		bool isFull() const// Метод для проверки, является ли куча полной
		{
			return (size >= maxSize);
		};
		bool isEmpty() const
		{
			return (size <= 0);
		};
		bool isLess(void* x1, void* x2) const// Объявление метода для сравнения двух элементов
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL;
		};
		void swap(int i, int j);
		void heapify(int ix); // Объявление метода для преобразования в кучу
		void insert(void* x, int); // Объявление метода для вставки элемента в кучу
		void* extractMax();
		void extractMin(heap::Heap&, heap::Heap&);
		void* extractI(int);
		void scan(int i) const;// Объявление метода для вывода значений элементов кучи на экран
		void unionHeap(heap::Heap, heap::Heap&);
	};
	Heap create(int maxsize, CMP(*f)(void*, void*));
};
#pragma once
