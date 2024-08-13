#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> time;
    vector<int> score;
    vector<int> dp(10001, -1);

    for (int i = 0; i < N; i++)
    {
        int K, S;
        cin >> K >> S;
        time.push_back(K);
        score.push_back(S);
    }

    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int now_time = time[i];
        int now_score = score[i];
        for (int j = 10000; j >= now_time; j--)
        {
            if (dp[j - now_time] != -1){
                dp[j] = max(dp[j], dp[j - now_time] + now_score);
            }
        }
    }

    int answer = 0;

    for(int i = 0; i <= T; i++)
        answer = max(answer ,dp[i]);

    cout << answer;
    return 0;
}
