// 그룹 단어 체커/ baekjoon_1316.cpp
// https://www.acmicpc.net/problem/1890

#include <iostream>
using namespace std;

bool check(string& s) {
	bool check[26] = { false, };

	for (int i = 0; i < s.size() - 1; i++) {
		int num = s[i] - 'a';
		check[num] = true;
		if (s[i + 1] == s[i])
			continue;
		else {
			int next = s[i + 1] - 'a';
			if (check[next] == true)
				return false;
		}
	}

	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (check(s))
			cnt++;
		else
			continue;
	}

	cout << cnt;
}
