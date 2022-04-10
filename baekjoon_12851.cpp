// 숨바꼭질 2 / baekjoon_12851.cpp
// https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
using namespace std;

int N, K;
int cnt = 0;
int minTime = 0;

// 100000 까지 설정하면 틀림, *2로 100000을 넘어서 이동한 후 -1로 동생에게 접근할 수도 있음
bool visited[200000] = { false, }; 


void BFS(int n) {
	queue<pair<int,int>> q; // { 현재위치, 경과시간 }
	q.push({ n,0 });
	visited[n] = true; // 방문여부

	while (!q.empty()){
		int now = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[now] = true;

		// 최솟값 체크
		if (cnt == 0 && now == K) {
			minTime = time;
			cnt++;
		}

		// 방법 수 체크
		else if (time == minTime && now == K && cnt != 0) {
			cnt++;
		}

		// *2배로 이동
		if (now * 2 >= 0 && now * 2 <= 100000 && visited[now * 2] == false) {
			q.push({ now * 2, time + 1 });
		}

		// + 1로 이동
		if (now + 1 >= 0 && now + 1 <= 100000 && visited[now + 1] == false) {
			q.push({ now + 1, time + 1 });
		}

		// -1로 이동
		if (now - 1 >= 0 && now - 1 <= 100000 && visited[now - 1] == false) {
			q.push({ now - 1, time + 1 });
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	BFS(N);
	cout << minTime << "\n";
	cout << cnt << "\n";
}
