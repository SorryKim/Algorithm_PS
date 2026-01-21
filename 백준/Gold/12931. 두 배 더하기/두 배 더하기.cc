#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> B;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    B.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> B[i];

    return;
}

bool isFinish(){
    
    for(int i = 0; i < N; i++) if(B[i] != 0) return false;
    
    return true;
}

int solve(){
    int ans = 0;
    
    // 뒤집어서 생각!
    // B배열을 모두 0으로 만들기
    
    while(!isFinish()){

        // 1. 홀수는 짝수로 만들기
        for(int i = 0; i < N; i++){
            if(B[i] % 2 != 0){
                B[i]--;
                ans++;
            }   
        }

        if(isFinish()) return ans;
        
        // 2. 전체 2로 나누기
        ans++;
        for(int i = 0; i < N; i++){
            B[i] /= 2;
        }
    }
    
    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}