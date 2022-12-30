// 탈출 / baekjoon_3055.cpp
// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C, result;
char map[51][51];
bool visit[51][51];
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0, 0, 1, -1 };
pair<int, int> start, destination;
queue<pair<int, int>> water;
queue<pair<int, int>> S;


void Input() {

	cin >> R >> C;
	result = 0;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			map[i][j] = s[j];
			if (map[i][j] == '*') {
				water.push({ i,j });
			}
			if (map[i][j] == 'S') {
				S.push({ i,j });
			}
		}
	}
}

// 물의 움직임
void MoveWater() {

	int end = water.size();
	for (int i = 0; i < end; i++) {
		int x0 = water.front().first;
		int y0 = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int nowX = x0 + moveX[i];
			int nowY = y0 + moveY[i];
			if (nowX < 0 || nowX >= R || nowY < 0 || nowY >= C) {
				continue;
			}
			if (map[nowX][nowY] == '.') {
				map[nowX][nowY] = '*';
				water.push({ nowX,nowY });
			}
		}
	}

}

void Print() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << map[i][j];
		cout << "\n";
	}

	cout << "\n";
}

void Solve() {

	while (!S.empty()) {

		result++;
		MoveWater();
		int end = S.size();

		for (int i = 0; i < end; i++) {
			
			int x0 = S.front().first;
			int y0 = S.front().second;
			S.pop();
			for (int j = 0; j < 4; j++) {
				int nowX = x0 + moveX[j];
				int nowY = y0 + moveY[j];

				if (nowX < 0 || nowX >= R || nowY < 0 || nowY >= C)
					continue;

				if (map[nowX][nowY] == '*' || map[nowX][nowY] == 'X' || visit[nowX][nowY])
					continue;

				if (map[nowX][nowY] == '.') {
					visit[nowX][nowY] = true;
					S.push({ nowX, nowY });
				}

				// 도착한 경우
				if (map[nowX][nowY] == 'D') {
					cout << result << "\n";
					return;
				}
			}
		}
	}
	
	// 탈출 실패한 경우
	cout << "KAKTUS" << "\n";
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
