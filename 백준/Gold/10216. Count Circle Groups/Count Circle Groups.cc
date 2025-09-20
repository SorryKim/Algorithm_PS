#include <bits/stdc++.h>
using namespace std;

int N;

struct Enemy
{
    int x, y, R;

    Enemy(int x, int y, int R)
    {
        this->x = x;
        this->y = y;
        this->R = R;
    }
};

vector<Enemy> enemies;

void input()
{
    cin >> N;
    enemies.clear();

    for (int i = 0; i < N; i++)
    {
        int x, y, R;
        cin >> x >> y >> R;

        enemies.push_back(Enemy(x, y, R));
    }
}

int Find(int n, vector<int> &parent)
{

    if (n == parent[n])
        return parent[n];

    else
    {
        return (parent[n] = Find(parent[n], parent));
    }
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank)
{

    int parentA = Find(a, parent);
    int parentB = Find(b, parent);
    int rankA = rank[parentA];
    int rankB = rank[parentB];

    if (parentA == parentB)
        return;

    if (rankA > rankB)
        parent[parentB] = parentA;
    else if (rankB > rankA)
        parent[parentA] = parentB;
    else
    {
        parent[parentB] = parentA;
        rank[parentA]++;
    }
}

int solve()
{
    int answer = 0;
    vector<int> parent(N);
    vector<int> rank(N, 1);

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 0; i < N; i++)
    {
        Enemy a = enemies[i];

        for (int j = i + 1; j < N; j++)
        {
            Enemy b = enemies[j];

            int dist = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
            int r = pow(a.R + b.R, 2);
            if (r >= dist)
                Union(i, j, parent, rank);
        }
    }

    set<int> result;
    for (int i = 0; i < N; i++)
        result.insert(Find(i, parent));
    return result.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        input();
        cout << solve() << "\n";
    }

    return 0;
}
