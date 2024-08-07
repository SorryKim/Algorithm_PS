#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

int n, m;
int graph[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(graph[i][j] != INF)
                cout << graph[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }

    

    return 0;
}