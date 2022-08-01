// 트리의 지름 / baekjoon_1967.cpp
// https://www.acmicpc.net/problem/1967

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int result, temp;
vector<pair<int, int>> tree[10001];
bool visited[10001] = { false, };

void input() {
	result = 0;
	cin >> n;
	int parent, child, cost;
	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> cost;
		tree[parent].push_back({ child,cost });
		tree[child].push_back({ parent,cost });
	}
}

void DFS(int n, int dist) {

	visited[n] = true;

	// 가장 먼 노드 저장
	if (dist > result) {
		result = dist;
		temp = n;
	}

	for (int i = 0; i < tree[n].size(); i++) {

		int next = tree[n][i].first;
		int next_dist = dist + tree[n][i].second;

		if (!visited[next]) {
			visited[next] = true;
			DFS(next, next_dist);
			visited[next] = false;
		}
	}

}

void clear() {
	for (int i = 1; i <= n; i++)
		visited[i] = false;
}

void calc() {

	// 가장 먼 노드를 구함
	DFS(1, 0);
	result = 0;

	// 가장 먼 노드에서 다시 DFS시작하여 가장 먼노드로 이동
	clear();
	DFS(temp, 0);

	// 결과 출력
	cout << result << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	calc();

	return 0;
}
