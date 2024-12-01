#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
        int N, M;
        cin >> N >> M;

        int answer = 0;
        vector<pair<int, int>> v(M);
        vector<bool> check(N + 1, false); // 책 수여 여부
     
        for (int i = 0; i < M; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), cmp);

        for (auto &now : v) {
            int start = now.first;
            int end = now.second;

            for (int i = start; i <= end; i++) {
                if (!check[i]) {
                    check[i] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}