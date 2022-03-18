// baekjoon_2206
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>

using namespace std;

// 사용 변수
int N, M;
int map[1001][1001] = { 1, };
int visited[1001][1001][2] = { 0, };
int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };

void move(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	visited[x][y][0] = 1;
	q.push({ make_pair(x,y),0 });

	while (!q.empty()) {
		int x0 = q.front().first.first;
		int y0 = q.front().first.second;
		int breakWall = q.front().second;
		q.pop();
		if (x0 == N && y0 == M)
			return;

		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if ((nowX >= 1 && nowY >= 1) && (nowX <= N && nowY <= M)) {
				// 벽을 부술 수 있는 경우
				if (map[nowX][nowY] == 1 && visited[nowX][nowY][breakWall] == 0 && breakWall == 0) {
					q.push({ make_pair(nowX, nowY), 1 });
					visited[nowX][nowY][1] = visited[x0][y0][breakWall] + 1;
				}
				// 부수지않고 그냥 갈 수 있는 경우
				else if ((map[nowX][nowY] == 0) && visited[nowX][nowY][breakWall] == 0) {
					q.push({ make_pair(nowX,nowY) , breakWall });
					visited[nowX][nowY][breakWall] = visited[x0][y0][breakWall] + 1;

				}
			}
		}
	}
}

int main() {
	
	fill(&map[0][0], &map[1000][1001], 1);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int value;
			scanf("%1d", &value);
			map[i][j] = value;
		}
	}

	move(1, 1);
	int result1 = visited[N][M][0]; // 벽을 부수지않고 도착한 경우
	int result2 = visited[N][M][1]; // 벽을 한번 부수고 간 경우

	if (result1 == 0 && result2 == 0)
		printf("-1");
	else if (result1 == 0)
		printf("%d", result2);
	else if (result2 == 0)
		printf("%d", result1);
	else if (result1 > result2)
		printf("%d", result2);
	else
		printf("%d", result1);

	
}
