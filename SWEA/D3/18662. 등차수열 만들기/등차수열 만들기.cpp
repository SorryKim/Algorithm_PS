#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {

        double a, b, c;
        cin >> a >> b >> c;

        double x1, x2 , ans = 0;
        x1 = abs(2 * b - a - c);
        x2 = abs((a + c) / 2 - b);
        
        ans = x1 <= x2 ? x1 : x2;
        
        cout.precision(1);
        cout << fixed;
        cout << "#" << test << " " << ans <<"\n";

    }

}