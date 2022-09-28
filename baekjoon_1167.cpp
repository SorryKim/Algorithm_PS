// 트리의 지름 / baekjoon_1167.cpp
// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int V, maxNode, maxDist;
bool check[100001] = { false, };
vector<pair<int, int>> tree[100001]; // { 다른 정점, 거리 } 쌍 형태

void Input() {

	cin >> V;

	for (int i = 0; i < V; i++) {
		int start,end,dist;

		cin >> start;

		while (true) {
			cin >> end;
			if (end == -1)
				break;
			cin >> dist;
			tree[start].push_back(make_pair(end, dist));
		}
	}

}

void DFS(int node, int dist) {

	if (check[node])
		return;
	check[node] = true;

	// 최대 노드 갱신
	if (maxDist < dist) {
		maxDist = dist;
		maxNode = node;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first;
		int nextDist = tree[node][i].second;
		DFS(next, dist + nextDist);
	}

}

void Solve() {
	
	// 정점 1에서 가장 먼 정점을 구함
	DFS(1, 0);

	for (int i = 0; i <= 100000; i++)
		check[i] = false;
	maxDist = 0;

	// 1에서 구한 가장 먼 정점에서 다시 가장 먼 정점까지의 거리를 구함
	DFS(maxNode, 0);

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	cout << maxDist;
}
