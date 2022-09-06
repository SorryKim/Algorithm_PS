// baekjoon_2667
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[26][26] = { 0, };
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
bool check[26][26] = { false, };
queue <pair<int, int>> q;
int cnt = 0; // 단지 수

int BFS(int x, int y) {

	cnt++;
	int num = 0; // 단지에 속한 집의 수
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty()) {
		num++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowX = x + moveX[i];
			int nowY = y + moveY[i];
			if ((nowX >= 1 && nowY >= 1) && (nowX <= N && nowY <= N)) {
				if (map[nowX][nowY] == 1 && check[nowX][nowY] == false) {
					q.push({ nowX,nowY });
					check[nowX][nowY] = true;
				}
			}
		}

	}

	return num;
}

int main() {

	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			scanf("%1d", &num);
			map[i][j] = num;
		}
	}
	vector<int> v;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((map[i][j] == 1) && (check[i][j] == false)) {
				v.push_back(BFS(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (auto a : v) {
		cout << a << "\n";
	}

}
