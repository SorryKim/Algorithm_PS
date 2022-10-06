// 최소비용 구하기 2 / baekjoon_11779.cpp
// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define INF 987654321
int n, m;
int start, destination;
int dist[1001];
int path[1001];
vector<pair<int, int>> graph[1001];

void Input() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
    }

    cin >> start >> destination;

}

void Dijkstra() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;

    while (!pq.empty()) {

        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 없을 시 시간초과
        if (dist[now] < cost)
            continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int nextCost = graph[now][i].second;

            if (dist[next] > cost + nextCost) {
                path[next] = now;
                dist[next] = cost + nextCost;
                pq.push({ dist[next], next});
            }
        }
    }

}

void Solve() {
   
    Dijkstra();
    cout << dist[destination] << "\n";
 
    int index = destination;
    stack<int> st;
    while (true) {
        st.push(index);
        if (index == start)
            break;
        int next = path[index];
        index = next;
    }
    
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();
}
