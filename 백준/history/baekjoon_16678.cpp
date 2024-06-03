// 모독 / baekjoon_16678.cpp
// https://www.acmicpc.net/problem/16678

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;


void Input() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
 
}

void Solve() {
    
    sort(v.begin(), v.end());
    int cnt = 1; // 프로젝트가 진행된 횟수
    long long result = 0;

    for (int i = 0; i < N; i++)
    {
        if (v[i] >= cnt)
        {
            
            result += v[i] - cnt; // 명성과 프로젝트 진행 횟수 차만큼 해커를 고용해야 프로젝트 유지 가능
            cnt++;
        }
    }

    cout << result << "\n";

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    Input();
    Solve();
}
