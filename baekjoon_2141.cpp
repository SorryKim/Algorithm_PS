// 우체국 / baekjoon_2141.cpp
// https://www.acmicpc.net/problem/2141

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<long long, long long>> v;
long long sum;
void Input() {
    
    cin >> N;
    sum = 0;

    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        v.push_back({ a,b });
        sum += b;
    }
  
}

void Solve() {

    sort(v.begin(), v.end());
    long long temp = 0;

    for (int i = 0; i < N; i++) {
        temp += v[i].second;
        
        if (temp >= (sum + 1) / 2) {
            cout << v[i].first << "\n";
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
