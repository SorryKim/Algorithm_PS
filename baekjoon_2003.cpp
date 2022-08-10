// 수들의 합 2/ baekjoon_2003.cpp
// https://www.acmicpc.net/problem/2003

#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int N, M;

void input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

}

void solve() {

    int start = 0, end = 0;
    int sum = arr[0];
    int cnt = 0;

    while (start <= end && end < N) {

        if (sum < M) {
            end++;
            sum += arr[end];
        }
        else if (sum == M) {
            cnt++;
            end++;
            sum += arr[end];
        }
        else if (sum > M) {
            sum -= arr[start];
            start++;
            if (start > end) {
                end = start;
                sum = arr[start];
            }
        }
        
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
