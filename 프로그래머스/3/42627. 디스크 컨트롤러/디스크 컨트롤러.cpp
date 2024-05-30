#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int jobIndex = 0;
    int totalJobs = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    
    while ( (jobIndex < totalJobs) || !pq.empty()) {
        
        while (jobIndex < totalJobs && jobs[jobIndex][0] <= time) {
            pq.push(jobs[jobIndex]);
            jobIndex++;
        }
        
        if (!pq.empty()) {
            vector<int> job = pq.top();
            pq.pop();
            time += job[1];
            answer += (time - job[0]);
        } else {
            if (jobIndex < totalJobs) {
                time = jobs[jobIndex][0];
            }
        }
    }

    return answer / totalJobs;
}