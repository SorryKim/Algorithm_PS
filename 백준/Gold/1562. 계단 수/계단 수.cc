#include <iostream>

using namespace std;

const int MOD = 1000000000;
int N;
long long dp[101][10][1 << 10] = {0}; // [계단 수 길이][현재문자][사용숫자mask]

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
}

long long solve(){
    
    // 길이가 1인 dp 테이블 초기화
    // 길이가 1일 때 0은 안됨
    for(int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;

    // 길이, 문자, mask 항목별 dp테이블 채우기
    for(int len = 1; len < N; len++){
        for(int digit = 0; digit < 10; digit++){
            for(int mask = 0; mask < 1 << 10; mask++){

                long long now = dp[len][digit][mask];
                if(now == 0) continue; // 맨 앞자리가 0인 경우
                
                // digit + 1
                if(digit < 9){
                    int nextDigit = digit + 1;
                    int nextMask = mask | (1 << nextDigit);
                    dp[len + 1][nextDigit][nextMask] = (dp[len + 1][nextDigit][nextMask] + now) %  MOD;
                }

                // digit - 1
                if(digit > 0){
                    int nextDigit = digit - 1;
                    int nextMask = mask | (1 << nextDigit);
                    dp[len + 1][nextDigit][nextMask] = (dp[len + 1][nextDigit][nextMask] + now) %  MOD;
                }
            }
        }
    }

    // 정답 계산
    long long ans = 0;  
    for(int i = 0; i < 10; i++){
        ans = (ans + dp[N][i][(1 << 10) - 1]) % MOD;
    }

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
}