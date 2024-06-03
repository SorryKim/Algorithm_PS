// 가장 긴 증가하는 부분 수열 3 / baekjoon_12738.cpp
// https://www.acmicpc.net/problem/12738

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<long long> v;

void input() {

	cin >> N;
	v.push_back(-1000000001);
}

void solve() {

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;

		if (num > v.back()) {
			v.push_back(num);
		}
		else {
			long long index = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[index] = num;
			
		}

	}

	cout << v.size() - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}
