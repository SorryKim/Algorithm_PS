// 수 묶기 / baekjoon_1744.cpp
// https://www.acmicpc.net/problem/1744

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnt_1, cnt_0;
vector<int> pos, neg, ans;

void input() {
    
    cin >> N;

    cnt_1 = 0;
    cnt_0 = 0;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        if (n > 1)
            pos.push_back(n);
        else if (n < 0)
            neg.push_back(n);
        else if (n == 1) {
            cnt_1++;
        }
        else if (n == 0) {
            cnt_0++;
        }
            
    }


}

bool compare(int a, int b) {
    return b < a;
}

void solve() {
    
    if(!pos.empty())
        sort(pos.begin(), pos.end(), compare);
    if(!neg.empty())
        sort(neg.begin(), neg.end());

    // 음수의 개수가 홀수
    if ((neg.size() % 2) == 1) {

        if (neg.size() != 1) {

            
            for (int i = 0; i < neg.size() - 1; i += 2) {
                int temp = neg[i] * neg[i + 1];
                ans.push_back(temp);
            }

            if (cnt_0 == 0) {
                ans.push_back(neg[neg.size() - 1]);
            }
            else
                ans.push_back(0);
        }
        else {
            if (cnt_0 == 0) {
                ans.push_back(neg[0]);
            }
            else
                ans.push_back(0);
        }
    }
    // 음수의 개수가 짝수
    else {
        for (int i = 0; i < neg.size(); i += 2) {
            int temp = neg[i] * neg[i + 1];
            ans.push_back(temp);
        }
        ans.push_back(0);
    }


    // 양수의 개수가 홀수
    if ((pos.size() % 2) == 1) {

        if (pos.size() != 1) {
            for (int i = 0; i < pos.size() - 1; i += 2) {
                int temp = pos[i] * pos[i + 1];
                ans.push_back(temp);
            }
            ans.push_back(pos[pos.size() - 1]);
        }
        else {
            ans.push_back(pos[0]);
        }
    }

    // 양수의 개수가 짝수
    else {
        for (int i = 0; i < pos.size(); i += 2) {
            ans.push_back(pos[i] * pos[i + 1]); 
        }
    }
    

    int result = cnt_1; // 1의 개수, 1은 그냥 더하는 것이 최댓값
    for (auto a : ans) {
        result += a;
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

}
