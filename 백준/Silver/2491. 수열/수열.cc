#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    vector<int> dp1(N + 1, 1);
    vector<int> dp2(N + 1, 1);

    // 1. 연속해서 증가하는 경우
    for (int i = 2; i <= N; i++)
    {
        if (v[i] >= v[i - 1])
        {
            dp1[i] = dp1[i - 1] + 1;
        }
    }

    // 2. 연속해서 감소하는 경우
    for (int i = 2; i <= N; i++)
    {
        if (v[i - 1] >= v[i])
            dp2[i] = dp2[i - 1] + 1;
    }

    int val1 = 0;
    int val2 = 0;

    for (int i = 1; i <= N; i++)
    {
        val1 = max(val1, dp1[i]);
        val2 = max(val2, dp2[i]);
    }

    cout << max(val1, val2) << "\n";
}