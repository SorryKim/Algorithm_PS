#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> A;
vector<pair<int, int>> cmds, clouds;
vector<vector<bool>> rainned;

// 1 ~ 8번 인덱스 사용
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void printA()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}

// 입력 받기
void input()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  A.resize(N, vector<int>(N, 0));
  rainned.resize(N, vector<bool>(N, false));

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    cmds.push_back({a, b});
  }

  // 초기 구름
  clouds.push_back({N - 1, 0});
  clouds.push_back({N - 1, 1});
  clouds.push_back({N - 2, 0});
  clouds.push_back({N - 2, 1});
}

// 구름 이동 메소드
void moveCloud(int idx)
{

  vector<pair<int, int>> newClouds;

  int d = cmds[idx].first - 1;
  int s = cmds[idx].second % N;

  for (auto cloud : clouds)
  {
    int x = cloud.first;
    int y = cloud.second;

    // 음수가 될 수도 있으니 N을 더해서 나머지 연산처리
    int nx = (x + s * dx[d] + N) % N;
    int ny = (y + s * dy[d] + N) % N;

    newClouds.push_back({nx, ny});
  }

  // 이동한 구름 변환
  clouds = newClouds;
}

void rainning()
{

  for (auto cloud : clouds)
  {

    int x = cloud.first;
    int y = cloud.second;

    A[x][y]++;
    rainned[x][y] = true; // 비내림 표시
  }
}

// 물복사 버그, 구름위치 기반으로 버그 시작, 버그 후 구름 삭제
void copyBug()
{

  // 대각선 방향만 체크
  int DX[4] = {1, 1, -1, -1};
  int DY[4] = {-1, 1, -1, 1};

  for (auto cloud : clouds)
  {

    int x = cloud.first;
    int y = cloud.second;

    int cnt = 0;
    for (int d = 0; d < 4; d++)
    {
      int nx = x + DX[d];
      int ny = y + DY[d];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        continue;

      if (A[nx][ny] > 0)
        cnt++;
    }

    A[x][y] += cnt;
  }

  clouds.clear(); // 모든 구름 삭제
}

void makeCloud()
{

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      // 2이상, 비내림x 시
      if (A[i][j] >= 2 && !rainned[i][j])
      {
        clouds.push_back({i, j});
        A[i][j] -= 2;
      }

      // 비내림 상태 초기화
      rainned[i][j] = false;
    }
  }
}

int solve()
{

  for (int m = 0; m < M; m++)
  {

    // 1. 모든 구름이 di 방향으로 si칸 이동한다.
    moveCloud(m);
    // cout << "구름이 움직인 후\n";
    // printA();

    // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
    rainning();
    // cout << "비가 내린 후\n";
    // printA();

    // 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
    copyBug();
    // cout << "물복사 버그 후\n";
    // printA();

    // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
    makeCloud();
    // cout << "구름 생성 후\n";
    // printA();
  }

  int result = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      result += A[i][j];
    }
  }

  return result;
}

int main()
{
  input();
  cout << solve() << "\n";
}