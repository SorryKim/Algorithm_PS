// baekjoon_1874
// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	vector<char> result;
	int count = 1;
	bool b = true;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		// 큰 값이 들어오는 경우
		if (num >= count) {
			while (num + 1 > count) {
				s.push(count);
				result.push_back('+');
				count++;
			}
			s.pop();
			result.push_back('-');
		}

		else {
			if (num == s.top()) {
				result.push_back('-');
				s.pop();
			}
			else // 스택수열이 아닌 경우
				b = false;
		}
	}

	// 결과 출력
	if (b) {
		for (auto a : result)
			cout << a << "\n";
	}
	else
		cout << "NO";
}
