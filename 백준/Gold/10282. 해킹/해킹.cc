#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    const int INF = 1e9;
    cin >> TC;

    while(TC--){

        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int,int>>> graph(n + 1);
        vector<int> dist(n + 1, INF);
        dist[c] = 0;

        // 그래프 생성
        for(int i = 0; i < d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s}); // b가 감염되면 같이 감염될 컴퓨터들
        }

        // 다익스트라
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, c});

        while(!pq.empty()){
            int now_dist = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if(now_dist > dist[now]) continue;

            for(auto a : graph[now]){
                int next = a.first;
                int next_dist = now_dist + a.second;
                if(next_dist < dist[next]){
                    dist[next] = next_dist;
                    pq.push({next_dist, next});
                }
            }
        }

        // 정답 구하기
        int cnt = 0, time = 0;
        
        for(int i = 1; i <= n; i++){
            if(dist[i] == INF) continue;
            cnt++; // 감염된 컴퓨터 수 체크
            time = max(time, dist[i]);
        }

        cout << cnt << ' ' << time << '\n';
    }

    
    
    return 0;
}
