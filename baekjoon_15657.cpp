// N과 M (8) / baekjoon_15657.cpp
// https://www.acmicpc.net/problem/15657

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool visited[9] = { false, };
vector<int> v;
int result[9];

void DFS(int start, int cnt, int index) {

	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < N; i++) {
		result[index] = v[i];
		DFS(i, cnt + 1, index+1);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	DFS(0, 0, 0);

}
