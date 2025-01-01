#include <iostream>
#include <stack>  // подключаем библиотеку для использования стека
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	stack <int> steck; 
	int i = 0;
	cout << "Введите шесть любых целых чисел: " << endl; // предлагаем пользователю 
	// ввести 6 чисел
	while (i != 6) {
		int a;
		cin >> a;

		steck.push(a);
		i++;
	}

	cout << "Верхний элемент стека: " << steck.top() << endl; // выводим верхний элемент

	steck.pop();
	return 0;
}
