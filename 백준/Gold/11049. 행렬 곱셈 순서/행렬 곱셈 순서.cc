#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    pair<long long, long long> arr[501];
    long long dp[501][501];
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 1; i <= N; i++)
        dp[i][i] = 0;

    for (int length = 1; length < N; length++)
    {
        for (int start = 1; start + length <= N; start++)
        {
            int end = start + length;
            dp[start][end] = LLONG_MAX;

            for (int i = start; i < end; i++)
            {
                dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + arr[start].first * arr[i].second * arr[end].second);
            }
        }
    }

    if (N == 1)
        cout << 0;
    else
        cout << dp[1][N] << '\n';

    return 0;
}
