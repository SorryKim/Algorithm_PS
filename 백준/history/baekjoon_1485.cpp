// 정사각형 / baekjoon_1485.cpp
// https://www.acmicpc.net/problem/1485

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// x좌표 y좌표순으로 정렬
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) {
		return true;
	}
	if (a.first > b.first) {
		return false;
	}
	else {
		if (a.second < b.second)
			return true;
		else
			return false;
	}
}

// 거리를 구하는 메소드
long long dist(pair<int, int> a, pair<int, int> b) {
	int v1 = (a.first - b.first) * (a.first - b.first);
	int v2 = (a.second - b.second) * (a.second - b.second);
	return v1 + v2;
}

// 정사각형인지 확인하는 메소드
int check(pair<int, int> arr[]) {
	if (dist(arr[0], arr[1]) == dist(arr[0], arr[2]) && dist(arr[3], arr[2]) == dist(arr[3], arr[1]))
		if (dist(arr[0], arr[3]) == dist(arr[1], arr[2]))
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		pair<int, int> arr[4];
		for (int i = 0; i < 4; i++) {
			pair<int, int> a;
			cin >> a.first >> a.second;
			arr[i] = a;
		}

		sort(arr, arr + 4, compare);
		cout << check(arr) << "\n";
		
	}

}
