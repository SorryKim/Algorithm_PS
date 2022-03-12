// baekjoon_17219
// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	map<string, string> m;
	for (int i = 0; i < N; i++) {
		string domain, password;
		cin >> domain >> password;
		m.insert({ domain, password });
	}

	for (int i = 0; i < M; i++) {
		string domain;
		cin >> domain;
		cout << m[domain] << "\n";
	}
}
