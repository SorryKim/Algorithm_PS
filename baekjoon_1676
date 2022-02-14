// baekjoon_1676
// https://www.acmicpc.net/problem/1676

#include <iostream>
#include <string>

using namespace std;

pair<int,int> calc(int n){
	int num2 = 0;
	int num5 = 0;
	int value = n;

	while (true) {
		if (value < 2)
			break;
		if (value % 2 != 0)
			break;
		value /= 2;
		num2++;
	}

	while (true) {
		if (value < 5)
			break;
		if (value % 5 != 0) {
			break;
		}
		value /= 5;
		num5++;
	}
	

	return { num2,num5 };
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;


	pair<int, int> result = { 0,0 };

	for (int i = 0; i <= N; i++) {
		result.first = result.first + calc(i).first;
		result.second = result.second + calc(i).second;
	}

	if (result.first >= result.second)
		cout << result.second;
	else
		cout << result.first;

}
