#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> vips;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        vips.insert(num);
    }
}

int solve()
{

    // 1. vip 기준으로 범위 자르기
    vector<pair<int, int>> v;

    int start = 1;
    int end = 1;

    for (int i = 1; i <= N; i++)
    {

        if (vips.find(i) != vips.end())
        {
            end = i - 1;
            v.push_back(make_pair(start, end));
            start = i + 1;
        }
        else
        {
            if (i == N)
            {
                v.push_back(make_pair(start, N));
            }
        }
    }

    // 2. dp테이블 작성
    vector<int> dp(N + 1, 1);
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int answer = 1;

    for (auto a : v)
    {
        int cnt = a.second - a.first + 1;
        answer *= dp[cnt];
    }

    return answer;
}

int main()
{
    input();
    cout << solve() << '\n';

    return 0;
}
