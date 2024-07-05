#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// 두 문자가 한글자만 다르면 true반환
bool check(string a, string b){
    
    int cnt = 0;
    
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
            cnt++;
    }
    
    return ((cnt == 1) ? true : false); 
    
}


int BFS(string begin, string target, const vector<string> &words){
    
    int cnt = 0;
    unordered_map<string, bool> visited;
    queue<pair<string, int>> q;
    
    for(auto a : words){
        visited.insert({a,false});
    }
    
    q.push({begin, 0});
    visited[begin] = true;
    
    while(!q.empty()){
        
        string now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(now == target)
            return cnt;
        
        for(auto word : words){
            if(!visited[word] && check(now, word)){
                visited[now] = true;
                q.push({word, cnt + 1});
            }
        }
    }
    
    // 정답에 도착할 수 없는 경우
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int length = words[0].size();
    
    answer = BFS(begin, target, words);
    return answer;
}