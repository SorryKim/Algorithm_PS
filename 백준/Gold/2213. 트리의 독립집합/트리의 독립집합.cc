#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> graph, tree;
vector<int> weight;
vector<vector<int>> dp;
vector<int> nodes; // 최대 독립집합

// 최대 독립집합일 때, 경로추적
void BackTracking(int node, bool check){

    if(check) nodes.push_back(node);

    for(int child : tree[node]){
        if(check) BackTracking(child, false); // 부모 선택됨
        else BackTracking(child, dp[child][1] > dp[child][0]); // 부모 선택 x, 경우 자식 선택가능
    }
}


// dp 갱신
void DFS(int node){

    dp[node][0] = 0; // 해당 노드 사용x
    dp[node][1] = weight[node];

    for(int child : tree[node]){
        DFS(child);
        dp[node][0] += max(dp[child][0], dp[child][1]); // 둘 중 가중치 큰걸로
        dp[node][1] += dp[child][0]; // 해당 노드를 사용하면 child 사용불가
    }
}


// graph -> tree 변환
void MakeTree(int node, int parent){

    for(int child : graph[node]){
        if(child == parent) continue;
        tree[node].push_back(child);
        MakeTree(child, node);
    }

}

void Input(){

    cin >> N;
    graph.resize(N + 1);
    tree.resize(N + 1);
    weight.resize(N + 1);
    dp.resize(N + 1, vector<int>(2));

    for(int i = 1; i <= N; i++) cin >> weight[i];

    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    MakeTree(1, 0);
    DFS(1);
    BackTracking(1, dp[1][1] > dp[1][0]);
    sort(nodes.begin(), nodes.end());

    cout << max(dp[1][1], dp[1][0]) << "\n";
    for(int node : nodes) cout << node << " ";
    cout << "\n";

    return 0;
}