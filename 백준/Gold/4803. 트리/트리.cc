#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int Find(int num, vector<int> &parent)
{

    if (num == parent[num])
        return num;
    else
        return Find(parent[num], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank)
{

    int rootA = Find(a, parent);
    int rootB = Find(b, parent);

    if (rootA == rootB)
        return;

    if (rank[rootA] > rank[rootB])
        parent[rootB] = rootA;
    else if (rank[rootB] > rank[rootA])
        parent[rootA] = rootB;
    else
    {
        parent[rootB] = rootA;
        rank[rootA] += 1;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 0;
    while (true)
    {
        tc++;
        int n, m;
        string answer = "";
        cin >> n >> m;
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 0);

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        set<int> cycle, tree;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            // 사이클 발생
            if (Find(a, parent) == Find(b, parent))
                cycle.insert(Find(a, parent));
            else
                Union(a, b, parent, rank);
        }

        for (int i = 1; i <= n; i++)
        {
            int now = Find(i, parent);
            // 사이클이 아닌 경우
            if (cycle.find(now) == cycle.end())
                tree.insert(now);
        }

        if (tree.size() == 0)
            answer = "No trees.";
        else if (tree.size() == 1)
            answer = "There is one tree.";
        else
            answer = "A forest of " + to_string(tree.size()) + " trees.";

        cout << "Case " << tc << ": " << answer << '\n';
    }

    return 0;
}
