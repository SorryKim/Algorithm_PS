// baekjoon_2468
// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int zone[101][101] = { 0, };
bool visited[101][101] = { false, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

void BFS(int a, int b, int arr[][101],int h) {
	visited[a][b] = true;
	queue<pair<int, int>> q;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x + moveX[i];
			int nowY = y + moveY[i];
			if (nowX > 0 && nowY > 0 && nowX <= N && nowY <= N) {
				if (visited[nowX][nowY] == false && arr[nowX][nowY] > h) {
					visited[nowX][nowY] = true;
					q.push({ nowX,nowY });
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int result = 0;

	// 지형 입력받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			zone[i][j] = num;
		}
	}


	for (int height = 0; height <= 100; height++) {
		fill(&visited[0][0], &visited[100][101], false); // 다차원 배열 초기화
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == false && zone[i][j] > height) {
					BFS(i, j, zone, height);
					cnt++;
				}
			}
		}
		if (cnt > result) {
			result = cnt;
		}
	}

	cout << result;
}
