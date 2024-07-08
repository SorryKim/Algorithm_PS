#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &parent, int i) {
    
    if (parent[i] == i) 
        return i;
    
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int a, int b) {
    int a_parent = find(parent, a);
    int b_parent = find(parent, b);
    
    if(a_parent < b_parent)
        parent[b_parent] = a_parent;
    else
        parent[a_parent] = b_parent;
}


bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}



int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent;
    
    for(int i = 0; i < n; i++){
        parent.push_back(i);
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        
        // 사이클 조건 확인
        if (find(parent, costs[i][0]) != find(parent, costs[i][1])) {
            answer += costs[i][2];
            Union(parent, costs[i][0], costs[i][1]);
        }
        
    }

    return answer;
}