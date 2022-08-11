// 입국심사 / baekjoon_3079.cpp
// https://www.acmicpc.net/problem/3079

#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int N, M;
long long arr[100001];
long long result = 1000000000000000001;

void input() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

}

void solve() {

    sort(arr, arr+ N);
    long long left = 0;
    long long right = arr[N-1] * M;

    // mid값: 모든 인원이 심사를 받는 데 걸리는 시간
    while (left <= right) {

        long long mid = (left + right) / 2;
        // temp: 심사를 받는 인원 수
        long long temp = 0;

        for (int i = 0; i < N; i++) {
            temp += (mid / arr[i]);
        }

        // mid 시간에 심사를 다 받을 수 있는 경우
        if (temp < M) {
            left = mid + 1;
        }
        else {
            result = min(result, mid);
            right = mid - 1;

        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
