// 인구 이동 / baekjoon_16234.cpp
// https://www.acmicpc.net/problem/16234

#include <iostream>
#include <queue>
using namespace std;

int N, L, R;
int graph[50][50];
bool visited[50][50] = { false, };
int cnt = 1;
int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,1,-1 };
queue<pair<int, int>> temp; // 한 연합의 가입된 칸의 좌표들

// 연합을 만드는 BFS, 연합을 만들지 않는 경우 -1 반환
int BFS(int x, int y) {
	int cnt = 1; // 연합을 이루는 칸의 갯수
	int sum = graph[x][y]; // 연합의 인구수
	queue<pair<int, int>> q;
	q.push({ x,y });
	temp.push({ x,y });
	visited[x][y] = true;
	bool b = false; // 국경선이 합병 여부 체크

	while(!q.empty()){
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];

			if (nowX >= 0 && nowY >= 0 && nowX < N && nowY < N) {
				int value = abs(graph[x0][y0] - graph[nowX][nowY]);

				if (visited[nowX][nowY] == false && value >= L && value <= R) {
					b = true;
					visited[nowX][nowY] = true;
					q.push({ nowX,nowY });
					cnt++;
					sum += graph[nowX][nowY];
					temp.push({ nowX,nowY });
				}
			}
		}
	}
	if (b)
		return sum / cnt;
	else
		return -1;
}

// bool형 배열 초기화 메소드
void Clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int time = 0;
	while (true) {
		Clear(); 
		bool b = false; // 국경선이 열리는지 여부
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					int value = BFS(i, j);
					// 연합을 만든 경우 각 연합의 인구수를 맞춰줌
					if (value != -1) {
						b = true;
						while (!temp.empty()) {
							int x = temp.front().first;
							int y = temp.front().second;
							graph[x][y] = value;
							temp.pop();
						}
					}
					// 연합을 만들지 않는 경우 temp 큐를 비움
					else {
						temp.pop();
					}
				}
			}
		}

		// 인구 이동이 발생하지 않은 경우
		if (!b)
			break;
		// 발생한 경우
		else
			time++;
		
	}

	cout << time;
}
