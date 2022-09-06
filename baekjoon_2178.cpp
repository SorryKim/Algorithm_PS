// baekjoon_2178
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
using namespace std;

int maze[200][200] = { 0, };
bool check[200][200] = { false, };
int result[200][200] = { 0, };
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };
queue<pair<int,int>> q;
int N, M;

void BFS(int x, int y) {

	q.push({ x,y });
	check[x][y] = true;
	result[x][y]++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int now_x = x + move_x[i];
			int now_y = y + move_y[i];

			if ((now_x >= 1 && now_y >= 1) && (now_x <= N && now_y <= M)){
				if (check[now_x][now_y] == false && maze[now_x][now_y] == 1) {
					check[now_x][now_y] = true;
					q.push({ now_x,now_y });
					result[now_x][now_y] = result[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	// ios::sync_with_stdio(0);  <== 사용시 cin과 scanf 혼용불가 오류발생
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;
			scanf("%1d", &num);
			maze[i][j] = num;
		}
	}

	BFS(1, 1);
	cout << result[N][M];
}
