#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;
int DP[100001];

int DFS(int now, vector<bool> &visit, const vector<vector<int>> (&graph)) {
    
    visit[now] = true;
    
    int cnt = 0;
    for (auto a : graph[now]) {
        if (!visit[a]) {
            cnt++;
            cnt += DFS(a, visit, graph);
        }
    }
    
    DP[now] = cnt + 1;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<bool> visit(N + 1, false);
    
    queue<int> q;
    
    for (int i = 0; i < N - 1; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    DFS(R, visit, graph);
    
    while (Q--) {
        int target;
        cin >> target;
        cout << DP[target] << "\n";
    }

    return 0;
}
