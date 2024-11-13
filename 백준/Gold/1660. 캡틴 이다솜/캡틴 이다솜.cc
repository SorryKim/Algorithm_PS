#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 사면체 모양으로 쌓을 때 필요한 대포알의 개수를 계산
vector<int> Calc(int num) {
    vector<int> result;
    int idx = 1;
    int sum = 0;

    while (true) {
        sum += (idx * (idx + 1)) / 2; 
        if (sum > num) 
            break;
        result.push_back(sum);
        idx++;
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    // 사면체 숫자들을 미리 계산
    vector<int> v = Calc(N);
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int num : v) {
        for (int i = num; i <= N; i++) {
            dp[i] = min(dp[i], dp[i - num] + 1);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
