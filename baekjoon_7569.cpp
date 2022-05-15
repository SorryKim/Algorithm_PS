// 토마토 / baekjoon_7569.cpp
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int box[101][101][101];
bool visited[101][101][101];
int moveX[6] = { 1,-1,0,0,0,0 };
int moveY[6] = { 0,0,1,-1,0,0 };
int moveZ[6] = { 0,0,0,0,1,-1 };

class tomato {
public:
	int x, y, z;
	int cnt;
	tomato() {}
	tomato(int x, int y, int z,int n) {
		this->x = x;
		this->y = y;
		this->z = z;
		cnt = n;
	}
};

queue<tomato> q;

int BFS() {
	int result = 0;
	while (!q.empty()) {
		tomato t = q.front();
		int x0 = t.x;
		int y0 = t.y;
		int z0 = t.z;
		result = max(result, t.cnt);
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			int nowZ = z0 + moveZ[i];
			if(nowX >= 0 && nowY >= 0 && nowZ >=0 && nowX < N && nowY < M && nowZ < H && visited[nowX][nowY][nowZ] == false && box[nowX][nowY][nowZ] == 0){
				visited[nowX][nowY][nowZ] = true;
				q.push({ nowX,nowY,nowZ, t.cnt + 1 });
				box[nowX][nowY][nowZ] = 1;
			}
		}
	}

	return result;
}

bool check() {
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][k] == 0)
					return false;
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool b = false;
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[i][j][k];
				// 익어있는 토마토는 큐에 저장
				if (box[i][j][k] == 1) {
					q.push({ i,j,k,0 });
					visited[i][j][k] = true;
				}
				// 익지않은 토마토는 방문여부 배열에 체크
				if (box[i][j][k] == 0) {
					b = true;
					visited[i][j][k] = false;
				}
				// 빈공간은 체크해서 탐색하지않게 함
				else
					visited[i][j][k] = true;
			}
		}
	}


	int result = BFS();

	// 결과 출력
	if (check())
		if (b)
			cout << result;
		else
			cout << 0; // 이미 토마토가 다 익어있는 경우
	else
		cout << -1; // 익지않은 토마토가 존재하는 경우

}
