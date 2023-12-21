#include <iostream>
#include <vector>
using namespace std;

int N;

void Input() {
    cin >> N;
}

void Solve() {

    long long dp[101] = { 0, };
    long long val = 0;

    for (int i = 1; i <= N; i++) {

        // a누르는 경우
        dp[i] = dp[i - 1] + 1;

        // 붙여넣기 하는 경우 2에서부터 현재 지점까지 작업 시작
        for (int j = 3; j <= i - 2; j++) {

            // j부터 i까지 반복
            long long copy = dp[j - 2];
            dp[i] = max(dp[i], copy * (i - j + 1));
        }
    }

    cout << dp[N] << "\n";
}


int main() {
    
    Input();
    Solve();

    return 0;
}
