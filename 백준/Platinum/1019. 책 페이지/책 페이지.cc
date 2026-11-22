
#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long cnt[10] = {0};

// 숫자 n에 등장하는 각 숫자의 개수 계산
void countNumber(long long n, long long digit) {
    while(n > 0) {
        cnt[n % 10] += digit;
        n /= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    long long start = 1;
    long long end = N;
    long long digit = 1;

    while(start <= end) {

        // 시작 숫자의 일의 자리를 0으로
        while(start <= end && start % 10 != 0) {
            countNumber(start, digit);
            start++;
        }

        // 끝 숫자의 일의 자리를 9로
        while(start <= end && end % 10 != 9) {
            countNumber(end, digit);
            end--;
        }

        if(start > end) break;

        // 완전한 구간 처리
        long long count = (end / 10 - start / 10 + 1);

        for(int i = 0; i <= 9; i++) {
            cnt[i] += count * digit;
        }

        // 다음 자릿수로 이동
        start /= 10;
        end /= 10;
        digit *= 10;
    }

    for(int i = 0; i < 10; i++) cout << cnt[i] << " ";
    
    return 0;
}
