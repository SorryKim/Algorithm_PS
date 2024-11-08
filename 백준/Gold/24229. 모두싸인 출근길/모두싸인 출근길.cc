#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int,int>> v;

void Input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        int L, R;
        cin >> L >> R;
        v[i].first = L;
        v[i].second = R;
    }
}

// 겹치는 판자 합치기
void Merge(){

    sort(v.begin(), v.end());
    vector<pair<int, int>> temp;

    int start = v[0].first;
    int now = v[0].second;

    for(int i = 1; i < N; i++){
        int L = v[i].first;
        int R = v[i].second;

        // 겹치는 경우
        if(now >= L)
            now = max(now, R);
        else{
            temp.push_back({start, now});
            start = L;
            now = R;
        }
    }

    temp.push_back({start, now});
    v = temp;
    N = v.size();
    return;
}

int BFS(){
    int answer = 0;
    queue<pair<int,int>> q;
    vector<bool> visited(N, false);
    q.push({v[0].second, 0});
    visited[0] = true;

    while(!q.empty()){
        int now = q.front().first;
        int idx = q.front().second;
        q.pop();

        int L = v[idx].first;
        int R = v[idx].second;
        int jump = R - L;
        int next = idx + 1;
        while(next < N){
            // 도달 가능
            if(R + jump >= v[next].first){
                if(!visited[next]){
                    visited[next] = true;
                    q.push({v[next].second, next});
                }
                next++;
            }
            else break;
        }
        answer = max(answer, now);
    }

    return answer;
}

int main() {
    Input();
    Merge();
    cout << BFS() << '\n';
    return 0;
}
