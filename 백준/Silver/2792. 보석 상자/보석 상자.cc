#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> jewels;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    jewels.resize(M);

    for (int i = 0; i < M; i++) cin >> jewels[i];
}

long long solve() {
    long long left = 1;
    long long right = *max_element(jewels.begin(), jewels.end());
    long long ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for (int jewel : jewels) {
            cnt += (jewel + mid - 1) / mid;  // 올림 나눗셈
        }

        if (cnt > N) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    input();
    cout << solve() << '\n';
}
