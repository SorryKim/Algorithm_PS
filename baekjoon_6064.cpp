// 카잉 달력 / baekjoon_6064.cpp
// https://www.acmicpc.net/problem/6064

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int M, N, x, y;
		bool b = false;
		cin >> M >> N >> x >> y;
		x--;
		y--;

		for (int i = x; i < (M * N); i += M) {
			if (i % N == y) {
				b = true;
				cout << i + 1 << "\n";
				break;
			}
		}

		if (b == false)
			cout << "-1\n";
	}
}

