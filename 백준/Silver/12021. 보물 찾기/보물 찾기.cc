#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b;
    cin >> a >> b;

    long double ans = sqrt(a * b);

    cout << fixed << setprecision(10) << ans << ' ' << ans << '\n';
    return 0;
}