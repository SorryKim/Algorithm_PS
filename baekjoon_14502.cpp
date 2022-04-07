// 연구소 / baekjoon_14502.cpp
// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[8][8] = { 0, };
int originalMap[8][8] = { 0, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
int result = 0;

// 배열을 원본 배열로 바꾸는 메소드
void copy(int change[8][8], int original[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			change[i][j] = original[i][j];
		}
	}
}

void BFS() {
	int infested[8][8];
	copy(infested, map);
	queue<pair<int, int>> q;
	
	// 맵에 바이러스를 확인하고 큐로 넣어줌
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (infested[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if ((nowX >= 0 && nowY >= 0) && (nowX < N && nowY < M)) {
				if (infested[nowX][nowY] == 0) {
					infested[nowX][nowY] = 2;
					q.push({ nowX,nowY });
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (infested[i][j] == 0)
				count++;
		}
	}

	result = max(result, count);
}

// 벽을 세우는 함수
void wall(int n) {
	if (n == 3) {
		BFS();
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					wall(n + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	// 지도정보 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> originalMap[i][j];
		}
	}

	// 0인 지점을 찾고 발견 시 나머지 두 0을 벽으로 바꾸면서 BFS진행
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (originalMap[i][j] == 0) {
				copy(map,originalMap);
				map[i][j] = 1;
				wall(1);
				map[i][j] = 0;
			}
		}
	}

	cout << result << '\n';
}
