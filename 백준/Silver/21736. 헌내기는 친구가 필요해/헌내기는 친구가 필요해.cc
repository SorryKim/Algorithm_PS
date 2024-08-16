#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int answer = 0;
    char graph[601][601];
    bool visited[601][601] = {false};
    int moveX[4] = {1, -1, 0, 0};
    int moveY[4] = {0, 0, 1, -1};
    int startX, startY;

    // INPUT
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = s[j];
            if (graph[i][j] == 'I')
            {
                startX = i;
                startY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push({startX, startY});

    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        if (graph[nowX][nowY] == 'P')
            answer++;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
            {
                if (!visited[nextX][nextY] && graph[nextX][nextY] != 'X')
                {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                }
            }
        }
    }

    if (answer == 0)
        cout << "TT";
    else
        cout << answer;

    return 0;
}
