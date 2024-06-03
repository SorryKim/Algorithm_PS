// 치즈/ baekjoon_2636.cpp
// https://www.acmicpc.net/problem/2636

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int graph[100][100] = { 0, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
bool visited[100][100] = { false, };
int wastedTime = 0;


// 치즈가 다녹았는지 확인하는 함수
bool isFinish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1)
				return false;
		}
	}
	return true;
}

int BFS() {
	int cnt = 0;
	// 치즈가 다 녹을 때까지 반복
	while (!isFinish()) {
		wastedTime++; // 시간 경과 체크
		cnt = 0;
		queue<pair<int, int>> q;
		q.push({ 0,0 });

		// visited 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				visited[i][j] = false;
		}
		visited[0][0] = true;

		
		while (!q.empty()) {
			int x0 = q.front().first;
			int y0 = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nowX = x0 + moveX[i];
				int nowY = y0 + moveY[i];

				// 조건이 맞지 않는 경우
				if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= M || visited[nowX][nowY] == true)
					continue;

				
				if (graph[nowX][nowY] == 0)
					q.push({ nowX,nowY });

				// 치즈인 경우 녹이고 안쪽으로 더 탐색하지는 않음
				else {
					graph[nowX][nowY] = 0;
					cnt++; // 치즈갯수 확인
				}

				visited[nowX][nowY] = true;
			}
		}
	}
	return cnt; // 다 녹기전 남은 치즈의 개수
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	// 결과 출력
	int result = BFS();
	cout << wastedTime << "\n";
	cout << result;

}
