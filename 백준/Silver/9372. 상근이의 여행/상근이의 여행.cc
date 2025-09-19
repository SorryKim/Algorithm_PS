#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> graph(N + 1, vector<int>());

        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(N + 1, false);
        int cnt = 0;

        for (int i = 1; i <= N; i++)
        {

            if (visited[i])
                continue;

            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int now = q.front();
                q.pop();

                for (int next : graph[now])
                {
                    if (visited[next])
                        continue;
                    visited[next] = true;
                    q.push(next);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}