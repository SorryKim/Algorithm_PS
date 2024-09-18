#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void printPath(int i, int j, const vector<vector<int>> next)
{

    if (next[i][j] == -1)
    {
        cout << 0 << "\n";
        return;
    }

    vector<int> path = {i};

    while (i != j)
    {
        i = next[i][j];
        path.push_back(i);
    }

    cout << path.size() << " ";
    for (int node : path)
        cout << node << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    const int INF = 1e9;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
    vector<vector<int>> next(N + 1, vector<int>(N + 1, -1));

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c)
        {
            graph[a][b] = c;
            next[a][b] = b;
        }
    }

    for (int i = 1; i <= N; i++)
        graph[i][i] = 0;

    // 플로이드-워샬
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                    next[j][k] = next[j][i];
                }
            }
        }
    }

    // 최소값 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j] == INF)
                cout << 0 << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << '\n';
    }

    // 노드별 경로 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // 방문 노드 숫자 + 방문 경로 출력
            printPath(i, j, next);
        }
    }
}
