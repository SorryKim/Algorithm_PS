// baekjoon_11052
// https://www.acmicpc.net/problem/11052

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, };
int price[1001] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		price[i] = num;
		arr[i] = num;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (price[j] + price[i-j] > price[i]) {
				price[i] = price[j] + price[i - j];
			}
		}
	}

	cout << price[N];
} 
