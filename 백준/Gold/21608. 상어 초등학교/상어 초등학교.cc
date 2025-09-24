#include <bits/stdc++.h>
using namespace std;

int N;

vector<set<int>> like;
vector<vector<int>> graph;

// {선호도, 빈칸}갯수 반환 함수
pair<int, int> cnt(int x, int y, int now)
{

  pair<int, int> result = {0, 0};

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || ny < 1 || nx > N || ny > N)
      continue;
    if (graph[nx][ny] == -1)
    {
      result.second++;
      continue;
    }

    int temp = graph[nx][ny];
    if (like[now].find(temp) != like[now].end())
      result.first++;
  }

  return result;
}

// 자리 부여
void give(int now)
{

  // 후보 선택 과정
  pair<int, int> candidate = {1, 1};
  int maxLike = -1;
  int maxEmpty = -1;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      // 이미 선정되어 있는 경우
      if (graph[i][j] != -1)
        continue;

      pair<int, int> temp = cnt(i, j, now);

      int likeCnt = temp.first;
      int emptyCnt = temp.second;

      // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
      if (maxLike < likeCnt)
      {
        maxLike = likeCnt;
        maxEmpty = emptyCnt;
        candidate.first = i;
        candidate.second = j;
      }
      else if (maxLike == likeCnt)
      {
        if (emptyCnt > maxEmpty)
        {
          maxEmpty = emptyCnt;
          candidate.first = i;
          candidate.second = j;
        }
      }
    }
  }

  graph[candidate.first][candidate.second] = now;
}

void input()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  like.resize(N * N + 1, set<int>());
  graph.resize(N + 1, vector<int>(N + 1, -1));

  for (int i = 1; i <= N * N; i++)
  {
    int now;
    cin >> now;

    for (int j = 0; j < 4; j++)
    {
      int temp;
      cin >> temp;
      like[now].insert(temp);
    }

    give(now);
  }
}

// 전체 만족도 계산
int solve()
{

  int ans = 0;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      pair<int, int> temp = cnt(i, j, graph[i][j]);
      int val = temp.first;
      if (val == 0)
        ans += 0;
      else if (val == 1)
        ans += 1;
      else if (val == 2)
        ans += 10;
      else if (val == 3)
        ans += 100;
      else if (val == 4)
        ans += 1000;
      else
        cout << "오류발생! \n";
    }
  }

  return ans;
}

int main()
{
  input();
  cout << solve() << "\n";
}