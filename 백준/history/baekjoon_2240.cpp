// 자두나무 / baekjoon_2240.cpp
// https://www.acmicpc.net/problem/2240

#include <iostream>
#include <algorithm>
using namespace std;

int T, W;
int arr[1001];


void Input() {

    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        cin >> arr[i];
    }
}

void Solve() {

    
    int dp[1001][31][2]; // 시간, 이동 횟수, 위치를 나타내는 3차원 배열

    // 초기값 설정
    if (arr[1] == 1) {
        dp[1][0][0] = 1;
        dp[1][1][1] = 0;
    }
    else {
        dp[1][0][0] = 0;
        dp[1][1][1] = 1;
    }

    int result = max(dp[1][0][0], dp[1][1][1]);

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            
            if (j > 0) {

                // 1번 나무에 떨어지는 경우
                if (arr[i] == 1) {
                    dp[i][j][0] = max(dp[i - 1][j - 1][1], dp[i - 1][j][0]) + 1;
                    dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]);
                }
                // 2번 나무에 떨어지는 경우
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + 1;
                }
            }

            // 움직이지 않는 경우
            else {
                if (arr[i] == 1) {
                    dp[i][0][0] = dp[i - 1][0][0] + 1;
                    dp[i][0][1] = dp[i - 1][0][1];
                }
                else {
                    dp[i][0][0] = dp[i - 1][0][0];
                    dp[i][0][1] = dp[i - 1][0][1] + 1;
                }
            }

            result = max(result, max(dp[i][j][0], dp[i][j][1]));
        }
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
