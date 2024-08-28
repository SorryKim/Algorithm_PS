// 오아시스 재결합 / baekjoon_3015.cpp
// https://www.acmicpc.net/problem/3015

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N;
long long cnt = 0;
int arr[500001];

void input() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

}

void solve() {

    stack<pair<int,long long>> s;
    cnt = 0;

    for (int i = 1; i <= N; i++) {
        
        int now = arr[i];

        while (!s.empty() && now > s.top().first) {
            cnt += s.top().second;
            s.pop();
        }

        if (s.empty())
            s.push({ now,1 });

        else{

            if (s.top().first > now) {
                s.push({ now, 1 });
                cnt++;
            }

            else{

                int height = s.top().first;
                long long temp = s.top().second;
                s.pop();

                if (!s.empty())
                    cnt++;
                cnt += temp;
                s.push({ height,temp + 1 });
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

}