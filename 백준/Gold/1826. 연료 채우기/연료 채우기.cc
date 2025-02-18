#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, P;
vector<pair<int,int>> stations;

void Input(){

    cin >> N;
    stations.resize(N);

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        stations[i] = {a, b};
    }

    cin >> L >> P;
}


int Solve(){
    
    // 거리순으로 주유소 정렬
    sort(stations.begin(), stations.end());

    priority_queue<int> pq; // 충전할 수 있는 연료들
    int now = 0; // 현재 위치
    int gas = P; // 현재 연료
    int cnt = 0;

    for(auto temp : stations){
        
        int station = temp.first;
        int dist = station - now; // 움직여야하는 거리

        // 충천해야함
        while(!pq.empty() && dist > gas){
            gas += pq.top();
            pq.pop();
            cnt++;
        }

        // 충전을 다해도 못가는 경우 종료
        if(dist > gas) return -1;

        // 이동
        now = station;
        gas -= dist;
        pq.push(temp.second);
    }

    
    // 마지막 구간
    while(!pq.empty() && L > now + gas){
        cnt++;
        gas += pq.top();
        pq.pop();
    }

    if(L > now + gas) return -1;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    cout << Solve() << "\n";

    return 0;
}