// IOIOI / baekjoon_5525.cpp
// https://www.acmicpc.net/problem/5525

#include <iostream>
#include <stack>
using namespace std;

int N, M;
stack<char> s;
int cnt = 0;
char temp = 'a';

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		char ch;
		cin >> ch;

		// 이번 글자가 전 글자랑 같은 경우, 문자열성립이 안되니 스택 초기화
		if (ch == temp) {
			while (!s.empty())
				s.pop();
		}
		
		// 문자열조건에 맞는 경우 스택에 추가
		if (!s.empty()) {
			if (s.top() == 'I' && ch == 'O') {
				s.push(ch);
			}

			if (s.top() == 'O' && ch == 'I') {
				s.push(ch);
			}
		}

		// 스택이 비어있고 I인 경우
		if (s.empty() && ch == 'I')
			s.push(ch);

		// Pn이 완성된 경우 스택에서 2개씩 제거, 결과 저장
		if (s.size() == 2 * N + 1) {
			cnt++;
			s.pop();
			s.pop();
		}

		temp = ch; // 이전문자를 저장함
	}
	
	cout << cnt;
}
