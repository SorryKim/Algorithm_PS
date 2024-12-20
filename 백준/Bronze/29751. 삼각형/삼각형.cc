#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double W, H;
    cin >> W >> H;

    double ans = (W * H) / 2;
    
    cout << fixed << setprecision(1) << ans << '\n';

    return 0;
}