#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<string> bulbs;
vector<int> ownCost;
vector<vector<int>> cost;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ans = 1e9;
    for(int i = 0; i < N; i++){
        string s;
        int cnt = 0;

        cin >> s;
        bulbs.push_back(s);
        
        for(int j = 1; j < s.size(); j++) if(s[j] != s[j - 1]) cnt++;
        ownCost.push_back(cnt);
    }

    cost.resize(N, vector<int>(N, 0));
}

// 만들어진 길 상태 체크 
int calc(vector<int> &v){

    int result = 0;
    
    if(N > 1){
        for(int i = 1; i < N; i++){
            int idx1 = v[i - 1];
            int idx2 = v[i];

            result += cost[idx1][idx2];
        }
    }
    
    return result;
}


void dfs(int mask, vector<int> v){

    // 모든 전구 다 사용한 경우
    if(mask == (1 << N) - 1){
        ans = min(ans, calc(v));
        return;
    }

    for(int i = 0; i < N; i++){
        if(mask & (1 << i)) continue;
        v.push_back(i);
        dfs(mask | (1 << i), v);
        v.pop_back();
    }

    return;
}

int solve(){

    // 기본 값 계산
    int cnt = 0;
    for(int val : ownCost) cnt += val;

    // 바뀌는 값 미리 카운트
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            string s1 = bulbs[i];
            string s2 = bulbs[j];
            if(s1.back() != s2.front()) cost[i][j] = 1;
            else cost[i][j] = 0;
        }
    }

    // 조합
    dfs(0, vector<int>());

    return ans + cnt;
}

int main(){
    input();    
    cout << solve() << "\n";
    return 0;
}