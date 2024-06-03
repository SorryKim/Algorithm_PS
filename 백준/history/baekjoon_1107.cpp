// baekjoon_1107
// https://www.acmicpc.net/problem/1107

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v; // 고장난 버튼

// 해당 번호로 출발할 수 있는지 검사하는 함수
bool check(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		int tmp = s[i] - '0';
		for (auto a : v) {
			if (tmp == a)
				return false;
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	// 고장난 버튼 벡터에 저장
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	string goal = to_string(N);
	int result = abs(N - 100); // 100번에서 출발하는 경우의 수

	// 0번부터 ~ 1000000번에서 출발하는 경우를 전부 확인
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int temp = abs(N - i) + to_string(i).length(); // 해당번호에서 목적지까지 도착하는 수
			result = min(result, temp); // 둘 중 작은 값을 저장
		}
	}

	cout << result;

}
