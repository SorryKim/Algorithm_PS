// 기타 레슨 / baekjoon_2343.cpp
// https://www.acmicpc.net/problem/2343

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
long long low, high;

void Input() {

    cin >> N >> M;
    low, high = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        high += num;
    }

}

void Solve() {

    sort(v.begin(), v.end());

   
    while (low <= high) {

        long long mid = (low + high) / 2;
        long long cnt = 0;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (sum + v[i] > mid) {
                sum = 0;
                cnt++;
            }
            sum += v[i];
                
        }

        if (sum != 0)
            cnt++;

        if (cnt <= M)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << low << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}
