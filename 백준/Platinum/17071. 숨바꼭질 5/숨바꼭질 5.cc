#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 500000;
bool visited[MAX + 1][2];

// time 초 후 동생의 위치
int Where(int N, int time)
{
    return N + (time * (time + 1)) / 2;
}


int BFS(int N, int K){

    queue<pair<int, int>> q;
    q.push({N, 0});

    while(!q.empty()){

        int now = q.front().first;
        int time = q.front().second;
        int target = Where(K, time);

        // 도착시점의 짝홀수 체크
        visited[now][time % 2] = true; 
        q.pop();

        // 동생이 범위 넘어간경우
        if(target > MAX)
            continue;
        
        // 수빈이는 현재지점을 +1, -1 같이 2초만 지나면 해당 위치를 유지할 수 있다
        // 즉 짝수 시간대에 이미 수빈이가 방문했던 적이 있으면 해당시간에 수빈이는 동생과 만날 수 있다.
        // 짝홀만 구분해주면 된다.
        if(visited[target][time % 2])
            return time;
        
        vector<int> moves {now + 1, now - 1 , 2 * now};

        for(int next : moves){
            if(next >= 0 && next <= MAX){
                if(!visited[next][(time + 1) % 2])
                    q.push({next, time + 1});  
            }
        }
    }

    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int answer =  BFS(N, K);
    cout << answer << '\n';
    
    return 0;
}