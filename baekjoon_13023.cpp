// ABCDE / baekjoon_13023.cpp
// https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[2001] = { false, };
int result;

void DFS(int n, int dep, vector<vector<int>>& v) {

	if (dep == 4) {
		result = 1;
		return;
	}

	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (visited[next])
			continue;
		visited[next] = true;
		DFS(next, dep + 1, v);
		visited[next] = false;
	}

}

void clear() {
	for (int i = 0; i <= 2000; i++) {
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	result = 0;
	vector<vector<int>> v(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		clear();
		visited[i] = true;
		DFS(i, 0, v);
		if (result == 1) {
			break;
		}
	}

	cout << result << "\n";
}
