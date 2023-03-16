// 귀여운 라이언 / baekjoon_15565.cpp
// https://www.acmicpc.net/problem/15565

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int arr[1000010];
vector<int> v;

void Input() {
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == 1)
            v.push_back(i);
    }

}


void Solve() {

    int left = 0, right = K - 1;
    int result = 987654321;

    if (v.size() < K) {
        cout << -1;
        return;
    }

    for (int i = 0; i <= v.size() - K; i++) {
        result = min(result, v[right] - v[left] + 1);
        left++;
        right++;
    }


    cout << result;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    
}
