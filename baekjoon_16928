// baekjoon_16928
// https://www.acmicpc.net/problem/16928

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[101] = { false, };
vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;
int dice[6] = { 1,2,3,4,5,6 };


// 현재의 칸이 사다리인지 뱀인지 구분하는 메소드
int isSnakeOrisLadder(int n) {
	for (int i = 0; i < snake.size(); i++) {
		if (n == snake[i].first)
			return snake[i].second;
	}
	for (int i = 0; i < ladder.size(); i++) {
		if (n == ladder[i].first)
			return ladder[i].second;
	}
	return n;
}

int BFS() {
	queue<pair<int,int>> q;
	q.push({ 1,0 });

	while (!q.empty()) {
		int x0 = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[x0] = true;

		if (x0 == 100)
			return cnt;

		for (int i = 0; i < 6; i++) {
			int nowX0 = x0 + dice[i];
			int nowX = isSnakeOrisLadder(nowX0); // 뱀과 사다리여부 처리
			if (visited[nowX] == false && nowX >0 && nowX <= 100) {
				q.push({nowX, cnt + 1});
			}
		
		}
	}

	return 0;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		ladder.push_back({ x,y });
	}
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		snake.push_back({ x,y });
	}
	
	cout << BFS();
}
