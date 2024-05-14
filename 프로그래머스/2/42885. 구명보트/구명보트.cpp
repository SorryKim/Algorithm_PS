#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    
    
    int light = 0;
    int heavy = people.size() - 1;
    int boats = 0;
    
    while (light <= heavy) {
        // 가장 가벼운 사람과 가장 무거운 사람의 무게 합이 제한보다 작거나 같다면 둘이 함께 타기
        if (people[light] + people[heavy] <= limit) {
            light++;  // 가벼운 사람은 보트를 타고 출발했으므로 다음 사람으로 이동
        }
        // 가장 무거운 사람은 항상 보트를 타게 됨
        heavy--;  // 무거운 사람은 보트를 타고 출발했으므로 다음 사람으로 이동
        boats++;  // 보트 하나 추가
    }
    
    return boats;
}