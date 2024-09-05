#include <string>
#include <vector>
#include <cmath>

using namespace std;
int cnt, N;

void DFS(int depth, vector<int> v){
    
    if(depth == N){
        cnt++;
        return;
    }
    
    // 이번 단계에서 넣을 숫자 선택
    for(int i = 1; i <= N; i++){
         bool flag = true;
        // 이전 단계에서 사용여부 체크
        for(auto num : v)
            if(num == i){
                flag = false;
                break;
            }
        
        // 이전단계랑 대각선 위치 여부 체크
        for(int j = 0; j < v.size(); j++){
            if(abs(j - depth) == abs(v[j] - i)){
                flag = false;
                break;
            }
        }
        if(flag){
            v.push_back(i);
            DFS(depth + 1, v);
            v.pop_back();
        }
    }
}

int solution(int n) {
    int answer = 0;
    cnt = 0;
    N = n;
    
    for(int i = 1; i <= N; i++){
        vector<int> v;
        v.push_back(i);
        DFS(1, v);
    }
    answer = cnt;
    return answer;
}