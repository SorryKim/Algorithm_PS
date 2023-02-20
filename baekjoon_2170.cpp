// 선 긋기 / baekjoon_2170.cpp
// https://www.acmicpc.net/problem/2170

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<pair<long long, long long>> v;


void Input() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
}

void Solve() {

    sort(v.begin(), v.end());
    long long start = v[0].first;
    long long end = v[0].second;

    long long result = 0;

    for (int i = 1; i < v.size(); i++) {

        long long temp1 = v[i].first;
        long long temp2 = v[i].second;

        // 안에서 시작하는 경우
        if (end >= temp1) {

            // 선이 연장되는 경우
            if (end < temp2)
                end = temp2;

        }

        // 밖으로 벗어나는 경우
        else {
            // 지금까지의 선을 더함
            result += end - start;
            start = temp1;
            end = temp2;
        }

    }

    result += end - start;
    cout << result << "\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

}
