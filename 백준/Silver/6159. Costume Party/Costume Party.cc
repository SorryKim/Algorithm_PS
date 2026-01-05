#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int S;
    cin >> N >> S;

    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    sort(L.begin(), L.end());

    int l = 0, r = N - 1;
    long long ans = 0;

    while (l < r) {
        if (L[l] + L[r] <= S) {
            ans += (r - l);
            l++;
        } else r--;
    }

    cout << ans << "\n";
    return 0;
}
