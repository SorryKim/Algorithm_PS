// 맥주 마시면서 걸어가기 / baekjoon_9205.cpp
// https://www.acmicpc.net/problem/9205

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
pair<int, int> store[101];
pair<int, int> home, destination;
bool visited[101];

void Input() {

}

void Solve() {

	queue<pair<int, int>> q;
	q.push({ home.first, home.second });

	while (!q.empty()) {

		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();

		if (abs(destination.first - x0) + abs(destination.second - y0) <= 1000) {
			cout << "happy" << "\n";
			return;
		}

		for (int i = 0; i < n; i++) {
			if (visited[i])
				continue;

			if (abs(store[i].first - x0) + abs(store[i].second - y0) <= 1000) {
				visited[i] = true;
				q.push({ store[i].first, store[i].second });
			}
		}
	}

	cout << "sad" << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while (t--) {

		cin >> n;
		int x, y;

		cin >> home.first >> home.second;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			store[i].first = x;
			store[i].second = y;
		}
		cin >> destination.first >> destination.second;

		for (int i = 0; i < n; i++)
			visited[i] = false;

		Solve();

	}
	
}
