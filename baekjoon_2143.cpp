// 두 배열의 합 / baekjoon_2143.cpp
// https://www.acmicpc.net/problem/2143

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m;
vector<int> A, B;
long long result;

void Input() {

	cin >> T;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	result = 0;

}


void Solve(){

	vector<long long> v1, v2;

	// 누적 합 벡터에 저장
	for (int i = 0; i < A.size(); i++) {
		long long sum = A[i];
		v1.push_back(sum);
		for (int j = i + 1; j < A.size(); j++) {
			sum += A[j];
			v1.push_back(sum);
		}
	}
	for (int i = 0; i < B.size(); i++) {
		long long sum = B[i];
		v2.push_back(sum);
		for (int j = i + 1; j < B.size(); j++) {
			sum += B[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	

	for (int i = 0; i < v1.size(); i++) {
		int val = T - v1[i];
		// 이진탐색을 통한 원소찾기
		long long low = lower_bound(v2.begin(), v2.end(), val) - v2.begin();
		long long high = upper_bound(v2.begin(), v2.end(), val) - v2.begin();
		result += high - low;
	}

	cout << result << "\n";

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Input();
	Solve();
}
