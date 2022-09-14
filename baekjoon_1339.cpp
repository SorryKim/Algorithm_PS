// 단어수학 / baekjoon_1339.cpp
// https://www.acmicpc.net/problem/1339

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string arr[10];
int word[26] = { 0, };

bool compare(int a, int b) {

	return a > b;
}

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

}

void Solve() {

	for (int i = 0; i < N; i++) {

		string s = arr[i];
		for (int j = 0; j < s.length(); j++) {
			int size = (int)pow(10, s.length() - j - 1);
			word[(s[j] - 'A')] += size;
		}
	}

	sort(word, word + 26, compare);
	
	int start = 9;
	int sum = 0;
	for (auto a : word) {
		if (start == 0 || a == 0)
			break;
		a *= start;
		start--;
		sum += a;
	}

	cout << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

}
