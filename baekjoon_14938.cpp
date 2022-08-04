// 서강그라운드  / baekjoon_14938.cpp
// https://www.acmicpc.net/problem/14938

#include<iostream>
#include<algorithm>
using namespace std;

#define INF 987654321
int n, m, r;
int item[101];
int graph[101][101];
int result;

void input() {

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = INF;
		}
	}

	for (int i = 0; i < r; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;
		graph[start][end] = dist;
		graph[end][start] = dist;
	}

}

void solve() {

	int cnt = 0;

	// 플로이드 - 워샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++){
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++){
		cnt = item[i];
		for (int j = 0; j <= n; j++){
			if (i != j && graph[i][j] <= m) 
				cnt += item[j];
		}
		result = max(result, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << result << "\n";
}
