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
}

void solve() {

	int left = 0;
	int right = v[N - 1] - 1;

	while (left <= right) {

		int cnt = 1;
		int mid = (left + right) / 2;
		int start = v[0];

		for (int i = 1; i < N; i++) {
			int temp = v[i];
			if (temp - start >= mid) {
				cnt++;
				start = temp;
			}
		}

		if (cnt >= C) {
			result = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	sort(v.begin(), v.end());
	solve();

	cout << result << "\n";
}
