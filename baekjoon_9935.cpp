// 문자열 폭발 / baekjoon_9935.cpp
// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s, bomb;
stack<char> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> bomb;
	
	for (int i = 0; i < s.length(); i++) {

		result.push(s[i]);

		// 폭탄 문자열의 마지막글자일 경우
		if (result.top() == bomb[bomb.length() - 1]) {
			
			if (result.size() >= bomb.length()) {
				int cnt = 1;
				stack<char> temp;
				temp.push(result.top());
				result.pop();

				// 뒷글자부터 비교시작
				for (int j = bomb.length() - 2; j >= 0; j--) {
					if (result.top() == bomb[j]) {
						temp.push(result.top());
						result.pop();
						cnt++;
					}
					
				}

				// 폭발문자열이 아닐 경우 temp에 저장된 char들을 원래 stack에 push
				if (cnt != bomb.length()) {
					while (!temp.empty()) {
						result.push(temp.top());
						temp.pop();
					}
				}
					
			}
		}
	}


	if (result.empty()) {
		cout << "FRULA";
	}
	else {
		string ans = "";
		while (!result.empty()) {
			ans += result.top();
			result.pop();
		}

		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
	}
	
}
