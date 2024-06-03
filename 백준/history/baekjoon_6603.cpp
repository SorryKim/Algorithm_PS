// 로또 / baekjoon_6603.cpp
// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

bool visit[50];
int k;
int arr[50];

void Input();
void Solve();

void Input() {

    while (true) {

        cin >> k;
        if (k == 0)
            return;

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < 50; i++)
            visit[i] = false;

        Solve();
        cout << "\n";
    }

}

void DFS(int start, int depth) {

    if (depth == 6) {
        for (int i = 0; i < 50; i++) {
            if (visit[i])
                cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++) {
        
        int now = arr[i];
        if (visit[now])
            continue;

        visit[now] = true;
        DFS(i + 1, depth + 1);
        visit[now] = false;
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
