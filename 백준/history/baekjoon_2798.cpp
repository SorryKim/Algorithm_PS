// baekjoon_2798
// https://www.acmicpc.net/problem/2798

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int result = 0;
	int sum= 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i+1; j < n-1 ; j++) {
			for (int k = j+1; k < n; k++) {
				sum = v[i] + v[j] + v[k];
				if (sum >= result && sum <= m)
					result = sum;
			}
		}
	}
	cout << result;
}
