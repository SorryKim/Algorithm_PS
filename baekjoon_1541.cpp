// 잃어버린 괄호 / baekjoon_1541.cpp
// https://www.acmicpc.net/problem/1541

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	vector<int> v;

	cin >> s;
	string temp = "";
	int result = 0;
	bool b = false;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		
		// 마이너스가 등장한 경우 그 뒤는 전부 빼주면 된다.
		else if (s[i] == '-') {

			// 마이너스가 처음 등장한 경우
			if (b == false) {
				result += stoi(temp);
				temp = "";
				b = true;
			}

			// 마이너스가 이미 등장한 경우
			else {
				result -= stoi(temp);
				temp = "";
				b = true;
			}
		}

		// +가 등장한 경우
		else if (s[i] == '+') {
			
			// 앞부분에서 마이너스가 등장하지 않은 경우
			if (b == false) {
				result += stoi(temp);
				temp = "";
			}

			// 앞부분에서 마이너스가 등장한 경우
			else {
				result -= stoi(temp);
				temp = "";
			}
		}

		// 마지막 연산
		if (i == s.size() - 1) {
			if (b) {
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
		}
	
	}

	// 결과 출력
	cout << result;
}
