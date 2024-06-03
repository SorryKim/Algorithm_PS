// baekjoon_2609
// https://www.acmicpc.net/problem/2609

#include <iostream>
using namespace std;

// 최대공약수를 구하는 함수 , 유클리드 호제법 사용
int cal(int a, int b) {
	int c = a % b; // a > b
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}

	return b;
}

int main() {
	int a, b;
	cin >> a >> b;
	
	// 최대 공약수 출력
	if (a >= b)
		cout << cal(a, b) << endl;
	else
		cout << cal(b, a) << endl;

	// 두 수의 곱 = 최대 공약수 * 최소 공배수
	// 따라서 최소 공배수 = 두 수의 곱 / 최대 공약수

	if (a >= b)
		cout << a * b / cal(a, b) << endl;
	else
		cout << a * b / cal(b, a) << endl;



}
