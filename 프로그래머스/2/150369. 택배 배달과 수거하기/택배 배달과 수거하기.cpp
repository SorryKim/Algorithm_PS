#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long d_remain = 0, p_remain = 0; 

    // 뒤에서부터 탐색
    for (int i = n - 1; i >= 0; i--) {
        d_remain += deliveries[i];
        p_remain += pickups[i];

        // 배달이나 수거가 남아 있다면 트럭을 보냄
        while (d_remain > 0 || p_remain > 0) {
            d_remain -= cap; // 한 번 나가면 cap만큼 배달
            p_remain -= cap; // cap만큼 수거
            answer += (long long)(i + 1) * 2; // 왕복 거리
        }
    }

    return answer;
}