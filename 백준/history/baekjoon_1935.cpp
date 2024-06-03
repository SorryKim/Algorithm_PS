// 후위 표기식2 / baekjoon_1935.cpp
// https://www.acmicpc.net/problem/1935

#include <iostream>
#include <stack>
using namespace std;

double arr[100];
stack<double> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(arr[str[i] - 'A']);
		}
		else {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();

			if (str[i] == '*') {
				s.push(a * b);
			}
			else if (str[i] == '/') {
				s.push(a / b);
			}
			else if (str[i] == '+') {
				s.push(a + b);
			}
			else if (str[i] == '-') {
				s.push(a - b);
			}
			
		}
		
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();

}// 후위 표기식2 / baekjoon_1935.cpp
// https://www.acmicpc.net/problem/1935

#include <iostream>
#include <stack>
using namespace std;

double arr[100];
stack<double> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(arr[str[i] - 'A']);
		}
		else {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();

			if (str[i] == '*') {
				s.push(a * b);
			}
			else if (str[i] == '/') {
				s.push(a / b);
			}
			else if (str[i] == '+') {
				s.push(a + b);
			}
			else if (str[i] == '-') {
				s.push(a - b);
			}
			
		}
		
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();

}
