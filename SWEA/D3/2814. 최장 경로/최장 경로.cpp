#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[11];
vector<int> graph[11];
int ans;


void DFS(int node, int length) {

    visited[node] = true;
    ans = max(ans, length);

    for (int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i];
        if (!visited[nextNode]) {
            DFS(nextNode, length + 1);
        }
    }

    visited[node] = false;
}


int main() {

    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        
        
        int N, M;
        cin >> N >> M;

        ans = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= N; i++) 
            graph[i].clear();
        
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= N; ++i) {
            DFS(i, 1);
        }
        cout << "#" << testCase << " " << ans << "\n";
    }

    return 0;
}
