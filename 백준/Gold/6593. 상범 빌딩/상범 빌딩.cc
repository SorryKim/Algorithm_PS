#include <bits/stdc++.h>

using namespace std;

int L, R, C;
char graph[30][30][30];
int start[3];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs()
{

  bool visited[30][30][30];
  memset(visited, false, sizeof(visited));
  queue<array<int, 4>> q; // 마지막원소 cnt

  q.push({start[0], start[1], start[2], 0});
  visited[start[0]][start[1]][start[2]] = true;

  while (!q.empty())
  {

    int x = q.front()[0];
    int y = q.front()[1];
    int z = q.front()[2];
    int cnt = q.front()[3];
    q.pop();

    if (graph[x][y][z] == 'E')
      return cnt;

    for (int i = 0; i < 6; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
        continue;
      if (visited[nx][ny][nz])
        continue;
      if (graph[nx][ny][nz] == '#')
        continue;

      visited[nx][ny][nz] = true;
      q.push({nx, ny, nz, cnt + 1});
    }
  }

  return -1;
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true)
  {
    cin >> L >> R >> C;

    if (L == 0 && R == 0 && C == 0)
      break;

    for (int l = 0; l < L; l++)
    {
      for (int r = 0; r < R; r++)
      {
        string s;
        cin >> s;
        for (int c = 0; c < C; c++)
        {
          graph[l][r][c] = s[c];
          if (s[c] == 'S')
          {
            start[0] = l;
            start[1] = r;
            start[2] = c;
          }
        }
      }
    }

    int result = bfs();
    if (result == -1)
      cout << "Trapped!\n";
    else
      cout << "Escaped in " << result << " minute(s).\n";
  }
}