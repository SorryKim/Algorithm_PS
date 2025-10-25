#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> v;


bool canMove(const pair<int, int> &a, const pair<int, int> &b){

    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;

    return (x2 < x1 && x1 < y2) || (x2 < y1 && y1 < y2);
}

// BFS
int solve(int a, int b){
    a--;
    b--;
    int n = v.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        if(now == b) return 1;

        for(int i = 0; i < n; i++){
            if(!visited[i] && canMove(v[now], v[i])){
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 0; i < N; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) v.push_back({a, b});
        else if(t == 2) cout << solve(a, b) << "\n";
    }

}

int main(){
    input();
}