#include <bits/stdc++.h>
using namespace std;

int G;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> G;

    int left = 1, right = 1;
    bool found = false;

    while (right <= 100000) {
        long long val = 1LL * right * right - 1LL * left * left;

        if (val == G) {
            cout << right << '\n';
            found = true;
            right++;
        }
        else if (val < G) right++;
        else left++;
    }

    if (!found) cout << -1 << '\n';
    
    return 0;
}
