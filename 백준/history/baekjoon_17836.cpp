// 공주님을 구해라!  / baekjoon_17836.cpp
// https://www.acmicpc.net/problem/17836

#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int graph[101][101];
bool visited[101][101];
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
int result = 987654321;

void input() {
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++)
			visited[i][j] = false;
	}

}

int gram(int x, int y) {
	int valueX = abs(x - (N - 1));
	int valueY = abs(y - (M - 1));

	return valueX + valueY;
}

void BFS(int x, int y) {

	queue<pair<pair<int,int>,int>> q;
	visited[x][y] = true;
	q.push({ { x, y },0 });

	while (!q.empty()) {

		int x0 = q.front().first.first;
		int y0 = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];

			if (nowX >= 0 && nowY >= 0 && nowX < N && nowY < M) {
				if (!visited[nowX][nowY] && graph[nowX][nowY] != 1) {

					visited[nowX][nowY] = true;
					if (graph[nowX][nowY] == 0)
						q.push({ { nowX,nowY }, cnt + 1 });
					
					if (graph[nowX][nowY] == 2) {
						q.push({ { nowX,nowY }, cnt + 1 });
						result = min(result, cnt + 1 + gram(nowX, nowY));
					}

					if (nowX == N - 1 && nowY == M - 1) {
						result = min(result, cnt + 1);
					}
				}
			}
				
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	BFS(0,0);

	if (result <= T) 
		cout << result << "\n";
	else
		cout << "Fail" << "\n";
}
