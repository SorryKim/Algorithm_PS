// 세 친구 / baekjoon_17089.cpp
// https://www.acmicpc.net/problem/17089

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool graph[4001][4001];
int arr[4001];

void Input() {
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;

        arr[a]++;
        arr[b]++;
    }
}


void Solve() {
    
    int result = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {

            // i와 j가 친구
            if (graph[i][j]) {
                for (int k = j + 1; k <= N; k++) {

                    // i j k 3명이서 동시에 친구인 경우만
                    if (graph[i][k] && graph[j][k]) {

                        int temp = arr[i] + arr[j] + arr[k];
                        temp -= 6; // 2 - 2 - 2 , 서로포함된 경우 빼줌
                        if (result == -1)
                            result = temp;
                        else
                            result = min(result, temp);
                    }
                }
            }
        }
    }

    cout << result << "\n";
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
