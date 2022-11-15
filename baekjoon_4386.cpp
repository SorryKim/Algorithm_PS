// 별자리 만들기 / baekjoon_4386.cpp
// https://www.acmicpc.net/problem/4386

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N;
double sum;
vector<pair<double, double>> stars; // { x좌표, y좌표 }
vector<pair<double, int>> edges[101]; // { 거리, 도착별의 index }
bool visit[101];


void Input() {
    
    cin >> N;
    sum = 0;

    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        stars.push_back({ a,b });
    }
    
}

double dist(double x1, double y1, double x2, double y2) {

    double x = (x2 - x1) * (x2 - x1);
    double y = (y2 - y1) * (y2 - y1);

    return sqrt(x + y);
}

void makeEdge() {

    for (int i = 0; i < N; i++) {

        // 출발하는 별
        double nowX = stars[i].first;
        double nowY = stars[i].second;

        for (int j = i + 1; j < N; j++) {
            
            // 목적지 별
            double nextX = stars[j].first;
            double nextY = stars[j].second;

            // 거리 값
            double val = dist(nowX, nowY, nextX, nextY);

            // 간선 저장
            edges[i].push_back({ val, j });
            edges[j].push_back({ val, i });
        }
    }

}

void Solve() {

    makeEdge();
    
    // prim 알고리즘
    // cost값 오름차순 우선순위 큐
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    for (int i = 0; i < edges[0].size(); i++) {

        double cost = edges[0][i].first;
        int next = edges[0][i].second;
        pq.push({ cost, next });
    }

    visit[0] = true;

    while (!pq.empty()) {

        double cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (visit[now])
            continue;
        
        else {

            visit[now] = true;
            sum += cost;

            for (int i = 0; i < edges[now].size(); i++) {
                double nextCost = edges[now][i].first;
                int next = edges[now][i].second;
                if (!visit[next])
                    pq.push({ nextCost, next });
            }
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << sum << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    Solve();

}
