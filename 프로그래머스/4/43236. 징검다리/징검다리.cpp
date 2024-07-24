#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    int left = 0;
    int right = distance;
    int answer = 0;
    
    while (left <= right) {
    
        int mid = (left + right) / 2;
        int temp = 0;
        int cnt = 0;
        
        for (int i = 0; i < rocks.size(); i++) {
            
            if ((rocks[i] - temp) < mid) {
                cnt++;
            } else {
                temp = rocks[i];
            }
        }
        
        if (distance - temp < mid) {
            cnt++;
        }
        
        if (cnt > n) {
            right = mid - 1;
        } else {
            answer = max(answer,mid);
            left = mid + 1;
        }
    }
    
    return answer;
}
