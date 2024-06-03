// 제곱 ㄴㄴ 수 / baekjoon_1016.cpp
// https://www.acmicpc.net/problem/1016

#include<iostream>
#include<algorithm>
using namespace std;

long long N, M;
bool arr[1000001] = { false, };

void input() {
    cin >> N >> M;
}

void solve() {

    long long cnt = 0;

    for (long long i = 2; i * i <= M; i++) {

        long long num = N / (i * i);

        if (N % (i * i) != 0)
            num++;
        
        while (num * (i * i) <= M) {
            arr[num * (i * i) - N] = true;
            num++;
        }
    }

    for (int i = 0; i <= M - N; i++) {
        if (!arr[i]) 
            cnt++;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    solve();
}
