// 골드바흐의 추측 / baekjoon_9020.cpp
// https://www.acmicpc.net/problem/9020

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int t, n;
bool arr[10010];
void solve();

void input() {

    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }

}

void solve() {

    for (int i = n / 2; i > 0; i--) {
        if (arr[i] && arr[n - i]) {
            cout << i << " " << n - i << "\n";
            break;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10000; i++) {
        arr[i] = true;
    }

    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= 10000; i++) {
        if (arr[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                arr[j] = false;
            }
        }
    }
   
    input();
}
