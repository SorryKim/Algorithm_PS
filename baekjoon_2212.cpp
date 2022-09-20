// 센서 / baekjoon_2212.cpp
// https://www.acmicpc.net/problem/2212

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[10001];
vector<int> dist;
long long sum;

void Input() {

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
}

void Solve() {

    for (int i = 0; i < N - 1; i++) 
        dist.push_back(arr[i + 1] - arr[i]);
    sort(dist.begin(), dist.end());

    sum = 0;
    for (int i = 0; i < N - K; i++)
        sum += dist[i];
    

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();
    Solve();
}
