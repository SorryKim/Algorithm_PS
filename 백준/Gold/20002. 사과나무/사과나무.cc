#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[300][300];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    return;
}

int solve(){
    vector<vector<int>> psum(N, vector<int>(N, 0));

    // 누적합 계산
    psum[0][0] = arr[0][0];
    for(int i = 1; i < N; i++){
        psum[i][0] = arr[i][0] + psum[i - 1][0];
        psum[0][i] = arr[0][i] + psum[0][i - 1];
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            psum[i][j] = arr[i][j]
                       + psum[i - 1][j]
                       + psum[i][j - 1]
                       - psum[i - 1][j - 1];
        }
    }

    int ans = arr[0][0];

    // len = 한 변 길이 - 1
    for(int len = 0; len < N; len++){
        for(int i = 0; i + len < N; i++){
            for(int j = 0; j + len < N; j++){
                int x2 = i + len;
                int y2 = j + len;

                int sum = psum[x2][y2];
                if (i > 0) sum -= psum[i - 1][y2];
                if (j > 0) sum -= psum[x2][j - 1];
                if (i > 0 && j > 0) sum += psum[i - 1][j - 1];

                ans = max(ans, sum);
            }
        }
    }

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}