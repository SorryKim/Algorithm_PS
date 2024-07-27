#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        int target;
        cin >> N >> K;

        vector<int> DP(N + 1, 0);
        vector<int> v(N + 1, 0);
        vector<int> indegree(N + 1, 0);
        vector<vector<int>> build(N + 1, vector<int>());
        queue<int> q;

        // Input
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            build[a].push_back(b);
            indegree[b]++;
        }
        cin >> target;

        // 가장 먼저 지을 수 있는 건물 체크
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                DP[i] = v[i];
            }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (auto a : build[now]) {
                indegree[a]--;
                if (indegree[a] == 0) {
                    q.push(a);
                }
                DP[a] = max(DP[a], DP[now] + v[a]);
            }
        }

        cout << DP[target] << "\n";
    }

    return 0;
}
