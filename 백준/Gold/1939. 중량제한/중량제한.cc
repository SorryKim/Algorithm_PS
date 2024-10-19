#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1000000000;
int N, M;
int start, target;

bool BFS(int val, vector<vector<pair<int,int>>> &graph){

    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){

        int now = q.front();
        q.pop();

        if(now == target)
            return true;
        
        for(auto temp : graph[now]){
            int next = temp.first;
            int next_weight = temp.second;

            if(visited[next])
                continue;
            if(next_weight < val)
                continue;
            
            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<vector<pair<int,int>>> graph(N + 1);
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin >> start >> target;

    int left = 1;
    int right = MAX;
    
    while(left <= right){

        int mid = (left + right) / 2;

        if(BFS(mid, graph)) left = mid + 1;
        else right = mid - 1;
    }

    cout << right;

    return 0;
}