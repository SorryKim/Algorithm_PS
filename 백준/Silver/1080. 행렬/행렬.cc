#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> A, B;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    A.resize(N, vector<int>(M));
    B.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            A[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            B[i][j] = s[j] - '0';
        }
    }

    return;
}

bool isSame(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i][j] != B[i][j]) return false;
        }
    }

    return true;
}

// 3x3 연산
void func(int x, int y){

    for(int i = x; i <= x + 2; i++){
        for(int j = y; j <= y + 2; j++){
            A[i][j] = (A[i][j] == 0) ? 1 : 0;
        }
    }

    return;
}

int solve(){

    int ans = 0;

    // 변환 못하는 경우
    if(N < 3 || M < 3){
        if(isSame()) return 0;
        else return -1;
    }

    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++){
            if(A[i][j] != B[i][j]) {
                ans++;
                func(i, j);
            }
        }
    }

    if(isSame()) return ans;
    else return -1;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}