#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph, dp;

void DFS(int now, int parent) {

    dp[now][0] = 0;  // OFF
    dp[now][1] = 1;  // ON

    for (int next : graph[now]) {
        if (next == parent) continue;

        DFS(next, now);

        dp[now][0] += dp[next][1];
        dp[now][1] += min(dp[next][0], dp[next][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 1e9;
    graph.resize(n + 1, vector<int>());
    dp.resize(n + 1, vector<int>(2, 0));
    
    for(auto a : lighthouse){
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    
    DFS(1, 0);
    answer = min(dp[1][0], dp[1][1]);
    
    return answer;
}