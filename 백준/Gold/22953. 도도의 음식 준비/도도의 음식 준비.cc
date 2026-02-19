#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, C;
vector<int> A;
vector<vector<int>> comb;
const long long MAX = 1e12;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> C;
    A.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    return;
}


// 격려의 모든 경우 구하기
void func(int idx, int remain, vector<int> v){

    if(idx == N){
        comb.push_back(v);
        return;
    }

    // 최대로 격려할 수 있는 경우
    int val = min(remain, A[idx] - 1);

    for(int i = 0; i <= val; i++){
        v[idx] = i;
        func(idx + 1, remain - i, v);
    }
}

long long solve(){

    long long ans = MAX;
   
    // 1. 격려하는 모든 경우 구하기
    func(0, C, vector<int>(N, 0));

    // 2. 해당 격려일 때의 시간 구하기
    for(auto &a : comb){

        // 해당조합에서의 요리사의 조리 시간
        vector<int> v = A;
        for(int i = 0; i < N; i++) v[i] -= a[i];
        
        // K개 만드는 데 걸리는 시간 구하기
        long long left = 0;
        long long right = MAX;

        while(left <= right){
            long long mid = (left + right) / 2;

            long long cnt = 0;
            for(int i = 0; i < N; i++) cnt += mid / v[i];
            
            if(cnt >= K) right = mid - 1;
            else left = mid + 1;
        }

        ans = min(ans, left);
    }

    return ans;
}
    


int main(){
    input();
    cout << solve() << "\n";

    return 0;
}