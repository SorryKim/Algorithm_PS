#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int N, M;
        double m;
        cin >> N >> m;                
        M = (int)(round(100 * m)); // 정수로 변환 시 반올림 처리

        if (N == 0 && M == 0)
            break;

        vector<int> calories(N, 0);
        vector<int> prices(N, 0);
        vector<int> dp(10001, 0);

        for (int i = 0; i < N; i++)
        {
            double temp;
            cin >> calories[i] >> temp;                     
            prices[i] = (int)(round(100 * temp)); // 정수로 변환 시 반올림 처리
        }

        for (int i = 0; i < N; i++)
        {
            int nowC = calories[i];
            int nowP = prices[i];

            for (int j = nowP; j <= M; j++)
            {
                dp[j] = max(dp[j], dp[j - nowP] + nowC);
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}
