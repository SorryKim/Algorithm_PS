// baekjoon_10773
// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num != 0) {
			s.push(num);
		}
		else
			s.pop();
	}
	
	while (s.size() != 0) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
}
