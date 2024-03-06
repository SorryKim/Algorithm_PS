#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(20001);
bool visited[20001] = {false, };
int solution(int n, vector<vector<int>> edge) {
    
    for (auto e : edge) {
        int a = e[0];
        int b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({1, 0}); 
    visited[1] = true;

    int maxDist = 0;
    int answer = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist > maxDist) {
            maxDist = dist;
            answer = 1; 
        } else if (dist == maxDist) {
            answer++;  
        }

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, dist + 1});
            }
        }
    }

    return answer;
}
