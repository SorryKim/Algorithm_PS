#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    graph.resize(N + 1, vector<int>());

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

string solve(){
    string result = "";

    for(int i = 2; i <= N; i++){
        int cnt = 0;
        for(int j : graph[i]){
            if(j < i) cnt++;
        }

        if(cnt == 0) result += "N";
        else if(cnt == i - 1) result += "E";
        else return "-1";
    }

    return result;
}

int main(){
    input();
    cout << solve() << "\n";
}