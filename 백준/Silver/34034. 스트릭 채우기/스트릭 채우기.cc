#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct problem{
    int idx;
    int time;

    bool operator<(const problem &other) const {
        return time < other.time;
    }
};

int N, M, K;
vector<problem> problems;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    
    for(int i = 1; i <= N; i++){
        int time;
        cin >> time;
        problems.push_back({i, time});
    }
    
    return;
}

void solve(){

    sort(problems.begin(), problems.end());

    vector<problem> used;

    int freeze_used = 0;
    int total_days = 0;

    for(auto &p : problems){
        if(freeze_used + (p.time - 1) > M) break;
        if(total_days + p.time > K) break;

        freeze_used += (p.time - 1);
        total_days += p.time;
        used.push_back(p);
    }

    if(total_days + (M - freeze_used) < K){
        cout << -1;
        return;
    }

    vector<int> answer;

    for(auto &p : used){
        for(int i = 0; i < p.time - 1; i++){
            answer.push_back(0);
        }
        answer.push_back(p.idx);
    }

    // 남은 날짜 프리즈로 채우기
    while(answer.size() < K) answer.push_back(0);
    for(int x : answer) cout << x << " ";
    
}

int main(){
    
    input();
    solve();

    return 0;
}