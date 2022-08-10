// 부분합 / baekjoon_1806.cpp
// https://www.acmicpc.net/problem/1806

#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int N, S;

void input() {

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

}

void solve() {

    int start = 0, end = 0;
    int sum = arr[0];
    int result = 987654321;

    while (start <= end && end < N) {

        if (sum >= S)
            result = min(result, (end - start + 1));

        if (sum < S) {
            end++;
            sum += arr[end];
        }
        else {
            sum -= arr[start];
            start++;
        }

    }

    if (result == 987654321)
        cout << "0";
    else
        cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

}
