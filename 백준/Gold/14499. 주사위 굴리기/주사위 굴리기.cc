#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K;
int topIdx, bottomIdx, northIdx, southIdx, westIdx, eastIdx;

vector<vector<int>> mp;
vector<int> moves;
vector<int> dice(6, 0);

void input()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> x >> y >> K;

  mp.resize(N, vector<int>(M, 0));

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> mp[i][j];
    }
  }

  for (int i = 0; i < K; i++)
  {
    int num;
    ;
    cin >> num;
    moves.push_back(num);
  }
}

void roll(int dir)
{
  int t = topIdx, b = bottomIdx, n = northIdx, s = southIdx, w = westIdx, e = eastIdx;

  if (dir == 1)
  { // 동
    topIdx = w;
    bottomIdx = e;
    eastIdx = t;
    westIdx = b;
  }
  else if (dir == 2)
  { // 서
    topIdx = e;
    bottomIdx = w;
    eastIdx = b;
    westIdx = t;
  }
  else if (dir == 3)
  { // 북
    topIdx = s;
    bottomIdx = n;
    northIdx = t;
    southIdx = b;
  }
  else if (dir == 4)
  { // 남
    topIdx = n;
    bottomIdx = s;
    northIdx = b;
    southIdx = t;
  }

  return;
}

void solve()
{

  // 1. 주사위 초기 셋팅
  topIdx = 0;
  bottomIdx = 1;
  northIdx = 2;
  southIdx = 3;
  eastIdx = 4;
  westIdx = 5;

  int dx[5] = {0, 0, 0, -1, 1};
  int dy[5] = {0, 1, -1, 0, 0};

  for (int move : moves)
  {

    int nx = x + dx[move];
    int ny = y + dy[move];

    // 지도 밖으로 나가는 지 체크
    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
      continue;

    // 위치 갱신
    x = nx;
    y = ny;
    roll(move);

    // 이동한 칸에 쓰여 있는 수가 0이면
    if (mp[x][y] == 0)
    {
      // 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
      mp[x][y] = dice[bottomIdx];
    }
    // 0이 아닌 경우
    else
    {
      // 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며
      dice[bottomIdx] = mp[x][y];
      // 칸에 쓰여 있는 수는 0이 된다.
      mp[x][y] = 0;
    }
    cout << dice[topIdx] << "\n";
  }
}

int main()
{
  input();
  solve();
}