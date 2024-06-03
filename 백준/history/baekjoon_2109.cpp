// 순회강연 / baekjoon_2109.cpp
// https://www.acmicpc.net/problem/2109

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void Input() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({ p,d });
    }
    
}

void Solve() {
    
    sort(v.begin(), v.end(), cmp);
    int sum = 0;

    for (int i = 0; i < n; i++) {

        int cost = v[i].first;
        int day = v[i].second;

        pq.push(cost);
        sum += cost;
        
        if (pq.size() > day) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << sum << "\n";

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    Solve();
}
