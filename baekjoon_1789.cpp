// 수들의 합 / baekjoon_1789.cpp
// https://www.acmicpc.net/problem/1789

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long s;
    cin >> s;

    long long cnt = 0;
    long long sum = 0;

    for (long long i = 1; i <= s; i++) {
        sum += i;
        cnt++;
        if (sum > s) {
            cnt--;
            break;
        }
        if (sum == s)
            break;
    }

    cout << cnt << '\n';

}
