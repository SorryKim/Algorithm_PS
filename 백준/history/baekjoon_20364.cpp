// 부동산 다툼 / baekjoon_20364.cpp
// https://www.acmicpc.net/problem/20364

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, Q;
vector<bool> visited;

void Func(int n) {

	stack<int> path;
	int temp = n;
	while (temp != 0) {
		path.push(temp);
		temp /= 2;
	}

	while (!path.empty()) {
		int now = path.top();
		path.pop();
		if (visited[now] == true) {
			cout << now << "\n";
			return;
		}
		if (path.empty() && visited[now] == false) {
			visited[now] = true;
			cout << 0 << "\n";
		}
			
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	for (int i = 0; i <= N; i++) {
		visited.push_back(false);
	}

	for (int i = 0; i < Q; i++) {
		int num;
		cin >> num;
		Func(num);
	}

	
}
