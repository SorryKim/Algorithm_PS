// 영역 구하기 / baekjoon_2583.cpp
// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int graph[100][100] = { 0, };
bool check[100][100] = { false, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
int cnt = 0;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		cnt++;
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if (nowX >= 0 && nowX < M && nowY >= 0 && nowY < N) {
				if (graph[nowX][nowY] == 0 && check[nowX][nowY] == false) {
					q.push({ nowX,nowY });
					check[nowX][nowY] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				graph[x][y] = 1;
			}
		}
	}

	vector<int> result;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false && graph[i][j] == 0) {
				cnt = 0;
				BFS(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto a : result) {
		cout << a << " ";
	}

}
