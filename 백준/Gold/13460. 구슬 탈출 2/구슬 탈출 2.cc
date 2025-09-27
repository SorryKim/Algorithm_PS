#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 구슬의 위치를 나타내는 구조체
struct Pos
{
  int x, y;
};

// BFS 큐에 저장할 상태 정보 구조체
// 두 구슬의 위치와 현재까지의 이동 횟수를 함께 관리합니다.
struct State
{
  Pos red, blue;
  int count;
};

int N, M;
vector<string> board;
// 방문 여부를 체크하는 4차원 배열
// visited[red_x][red_y][blue_x][blue_y]
bool visited[10][10][10][10];

// 방향 벡터 (상, 하, 좌, 우)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void input()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  board.resize(N);
  for (int i = 0; i < N; i++)
  {
    cin >> board[i];
  }
}

// 너비 우선 탐색(BFS) 함수
void solve()
{
  Pos startRed, startBlue;

  // 초기 구슬 위치 찾기
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (board[i][j] == 'R')
      {
        startRed = {i, j};
        board[i][j] = '.'; // 구슬이 있던 자리는 빈 공간으로 변경
      }
      if (board[i][j] == 'B')
      {
        startBlue = {i, j};
        board[i][j] = '.'; // 구슬이 있던 자리는 빈 공간으로 변경
      }
    }
  }

  queue<State> q;

  // 1. 초기 상태를 큐에 삽입
  q.push({startRed, startBlue, 0});
  // 2. 초기 상태 방문 처리
  visited[startRed.x][startRed.y][startBlue.x][startBlue.y] = true;

  while (!q.empty())
  {
    State current = q.front();
    q.pop();

    // 10번을 초과해서 움직인 경우는 더 이상 탐색하지 않음
    if (current.count >= 10)
    {
      continue;
    }

    // 4방향으로 기울이는 시도
    for (int i = 0; i < 4; i++)
    {
      Pos nextRed = current.red;
      Pos nextBlue = current.blue;
      int moveCount = current.count + 1;

      bool redInHole = false;
      bool blueInHole = false;

      // 파란 구슬 먼저 이동
      while (board[nextBlue.x + dx[i]][nextBlue.y + dy[i]] != '#')
      {
        nextBlue.x += dx[i];
        nextBlue.y += dy[i];
        if (board[nextBlue.x][nextBlue.y] == 'O')
        {
          blueInHole = true;
          break;
        }
      }

      // 빨간 구슬 이동
      while (board[nextRed.x + dx[i]][nextRed.y + dy[i]] != '#')
      {
        nextRed.x += dx[i];
        nextRed.y += dy[i];
        if (board[nextRed.x][nextRed.y] == 'O')
        {
          redInHole = true;
          break;
        }
      }

      // 파란 구슬이 구멍에 빠진 경우는 실패. 해당 경로는 더 이상 탐색하지 않음.
      if (blueInHole)
      {
        continue;
      }

      // 빨간 구슬만 구멍에 빠진 경우 성공!
      if (redInHole)
      {
        cout << moveCount << '\n';
        return; // 탐색 종료
      }

      // 두 구슬의 위치가 겹치는 경우 처리
      if (nextRed.x == nextBlue.x && nextRed.y == nextBlue.y)
      {
        // 더 많이 움직인 구슬이 뒤에 있었던 것임. 한 칸 뒤로 물린다.
        int redDist = abs(nextRed.x - current.red.x) + abs(nextRed.y - current.red.y);
        int blueDist = abs(nextBlue.x - current.blue.x) + abs(nextBlue.y - current.blue.y);

        if (redDist > blueDist)
        {
          nextRed.x -= dx[i];
          nextRed.y -= dy[i];
        }
        else
        {
          nextBlue.x -= dx[i];
          nextBlue.y -= dy[i];
        }
      }

      // 아직 방문하지 않은 새로운 상태라면 큐에 추가
      if (!visited[nextRed.x][nextRed.y][nextBlue.x][nextBlue.y])
      {
        visited[nextRed.x][nextRed.y][nextBlue.x][nextBlue.y] = true;
        q.push({nextRed, nextBlue, moveCount});
      }
    }
  }

  // while문이 끝날 때까지 답을 못 찾았다면 불가능한 경우
  cout << -1 << '\n';
}

int main()
{
  input();
  solve();
  return 0;
}