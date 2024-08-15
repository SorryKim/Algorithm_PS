#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int N;
long long answer1 = -LLONG_MAX;
long long answer2 = LLONG_MAX;

void DFS(long long now, int depth, const vector<long long> &v1, vector<int> v2)
{

    if (depth == N)
    {
        answer1 = max(answer1, now);
        answer2 = min(answer2, now);

        return;
    }

    // +
    if (v2[1] != 0)
    {
        v2[1] -= 1;
        DFS(now + v1[depth + 1], depth + 1, v1, v2);
        v2[1] += 1;
    }

    // -
    if (v2[2] != 0)
    {
        v2[2] -= 1;
        DFS(now - v1[depth + 1], depth + 1, v1, v2);
        v2[2] += 1;
    }

    // *
    if (v2[3] != 0)
    {
        v2[3] -= 1;
        DFS(now * v1[depth + 1], depth + 1, v1, v2);
        v2[3] += 1;
    }

    // /
    if (v2[4] != 0)
    {
        v2[4] -= 1;
        long long result;
        if (now < 0 && v1[depth + 1] > 0)
            result = -((-now) / v1[depth + 1]);
        else
            result = now / v1[depth + 1];
        DFS(result, depth + 1, v1, v2);
        v2[4] += 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<long long> v1(N + 1, 0);
    vector<int> v2(5, 0);

    for (int i = 1; i <= N; i++)
        cin >> v1[i];

    for (int i = 1; i <= 4; i++)
        cin >> v2[i];

    DFS(v1[1], 1, v1, v2);

    cout << answer1 << '\n';
    cout << answer2 << '\n';

    return 0;
}
