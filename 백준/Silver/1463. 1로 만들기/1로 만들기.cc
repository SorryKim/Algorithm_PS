#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	int* arr = new int[x + 1];
	arr[0] = 0;
	arr[1] = 1;
	if (x >= 2)
		arr[2] = 1;
	if (x >= 3)
		arr[3] = 1;

	if (x >= 4) {
		for (int i = 4; i <= x; i++) {
			arr[i] = arr[i - 1] + 1;
			if (i % 2 == 0) {
				arr[i] = min(arr[i / 2] + 1, arr[i]);
			}
			if (i % 3 == 0) {
				arr[i] = min(arr[i / 3] + 1, arr[i]);
			}
		}
	}

	if (x == 1)
		cout << 0;
	else
		printf("%d",arr[x]);
	delete[] arr;
}