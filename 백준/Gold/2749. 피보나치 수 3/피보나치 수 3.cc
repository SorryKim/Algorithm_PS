#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000;
vector<int> fibo;

int main()
{
    long long n;
    cin >> n;

    // 피사노 주기 사용
    // 주기 구하기
    int a = 1;
    int b = 1;
    int period = 1;

    while(!(a == 0 && b == 1)){
        int c = (a + b) % MOD;
        a = b;
        b = c;
        period++;
    }

    fibo.push_back(0);
    fibo.push_back(1);

    for(int i = 2; i <= period; i++)
        fibo.push_back((fibo[i - 1] + fibo[i - 2]) % MOD);
    

    cout << fibo[n % period];
    return 0;
}
