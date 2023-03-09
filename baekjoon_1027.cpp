// 고층 건물 / baekjoon_1027.cpp
// https://www.acmicpc.net/problem/1027

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[51];

void Input() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

}

void Solve() {

    int result = -1;
    int cnt = 0;

    for (int i = 1; i <= N; i++) {

        cnt = 0;
        double temp = 1111111111;
        double m = 0; // 기울기

        // left
        for (int j = i - 1; j >= 1; j--) {
            m = (arr[j] - arr[i]) / ((double)j - (double)i);
            // 접하지 않는 경우
            if (temp > m) {
                cnt++;
                temp = m;
            }
        }

        // right
        temp = -1111111111;
        for (int j = i + 1; j <= N; j++) {
            m = (arr[j] - arr[i]) / ((double)j - (double)i);
            // 접하지 않는 경우
            if (temp < m) {
                cnt++;
                temp = m;
            }
        }

        result = max(result, cnt);
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
