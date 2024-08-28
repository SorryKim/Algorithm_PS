#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int dp[501];

int Solve(int n)
{
    if (dp[n] == 0)
    {
        dp[n] = 1;
        for (int i = n + 1; i < N; i++)
        {
            if (v[n].second < v[i].second)
            {
                dp[n] = max(dp[n], Solve(i) + 1);
            }
        }
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 0;
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    int answer = 0;

    for (int i = 0; i < N; i++)
        answer = max(answer, Solve(i));

    cout << N - answer;
}