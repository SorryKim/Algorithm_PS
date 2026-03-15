#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> len;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        len.push_back(s.length());
    }
}

long long solve(){

    long long ans = 0;
    vector<int> cnt(21, 0);

    for(int i = 0; i < N; i++){
        
        if(i > K) {
            int first = len[i - K - 1];
            cnt[first]--;
        }
        
        int last = len[i];
        ans += cnt[last];
        cnt[last]++;
    }

    return ans;
}

int main(){

    input();
    cout << solve() << "\n";

    return 0;
}