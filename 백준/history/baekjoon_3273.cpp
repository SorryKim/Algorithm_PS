// 두 수의 합 / baekjoon_3273.cpp
// https://www.acmicpc.net/problem/3273

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,x;
vector<int> v;

void input() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> x;
   
}

void solve() {

    int result = 0;
    int left = 0;
    int right = n - 1;
    sort(v.begin(), v.end());

    while (left < right) {

        int sum = v[left] + v[right];
        
        if (sum == x) {
            result++;
            left++;
        }
        else if (sum > x) 
            right--;
        else
            left++;

    }

    cout << result << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

}
