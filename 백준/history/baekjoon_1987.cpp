// 알파벳 /  baekjoon_1987.cpp
// https://www.acmicpc.net/problem/1987

#include <iostream>
using namespace std;

int R, C;
char board[20][20];
bool check[26] = { false, }; // 사용한 알파벳을 체크하는 배열
int result = 0;
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

void DFS(int x, int y, int cnt) {

	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int nowX = x + moveX[i];
		int nowY = y + moveY[i];
		if (nowX >= 0 && nowX < R && nowY >= 0 && nowY < C) {
			int index = board[nowX][nowY] - 'A';
			if (check[index] == false){
				check[index] = true;
				DFS(nowX, nowY, cnt + 1);
				check[index] = false; // 백트래킹시 미사용으로 하기 위함
			}
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	// 첫번째 칸 표기

	check[board[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	
	cout << result;
}
