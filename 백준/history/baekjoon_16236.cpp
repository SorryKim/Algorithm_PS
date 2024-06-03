// 아기 상어 / baekjoon_16236.cpp
// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int map[20][20] = { 0, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

class Fish {
public:
	int y, x, distance;

	// 생성자
	Fish(int y, int x, int distance) {
		this->y = y;
		this->x = x;
		this->distance = distance;
	}

	// 우선순위 큐를 활용하기 위한 비교연산자 정의
	bool operator<(const Fish& f) const {
		if (distance == f.distance){
			if (y == f.y)
				return x > f.x;
			return y > f.y;
		}
		return distance > f.distance;
	}
};

queue<Fish> shark;

int BFS() {
	int time = 0;
	int cnt = 0;
	int size = 2;

	while (1) {

		priority_queue<Fish> feedFish; // 거리가 가까운 먹이가 우선순위로 올라감
		vector<vector<bool>> visited(N, vector<bool>(N)); // 방문여부확인 2차원 벡터

		// BFS로 현재 먹을 수 있는 먹이들 확인
		while (!shark.empty()) {
			
			Fish nowFish = shark.front();
			shark.pop();

			for (int i = 0; i < 4; i++) {
				int nowX = nowFish.x + moveX[i];
				int nowY = nowFish.y + moveY[i];

				// 움직임이 map을 벗어난 경우
				if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= N)
					continue;

				// 이미 방문했거나 물고기크기가 커서 못지나가는 경우
				if (visited[nowY][nowX] || map[nowY][nowX] > size)
					continue;
				
				visited[nowY][nowX] = true;
				if (map[nowY][nowX] < size && map[nowY][nowX] != 0) {
					feedFish.push({ nowY,nowX,nowFish.distance + 1 });
				}
				shark.push({ nowY,nowX,nowFish.distance + 1 });
			}
		}

		if (feedFish.empty())
			return time;

		// 먹이먹음
		Fish selected = feedFish.top();
		cnt++;
		if (cnt == size) {
			size++;
			cnt = 0;
		}
		map[selected.y][selected.x] = 0;
		shark.push({ selected.y,selected.x, 0 });
		time += selected.distance; // 떨어진 거리만큼 시간 증가
		feedFish.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				shark.push({ i,j,0 });
			}
		}
	}

	cout << BFS();
}
