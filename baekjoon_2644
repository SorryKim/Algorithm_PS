// baekjoon_2644
// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <queue>
using namespace std;

int visited[101] = { 0, };
int people[101][101] = { 0, };

void BFS(int x, int y) {
	visited[x] = 1;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= 100; i++) {
			if (visited[i] != 0 || people[now][i] == 0)
				continue;
			q.push(i);
			visited[i] = visited[now] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y;
	cin >> n;
	cin >> x >> y;
	cin >> m;

	while (m--) {
		int x1, y1;
		cin >> x1 >> y1;
		people[x1][y1] = 1;
		people[y1][x1] = 1;
	}

	BFS(x, y);

	if (visited[y] == 0)
		cout << -1;
	else {
		cout << visited[y] - 1;
	}

}
