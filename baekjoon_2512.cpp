// 예산 / baekjoon_2512.cpp
// https://www.acmicpc.net/problem/2512

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v0, v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++){
		int num;
		cin >> num;
		v0.push_back(num);
		v.push_back(num);
	}

	cin >> M;

}

int Sum() {
	int temp = 0;
	for (auto a : v)
		temp += a;
	return temp;
}

void clear() {
	for (int i = 0; i < N; i++)
		v[i] = v0[i];
}

void solve() {
	sort(v0.begin(), v0.end());
	int sum = Sum();
	int cnt = 1;
	int temp = v0[N - 1];
	while (sum > M) {
		clear();
		for (int i = 0; i < N; i++) {
			if (v[i] > temp)
				v[i] = temp;
		}
		sum = Sum();
		temp--;
		cnt++;
	}
	sort(v.begin(), v.end());
	cout << v[N - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}
