#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    int a, b, idx;
};

int N, M, K;
vector<Score> scores;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    scores.resize(N);
    for(int i = 0; i < N; i++){
        cin >> scores[i].a >> scores[i].b;
        scores[i].idx = i;
    }
}

long long solve(){
    
    long long ans = 0;
    vector<bool> check(N, false);

    // b 기준 내림차순 
    sort(scores.begin(), scores.end(), [](const Score& x, const Score& y){
        return x.b > y.b;
    });

    // 본상 K명 먼저 선택
    for(int i = 0; i < K; i++) {
        ans += scores[i].a;
        check[scores[i].idx] = true;
    }
     
    // a 기준 내림차순
    sort(scores.begin(), scores.end(), [](const Score& x, const Score& y){
        return x.a > y.a;
    });

    int cnt = 0;
    int i = 0;
    while(cnt < M){
        Score now = scores[i];
        if(check[now.idx]){
            i++;
            continue;
        }

        ans += now.a;
        cnt++;
        check[now.idx] = true;
        i++;
    }

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}
