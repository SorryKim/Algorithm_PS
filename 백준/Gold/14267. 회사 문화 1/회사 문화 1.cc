#include <iostream>
#include <vector>
using namespace std;

void DFS(int idx, int w, vector<int> &parent, vector<vector<int>> &tree, vector<int> &dp){
    
    dp[idx] += w;
    for(auto next : tree[idx])
        DFS(next, dp[idx], parent, tree, dp);
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> parent(N + 1);          // 각 직원의 직속 상사 번호
    vector<vector<int>> tree(N + 1);   // 트리 구조를 저장할 벡터
    vector<int> dp(N + 1, 0); // 칭찬받은 정도 기록

    // 입력받아 트리 구성
    for (int i = 1; i <= N; ++i) {
        cin >> parent[i];
        if (parent[i] != -1) 
            tree[parent[i]].push_back(i);
    }

    // 칭찬받은 사람만 일단 기록
    for(int i = 0; i < M; i++){
        int idx, w;
        cin >> idx >> w;
        dp[idx] += w;
    }

    // DFS로 누적칭찬 전파
    DFS(1, 0, parent, tree, dp);
    
    // 결과출력
    for(int i = 1; i <= N; i++)
        cout << dp[i] << " ";

    return 0;
}
