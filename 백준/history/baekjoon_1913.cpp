// 달팽이 / baekjoon_1913.cpp
// https://www.acmicpc.net/problem/1913

#include <iostream>
using namespace std;

int N, num;
int arr[1000][1000];

// 가장 바깥쪽 테두리부터 하나씩 채워들어감
void func(int n) {

	if (n == 1)
		return;

	int start = (n - N - 2) / (-2);
	int end = start + n - 1;
	int val = n * n;

	// 11시방향에서 7시 방향
	for (int i = start; i <= end; i++) {
		arr[i][start] = val;
		val--;
	}

	// 7시방향에서 5시 방향
	for (int i = start + 1; i <= end; i++) {
		arr[end][i] = val;
		val--;
	}

	// 5시 방향에서 1시 방향
	for (int i = end - 1; i >= start; i--) {
		arr[i][end] = val;
		val--;
	}
	 
	// 1시 방향에서 11시 방향
	for (int i = end - 1; i >= start + 1; i--) {
		arr[start][i] = val;
		val--;
	}

}

void make() {
	int tmp = N;
	while (tmp != 1) {
		func(tmp);
		tmp -= 2;
	}

	int a = (int)(N / 2) + 1;
	arr[a][a] = 1;

}

// 위치를 찾고자하는 자연수
pair<int,int> search(int n) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == num)
				return { i,j };
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> num;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++)
			arr[i][j] = 0;
	}

	make();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	pair<int, int> target = search(num);
	cout << target.first << " " << target.second;
}
