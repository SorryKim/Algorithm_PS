#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    
    return p1.second > p2.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 987654321;
    unordered_map<int,int> map;
    vector<pair<int,int>> v;
    
    for(auto a : tangerine){
        map[a]++;
    }
    
    for(auto a : map){
        int key = a.first;
        int value = a.second;
        
        v.push_back({key,value});
    }
    
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += v[i].second;
        if(cnt >= k){
            answer = i + 1;
            break;
        }
    }
    
    
    
    return answer;
}