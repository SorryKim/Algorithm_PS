// 호텔 / baekjoon_1106.cpp
// https://www.acmicpc.net/problem/1106

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, C;
int DP[1010];
int people[20], cost[20];

void Input() {
	
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> cost[i] >> people[i];
	}

}


void Solve() {

	for (int i = 1; i <= C; i++)
		DP[i] = INF;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= C; j++) {
			int temp = 0;

			while (true) {
				temp++;
				int val = 0;
				if (j - people[i] * temp >= 0)
					val = DP[j - people[i] * temp];

				if (DP[j] > val + cost[i] * temp)
					DP[j] = val + cost[i] * temp;
				else
					break;
			}
		}
	}

	cout << DP[C] << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
