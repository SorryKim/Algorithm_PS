// 로봇 청소기  / baekjoon_14503.cpp
// https://www.acmicpc.net/problem/14503

#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int map[50][50] = { 0, };
bool isClean[50][50] = { false, };
pair<int, int> nextMove[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int cnt = 0;

void input() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

int rotate(int dir) {
	int nowDir;
	if (dir == 0)
		nowDir = 3;
	else
		nowDir = dir - 1;
	return nowDir;
}

void cleancheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isClean[i][j])
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";

	}
}

void clean(int x, int y, int dir) {
	// dir, 0: 북, 1: 동, 2: 남, 3: 서

	// 1. 현재 위치를 청소한다.
	if (map[x][y] == 0 && isClean[x][y] == false) {
		cnt++;
		isClean[x][y] = true;
	}

	int nowDir = dir;
	// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	for (int i = 0; i < 4; i++) {
		nowDir = rotate(nowDir);
		int nextX = x + nextMove[nowDir].first;
		int nextY = y + nextMove[nowDir].second;
		
		// 2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M || map[nextX][nextY] == 1)
			continue;

		// 1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (map[nextX][nextY] == 0 && isClean[nextX][nextY] == false) {
			clean(nextX, nextY, nowDir);
		}
	}

	int backX = x - nextMove[nowDir].first;
	int backY = y - nextMove[nowDir].second;
	if (backX >= 0 && backY >= 0 && backX < N && backY < M) {
		// 3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		if (map[backX][backY] == 0)
			clean(backX, backY, nowDir);
		// 4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		else {
			cout << cnt << "\n";
			exit(0);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	clean(r, c, d);
}
