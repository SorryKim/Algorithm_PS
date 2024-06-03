// baekjoon_7568
// https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<pair<int, int>> v;
	vector<int> result;
	int weight, height, n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> weight >> height;
		v.push_back({ weight,height });
	}

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				rank++;

		}
		result.push_back(rank);
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << result[i];
		else
			cout << result[i] << " ";
	}
}
