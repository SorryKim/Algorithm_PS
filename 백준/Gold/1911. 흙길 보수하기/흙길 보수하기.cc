#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, L;
    int answer = 0;
    vector<pair<int, int>> v;

    // Input
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    
    // 현재 다리를 놓은 범위
    int left = v[0].first;
    int right = left;

    while(right < v[0].second){
        right += L;
        answer++;
    }

    for(int i = 1; i < v.size(); i++){
        int start = v[i].first;
        int end = v[i].second;

        // 처음부터 다리를 다시 놓아야하는 경우
        if(start >= right){
            left = start;
            right = start;
            while(right < end){
                right += L;
                answer++;
            }
        }
        // 일부만 겹치는 경우
        else if(right < end && right >= start){
            left = start;
            while(right < end){
                right += L;
                answer++;
            }
        }
    }

    cout << answer;
    
    return 0;   
}