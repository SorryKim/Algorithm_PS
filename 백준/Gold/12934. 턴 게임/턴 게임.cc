#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long X, Y, N;

    cin >> X >> Y;
    long long sum = X + Y;

    // 근의 공식 사용
    long long D = 1 + 8 * sum;
    long long sqrt_D = (long long)sqrt(D);

    if (sqrt_D * sqrt_D != D) {
        cout << -1;
        return 0;
    }

    N = (-1 + sqrt_D) / 2;

    // x + y는 [1,N]의 합이 되어야함.
    if (N * (N + 1) / 2 != sum) {
        cout << -1;
        return 0;
    }

    long long cnt = 0;
    long long temp = X;

    // 최소갯수로 X값을 만드는지 체크
    for (long long i = N; i >= 1 && temp > 0; i--) {
        if (temp >= i) {
            temp -= i;
            cnt++;
        }
    }

    if (temp == 0)
        cout << cnt;
    else 
        cout << -1;

    return 0;
}