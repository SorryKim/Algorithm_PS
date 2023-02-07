// 숨바꼭질 4 / baekjoon_13913.cpp
// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int N, K;
bool visited[200000] = { false, };
int route[200000];

void Input() {

	cin >> N >> K;

}

void BFS() {

	queue<pair<int, int>> q;
	int time = 0;
	vector<int> v;
	q.push({ N,0 });

	while (!q.empty()) {

		int now = q.front().first;
		int time = q.front().second;
		visited[now] = true;
		q.pop();

		if (now == K) {
			cout << time << "\n";

			stack<int> st;
			int index = now;

			while (index != N) {
				st.push(index);
				index = route[index];
			}
			st.push(N);

			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}


			return;
		}

		// *2배로 이동
		if (now * 2 >= 0 && now * 2 <= 100000 && visited[now * 2] == false) {
			route[now * 2] = now;
			visited[now * 2] = true;
			q.push({ now * 2, time + 1 });
		}

		// + 1로 이동
		if (now + 1 >= 0 && now + 1 <= 100000 && visited[now + 1] == false) {
			route[now + 1] = now;
			visited[now + 1] = true;
			q.push({ now + 1, time + 1 });
		}

		// -1로 이동
		if (now - 1 >= 0 && now - 1 <= 100000 && visited[now - 1] == false) {
			route[now - 1] = now;
			visited[now - 1] = true;
			q.push({ now - 1, time + 1 });
		}
	}

	return;

}

void Solve() {

	BFS();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
