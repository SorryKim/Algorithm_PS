// baekjoon_1918
// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	stack<char> s;
	
	for (auto a : str) {
		if (a == '(') {
			s.push(a);
			continue;
		}
		else if (a == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop(); // 여는괄호 삭제
		}
		else if (a == '+' || a == '-') {
			// 스택이 비어있는 경우나 top이 (인 경우에 push, 아닐 경우 해당조건이 될때까지 pop한 후 push
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop(); 
			}
			s.push(a);
		}
		else if (a == '*' || a == '/') {
			// 스택이 비어있는 경우나 top이 자신보다 낮은 경우에만 push 아닐 경우 pop을 한 후 조건이 성립되면 push
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(a);
		}
		// 연산자가 아닌 알파벳인 경우
		else {
			cout << a;
		}
	}

	while (s.size() != 0) {
		cout << s.top();
		s.pop();
	}

}
