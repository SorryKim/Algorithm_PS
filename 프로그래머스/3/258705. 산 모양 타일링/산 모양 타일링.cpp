#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    const int MOD = 10007;
    
    // n번 기준 4가지 방법가능
    // 1. 윗타일
    // 2. 왼타일
    // 3. 오타일
    // 4. 노타일
    
    vector<int> a(n + 1, 0); // i번째에 3번 방법 제외
    vector<int> b(n + 1, 0); // i번째에 3번 방법 사용
    
    a[0] = 1;
    b[0] = 0;
    
    for(int i = 1; i <= n; i++){
        
        // top이 있는 경우
        if(tops[i - 1] == 1){
            a[i] = (2 * b[i - 1] + 3 * a[i - 1]) % MOD;
            b[i] = (a[i - 1] + b[i - 1]) % MOD;
        }
        // top이 없는 경우
        else{
            a[i] = (2 * a[i - 1] + b[i - 1]) % MOD;
            b[i] = (a[i - 1] + b[i - 1]) % MOD;
        }
    }
  
    return (a[n] + b[n]) % MOD;
}