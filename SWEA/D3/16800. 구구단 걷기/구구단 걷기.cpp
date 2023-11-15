#include <iostream>
#include <climits>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        long long N;
        cin >> N;
        long long ans = LLONG_MAX - 1;
        long a = 0, b = 0;
        for (int i = 1; i <= sqrt(N); i++) {
            
            if (N % i == 0) {
                a = i;
                b = N / i;
                a--;
                b--;
                ans = ans > a + b ? a + b : ans;
            }
            
        }
        cout << "#" << test << " " << ans << "\n";
    }
}