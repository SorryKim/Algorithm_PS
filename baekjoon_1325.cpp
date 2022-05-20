// 효율적인 해킹 / baekjoon_1325.cpp
// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];
vector<int> v;
int cnt = 0;
int temp = 0;

void DFS(int n) {
	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		int now = graph[n][i];
		if (visited[now] == false) {
			cnt++;
			DFS(now);
		}
	}
}

void clear() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	// 2차원 배열 사용시 메모리 초과 발생하여 벡터사용
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		clear();
		cnt = 0;
		DFS(i);
		if (temp == cnt) {
			v.push_back(i);
		}
		else if (temp < cnt) {
			temp = cnt;
			v.clear();
			v.push_back(i);
		}
	}

	// sort
	sort(v.begin(), v.end());

	for (auto a : v) 
		cout << a << " ";
	
}
