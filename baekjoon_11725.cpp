// 트리의 부모 찾기 / baekjoon_11725
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001 // 최대범위

int N;
vector<int> tree[MAX];
int result[MAX];
bool visited[MAX];

void DFS(int n) {
	visited[n] = true;
	for (int i = 0; i < tree[n].size(); i++) { 
		int next = tree[n][i];
		if (visited[next] == false) {
			result[next] = n;
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for(int i = 0 ; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}


}
