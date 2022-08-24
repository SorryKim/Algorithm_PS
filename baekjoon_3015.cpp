// 오아시스 재결합 / baekjoon_3015.cpp
// https://www.acmicpc.net/problem/3015

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int N;
long long cnt = 0; // 답이 int범위 초과할 수 있음
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

        // now가 더 큰 경우
        while (!s.empty() && now > s.top().first) {
            cnt += s.top().second;
            s.pop();
        }

        if (s.empty())
            s.push({ now,1 });

        else{

            // now가 더 작은 경우
            if (now < s.top().first) {
                s.push({ now, 1 });
                cnt++;
            }

            // now랑 같을 경우
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
