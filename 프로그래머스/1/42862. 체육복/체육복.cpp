#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int n, vector<int> &reserve) {
    for(auto a : reserve) {
        if(a == n)
            return true;
    }
    return false;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool visit[31] = { false, };
    int cnt = 0;
    
    // reserve와 lost에서 같은 값을 제거할 때, 역순으로 처리
    for(int i = reserve.size() - 1; i >= 0; i--) {
        for(int j = lost.size() - 1; j >= 0; j--) {
            if(lost[j] == reserve[i]) {
                reserve.erase(reserve.begin() + i);
                lost.erase(lost.begin() + j);
                break; // 한번 제거했으면 반복문 탈출
            }
        }
    }
    
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    
    for(auto a : lost) {
        int p1 = a - 1;
        int p2 = a + 1;
        
        if(p1 > 0 && !visit[p1] && check(p1, reserve)) {
            visit[p1] = true;
            continue;
        } else if(p2 <= n && !visit[p2] && check(p2, reserve)) {
            visit[p2] = true;
            continue;
        }
        cnt++;
    }
    
    return n - cnt;
}
