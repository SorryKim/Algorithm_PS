// 말이 되고픈 원숭이 / baekjoon_1600.cpp
// https://www.acmicpc.net/problem/1600

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int K, W, H;
int graph[201][201];
bool visited[201][201][31];
int moveMonkeyX[4] = { -1, 1, 0, 0 };
int moveMonkeyY[4] = { 0, 0, 1, -1 };
int moveHorseX[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int moveHorseY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void Input() {

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> graph[i][j];
		}
	}
}

int BFS() {

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 0,0 }, {0,0} });
	visited[0][0][0] = true;

	while (!q.empty()) {

		int x0 = q.front().first.first;
		int y0 = q.front().first.second;
		int cnt = q.front().second.first;
		int jump = q.front().second.second;
		q.pop();

		if (x0 == H - 1 && y0 == W - 1) {
			return cnt;
		}

		if (jump < K) {

			for (int i = 0; i < 8; i++) {
				int nowX = x0 + moveHorseX[i];
				int nowY = y0 + moveHorseY[i];
				if (nowX < 0 || nowY < 0 || nowX >= H || nowY >= W)
					continue;

				if (graph[nowX][nowY] == 0 && !visited[nowX][nowY][jump + 1]) {
					visited[nowX][nowY][jump + 1] = true;
					q.push({ { nowX,nowY }, { cnt + 1, jump + 1 } });
				}
			}
		}

		for (int i = 0; i < 4; i++) {

			int nowX = x0 + moveMonkeyX[i];
			int nowY = y0 + moveMonkeyY[i];

			if (nowX < 0 || nowY < 0 || nowX >= H || nowY >= W)
				continue;

			if (graph[nowX][nowY] == 0 && !visited[nowX][nowY][jump]) {
				visited[nowX][nowY][jump] = true;
				q.push({ {nowX,nowY},{cnt + 1, jump} });
			}
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
