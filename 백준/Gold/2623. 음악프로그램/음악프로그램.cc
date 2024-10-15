#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[1001];
int in_degree[1001]; 


vector<int> Sort(){

    vector<int> result;
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(in_degree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){

        int now = q.front();
        q.pop();
        result.push_back(now);

        for(int next : graph[now]){
            in_degree[next]--;
            if(in_degree[next] == 0)
                q.push(next);
        }
    }

    if(result.size() != N)
        return vector<int>(1,0);
    
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;

        vector<int> temp(k);
        for (int j = 0; j < k; j++) 
            cin >> temp[j];

        for (int j = 0; j < k - 1; j++) {
            int a = temp[j];
            int b = temp[j + 1];
            graph[a].push_back(b);
            in_degree[b]++;
        }
    }

    vector<int> answer = Sort();

    for(auto now : answer)
        cout << now << '\n';
    
    return 0;
}
