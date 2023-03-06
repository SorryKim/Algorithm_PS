// 퇴사 2 / baekjoon_15486.cpp
// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1500001][2];
int dp[1500001];

void Input() {

    cin >> N;
    for (int i = 1; i <= N; i++) {

        cin >> arr[i][0] >> arr[i][1];

    }
    
}

void Solve() {

    int result = 0;

    
    for (int i = 1; i <= N + 1; i++) {

        result = max(result, dp[i]);

        int day = i + arr[i][0];
        int money = arr[i][1] + result;

        // 퇴사
        if (i + arr[i][0] > N + 1)
            continue;

        dp[day] = max(money, dp[day]);
    }

    cout << result << "\n";
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}
