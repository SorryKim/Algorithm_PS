#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool visited[11][1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    int answer = -1;
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});

    while(!q.empty()){
        int n = q.front().first;
        int k = q.front().second;
        q.pop();

        if(k == K) {
            answer = max(answer, n);
            continue;
        }
        
        string s = to_string(n);

        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j <s.size(); j++){
                char ch1 = s[i];
                char ch2 = s[j];
                string tmp = s;
                tmp[i] = ch2;
                tmp[j] = ch1;

                if(tmp[0] == '0') continue;
                if(visited[k][stoi(tmp)]) continue;
                visited[k][stoi(tmp)] = true;
                q.push({stoi(tmp), k + 1});
            }
        }
    }
    
    cout << answer << "\n";

    return 0;
}