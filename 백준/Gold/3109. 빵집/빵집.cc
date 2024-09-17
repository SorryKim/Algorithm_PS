#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

char graph[10000][500];
bool visited[10000][500];
int answer;
int R, C;

bool DFS(int x, int y)
{

    if (y == C - 1)
    {
        answer++;
        visited[x][y] = true;
        return true;
    }

    // 1. 오른 대각 위
    if (x > 0)
    {
        if (graph[x - 1][y + 1] == '.' && !visited[x - 1][y + 1])
        {
            visited[x - 1][y + 1] = true;
            if (DFS(x - 1, y + 1))
                return true;
        }
    }

    // 2. 오른
    if (graph[x][y + 1] == '.' && !visited[x][y + 1])
    {
        visited[x][y + 1] = true;
        if (DFS(x, y + 1))
            return true;
    }

    // 3. 오른 대각 아래
    if (x + 1 < R)
    {
        if (graph[x + 1][y + 1] == '.' && !visited[x + 1][y + 1])
        {
            visited[x + 1][y + 1] = true;
            if (DFS(x + 1, y + 1))
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            graph[i][j] = s[j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < R; i++)
        DFS(i, 0);

    cout << answer << "\n";
    return 0;
}
