#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
    
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    vector<vector<pair<int, int>>> graph(n + 1);
    
    vector<bool> is_gate(n + 1, false);
    vector<bool> is_summit(n + 1, false);
    
    for(int gate : gates)
        is_gate[gate] = true;
    
    for(int summit : summits)
        is_summit[summit] = true;
    
    
    // 그래프 생성
    for(auto& path : paths){
        int a = path[0];
        int b = path[1];
        int c = path[2];
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
 
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // 모든 출입구를 시작 지점으로 설정
    for(int gate : gates){
        dist[gate] = 0;
        pq.push({0, gate});
    }
    
    while(!pq.empty()){
        int intensity = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
       
        if(intensity > dist[now] || is_summit[now])
            continue;
        
        for(auto path : graph[now]){
            int next = path.first;
            int weight = path.second;
            
            // 인접 노드가 출입구인 경우 스킵
            if(is_gate[next])
                continue;
            
            int next_intensity = max(intensity, weight);
            
            if(dist[next] > next_intensity){
                dist[next] = next_intensity;
                pq.push({dist[next], next});
            }
        }
    }
    
    // 산봉우리 중에서 intensity가 가장 작은 것 선택
    sort(summits.begin(), summits.end());
    answer[1] = 1e9;
    answer[0]  = 0;
    
    for(int summit : summits){
        if(dist[summit] < answer[1]){
            answer[1] = dist[summit];
            answer[0]  = summit;
        }
    }
    
    return answer;
}
