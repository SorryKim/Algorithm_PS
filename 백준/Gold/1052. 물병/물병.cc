#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    int answer = 0;
    cin >> N >> K;

    while (true)
    {
        int cnt = 0;
        int temp = N;

        while (temp > 0)
        {
            if (temp % 2 == 1)
                cnt++;
            temp /= 2;
        }

        if (cnt <= K)
            break;

        N++;
        answer++;
    }

    cout << answer;
    return 0;
}
