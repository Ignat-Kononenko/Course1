#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

bool brackets(string);

int main() {
	
	setlocale(LC_ALL, "rus");

	string str;
	static int sum = 0;

	cout << "¬ведите строку: " << endl;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
			sum += 1;

		}
	}
	if (sum < 1) {
		cout << "недостаточно или отсутствуют скобки" << endl;
		exit(0);
	}

	if (brackets(str)) {
		cout << "скобки расставлены верно" << endl;
	}
	else {
		cout << "скобки расставлены неверно" << endl;
	}


	return 0;
}

bool brackets(string str) {

	stack<char> s;

	for (char ch : str) {
		switch (ch) {
		case '(':
		
		
		case '[':
			
			
		case '{':
			s.push(ch);
			break;
		case ')':
			if (s.empty() || s.top() != '(') {
				return false;
			}
			s.pop();
			break;
		case ']':
			if (s.empty() || s.top() != '[') {
				return false;
			}
			s.pop();
			break;
		case '}':
			if (s.empty() || s.top() != '{') {
				return false;
			}
			s.pop();
			break;
		}
	}
	return s.empty();

}