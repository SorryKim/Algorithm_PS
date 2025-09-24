#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int arr[100][100];
int cntC, cntR;

void input()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C >> K;
  cntC = 3;
  cntR = 3;

  // 배열 초기화
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      arr[i][j] = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> arr[i][j];
    }
  }
}

// R 연산
// R연산 이후 열의 갯수가 바뀜
void funcR()
{
  int newC = 0; // 새로운 열 크기
  for (int i = 0; i < cntR; i++)
  {
    vector<int> temp;
    map<int, int> cnt;

    // 숫자 카운트
    for (int j = 0; j < cntC; j++)
    {
      int now = arr[i][j];
      if (now == 0)
        continue;
      cnt[now]++;
    }

    // 정렬 준비
    vector<pair<int, int>> vec(cnt.begin(), cnt.end());

    // 정렬 (value → key)
    sort(vec.begin(), vec.end(), [](auto &a, auto &b)
         {
      if (a.second == b.second) return a.first < b.first;
      return a.second < b.second; });

    // 임시 벡터에 집어넣음
    for (auto t : vec)
    {
      temp.push_back(t.first);
      temp.push_back(t.second);
    }

    // 길이 제한
    int len = min((int)temp.size(), 100);
    newC = max(newC, len);

    // 값 채우기
    for (int j = 0; j < len; j++)
      arr[i][j] = temp[j];
    for (int j = len; j < 100; j++)
      arr[i][j] = 0; // 남는 칸 0
  }
  cntC = newC;
}

// C 연산
void funcC()
{
  int newR = 0; // 새로운 행 크기
  for (int i = 0; i < cntC; i++)
  {
    vector<int> temp;
    map<int, int> cnt;

    // 숫자 카운트
    for (int j = 0; j < cntR; j++)
    {
      int now = arr[j][i];
      if (now == 0)
        continue;
      cnt[now]++;
    }

    // 정렬 준비
    vector<pair<int, int>> vec(cnt.begin(), cnt.end());

    // 정렬 (value → key)
    sort(vec.begin(), vec.end(), [](auto &a, auto &b)
         {
      if (a.second == b.second) return a.first < b.first;
      return a.second < b.second; });

    // 임시 벡터에 집어넣음
    for (auto t : vec)
    {
      temp.push_back(t.first);
      temp.push_back(t.second);
    }

    // 길이 제한
    int len = min((int)temp.size(), 100);
    newR = max(newR, len);

    // 값 채우기
    for (int j = 0; j < len; j++)
      arr[j][i] = temp[j];
    for (int j = len; j < 100; j++)
      arr[j][i] = 0; // 남는 칸 0
  }
  cntR = newR;
}

int solve()
{
  int ans = 0;

  while (ans <= 100)
  {
    if (arr[R - 1][C - 1] == K)
      return ans;

    if (cntR >= cntC)
      funcR();
    else
      funcC();

    ans++;
  }
  return -1;
}

int main()
{
  input();
  cout << solve() << "\n";
}
