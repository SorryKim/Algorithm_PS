// 욕심쟁이 판다 / baekjoon_1937.cpp
// https://www.acmicpc.net/problem/1937

// DFS 그래프로 활용한 풀이 -> 시간초과

/*
#include <iostream>
using namespace std;

int forest[500][500] = { 0, };
bool visited[500][500];
int n = 0;
int result = 0;
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

void DFS(int x,int y,int cnt) {

	visited[x][y] = true;
	int nowV = forest[x][y];
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int nowX = x + moveX[i];
		int nowY = y + moveY[i];
		if (nowX >= 0 && nowY >= 0 & nowX < n && nowY < n) {
			if (visited[nowX][nowY] == false && forest[nowX][nowY] > nowV) {
				DFS(nowX, nowY, cnt + 1);
			}
		}
	}
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			clear();
			DFS(i, j, 1);
		}
	}

	cout << result;
}
*/

// dp를 사용한 풀이
#include <iostream>
using namespace std;

int n;
int forest[500][500] = { 0, };
int dp[500][500] = { 0, }; // dp[x][y] = z , 판다가 x,y칸 위에 있을 시 최대로 움직일 수 있는 거리 z
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
int result = 0;

int Move(int x, int y) {

	// 이미 dp 값이 존재하는 경우
	if (dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nowX = x + moveX[i];
		int nowY = y + moveY[i];

		if (nowX >= 0 && nowY >= 0 && nowX < n && nowY < n) {
			if (forest[x][y] < forest[nowX][nowY]) {
				dp[x][y] = max(dp[x][y], Move(nowX, nowY) + 1);
			}
		}
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, Move(i, j));
		}
	}

	cout << result;
}
