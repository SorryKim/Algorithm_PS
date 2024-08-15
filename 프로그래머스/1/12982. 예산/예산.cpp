#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    for(auto a : d){
        budget -= a;
        if(budget < 0)
            break;
        answer++;
    }
    return answer;
}