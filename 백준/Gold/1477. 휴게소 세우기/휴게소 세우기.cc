#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> rest;
    rest.push_back(0);
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        rest.push_back(num);
    }
    rest.push_back(L);
    

    sort(rest.begin(), rest.end());

    int start = 1;
    int end = L;
    int answer = 1e9;


    while(start <= end){

        // 휴게소 사이 최소거리 
        int mid = (start  + end) / 2;
       
        int cnt = 0; // 새로 지어야하는 휴게소의 갯수
        for(int i = 1; i < rest.size(); i++){
            int dist = rest[i] - rest[i - 1];
            if(dist > mid){
                cnt += (dist - 1) / mid; // (dist - 1)인 이유 휴게소가 생길 경우 보정
            }
        }

        if(cnt <= M){
            answer = min(answer, mid);
            end = mid - 1;
        }
        else if(cnt > M)
            start = mid + 1;
    }

    cout << answer << '\n';
    return 0;
}
