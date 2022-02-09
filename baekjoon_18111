// baekjoon_18111
// https://www.acmicpc.net/problem/18111

#include<iostream>
using namespace std;

int arr[500][500];
int n, m, b;

// 주어진 층을 기준으로 평평하게 만들 경우의 시간을 반환하는 함수
int calc(int height) {
	int time = 0;
	int block = b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > height) { 
				int num = arr[i][j] - height;
				time = time + num*2;
				block = block + num;
			}
			else {
				int num = height - arr[i][j];
				time = time + num;
				block = block - num;
			}
		}
	}

	if (block < 0) {
		return -1;
	}
	else {
		return time;
	}
}

int main() {
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int time = 0;
	int height = 0;
	int min_time = 2147483647;

	// 가능한 높이는 0 ~ 256범위
	for (int i = 0; i <= 256; i++) {
		time = calc(i);
		if (time >= 0) {
			// 결과가 같은 경우 더 높은 층이 출력되도록 조건 설정
			if (min_time >= time) {
				min_time = time;
				height = i;
			}
		}
	}

	// 결과 출력
	cout << min_time << " " << height;
}
