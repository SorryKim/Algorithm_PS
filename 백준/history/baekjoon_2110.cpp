// 공유기 설치/ baekjoon_2110.cpp
// https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, result;
vector<int> v;

void input() {

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	result = -1;
}

void solve() {

	sort(v.begin(), v.end());
	int left = 0;
	int right = v[N - 1];

	while (left <= right) {

		int mid = (left + right) / 2;
		int cnt = 1;
		int start = v[0];

		for (int i = 1; i < N; i++) {

			if (v[i] - start >= mid) {
				cnt++;
				start = v[i];
			}
		}

		if (cnt >= C) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << result << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}