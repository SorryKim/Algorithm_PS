// 친구 / baekjoon_1058.cpp
// https://www.acmicpc.net/problem/1058

#include <iostream>
using namespace std;

#define INF 987654321
int N;
int graph[50][50];

void floyd_warshall(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i == j || j == k || k == i)
					continue;
				else if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			if (i == j) {
				graph[i][j] = 0;
				continue;
			}
			if (ch == 'Y')
				graph[i][j] = 1;
			else if(ch == 'N')
				graph[i][j] = INF;
		}
	}

	floyd_warshall();

	int result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (graph[i][j] <= 2)
				cnt++;
		}
		result = max(result, cnt);
	}

	cout << result;

}
