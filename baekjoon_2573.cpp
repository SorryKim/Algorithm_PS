// 빙산 / baekjoon_2573.cpp
// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[300][300];
bool visited[300][300];
queue<pair<int, int>> iceberg;
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

// 녹는 메소드
void melt() {
	queue<int> height;
	int k = iceberg.size();

	// 각 빙산마다 녹일정도를 큐에 저장
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		int x0 = iceberg.front().first;
		int y0 = iceberg.front().second;
		iceberg.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if (nowX >= 0 && nowY >= 0 && nowX < N && nowY < M) {
				if (map[nowX][nowY] == 0)
					cnt++;
			}

		}
		height.push(cnt);
		iceberg.push({ x0,y0 });
	}

	for (int i = 0; i < k; i++) {
		int x = iceberg.front().first;
		int y = iceberg.front().second;
		int cnt = height.front();
		iceberg.pop();
		height.pop();
		map[x][y] -= cnt;

		if (map[x][y] > 0)
			iceberg.push({ x,y });
		else {
			map[x][y] = 0;
		}
	}

}

// 빙산의 갯수 확인
void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if (nowX >= 0 && nowY >= 0 && nowX < N && nowY < M) {
				if (visited[nowX][nowY] == false && map[nowX][nowY] != 0) {
					visited[nowX][nowY] = true;
					q.push({ nowX,nowY });
				}
			}
		}
	}
}

int start() {
	int result = 0;

	while (true) {



		// 방문 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}

		int temp = 0;
		// 빙산의 갯수 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0 && visited[i][j] == false) {
					BFS(i, j);
					temp++;
				}
			}
		}

		// 빙산의 갯수가 1이 아닐 경우
		if (temp > 1) {
			return result;
		}
		else if (temp == 0)
			return 0;

		// 빙산을 녹이는 과정
		melt();

		// 년수 증가
		result++;
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
			visited[i][j] = false;
			if (map[i][j] != 0) {
				iceberg.push({ i,j });
			}
		}
	}

	cout << start();
}
