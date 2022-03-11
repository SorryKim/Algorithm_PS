// baekjoon_11729
// https://www.acmicpc.net/problem/11729

#include <iostream>
#include <cmath>
using namespace std;

void Move(int N, int l1,int l2, int l3) {
	if (N == 1) {
		cout << l1 << " " << l3 << "\n";
	}
	else{
		// N - 1개를 l2로 움직임
		Move(N - 1, l1, l3, l2);
		// N번째에 있는 원판을 l3로 이동
		Move(1, l1, l2, l3);
		// N - 1개를 l2에서 l3로 이동
		Move(N - 1, l2, l1, l3);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	int cnt = (int)pow(2, N) - 1; // 움직인 횟수는 2^n - 1이 된다.
	cout << cnt << "\n";
	Move(N, 1, 2, 3);

}
