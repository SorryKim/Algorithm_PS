// baekjoon_7562
// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <queue>
using namespace std;

bool visited[300][300] = { false, };
int board[300][300] = { 0, };

int moveX[8] = { 1,2,2,1,-1,-2,-2,-1 };
int moveY[8] = { 2,1,-1,-2,-2,-1,1,2 };
int l;

void BFS(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if ((nowX >= 0 && nowY >= 0) && (nowX < l && nowY < l)) {
				if (visited[nowX][nowY] == false) {
					visited[nowX][nowY] = true;
					board[nowX][nowY] = board[x0][y0] + 1;
					q.push({ nowX , nowY });
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		fill(&visited[0][0], &visited[299][300], false);
		fill(&board[0][0], &board[299][300], 0);
		int x1, x2, y1, y2;
		cin >> l;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		BFS(x1, y1);
		cout << board[x2][y2] << "\n";
	}
}
