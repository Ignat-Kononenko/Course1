#include<iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	int low = 1, average, number,second_number, sum = 1, second_sum = 1, result;
	char input;

	

	cout << "Введите число N , до которого выполняться предел (1 <=X <= N) " << endl;
	cin >> number;
	second_number = number;

	if (number < 1) {
		cout << "Ошибка" << endl;
		exit(0);
	}

	while (second_number != 1) {
		
		second_number /= 2;
		second_sum += 1;

	}

	cout << "Загадайте число от 1 до " << number << ", а я попробую отгадать" << endl;
	average = (number + low) / 2;
	cout << "Ваше число " << average << "?" << endl;
	cout << "Нажмите:q - да , d - больше, a - меньше" << endl;

	while ((input = getchar()) != 'q') {
		if (input != '\n') {
			if (input == 'd') {
				low = average + 1;
				average = (number + low) / 2;
				cout << "Ваше число " << average << "?" << endl;
				sum += 1;
			}
			else if (input == 'a') {
				number = average - 1;
				average = (number + low) / 2;
				cout << "Ваше число " << average << "?" << endl;
				sum += 1;
			}
			else {
				cout << "Я не понимаю. Введите q, d или a" << endl;
			}


		}

	}

	cout << "Я знала, что смогу это сделать!"<<endl;
	cout <<"Выполнило следущее количество шагов бинарного поиска: " << sum << endl;
	cout << "Максимальное количество шагов бинарного поиска: " << second_sum << endl;
	
	return 0;
}