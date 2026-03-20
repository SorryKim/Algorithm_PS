#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> seq;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    seq.resize(N);
    for (int i = 0; i < N; i++) cin >> seq[i];
}

int solve() {
    int cnt = 0;
    int mn = 0, mx = 0;

    for (int i = 0; i < N; i++) {
        if (cnt == 0) {
            cnt = 1;
            mn = mx = seq[i];
            continue;
        }

        int new_mn = min(mn, seq[i]);
        int new_mx = max(mx, seq[i]);

        if (new_mx - new_mn <= K - 1) {
            mn = new_mn;
            mx = new_mx;
        } else {
            cnt++;
            mn = mx = seq[i];
        }
    }

    return cnt - 1; // 처음 시작은 이동이 아님
}

int main() {
    input();
    cout << solve() << '\n';
    return 0;
}