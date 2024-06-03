// 보석 도둑 / baekjoon_1202.cpp
// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
long long result;
int bag[300001];
pair<int,int> arr[300001];

void Input() {
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        arr[i] = { M,V };
    }

    for (int i = 0; i < K; i++)
        cin >> bag[i];
    
}

void Solve() {

    sort(arr, arr + N);
    sort(bag, bag + K);
    priority_queue<int, vector<int>, less<int>> pq;

    int index = 0;
    result = 0;

    for (int i = 0; i < K; i++) {
       
        for (int j = index; j < N; j++) {
            if (arr[j].first > bag[i])
                break;
            pq.push(arr[j].second);
            index++;
        }

        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
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
