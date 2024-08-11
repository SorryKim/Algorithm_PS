#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 100000;
int n;
int arr[MAX + 1];
bool check[MAX + 1];
bool finished[MAX + 1];
int cnt;

void DFS(int now){

    check[now] = true;
    int next = arr[now];

    
    if(!check[next]){
        DFS(next);
    }else if(!finished[next]){ // 방문은했지만 finished가 안된 상태 즉, 사이클 상태
        cnt++;
        finished[now] = true;

        for(int i = next; i != now; i = arr[i]){
            cnt++;
            finished[i] = true;
        }
        
    }

    finished[now] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        int answer = 0;
        cnt = 0;

        for(int i = 0; i <= n; i++){
            finished[i] = false;
            check[i] = false;
        }

        for (int i = 1; i <= n; i++) 
            cin >> arr[i];


        for (int i = 1; i <= n; i++) {
            if (!check[i]) {
                DFS(i);
            }
        }

        answer = n - cnt;
        cout << answer << '\n';
    }

    return 0;
}