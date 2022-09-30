// 거짓말 / baekjoon_1043.cpp
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> party[51];
bool people[51] = { false, };
int parent[51];

void Input() {

    cin >> N >> M;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        people[temp] = true;
    }
        
    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }
    
}


void Solve() {

    int cnt = 0;
    int loop = N;
    while (loop--) {
       
        for (int i = 0; i < M; i++) {
            bool b = false;

            // 파티에 진실을 아는 사람이 있는 경우
            for (int j = 0; j < party[i].size(); j++) {
                int now = party[i][j];

                if (people[now] == true) {
                    b = true;
                    break;
                }
            }

            // 파티에 모든사람이 진실을 알게 됨
            if (b) {
                for (int j = 0; j < party[i].size(); j++) {
                    int now = party[i][j];
                    people[now] = true;
                }
            }

        }
    }

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < party[i].size(); j++) {
            int now = party[i][j];
            if (people[now]) {
                cnt++;
                break;
            }
        }
    }

    cout << M - cnt << "\n";
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    Solve();

}
