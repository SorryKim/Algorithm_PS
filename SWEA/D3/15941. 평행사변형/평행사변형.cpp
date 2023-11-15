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
        int N;
        cin >> N;
        int ans = N * N;
        cout << "#" << test << " " << ans << "\n";
    }
}