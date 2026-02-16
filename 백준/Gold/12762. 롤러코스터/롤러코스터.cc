#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int dp[1000][1000][2];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N);

    for(int i = 0; i < N; i++) cin >> arr[i];

    return;
}

int solve(){
    
    vector<int> dp1, dp2;
    dp1.resize(N, 1); // 왼쪽 기준 내림차순
    dp2.resize(N, 1); // 오른쪽 기준 오름차순

    // 1. 왼쪽 기준 내림차순 구하기
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    // 2. 오른쪽 기준 오름차순 구하기
    for(int i = N - 2; i >= 0; i--){
        for(int j = N - 1; j > i; j--){
            if(arr[i] < arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    
    int ans = 1;

    for(int i = 0; i < N; i++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    return ans;
}

int main(){
    
    input();
    cout << solve() << "\n";

    return 0;
}