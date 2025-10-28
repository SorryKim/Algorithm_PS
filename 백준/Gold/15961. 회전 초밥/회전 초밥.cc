#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, d, k, c;
vector<int> sushi;
int ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> d >> k >> c;
    ans = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        sushi.push_back(num);
    }

}


void solve(){

    unordered_map<int, int> mp;

    int left = 0;
    int right = k - 1;

    // 처음 갯수 세기
    for(int i = left; i <= right; i++){
        mp[sushi[i]]++;
    }

    // 쿠폰 챙기기
    mp[c]++;
    
    while(true){

        ans = max(ans, (int)mp.size());

        int del = sushi[left];

        left = (left + 1) % N;
        right = (right + 1) % N;
        if(left == 0) return; // 한바퀴 다돌음

        mp[del]--;
        if(mp[del] == 0) mp.erase(del);
        mp[sushi[right]]++;
    }
    
    return;
}

int main(){
    
    input();
    solve();
    cout << ans << "\n";
}