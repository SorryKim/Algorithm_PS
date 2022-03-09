// baekjoon_18870
// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	vector<int> v, v2;
	// v로 각 원소에 순서정해줌
	// v2는 원본

	while (N--) {
		int value;
		cin >> value;
		v.push_back(value);
		v2.push_back(value);
	}

	unique(v.begin(), v.end()); // 벡터의 중복원소들을 뒤로 몰아주는 unique메소드 algorithm 헤더에 존재
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복원소들을 삭제


	// lower_bound메소드, key값이상인 숫자가 몇번째 배열에서 나타나는지 아는 메소드
	// 이진탐색을 사용하여 탐색함, 반환 값이 iterator 이다.
	for (auto a : v2) {
		auto a2 = lower_bound(v.begin(), v.end(), a);
		cout << a2 - v.begin() << " ";
	}

}
