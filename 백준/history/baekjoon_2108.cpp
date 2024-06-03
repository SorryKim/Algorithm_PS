// baekjoon_2108
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int number[8001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int n;
	cin >> n;
	int* arr = new int[n];
	long long sum = 0;
	fill_n(number, 8001, 0);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		sum += num;
		number[num + 4000] = number[num + 4000] + 1;
	}
    
	sort(arr, arr + n);
	int count = 0;
	int max = *max_element(number, number + 8001);
	int value = 0;

	for (int i = 0; i <= 8000; i++) {
		if (number[i] == max) {
			count++;
			value = i - 4000;
		}
		if (count == 2) {
			value = i - 4000;
			break;
		}
	}

	double avg = double(sum) / n;
	if (round(avg) == -0)
		cout << 0 << "\n";
	else
		cout << round(avg) << "\n";
	cout << arr[n / 2] << "\n";
	cout << value << "\n";
	cout << arr[n - 1] - arr[0] << "\n";

	delete[] arr;
}
