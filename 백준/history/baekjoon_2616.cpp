// 소형기관차 / baekjoon_2616.cpp
// https://www.acmicpc.net/problem/2616

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[50001];

void Input() {

    for (int i = 0; i <= 50000; i++)
        arr[i] = 0;

    cin >> N;

    // 누적 합으로 승객 수 저장
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
       
        arr[i] = arr[i - 1] + num;
    }

    cin >> M;
}

void Solve() {

    int dp[50001][4];

    // dp배열 초기화
    for (int i = 0; i <= 50000; i++)
        for (int j = 0; j < 4; j++)
            dp[i][j] = 0;


    for (int i = 1; i <= 3; i++) {
        for (int j = i * M; j <= N; j++) {

            int now = arr[j] - arr[j - M]; // Out of Bounds 발생주의
            int n1 = dp[j - 1][i]; // 이번 객차를 선택안할 경우 최대승객수
            int n2 = dp[j - M][i - 1] + now; // 전에 보낸 승객 수 + 이번에 보낼 승객 수 
            
            dp[j][i] = max(n1, n2);
        }
    }

    
    cout << dp[N][3];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}
