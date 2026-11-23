#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, int> mp;
    unordered_map<int, int> ans;
    vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        mp[num[i]]++;
    }

    for (const auto& var : mp) {
        int n = var.first;
        int cnt = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i != 0) continue;

            auto it = mp.find(i);
            if (it != mp.end()) {
                cnt += it->second;
            }

            int other = n / i;

            if (i != other) {
                it = mp.find(other);
                if (it != mp.end()) {
                    cnt += it->second;
                }
            }
        }

        ans[n] = cnt - 1;
    }

    for (int n : num) cout << ans[n] << '\n';
    

    return 0;
}