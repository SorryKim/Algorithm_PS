#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct cmp{

    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
        return p1.second > p2.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int answer = 0;
    cin >> N;
    vector<pair<int,int>> v;

    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    for(auto now : v){
        int start = now.first;
        int end = now.second;

        while(!pq.empty() && pq.top().second <= start){
            pq.pop();
        }
        pq.push(now);

        answer = max(answer, (int)pq.size());
    }

    cout << answer;

    return 0;
}
