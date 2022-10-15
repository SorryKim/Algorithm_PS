// N과 M (12) / baekjoon_15666.cpp
// https://www.acmicpc.net/problem/15666

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[8];
int ans[8];

void Input() {

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
}

void DFS(int index, int cnt) {

    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";

        cout << "\n";
        return;
    }

    int temp = -1;

    for (int i = index; i < N; i++) {

        if (temp != arr[i]) {
            ans[cnt] = arr[i];
            temp = arr[i];
            DFS(i, cnt + 1);
        }
    }

}

void Solve() {

    DFS(0, 0);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    Input();
    Solve();
    
}
