// 조합 / baekjoon_2407.cpp
// https://www.acmicpc.net/problem/2407

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
string com[101][101] = {};

string add(string s1, string s2) {
	int sum = 0;
	string result = "";

	while (!s1.empty() || !s2.empty() || sum) {

		if (!s1.empty()) {
			sum += s1.back() - '0';
			s1.pop_back();
		}

		if (!s2.empty()) {
			sum += s2.back() - '0';
			s2.pop_back();
		}

		// 자릿수저장
		result += sum % 10 + '0';
		// carry
		sum /= 10;
	}

	// 역순으로 되어있기때문에 뒤집어줌
	reverse(result.begin(), result.end());
	return result;
}

string combination(int n1, int n2) {

	string &result = com[n1][n2]; // 수정하기 위해 &사용

	// 재귀함수 종료지점
	if (n1 == n2 || n2 == 0)
		return "1";

	if (result != "") 
		return result;

	// nCr = n-1 C r + n-1 C r-1, 공식사용
	result = add(combination(n1 - 1, n2 - 1), combination(n1 - 1, n2));
	return result;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&com[0][0], &com[100][101], "");

	cin >> N >> M;

	cout << combination(N, M);

}
