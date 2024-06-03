// 부분수열의 합 / baekjoon_14225.cpp
// https://www.acmicpc.net/problem/14225

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
bool check[2000001];
int arr[21];

void Input() {
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

// 재귀로 가능한 수들 체크
void Func(int x, int sum) {

    check[sum] = true;

    if (x == N)
        return;

    Func(x + 1, sum);
    Func(x + 1, sum + arr[x]);

}

void Solve() {

    Func(0, 0);
    
    for (int i = 0; i <= 2000000; i++) {
        if (!check[i]) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    
}
