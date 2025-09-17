#include <bits/stdc++.h>
using namespace std;

int N;
int town[11];
vector<int> graph[11];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> town[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            graph[i].push_back(temp);
        }
    }
}

int BFS(int code)
{

    // 그룹 분리
    vector<int> groupA, groupB;
    for (int i = 1; i <= N; i++)
    {
        if (code & (1 << (i - 1)))
            groupA.push_back(i);
        else
            groupB.push_back(i);
    }

    queue<int> q;
    vector<bool> visited(N + 1, false);

    // 1. groupA
    q.push(groupA[0]);
    visited[groupA[0]] = true;
    int cnt = 0;

    while (!q.empty())
    {
        int now = q.front();
        cnt++;
        q.pop();
        for (int next : graph[now])
        {
            if (!visited[next] && (find(groupA.begin(), groupA.end(), next) != groupA.end()))
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if (cnt != groupA.size())
        return -1;

    // 2. groupB
    q.push(groupB[0]);
    visited[groupB[0]] = true;
    cnt = 0;

    while (!q.empty())
    {
        int now = q.front();
        cnt++;
        q.pop();
        for (int next : graph[now])
        {
            if (!visited[next] && (find(groupB.begin(), groupB.end(), next) != groupB.end()))
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if (cnt != groupB.size())
        return -1;

    int cnt1 = 0;
    int cnt2 = 0;
    for (int n : groupA)
        cnt1 += town[n];
    for (int n : groupB)
        cnt2 += town[n];

    return abs(cnt1 - cnt2);
}

int solve()
{

    int ans = 1e9;

    // 1. 비트마스킹으로 선거구 나누기
    for (int code = 1; code < (1 << N) - 1; code++)
    {

        int temp = BFS(code);
        if (temp != -1)
            ans = min(ans, temp);
    }

    return ans == 1e9 ? -1 : ans;
}

int main()
{
    input();

    cout << solve() << '\n';
    return 0;
}
