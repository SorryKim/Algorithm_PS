// baekjoon_1012
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <queue>
using namespace std;

int arr[50][50] = { {0,0} };
int N, M, K;

void BFS(int x, int y) {

	int moveX[4] = { 0,0,-1,1 };
	int moveY[4] = { 1,-1,0,0 };
	queue <pair<int, int>> q;
	q.push({ x, y });
	
	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int mx = dx + moveX[i];
			int my = dy + moveY[i];
			if (mx < 0 || mx >= N || my < 0 || my >= M)
				continue;
			if (arr[mx][my] == 0)
				continue;
			else if (arr[mx][my] == 1) {
				arr[mx][my] = 0;
				q.push({ mx,my });
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	for (int test = 0; test < T; test++) {
		
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					count++;
					BFS(i, j);
				}
			}
		}

		cout << count << "\n";
		fill(arr[0], arr[50], 0);
	}
}
