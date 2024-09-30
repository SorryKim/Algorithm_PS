#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int arr[20][20];
int team_sum[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int full_team = (1 << N) - 1; // 모든 선수가 포함된 팀

    // 모든 팀의 능력치를 미리 계산
    for(int team = 1; team <= full_team; team++) {
        int sum = 0;

        for(int i = 0; i < N; i++) {
            if((team >> i) & 1) {
                for(int j = i + 1; j < N; j++) {
                    if((team >> j) & 1)
                        sum += arr[i][j] + arr[j][i];
                }
            }
        }
        team_sum[team] = sum;
    }

    int answer = 1e9;

    // 가능한 모든 팀 조합에 대해 능력치 차이 계산
    for(int team1 = 1; team1 <= full_team; team1++) {

        int team2 = full_team ^ team1;

        // 두 팀 모두 최소 한 명 이상의 선수를 가져야 함
        if(team1 == 0 || team2 == 0) 
            continue;

        // 중복 계산 방지
        if(team1 > team2) continue;

        int result = abs(team_sum[team1] - team_sum[team2]);

        if(result < answer) {
            answer = result;
            if(answer == 0) 
                break;
        }
    }

    cout << answer << '\n';
    return 0;
}
