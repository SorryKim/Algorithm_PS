// 치킨 배달 / baekjoon_15686.cpp
// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
int map[51][51] = { 0, };
bool check[13] = { false, };
int result = INT32_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;

// n == 치킨집 인덱스, cnt는 선택된 치킨집의 수
void DFS(int n, int cnt) {
	if (cnt > chicken.size())
		return;

	// M개가 선택된 경우 치킨거리를 구하고 재귀 종료
	if (cnt == M) {
		int tmp = 0;
		for (int i = 0; i < home.size(); i++) {
			int distance = INT32_MAX;
			for (int j = 0; j < selected.size(); j++) {
				distance = min(distance, (abs(home[i].first - selected[j].first) + abs(home[i].second - selected[j].second)));
			}
			tmp += distance;
		}
		result = min(tmp, result);
		return;
	}

	// M개의 치킨집을 뽑아 selected벡터에 넣어줌
	for (int i = n; i < chicken.size(); i++) {
		if (check[i] == true)
			continue;
		else {
			check[i] = true;
			selected.push_back({ chicken[i].first, chicken[i].second });
			DFS(i, cnt + 1);
			check[i] = false;
			selected.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 1) {
				home.push_back({ i,j });
			}
			if (num == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	DFS(0, 0);

	cout << result;


}
