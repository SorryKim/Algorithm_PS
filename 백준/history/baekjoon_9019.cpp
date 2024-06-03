// DSLR / baekjoon_9019.cpp
// https://www.acmicpc.net/problem/9019

#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool visited[10000];

string BFS(int a, int b) {

	queue<pair<int, string>> q;
	q.push({ a,""});
	visited[a] = true;

	while(!q.empty()){
		int n = q.front().first;
		string s = q.front().second;
		q.pop();

		if (n == b)
			return s;

		// D를 하는 경우
		int D = (2 * n) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D,s +"D"});
		}

		// S를 하는 경우
		int S;
		if (n == 0)
			S = 9999;
		else
			S = n - 1;

		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, s + "S"});
		}

		// L을 하는 경우
		int L = (n % 1000) * 10 + n / 1000;
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L,s + "L" });
		}

		// R을 하는 경우
		int R = (n % 10) * 1000 + (n / 10);
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R,s + "R" });
		}
	
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		for (int i = 0; i < 10000; i++)
			visited[i] = false;
		int a, b;
		cin >> a >> b;
		cout << BFS(a, b) << "\n";
	}

	return 0;
}
