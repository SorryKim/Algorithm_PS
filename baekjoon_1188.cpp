// 음식 평론가  / baekjoon_1188.cpp
// https://www.acmicpc.net/problem/1188

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int GCD(int a, int b) {

    if (a % b == 0)
        return b;

    else
        return GCD(b, a % b);
}

void Input() {

    cin >> N >> M;
}

void Solve() {

    int result = M - GCD(N, M);
    cout << result << "\n";
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
