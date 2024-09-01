#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const pair<int, double> &p1, const pair<int, double> &p2){
    
    if(p1.second != p2.second)
        return p1.second > p2.second;
    else
        return p1.first < p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> clear(N + 1, 0);
    vector<int> not_clear(N + 1, 0);
    
    for(auto now : stages){
        for(int i = 1; i < now; i++){
            clear[i]++;
        }
        not_clear[now]++;
        
    }
    
    vector<pair<int, double>> v;
    for(int i = 1; i <= N; i++){
        if(clear[i] == 0 && not_clear[i] == 0)
            v.push_back({i, 0.0});
        else{
            double val = (double)not_clear[i] / (double)(not_clear[i] + clear[i]);
            v.push_back({i, val});
        }
        
    }
    sort(v.begin(), v.end(), cmp);
    
    for(auto now : v)
        answer.push_back(now.first);
    
 
    return answer;
}