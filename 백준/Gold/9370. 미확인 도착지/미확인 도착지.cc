#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int INF = 1000000000;
    int T;
    cin >> T;

    while (T--)
    {

        int n, m, t; // 교차로, 도로, 목적지 후보의 개수
        int s, g, h; // 출발지, g,h사이의 교차로를 지나감
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
        vector<int> sub; // 목적지 후보
        vector<int> answer;

        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;

            graph[a][b] = d;
            graph[b][a] = d;
        }

        for (int i = 0; i < t; i++)
        {
            int target;
            cin >> target;
            sub.push_back(target);
        }

        // 시작점을 기준으로 다익스트라
        vector<int> dist(n + 1, INF);
        vector<bool> passed(n + 1, false); // g-h 경로를 지났는지 체크
        dist[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});

        while (!pq.empty())
        {
            int nowDist = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if (dist[now] < nowDist)
                continue;

            for (int i = 1; i <= n; i++)
            {
                if (graph[now][i] == -1)
                    continue;

                int nextDist = nowDist + graph[now][i];

                // 현재 경로가 g-h 간선을 지나는지 여부 확인
                bool isGH = ((now == g && i == h) || (now == h && i == g));

                // 다음 노드까지의 경로가 g-h 간선을 지났는지 여부
                bool nextPassed = passed[now] || isGH;

                if (nextDist < dist[i])
                {
                    dist[i] = nextDist;
                    passed[i] = nextPassed;
                    pq.push({nextDist, i});
                }
                else if (nextDist == dist[i])
                {
                    // 동일한 거리인 경우 g-h 경로를 지났다면 passed[i]를 업데이트
                    if (nextPassed && !passed[i])
                    {
                        passed[i] = true;
                        pq.push({nextDist, i});
                    }
                }
            }
        }

        // 후보지들 중 pass여부 체크하여 답안 추가
        for (auto au : sub)
        {
            if (passed[au] && dist[au] != INF)
                answer.push_back(au);
        }

        sort(answer.begin(), answer.end());

        for (auto ans : answer)
            cout << ans << " ";

        cout << "\n";
    }
    return 0;
}
