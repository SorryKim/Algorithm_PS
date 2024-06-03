// 쇠막대기 / baekjoon_10799.cpp
// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	stack<char> st;
	int cnt = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') {
			st.push(s[i]);
		}

		else if (s[i] == ')') {
			if (s[i - 1] == '(') {
				st.pop();
				cnt += st.size();
			}
			else {
				st.pop();
				cnt++;
			}
		}
	}

	cout << cnt;
}
