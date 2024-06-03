// 수리공 항승/ baekjoon_1449.cpp
// https://www.acmicpc.net/problem/1449

#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];

void Input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void Solve() {

    sort(arr, arr + N);
    int start = arr[0];
    int result = 1;

    for (int i = 0; i < N; i++) {

        if (arr[i] - start + 1 > L) {
            result++;
            start = arr[i];
        }
    }

    cout << result << "\n";
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();

}
