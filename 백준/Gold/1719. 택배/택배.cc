#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int graph[201][201];
int dist[201][201];
int path[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;

        if (graph[u][v] > w)
        {
            graph[u][v] = w;
            path[u][v] = v;
        }

        if (graph[v][u] > w)
        {
            graph[v][u] = w;
            path[v][u] = u;
        }
    }

    // 플로이드-워샬
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j)
                cout << "- ";
            else
                cout << path[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
