#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, D;
vector<vector<int>> tree;
vector<int> height;
int answer;

void Input() {
    cin >> N >> S >> D;
    tree.resize(N + 1);
    height.resize(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

int DFS(int now, int parent) {
    
    // 자식 노드들 거리값 갱신
    for(int next : tree[now]){
        if(next != parent)
            height[now] = max(height[now] , DFS(next, now) + 1);
    }

    if(height[now] >= D && now != S) answer += 2;

    return height[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    DFS(S, -1);
    cout << answer << '\n'; 

    return 0;
}
