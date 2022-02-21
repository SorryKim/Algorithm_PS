// baekjoon_9375
// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int T = 0; T < N; T++) {
		int cloth = 0;
		cin >> cloth;
		map<string, int> m;
		for (int i = 0; i < cloth; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m.find(s2) != m.end()) {
				m[s2]++;
			}
			else {
				m.insert({ s2,1 });
			}
		}
		int cnt = 1;
		for (auto a : m) {
			cnt *= (a.second + 1);
		}
		cout << cnt - 1 << "\n";
	}
}
