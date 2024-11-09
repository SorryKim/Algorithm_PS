#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> time(N + 1, 0);
    vector<int> dp(N + 1, 0);
    vector<vector<int>> pre(N + 1);
    vector<int> indegree(N + 1, 0);
    queue<int> q;

    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        time[i] = a;
        indegree[i] = b;

        // 처음으로 할 수 있는 작업
        if(b == 0){
            q.push(i);
            dp[i] = a;
        }

        for(int j = 0; j < b; j++){
            int num;
            cin >> num;
            pre[num].push_back(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto& a : pre[now]){
            indegree[a]--;
            if(indegree[a] == 0)
                q.push(a);
            
            dp[a] = max(dp[a], dp[now] + time[a]);
        }
    }
   
    
    int answer = 0;
    for(auto &a : dp)
        answer = max(answer, a);

    cout << answer << '\n';

    

    return 0;
}
