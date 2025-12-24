#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char type[1001];
int money[1001];
vector<vector<int>> graph;

string bfs()
{
    vector<int> maxMoney(N + 1, -1);
    queue<pair<int, int>> q;

    int startMoney = 0;
    if (type[1] == 'L') {
        startMoney = money[1];
    }
    else if (type[1] == 'T') {
        if (startMoney < money[1])
            return "No";
        startMoney -= money[1];
    }

    q.push({1, startMoney});
    maxMoney[1] = startMoney;

    while (!q.empty())
    {
        auto [now, nowMoney] = q.front();
        q.pop();

        if (now == N)
            return "Yes";

        for (int next : graph[now])
        {
            int nextMoney = nowMoney;

            if (type[next] == 'L') {
                nextMoney = max(nextMoney, money[next]);
            }
            else if (type[next] == 'T') {
                if (nextMoney < money[next])
                    continue;
                nextMoney -= money[next];
            }

            if (nextMoney <= maxMoney[next])
                continue;

            maxMoney[next] = nextMoney;
            q.push({next, nextMoney});
        }
    }

    return "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        graph.assign(N + 1, vector<int>());

        for (int i = 1; i <= N; i++)
        {
            cin >> type[i] >> money[i];
            while (true)
            {
                int x;
                cin >> x;
                if (x == 0)
                    break;
                graph[i].push_back(x);
            }
        }

        cout << bfs() << "\n";
    }

    return 0;
}
