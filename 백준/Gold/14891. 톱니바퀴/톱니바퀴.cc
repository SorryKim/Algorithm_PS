#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> gears[4];
int K;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        gears[i].clear();
        gears[i].reserve(8);
        for (char ch : s)
            gears[i].push_back(ch - '0');
    }

    cin >> K;
}

void rotate(int idx, int dir)
{

    vector<int> temp = gears[idx];

    // 시계 방향
    if (dir == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            int next = (i + 1) % 8;
            gears[idx][next] = temp[i];
        }
    }
    else if (dir == -1)
    { // 반시계 방향
        for (int i = 0; i < 8; i++)
        {
            int next = (i + 7) % 8; // (i - 1 + 8) % 8, 음수 방지용
            gears[idx][next] = temp[i];
        }
    }
}

int solve()
{
    while (K--)
    {
        int idx1, dir;
        cin >> idx1 >> dir;
        int start = idx1 - 1; // 0-based

        // 1) 현재 상태 기준으로 네 톱니의 회전 방향만 계산
        int dirs[4] = {0, 0, 0, 0};
        dirs[start] = dir;

        // 왼쪽으로 전파, gears[i][3] vs gears[i+1][6]
        for (int i = start - 1; i >= 0; i--)
        {
            if (gears[i][2] == gears[i + 1][6])
                break;
            dirs[i] = -dirs[i + 1];
        }
        // 오른쪽으로 전파,  gears[i-1][3] vs gears[i][6]
        for (int i = start + 1; i < 4; i++)
        {
            if (gears[i - 1][2] == gears[i][6])
                break;
            dirs[i] = -dirs[i - 1];
        }

        // 2) 계산된 방향대로 일괄 회전
        for (int i = 0; i < 4; i++)
        {
            if (dirs[i] != 0)
                rotate(i, dirs[i]);
        }
    }

    // 3) 점수 계산
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gears[i][0] == 1)
            sum += (1 << i);
    }

    return sum;
}

int main()
{
    input();
    cout << solve();
    return 0;
}