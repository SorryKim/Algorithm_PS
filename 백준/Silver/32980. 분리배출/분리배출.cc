#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> trash(N);
    for (int i = 0; i < N; i++) cin >> trash[i];

    // P C V S G F 순서
    unordered_map<char, long long> mp;
    char types[6] = {'P', 'C', 'V', 'S', 'G', 'F'};
    for (int i = 0; i < 6; i++) {
        long long c;
        cin >> c;
        mp[types[i]] = c;
    }

    long long costO;
    cin >> costO;

    long long ans = 0;

    for (const string &s : trash) {
        int len = s.size();
        bool single = true;
        char first = s[0];

        for (char c : s) {
            if (c != first) {
                single = false;
                break;
            }
        }

        long long cost = 1LL * len * costO;

        if (single && mp.count(first)) {
            long long temp = 1LL * len * mp[first];
            ans += min(temp, cost);
        } else ans += cost;
        
    }

    cout << ans << "\n";
    return 0;
}
