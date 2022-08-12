// 두 용액 / baekjoon_2470.cpp
// https://www.acmicpc.net/problem/2470

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
long long arr[100001];
long long sum = 1000000000001;
long long temp[2];

void input() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {

    sort(arr, arr + N);
    int left = 0;
    int right = N - 1;

    while (left < right) {
        long long value = arr[left] + arr[right];

        if (abs(sum) > abs(value)) {
            sum = value;
            temp[0] = arr[left];
            temp[1] = arr[right];
        }

        if (value > 0)
            right--;
        else if (value < 0)
            left++;
        else {
            temp[0] = arr[left];
            temp[1] = arr[right];
            break;
        }

    }

    cout << temp[0] << " " << temp[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
