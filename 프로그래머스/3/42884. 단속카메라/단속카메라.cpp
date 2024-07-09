#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 끝나는 점 기준 오름차순 정렬
bool cmp(const vector<int> &v1, const vector<int> &v2){
      return (v1[1] == v2[1]) ? v1[0] < v2[0] : v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<bool> check; // 감시가능 여부
    sort(routes.begin(), routes.end(), cmp);
    
    for(int i = 0; i < routes.size(); i++)
        check.push_back(false);
    
    // 마지막으로 있는 카메라 위치 기록
    int camera;

    for(int i = 0; i < routes.size(); i++){
        
        // 이미 카메라와 만난 경우
        if(check[i])
            continue;
        
        // 만나지 않은 경우 해당 경로의 마지막 부분에 카메라 추가
        int start = routes[i][0];
        int end = routes[i][1];
        camera = end;
        check[i] = true;
        answer++;
        
        for(int j = i + 1; j < routes.size(); j++){
            
            int next_start = routes[j][0];
            int next_end = routes[j][1];
            if(!check[j]){
                if(camera >= next_start && camera <= next_end){
                    check[j] = true;
                }
            }
        }
    }
    
    return answer;
}