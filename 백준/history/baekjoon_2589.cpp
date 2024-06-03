// 보물섬 / baekjoon_2589.cpp
// https://www.acmicpc.net/problem/2589

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
char map[50][50];
bool visited[50][50];
int value[50][50];
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

int BFS(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	value[x][y] = 0;
	int cnt = 0;

	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();

		if (cnt < value[x0][y0])
			cnt = value[x0][y0];

		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if (nowX >= 0 && nowY >= 0 && nowX < N && nowY < M) {
				if (visited[nowX][nowY] == false && map[nowX][nowY] == 'L') {
					visited[nowX][nowY] = true;
					q.push({ nowX,nowY });
					value[nowX][nowY] = value[x0][y0] + 1;
				}
			}
		}
	}

	return cnt;
}

void Clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				Clear();
				int temp = BFS(i, j);
				result = max(temp, result);
			}
		}
	}

	cout << result;
	
}
