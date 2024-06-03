// 가장 긴 증가하는 부분 수열 2 / baekjoon_12015.cpp
// https://www.acmicpc.net/problem/12015

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> v;

void input() {

	cin >> N;
	v.push_back(0);
}

void solve() {

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num > v.back()) {
			v.push_back(num);
		}
		else {

			// lower_bound, 이진탐색 기반
			// v.begin()을 빼주면  num값 이상의 숫자가 처음을 등장하는 인덱스위치를 알려준다
			// sort가 되어있어야한다.
			/*int index = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[index] = num;*/

			// 이진탐색 구현
			int left = 0;
			int right = v.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;

				if (v[mid] == num)
					break;

				if (v[mid] < num)
					left = mid + 1;
				else {
					if (v[mid - 1] < num) {
						v[mid] = num;
						break;
					}
					else
						right = mid - 1;
				}
			}
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
