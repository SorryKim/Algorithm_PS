// 치즈 / baekjoon_2638.cpp
// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int cheese[101][101];
bool visited[101][101];
bool air[101][101];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1,-1 };

void Input() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> cheese[i][j];
	}
}

void visitClear() {
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = false;
		}
	}

	return;
}

void checkAir() {

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			air[i][j] = false;
		}
	}

	air[0][0] = true;
	visitClear();

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + moveX[i];
			int nextY = y + moveY[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;
			if (visited[nextX][nextY] || cheese[nextX][nextY] == 1)
				continue;

			if (cheese[nextX][nextY] == 0) {
				air[nextX][nextY] = true;
				visited[nextX][nextY] = true;
				q.push({ nextX,nextY });
			}

		}
		
	}
	return;
}

void Melt(int x, int y) {

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nowX = x + moveX[i];
		int nowY = y + moveY[i];
		
		if (nowX < 0 || nowX >= N || nowY < 0 || nowY >= M)
			continue;
		
		if (air[nowX][nowY])
			cnt++;
	}

	// 두 면이상 공기에 닿을 경우 녹음
	if (cnt >= 2)
		cheese[x][y] = 0;
	
	return;
}

// 치즈가 다녹았는지 확인
bool checkMelt() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cheese[i][j] == 1)
				return false;
		}
	}

	return true;
}



void Solve() {

	int cnt = 0;

	while (!checkMelt()) {
		cnt++;

		checkAir();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cheese[i][j] == 1) {
					Melt(i, j);
				}
			}
		}
	}

	cout << cnt << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

}
