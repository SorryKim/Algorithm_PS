#include <bits/stdc++.h>
using namespace std;

int N;
int dist[101][101];
vector<pair<int, int>> dots; // 0=회사, 1=집, 2~N+1=고객
int ans;

void calcDist()
{
  for (int i = 0; i < dots.size(); i++)
  {
    for (int j = i + 1; j < dots.size(); j++)
    {
      int val = abs(dots[i].first - dots[j].first) + abs(dots[i].second - dots[j].second);
      dist[i][j] = val;
      dist[j][i] = val;
    }
  }
}

void dfs(int now, int visited, int cost)
{
  if (cost >= ans)
    return; // pruning

  // 고객 모두 방문했으면 집으로 이동
  int allVisited = ((1 << (N + 2)) - 1) - (1 << 1); // 집 제외
  if (visited == allVisited)
  {
    ans = min(ans, cost + dist[now][1]); // 집으로
    return;
  }

  for (int next = 2; next <= N + 1; next++)
  {
    if (visited & (1 << next))
      continue;
    dfs(next, visited | (1 << next), cost + dist[now][next]);
  }
}

int solve()
{
  calcDist();
  dfs(0, 1 << 0, 0); // 회사에서 출발
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int test = 1; test <= T; test++)
  {
    ans = 1e9;
    cin >> N;

    dots.clear();
    for (int i = 0; i <= N + 1; i++)
    {
      int x, y;
      cin >> x >> y;
      dots.push_back({x, y});
    }

    cout << "#" << test << " " << solve() << "\n";
  }
    
    return 0;
}
