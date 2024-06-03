// 데스 나이트 / baekjoon_16948.cpp
// https://www.acmicpc.net/problem/16948

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
bool visit[201][201];
int r1, c1, r2, c2;
int result = 0;
int moveR[6] = { -2, -2, 0, 0, 2, 2 };
int moveC[6] = { -1, 1, -2, 2, -1, 1 };

void Input() {

	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	result = 0;
}

int BFS() {

	queue<pair<pair<int,int>, int>> q;
	q.push({{ r1,c1 },0 });
	visit[r1][c1] = true;

	while (!q.empty()) {
		int r0 = q.front().first.first;
		int c0 = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int r = r0 + moveR[i];
			int c = c0 + moveC[i];

			if (r < 0 || r >= N || c < 0 || c >= N)
				continue;

			if (visit[r][c])
				continue;

			if (r == r2 && c == c2) {
				return time+1;
			}

			visit[r][c] = true;
			q.push({ { r,c }, time + 1 });
		}
	}

	return -1;
}

void Solve() {

	cout << BFS() << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
