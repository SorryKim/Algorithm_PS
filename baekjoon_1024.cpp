// 수열의 합 / baekjoon_1024.cpp
// https://www.acmicpc.net/problem/1024

#include <iostream>
#include <algorithm>
using namespace std;

int N, L;

void Input() {

    cin >> N >> L;
  
}

void Solve() {

    int start = -1, cnt = 0;

    for (int i = L; i <= 100; i++) {

        int temp = i * (i - 1) / 2;
        int val = N - temp;
        if (val % i == 0 && val / i >= 0) {
            start = val / i;
            cnt = i;
            break;
        }
    }

    if (start < 0) 
        cout << start << "\n";

    for (int i = 0; i < cnt; i++) 
        cout << start + i << " ";
    

 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
