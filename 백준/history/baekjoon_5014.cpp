// 스타트링크 / baekjoon_5014.cpp
// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool building[1000001] = { false, };
int dir[2];

// F: 건물의 총 층수
// S: 강호가 지금 있는 층
// G: 스타트링크의 위치
// U: 위층으로 이동하는 엘레베이터의 버튼
// D: 아래층으로 이동하는 엘레베이터의 버튼

int BFS(int n) {
	queue<pair<int,int>> q;
	q.push({ n,0 });
	building[n] = true;
	
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		if (now == G)
			return cnt;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next = now + dir[i];

			if ((next <= F && next >=1) && building[next] == false) {
				building[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	dir[0] = U;
	dir[1] = -1 * D;

	int result = BFS(S);
	if (result == -1) {
		cout << "use the stairs";
	}
	else {
		cout << result;
	}

}
