#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long answer = LLONG_MAX;
    sort(times.begin(), times.end());
    
    long long left = 0;
    long long right = 10000000000000000;

    // mid값: 모든 인원이 심사를 받는 데 걸리는 시간
    while (left <= right) {

        long long mid = (left + right) / 2;
        
        // 심사를 받는 인원 수
        long long cnt = 0;
        
        // mid 시간동안 받는 인원 수 체크
        for (int i = 0; i < times.size(); i++) {
            cnt += (mid / times[i]);
        }
        
        // mid 시간동안 인원이 부족한 경우 시간을 늘림
        if (cnt < n) {
            left = mid + 1;
        }
        
        // 다 받을 수 있는 경우 시간 체크
        else {
            answer = min(answer, mid);
            right = mid - 1;
        }
    }
    
    return answer;
}