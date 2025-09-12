#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> v;
int answer = 0;
pair<int, int> nextPoint;

void shoot()
{

    int dist = 0;
    int idx = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int temp = pow(nextPoint.first - v[i].first, 2) + pow(nextPoint.second - v[i].second, 2);
        if (temp > dist)
        {
            idx = i;
            dist = temp;
        }
    }

    answer += dist;
    nextPoint.first = v[idx].first;
    nextPoint.second = v[idx].second;
    v.erase(v.begin() + idx);

    return;
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    nextPoint.first = 0;
    nextPoint.second = 0;

    for (int i = 0; i < M; i++)
    {
        shoot();
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
}

int main()
{
    input();
    cout << answer << '\n';
    return 0;
}
