// baekjoon_10026
// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <queue>
using namespace std;

char picture[101][101];
bool visited[101][101];
int N;
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

// 일반적인 사람의 그림 구분
void BFS1(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		char color = picture[x0][y0];
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if ((nowX > 0 && nowY > 0) && nowX <= N && nowY <= N) {
				if (visited[nowX][nowY] == false && picture[nowX][nowY] == color) {
					visited[nowX][nowY] = true;
					q.push({ nowX,nowY });
				}
			}
		}
	}
}

// 적록색약의 사람의 그림 구분
void BFS2(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		char color = picture[x0][y0];
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			char nowColor = picture[nowX][nowY];
			bool sameColor = false;
			// 적록색약은 R == G로 하여 BFS진행
			if (color == nowColor)
				sameColor = true;
			else if (color == 'R' && nowColor == 'G')
				sameColor = true;
			else if (color == 'G' && nowColor == 'R')
				sameColor = true;
			else
				sameColor = false;
			if ((nowX > 0 && nowY > 0) && nowX <= N && nowY <= N) {
				if (visited[nowX][nowY] == false && sameColor == true) {
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

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char ch;
			cin >> ch;
			picture[i][j] = ch;
		}
	}

	// 일반사람의 구분
	int result1 = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == false) {
				BFS1(i, j);
				result1++;
			}
		}
	}
	// 방문여부 배열 초기화
	fill(&visited[0][0], &visited[100][101], false);
	
	// 적록색약의 구분
	int result2 = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == false) {
				BFS2(i, j);
				result2++;
			}
		}
	}

	cout << result1 << " " << result2;
}
