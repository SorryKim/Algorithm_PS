// baekjoon_17298
// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	stack<int> s;
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	delete arr;
	for (auto a : result) {
		printf("%d ", a);
	}

	
}