#include <iostream>
#include <vector>

using namespace std;

// 특정 숫자 x 이하의 수에서 1의 개수를 계산하는 함수
long long func(long long n) {

    long long cnt = 0;
    long long temp = 1;// 자리수

    while (temp <= n) {

        long long a = (n / (temp * 2)) * temp;
        long long b = max(0LL, (n % (temp * 2)) - temp + 1);

        cnt += (a + b);

        temp *= 2;
    }

    return cnt;
}

int main() {
    long long A, B;
    cin >> A >> B;

    long long result = func(B) - func(A - 1);
    cout << result << '\n';

    return 0;
}
