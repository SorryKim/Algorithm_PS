#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long long ans = 0;

    for(int i = 1; i <= N; i++){
        int expect = v[i - 1];
        ans += abs(i - expect);
    }

    cout << ans << "\n";
    
    return 0;
}
