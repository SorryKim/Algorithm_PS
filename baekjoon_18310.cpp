// 안테나 / baekjoon_18310.cpp
// https://www.acmicpc.net/problem/18310

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v;


void Input() {
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

void Solve() {

    sort(v.begin(), v.end());
    int idx = v.size() / 2;
    int result;
    long long sum = LLONG_MAX;

    for (int i = idx - 1; i <= idx + 1; i++) {
        long long temp = 0;

        for (auto a : v) 
            temp += abs(a - v[i]);
        

        if (sum > temp) {
            result = v[i];
            sum = temp;
        }

    }

    cout << result;
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();

}
