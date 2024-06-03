// 동전 / baekjoon_9084.cpp
// https://www.acmicpc.net/problem/9084

#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int arr[21];
int cnt[10001];
int N, M;

void Input() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;

}

void Solve() {

    for (int i = 0; i <= 10000; i++)
        cnt[i] = 0;

    cnt[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= M; j++) {
            cnt[j] += cnt[j - arr[i]];
        }
    }
    
    cout << cnt[M] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        Input();
        Solve();
    }

}