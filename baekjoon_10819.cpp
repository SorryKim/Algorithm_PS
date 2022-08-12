// 차이를 최대로 / baekjoon_10819.cpp
// https://www.acmicpc.net/problem/10819

#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[10], temp[10];
bool visited[10];
int result = 0;

void input() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        visited[i] = false;
    }

}

int calc() {

    int sum = 0;
    for (int i = 1; i < N; i++) {
        sum += abs(temp[i] - temp[i - 1]);
    }
    return sum;
}

void DFS(int n) {

    if (n == N) {
        result = max(result, calc());
        return;
    }
    else {
        for (int i = 0; i < N; i++) {

            if (visited[i])
                continue;

            temp[n] = arr[i];
            visited[i] = true;
            DFS(n + 1);
            visited[i] = false;
        }
    }
}

void solve() {

    DFS(0);
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
