// 검문  / baekjoon_2981.cpp
// https://www.acmicpc.net/problem/2981

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
vector<int> result;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}

// 최대공약수를 구하는 함수
int GCD(int a, int b) {

	if (b == 0)
		return a;

	return GCD(b, a % b);
}

void Solve() {

	sort(v.begin(), v.end());
	int gcd = v[1] - v[0];

	// N - 1개의 v[i] - v[i - 1] 값들의 최대공약수를 구함
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, v[i] - v[i - 1]);
	}

	// 유클리드 호제법으로 gcd값의 약수를 구함
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0){
			result.push_back(i);
			result.push_back(gcd / i);
		}
	}

	result.push_back(gcd);
	sort(result.begin(), result.end());

	// 중복값 제거
	result.erase(unique(result.begin(), result.end()), result.end());

	for (auto a : result)
		cout << a << " ";

}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	
}
