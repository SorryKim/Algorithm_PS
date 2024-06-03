// 카드 정렬하기 / baekjoon_1715.cpp
// https://www.acmicpc.net/problem/1715

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N;
long long result;
int card[100001];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

}

void solve() {

    priority_queue<int, vector<int>, greater<int>> pq;
    result = 0;

    for (int i = 0; i < N; i++) {
        int temp = card[i];
        pq.push(temp);
    }

    while (pq.size() > 1) {

        int card1 = pq.top();
        pq.pop();
        int card2 = pq.top();
        pq.pop();

        int value = card1 + card2;
        result += value;
        pq.push(value);
    }
    
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

}
