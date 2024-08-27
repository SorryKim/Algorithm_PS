#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    vector<long long> dice(6);
    long long answer = 0;

    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
    }

    // 각 면의 최소값 계산
    long long min1 = LLONG_MAX;
    long long min2 = LLONG_MAX;
    long long min3 = LLONG_MAX;

    for (int i = 0; i < 6; i++)
    {
        min1 = min(min1, dice[i]);
        for (int j = i + 1; j < 6; j++)
        {
            if (i + j == 5)
            {
                continue;
            }
            min2 = min(min2, dice[i] + dice[j]);
            for (int k = j + 1; k < 6; k++)
            {
                if (j + k == 5 || k + i == 5)
                {
                    continue;
                }
                min3 = min(min3, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    if (N == 1)
    {
        // 주사위의 한 면이 보이는 경우: 가장 큰 면을 제외한 나머지 면의 합
        sort(dice.begin(), dice.end());
        answer = dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; // 다섯 면의 합
    }
    else
    {
        // N이 2인 경우
        if (N == 2)
        {
            // 각 꼭짓점에 세 면이 보이는 주사위가 4개
            answer = 4 * min3;
            // 각 변에 두 면이 보이는 주사위가 4개
            answer += 4 * min2;
        }
        else
        {
            // N이 3 이상일 때:
            long long num_min3 = 4;                                         // 세 면이 보이는 주사위의 개수
            long long num_min2 = 4 * (N - 2) + 4 * (N - 1);                 // 두 면이 보이는 주사위의 개수
            long long num_min1 = (N - 2) * (N - 2) + (N - 2) * 4 * (N - 1); // 한 면이 보이는 주사위의 개수

            answer = num_min3 * min3 + num_min2 * min2 + num_min1 * min1;
        }
    }

    cout << answer;
    return 0;
}
