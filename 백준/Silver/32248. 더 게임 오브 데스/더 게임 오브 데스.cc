#include <iostream>
#include <vector>

using namespace std;

int N;
long long T;
vector<int> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T;
    graph.resize(N + 1, 0);

    for(int i = 1; i <= N; i++) cin >> graph[i];

    return;
}

int solve(){
    
    int ans = 1;

    vector<int> visited(N + 1, -1);
    vector<int> order;

    // 사이클 찾기
    int now = 1;
    long long depth = 0;
    
    while(visited[now] == -1){
        order.push_back(now);
        visited[now] = depth;
        now = graph[now];
        depth++;
    }

    // 사이클 시작지점
    int cycle_start = visited[now];
    int cycle_len = order.size() - cycle_start;

    if(T < order.size()) ans = order[T];
    else{
        long long remain = (T - cycle_start) % cycle_len;
        ans = order[cycle_start + remain];
    }

    
    return ans;
}

int main(){
    
    input();
    cout << solve() << "\n";

    return 0;
}