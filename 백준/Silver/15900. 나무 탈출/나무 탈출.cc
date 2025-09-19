#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> graph;
vector<int> tree;
long long cnt; // 경로 수

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cnt = 0;
    cin >> N;
    graph = vector<vector<int>>(N + 1, vector<int>());
    tree = vector<int>(N + 1, -1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

// DFS로 리프까지 내려가면서 깊이를 더한다
void dfs(int node, int parent, int depth)
{

    bool isLeaf = true;
    for (int next : graph[node])
    {
        if (next == parent)
            continue;
        isLeaf = false;
        dfs(next, node, depth + 1);
    }

    // 리프 노드라면 깊이를 합산
    if (isLeaf)
    {
        cnt += depth;
    }
}

bool solve()
{
    dfs(1, -1, 0);

    return cnt % 2 != 0 ? true : false;
}

int main()
{
    input();
    cout << (solve() ? "Yes" : "No") << "\n";
}