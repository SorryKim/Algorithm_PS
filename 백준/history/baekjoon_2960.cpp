// 에라토스테네스의 체 / baekjoon_2960.cpp
// https://www.acmicpc.net/problem/2960

#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
bool arr[1001];

bool isPrime(int n) {

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= 1000; i++)
        arr[i] = true;

    arr[0] = false;
    arr[1] = false;

    int num = 2;
    int temp = 1;
    int cnt = 0;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            if (arr[i * j]) {
                arr[i * j] = 0;
                cnt++;
                
                if (cnt == K)
                    cout << i * j << "\n";
                

            }
        }

    }

    

}
