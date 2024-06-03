// 최대공약수 / baekjoon_2824.cpp
// https://www.acmicpc.net/problem/2824

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool check[1300001];
int k;
vector<int> v; // 소수 모임

void Input() {
    
    cin >> k;
 
}

int BinarySearch(int value) {

    int left = 2;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (v[mid] >= value)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

void Solve() {
    
    if (!check[k])
        cout << 0 << "\n";
    else {
        int temp = BinarySearch(k);
        int result = v[temp] - v[temp - 1];
        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    // 에라토스테네스의 체
    for (int i = 2; i <= 1300000; i++) {
        if (!check[i])
            for (int j = 2 * i; j <= 1300000; j += i) {
                check[j] = true;
            }
    }

    // 범위 내의 소수들 벡터로 모음
    for (int i = 2; i <= 1300000; i++) {
        if (!check[i])
            v.push_back(i);
    }

    while (t--) {
        Input();
        Solve();
    }
}
