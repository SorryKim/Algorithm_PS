#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;

// 두 점 사이 거리의 제곱 반환
int calc(pair<int, int> a, pair<int, int> b)
{

    int dx = pow(a.first - b.first, 2);
    int dy = pow(a.second - b.second, 2);

    return dx + dy;
}

int calc2(int left, int right)
{

    int val = 987654321;

    for (int i = left; i < right; i++)
    {
        for (int j = i + 1; j < right; j++)
        {
            val = min(val, calc(v[i], v[j]));
        }
    }

    return val;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int func(int left, int right)
{

    if (right - left <= 3)
        return calc2(left, right);

    int mid = (left + right) / 2;
    int idx = v[mid].first;

    int dist = min(func(left, mid), func(mid + 1, right));

    // 중앙선 strip 후보
    vector<pair<int, int>> strip;
    for (int i = left; i < right; i++)
    {
        int dx = v[i].first - idx;
        if (pow(dx, 2) < dist)
            strip.push_back(v[i]);
    }

    // strip는 y좌표 기준 정렬
    sort(strip.begin(), strip.end(), cmp);

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size(); j++)
        {
            int dy = strip[j].second - strip[i].second;
            if (pow(dy, 2) >= dist)
                break;
            dist = min(dist, calc(strip[i], strip[j]));
        }
    }

    return dist;
}

int solve()
{

    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++)
        if (v[i] == v[i - 1])
            return 0;

    return func(0, v.size());
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main()
{

    input();
    cout << solve() << "\n";
    return 0;
}
