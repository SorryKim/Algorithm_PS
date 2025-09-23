#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;
vector<bool> robots;

template <typename T>
void rotateRight(vector<T> &arr)
{
    T last = arr.back();
    for (int i = arr.size() - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = last;
}

int solve()
{

    int ans = 0;

    while (true)
    {
        ans++;

        // 1. 벨트 회전
        rotateRight(v);
        rotateRight(robots);
        robots[N - 1] = false; // 로봇 내리기

        // 2. 로봇 회전
        for (int i = N - 2; i >= 0; i--)
        {
            if (robots[i] && !robots[i + 1] && v[i + 1] > 0)
            {
                robots[i + 1] = true;
                robots[i] = false;
                v[i + 1]--;
            }
        }
        robots[N - 1] = false;
        
        // 3. 올리기
        if (v[0] > 0)
        {
            robots[0] = true;
            v[0]--;
        }

        // 4. 내구도 0 세기
        int cnt = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (v[i] == 0)
                cnt++;
        }

        if (cnt >= K)
            return ans;
    }

    return ans;
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    v.resize(2 * N, 0);
    robots.resize(2 * N, false);

    for (int i = 0; i < 2 * N; i++)
        cin >> v[i];
}

int main()
{
    input();
    cout << solve() << '\n';
}