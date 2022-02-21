// baekjoon_11047
// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		v.push_back(value);
	}

	int count = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (K >= v[i]) {
			while (v[i] <= K) {
				count++;
				K = K - v[i];
			}
		}
		if (K == 0)
			break;
	}

	cout << count;
}
