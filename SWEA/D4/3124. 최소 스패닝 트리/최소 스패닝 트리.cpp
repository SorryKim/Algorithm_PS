#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {

    int end, cost;

    Edge(int b, int c) : end(b), cost(c) {}

    bool operator>(const Edge& other) const{
        return cost > other.cost;
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
   
    
    for (int test = 1; test <= T; test++) {

        int V, E;
        cin >> V >> E;
        long long ans = 0;

        bool visited[100001];
        for (int i = 0; i <= 100000; i++)
            visited[i] = false;

        vector<vector<Edge>> graph(V + 1);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        

        for (int i = 0; i < E; i++) {
            int start, end, cost;
            cin >> start >> end >> cost;
            graph[start].push_back({ end,cost });
            graph[end].push_back({ start,cost });
        }

        pq.push({ 1,0 });

        while (!pq.empty()) {
            int end = pq.top().end;
            int cost = pq.top().cost;
            pq.pop();

            if (visited[end])
                continue;

            visited[end] = true;
            ans += cost;
            for (Edge& edge : graph[end]) {
                if (!visited[edge.end]) {
                    pq.push(edge);
                }
            }
        }


        cout << "#" << test << " " << ans << "\n";
    }

    return 0;
}
