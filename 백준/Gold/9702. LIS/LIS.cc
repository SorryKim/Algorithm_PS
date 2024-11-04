#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int N;
        cin >> N;
        
        vector<int> v(N);
        for(int i = 0; i < N; i++)
            cin >> v[i];

        int ans = 0;
        for(int i = 0; i < N; i++) {
            vector<int> lis;
            for(int j = i; j < N; j++) {
                if(lis.empty() || lis.back() < v[j]) {
                    lis.push_back(v[j]);
                } else {
                    int idx = lower_bound(lis.begin(), lis.end(), v[j]) - lis.begin();
                    lis[idx] = v[j];
                }
                ans += lis.size();
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
