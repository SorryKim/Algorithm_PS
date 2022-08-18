// 골드바흐의 추측 / baekjoon_6588.cpp
// https://www.acmicpc.net/problem/6588

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int t, n;
bool arr[1000001];
void solve();

void input() {

    
    for (int i = 0; i < 100000; i++) {
        cin >> n;
        if (n == 0)
            break;
        solve();
    }

}

void solve() {

    int start = 0;
    int end = n - 1;
    bool b = true;

    for (int i = 1; i < 1000000 / 2; i++) {
        if (arr[i] && arr[n - i]) {
            cout << n << " = " << i << " + " << n - i << "\n";
            b = false;
            break;
        }
    }

    if (b)
        cout << "Goldbach's conjecture is wrong." << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 1000000; i++) {
        arr[i] = true;
    }

    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (arr[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                arr[j] = false;
            }
        }
    }
   
    input();
}
