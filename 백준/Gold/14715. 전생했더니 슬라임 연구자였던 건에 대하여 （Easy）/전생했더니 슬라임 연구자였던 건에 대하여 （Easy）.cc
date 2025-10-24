#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(int n) {

    if (n < 4) return 0;
    int cnt = 0;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }
    if (n > 1) cnt++; // 마지막 소수 처리

    if (cnt == 1) return 0; // 소수
    return ceil(log2(cnt));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    cout << solve(K) << "\n";
    return 0;
}
