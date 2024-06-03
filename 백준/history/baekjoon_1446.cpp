// 지름길 / baekjoon_1446.cpp
// https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
using namespace std;

int N, D;
#define INF  987654321
int map[10001];
vector<pair<int, int>> v[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;
	for (int i = 0; i <= 10000; i++)
		map[i] = INF;

	// 도착지점에 {출발지점, 거리값} 쌍 적용
	for(int i = 0 ; i < N;i++){
		int start, destination, cost;
		cin >> start >> destination >> cost;
		v[destination].push_back({ start,cost });
	}

	map[0] = 0;

	for (int i = 1; i <= D; i++) {
		if (v[i].size() == 0) {
			map[i] = map[i - 1] + 1;
		}
		else {
			for (int j = 0; j < v[i].size(); j++) {
				map[i] = min(map[i], min(map[i - 1] + 1, map[v[i][j].first] + v[i][j].second));
			}
		}
	}

	cout << map[D];
}
