#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board[5];  // 철수의 보드판
vector<bool> check[5]; // 빙고 체크
vector<int> arr;       // 사회자가 부른 순서

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 철수 빙고판 기록
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            board[i].push_back(num);
            check[i].push_back(false);
        }
    }

    // 사회자의 번호 순서 기록
    for (int i = 0; i < 25; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
}

// 현재 보드판의 빙고 여부 반환 함수
bool checkBingo()
{

    int cnt = 0;

    // 1. 가로 빙고 체크
    for (int i = 0; i < 5; i++)
    {
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (!check[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }

    // 2. 세로 빙고 체크
    for (int i = 0; i < 5; i++)
    {
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (!check[j][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }

    // 3. 대각선 빙고 체크
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (!check[i][i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cnt++;
    flag = true;

    for (int i = 0; i < 5; i++)
    {
        if (!check[i][4 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cnt++;

    if (cnt >= 3)
        return true;
    else
        return false;
}

// 해당 숫자 체크 처리
void checkNum(int num)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == num)
            {
                check[i][j] = true;
                return;
            }
        }
    }

    return;
}

int solve()
{

    int ans = 0;

    for (int i = 0; i < 25; i++)
    {
        ans++;

        // 1. 사회자가 부른 번호 체크
        int now = arr[i];
        checkNum(now);

        // 2. 빙고 확인
        if (checkBingo())
            break;
    }

    return ans;
}

int main()
{
    input();
    cout << solve() << '\n';
}