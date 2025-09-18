#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> eggs;
int ans = 0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int hp, weight;
        cin >> hp >> weight;
        eggs.push_back({hp, weight});
    }
}

int countBrokenEggs(vector<pair<int, int>> v)
{
    int cnt = 0;
    for (auto egg : v)
    {
        if (egg.first <= 0)
            cnt++;
    }

    return cnt;
}

// v: 현재 계란들 상태
// hand: 현재 손에 든 계란의 인덱스
void dfs(vector<pair<int, int>> v, int hand)
{
    if (hand >= N)
    {
        ans = max(ans, countBrokenEggs(v));
        return;
    }

    if (v[hand].first <= 0)
    {
        dfs(v, hand + 1);
        return;
    }

    ans = max(ans, countBrokenEggs(v));
    bool hit = false;

    for (int i = 0; i < N; i++)
    {
        if (i == hand || v[i].first <= 0)
            continue;

        hit = true;
        auto temp = v;
        temp[i].first -= temp[hand].second;
        temp[hand].first -= temp[i].second;
        dfs(temp, hand + 1);
    }

    if (!hit)
        dfs(v, hand + 1);
}

void solve()
{
    dfs(eggs, 0);
    cout << ans << '\n';
}

int main()
{
    input();
    solve();
    return 0;
}
