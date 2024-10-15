#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int in_degree[32001];
vector<int> graph[32001];

vector<int> BFS(){

    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i <= N; i++){
        if(in_degree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){

        int now = q.top();
        q.pop();
        result.push_back(now);

        for(int next : graph[now]){
            in_degree[next]--;
            if(in_degree[next] == 0)
                q.push(next);
        }
    }

    if(result.size() != N)
        return vector<int>();
    
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    vector<int> result = BFS();
    for(int ans : result)
        cout << ans << " ";
    
    return 0;
}
