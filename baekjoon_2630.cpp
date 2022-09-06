// baekjoon_2630
// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int tomato[1001][1001] = { -1, };
bool check[1001][1001] = { false, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
int result[1001][1001] = { 0, };
queue <pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x + moveX[i];
			int nowY = y + moveY[i];
			if ((nowX >= 1 && nowY >= 1) && (nowX <= M && nowY <= N)) {
				if ((tomato[nowX][nowY] == 0) && (check[nowX][nowY] == false)) {
					tomato[nowX][nowY] = 1;
					check[nowX][nowY] = true;
					q.push({ nowX,nowY });
					result[nowX][nowY] = result[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 토마토 박스 초기화
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++)
			tomato[i][j] = -1;
	}

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			tomato[i][j] = num;
		}
	}

	// 처음부터 다익어있는 경우
	bool b1 = true;
	// 안익은 토마토가 존재하는 경우
	bool b2 = true;
	

	// 처음부터 모든 토마토가 다익어있는 경우
	for(int i =1; i <=M; i++){
		for (int j = 1; j <= N; j++) {
			if (tomato[i][j] == 0) {
				b1 = false;
				break;
			}
		}
	}

	// 익어있는 토마토를 큐에 저장
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (tomato[i][j] == 1 && check[i][j] == false) {
				q.push({ i,j });
			}
		}
	}

	BFS();

	// 모든 토마토가 익는 days 검사
	int max = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (tomato[i][j] == 0) {
				b2 = false;
			}
			if (max < result[i][j])
				max = result[i][j];
		}
	}

	if (b1)
		cout << 0;
	else if (!b2)
		cout << -1;
	else
		cout << max;
	
}
