#include <iostream>
#include <cmath>

using namespace std;

static inline long long ceil_div(long long n, long long d) {
    return (n + d - 1) / d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;

        long long r = (long long) sqrt((long double)N);
        while ((r + 1) * (r + 1) <= N) r++;
        while (r * r > N) r--;

        long long s1 = r + ceil_div(N, r);

        long long r2 = r + 1;
        long long s2 = r2 + ceil_div(N, r2);

        long long best = min(s1, s2);
        cout << 2 * best << '\n';
    }
    return 0;
}
