#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<long long> A, B;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);

    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
}

bool can(long long days){
    long long cnt = 0;

    for(int i = 0; i < N; i++){
        long long remain = A[i] - days * B[i];
        if(remain > 0){
            
            long long var = ceil((double)remain / (double)B[i]);
            cnt += var;
            if(cnt > days) return false;
        }
    }
    
    return true;
}

long long solve(){

    long long left = 0;
    long long right = 0;

    // 상한: 능력 안 쓰고 가장 오래 걸리는 나무 기준
    for(int i = 0; i < N; i++) right = max(right, (A[i] + B[i] - 1) / B[i]);

    long long ans = right;

    while(left <= right){
        long long mid = (left + right) / 2;

        if(can(mid)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}
