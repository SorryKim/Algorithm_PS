#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Robot {
    vector<int> route;
    int target_idx;
    pair<int, int> now;
};

bool move(Robot &robot, const vector<vector<int>> &points) {

    int idx = robot.route[robot.target_idx] - 1;
    int r = points[idx][0];
    int c = points[idx][1];
    
    // 도착한 경우
    if(robot.now.first == r && robot.now.second == c){
        robot.target_idx++;
        // 종료
        if(robot.target_idx == robot.route.size()) return false;
        
        // 다음 목적지 설정
        idx = robot.route[robot.target_idx] - 1;
        r = points[idx][0];
        c = points[idx][1];
    }
    
    if(robot.now.first < r)
        robot.now.first++;
    else if(robot.now.first > r)
        robot.now.first--;
    else if(robot.now.second < c)
        robot.now.second++;
    else if(robot.now.second > c)
        robot.now.second--;
    
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    queue<Robot> q;
    
    for(auto a : routes){
        int start_idx = a[0] - 1;
        int end_idx = a[1] - 1;
        pair<int, int> start = {points[start_idx][0], points[start_idx][1]};
        q.push({a, 0, start});
    }
    
    
    
    while(true){
        
        queue<Robot> tmp;
        int map[101][101] = {0};
        
        while(!q.empty()){
            Robot robot = q.front();
            q.pop();
            map[robot.now.first][robot.now.second]++;
            if(map[robot.now.first][robot.now.second] == 2) answer++;
            if(move(robot, points)) tmp.push(robot);
        }
        
        if(tmp.empty()) return answer;
        q = tmp;
    }
    
    return answer;
}