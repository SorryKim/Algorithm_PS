#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }

    for (int i = 1; i <= N; i++)
        graph[i][i] = true;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if(graph[j][i] && graph[i][k])
                    graph[j][k] = true;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        int cnt = 0;
        for(int j = 1; j <= N; j++){
            if(!graph[i][j] && !graph[j][i])
                cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
