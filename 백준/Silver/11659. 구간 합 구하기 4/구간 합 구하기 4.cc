// baekjoon_11659
// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>
using namespace std;

vector<int> sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sum.push_back(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N+1; i++) {
		int num;
		cin >> num;
		int value = num + sum[i - 1];
		sum.push_back(value);
	}

	for (int test = 0; test < M; test++) {
		int start, finish;
		cin >> start >> finish;
		cout << sum[finish] - sum[start - 1] << "\n";
	}
	
}
